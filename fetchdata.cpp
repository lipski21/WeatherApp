#include "fetchdata.h"
#include <QNetworkRequest>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

WeatherDataFetcher::WeatherDataFetcher(QObject *parent) : QObject(parent)
{
    manager = new QNetworkAccessManager(this);
    connect(manager, &QNetworkAccessManager::finished,
            this, &WeatherDataFetcher::handleNetworkReply);
}

void WeatherDataFetcher::fetchData(const QUrl &url , const QString& city) // Zapytanie o dane
{
    QNetworkRequest request(url);
    QNetworkReply *reply = manager->get(request);

    replyToCityMap[reply] = city;
 //   connect(reply, &QNetworkReply::finished, this, [this, reply]() { handleNetworkReply(reply); });
}

void WeatherDataFetcher::handleNetworkReply(QNetworkReply *reply)
{
    QString city = replyToCityMap.value(reply);

    if (reply->error() != QNetworkReply::NoError) {
        qDebug() << "Wystąpił błąd podczas pobierania danych:" << reply->errorString(); // Obsługa błędu przy pobieraniu danych
        return;
    }

    auto response = reply->readAll();
    QJsonDocument doc = QJsonDocument::fromJson(response);
    QJsonObject json = doc.object();                        // stworzenie obiektu json

    emit dataReady(json , city);   // wysłanie sygnału
    reply->deleteLater();
    replyToCityMap.remove(reply);
}
