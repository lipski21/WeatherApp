#ifndef WEATHERDATA_H
#define WEATHERDATA_H

#include <QObject>
#include <QJsonObject>

/*!
 * \class WeatherData
 * \brief Klasa służy do przechowywania oraz przekazywania danych pogodowych.
 */
class WeatherData : public QObject
{
    Q_OBJECT

public:
    /*!
     * \brief Konstruktor.
     * \param parent Wskaźnik na obiekt nadrzędny.
     */
    explicit WeatherData(QObject *parent = nullptr);

public slots:
    /*!
     * \brief Funkcja obsługująca pobierane dane.
     * \param data Dane pogodowe pobrane z API.
     * \param city Nazwa miasta, dla którego pobrano dane.
     */
    void handleData(const QJsonObject &data , const QString &city);

signals:
    /*!
     * \brief Sygnał przekazujący aktualną temperaturę.
     * \param temperature Aktualna temperatura. [°C]
     * \param city Nazwa miasta, dla którego przekazywane są dane.
     */
    void temperatureReady(double &temperature , const QString &city);

    /*!
     * \brief Sygnał przekazujący dane do aktualizacji wykresów.
     * \param temperatures Tablica temperatur. [°C]
     * \param timeArray Tablica czasów. [yyyy-MM-ddTHH:mm]
     * \param rainArray Tablica opadów. [mm]
     * \param pressArray Tablica ciśnień. [hPa]
     * \param windArray Tablica prędkości wiatru. [km/h]
     * \param city Nazwa miasta, dla którego przekazywane są dane.
     */
    void ChartsReady(const QJsonArray &temperatures, const QJsonArray &timeArray, const QJsonArray &rainArray, const QJsonArray &pressArray, const QJsonArray &windArray, const QString &city);
};

#endif // WEATHERDATA_H
