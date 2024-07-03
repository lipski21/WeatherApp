#include "weatherdata.h"
#include <QDebug>
#include <QJsonArray>
#include <QDateTime>

WeatherData::WeatherData(QObject *parent)
    : QObject(parent)
{
}


void WeatherData::handleData(const QJsonObject &data, const QString &city)
{
    QJsonObject hourlyData = data["hourly"].toObject();     //   Obiekt przechowujący wszystkie dane pobierane z API (pomiary odbywają się co godzinę)
    QJsonArray timeArray = hourlyData["time"].toArray();    //  przechowująca dane godzinowe pomiarów
    QJsonArray temperatures = hourlyData["temperature_2m"].toArray();   // tablica z danymi o tempeaturze
    QJsonArray rain = hourlyData["rain"].toArray(); // [mm]
    QJsonArray surface_pressure = hourlyData["surface_pressure"].toArray(); // [hPa]
    QJsonArray wind_speed = hourlyData["wind_speed_10m"].toArray(); //km/h


    QDateTime currentDateTime = QDateTime::currentDateTime(); //Aktualna godzina

    double currentTemperature = -9999.9;    // dziwna wartość do obsługi błędu

    for (int i = 0; i < timeArray.size(); ++i) {  //for do znalezienia aktualnej temperatury
        QString timeString = timeArray[i].toString();
        QDateTime temperatureDateTime = QDateTime::fromString(timeString, "yyyy-MM-ddTHH:mm");  //data pomiaru w odpowiednim formacie

        // qDebug() << temperatureDateTime;
        // Sprawdź, czy znaleziono czas bliski do bieżącego
        if (temperatureDateTime.isValid() && temperatureDateTime <= currentDateTime) {
            // Uwzględnij tylko pomiary wykonane w tej samej godzinie
            if (temperatureDateTime.date() == currentDateTime.date() &&                     //sprawdza date
                temperatureDateTime.time().hour() == currentDateTime.time().hour()) {       //sprawdza godzine
                currentTemperature = temperatures[i].toDouble();                           // podstawia odpowiednia wartość
                qDebug() << temperatureDateTime;
                break;
            }
        }
    }

    // Sprawdź, czy udało się znaleźć aktualną temperaturę
    if (currentTemperature != -9999.9) {
        emit temperatureReady(currentTemperature , city);                  //emituje sygnał z aktualną temperaturą
    } else {
        qDebug() << "Nie można pobrać aktualnej temperatury. Brak danych.";                 //wypisuje błąd jeżeli wartość była niezmieniona
    }

    emit ChartsReady(temperatures, timeArray, rain, surface_pressure, wind_speed, city);

}

