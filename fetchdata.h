#ifndef FETCHDATA_H
#define FETCHDATA_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>

/*!
 * \class WeatherDataFetcher
 * \brief Klasa służąca do pobierania danych pogodowych z internetu.
 */
class WeatherDataFetcher : public QObject
{
    Q_OBJECT
public:
    /*!
     * \brief Konstruktor.
     * \param parent Wskaźnik na obiekt nadrzędny.
     */
    explicit WeatherDataFetcher(QObject *parent = nullptr);

    /*!
     * \brief Inicjuje pobieranie danych.
     * \param url Adres URL do pobrania danych.
     * \param city Nazwa miasta, dla którego mają zostać pobrane dane.
     */
    void fetchData(const QUrl &url, const QString& city);

signals:
    /*!
     * \brief Sygnał wysyłany, gdy dane są gotowe.
     * \param json Obiekt JSON z danymi.
     * \param city Nazwa miasta, dla którego pobrano dane.
     */
    void dataReady(const QJsonObject &json, const QString &city);

private slots:
    /*!
     * \brief Slot do obsługi odpowiedzi sieciowej.
     * \param reply Wskaźnik na odpowiedź sieciową.
     */
    void handleNetworkReply(QNetworkReply *reply);

private:
    QNetworkAccessManager *manager; /*!< Menedżer dostępu do sieci. */
    QMap<QNetworkReply*, QString> replyToCityMap; /*!< Mapa odpowiedzi sieciowych do miast. */
};

#endif // FETCHDATA_H
