#include "mainwindow.h"
#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include <QCoreApplication>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QDebug>
#include "fetchdata.h"
#include "weatherdata.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    WeatherDataFetcher fetcherWroc, fetcherWar, fetcherGda, fetcherRze, fetcherSz;
    WeatherData WrocData, WarData, GdaData, RzeData, SzData;

    // Połącz sygnał dataReady z metodą handleData w obiekcie weatherdata
    QObject::connect(&fetcherWroc, &WeatherDataFetcher::dataReady, &WrocData, &WeatherData::handleData);
    QObject::connect(&fetcherWar, &WeatherDataFetcher::dataReady, &WarData, &WeatherData::handleData);
    QObject::connect(&fetcherGda, &WeatherDataFetcher::dataReady, &GdaData, &WeatherData::handleData);
    QObject::connect(&fetcherRze, &WeatherDataFetcher::dataReady, &RzeData, &WeatherData::handleData);
    QObject::connect(&fetcherSz, &WeatherDataFetcher::dataReady, &SzData, &WeatherData::handleData);

    WizualizacjaPogody w;

    QObject::connect(&WrocData, &WeatherData::temperatureReady, &w, &WizualizacjaPogody::updateTemperature);
    QObject::connect(&WarData, &WeatherData::temperatureReady, &w, &WizualizacjaPogody::updateTemperature);
    QObject::connect(&GdaData, &WeatherData::temperatureReady, &w, &WizualizacjaPogody::updateTemperature);
    QObject::connect(&RzeData, &WeatherData::temperatureReady, &w, &WizualizacjaPogody::updateTemperature);
    QObject::connect(&SzData, &WeatherData::temperatureReady, &w, &WizualizacjaPogody::updateTemperature);

    QObject::connect(&WrocData, &WeatherData::ChartsReady, &w, &WizualizacjaPogody::updateCharts);
    QObject::connect(&WarData, &WeatherData::ChartsReady, &w, &WizualizacjaPogody::updateCharts);
    QObject::connect(&GdaData, &WeatherData::ChartsReady, &w, &WizualizacjaPogody::updateCharts);
    QObject::connect(&RzeData, &WeatherData::ChartsReady, &w, &WizualizacjaPogody::updateCharts);
    QObject::connect(&SzData, &WeatherData::ChartsReady, &w, &WizualizacjaPogody::updateCharts);

    //dane pobierane - 3dni w tył + przód temperatura, opady, ciśnienie, prędkość wiatru
    //Wrocław
    fetcherWroc.fetchData(QUrl("https://api.open-meteo.com/v1/forecast?latitude=51.1&longitude=17.0333&hourly=temperature_2m,rain,surface_pressure,wind_speed_10m&timezone=Europe%2FBerlin&past_days=3&forecast_days=3"), "Wroclaw");
    fetcherWar.fetchData(QUrl("https://api.open-meteo.com/v1/forecast?latitude=52.2298&longitude=21.0118&hourly=temperature_2m,rain,surface_pressure,wind_speed_10m&timezone=Europe%2FBerlin&past_days=3&forecast_days=3"), "Warszawa");
    fetcherSz.fetchData(QUrl("https://api.open-meteo.com/v1/forecast?latitude=53.4289&longitude=14.553&hourly=temperature_2m,rain,surface_pressure,wind_speed_10m&timezone=Europe%2FBerlin&past_days=3&forecast_days=3"), "Szczecin");
    fetcherGda.fetchData(QUrl("https://api.open-meteo.com/v1/forecast?latitude=54.3523&longitude=18.6491&hourly=temperature_2m,rain,surface_pressure,wind_speed_10m&timezoneEurope%2FBerlin&past_days=3&forecast_days=3"), "Gdansk");
    fetcherRze.fetchData(QUrl("https://api.open-meteo.com/v1/forecast?latitude=50.0413&longitude=21.999&hourly=temperature_2m,rain,surface_pressure,wind_speed_10m&timezone=Europe%2FBerlin&past_days=3&forecast_days=3") , "Rzeszow");

    w.show();



    return a.exec();
}
