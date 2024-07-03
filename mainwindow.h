#ifndef WIZUALIZACJAPOGODY_H
#define WIZUALIZACJAPOGODY_H

#include <QMainWindow>
#include "weatherdata.h"

#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QDateTimeAxis>
#include <QtCharts/QValueAxis>
#include <QComboBox>
#include <QLabel>

QT_BEGIN_NAMESPACE
namespace Ui {
class WizualizacjaPogody;
}
QT_END_NAMESPACE

/*!
 * \class WizualizacjaPogody
 * \brief Główna klasa aplikacji do wizualizacji pogody.
 *
 * Klasa odpowiedzialna za wyświetlanie interfejsu użytkownika
 * oraz aktualizację danych pogodowych i wykresów.
 */
class WizualizacjaPogody : public QMainWindow
{
    Q_OBJECT

public:
    /*!
     * \brief Konstruktor.
     * \param parent Wskaźnik na obiekt nadrzędny.
     */
    explicit WizualizacjaPogody(QWidget *parent = nullptr);

    /*!
     * \brief Destruktor.
     */
    ~WizualizacjaPogody();

    /*!
     * \brief Aktualizuje wykres temperatury.
     * \param temperatures Tablica temperatur. [°C]
     * \param timeArray Tablica czasów. [yyyy-MM-ddTHH:mm]
     */
    void updateTempChart(const QJsonArray &temperatures, const QJsonArray &timeArray);

    /*!
     * \brief Aktualizuje wykres opadów.
     * \param rains Tablica opadów. [mm]
     * \param timeArray Tablica czasów. [yyyy-MM-ddTHH:mm]
     */
    void updateRainChart(const QJsonArray &rains, const QJsonArray &timeArray);

    /*!
     * \brief Aktualizuje wykres ciśnienia.
     * \param pressS Tablica ciśnień. [hPa]
     * \param timeArray Tablica czasów. [yyyy-MM-ddTHH:mm]
     */
    void updatePressChart(const QJsonArray &pressS, const QJsonArray &timeArray);

    /*!
     * \brief Aktualizuje wykres prędkości wiatru.
     * \param winds Tablica prędkości wiatru. [km/h]
     * \param timeArray Tablica czasów.[yyyy-MM-ddTHH:mm]
     */
    void updateWindChart(const QJsonArray &winds, const QJsonArray &timeArray);

protected:
    /*!
     * \brief Przesłonięta metoda do obsługi zdarzenia zmiany rozmiaru okna.
     * \param event Zdarzenie zmiany rozmiaru.
     */
    void resizeEvent(QResizeEvent *event) override;

public slots:
    /*!
     * \brief Slot do aktualizacji temperatury w interfejsie aplikacji.
     * \param temperature Aktualna temperatura. [°C]
     * \param city Nazwa miasta, dla którego pobrano dane.
     */
    void updateTemperature(double temperature, const QString &city);

    /*!
     * \brief Slot do aktualizacji wykresów dla danego miasta.
     * \param temperatures Tablica temperatur. [°C]
     * \param timeArray Tablica czasów. [yyyy-MM-ddTHH:mm]
     * \param rainArray Tablica opadów. [mm]
     * \param pressArray Tablica ciśnień. [hPa]
     * \param windArray Tablica prędkości wiatru. [km/h]
     * \param city Nazwa miasta, dla którego pobrano dane.
     */
    void updateCharts(const QJsonArray &temperatures, const QJsonArray &timeArray,
                      const QJsonArray &rainArray, const QJsonArray &pressArray,
                      const QJsonArray &windArray, const QString &city);

    /*!
     * \brief Slot do zmiany wybranego miasta w interfejsie aplikacji.
     * \param index Indeks wybranego miasta.
     */
    void CityChanged(int index);

    /*!
     * \brief Slot do zmiany języka aplikacji.
     * \param index Indeks wybranego języka.
     */
    void languageChanged(int index);

private:
    Ui::WizualizacjaPogody *ui; /*!< Wskaźnik na interfejs użytkownika. */
    WeatherData weatherData; /*!< Obiekt WeatherData do pobierania danych pogodowych. */
    QChartView *TempChart, *RainChart, *PressChart, *WindChart; /*!< Widoki wykresów temperatury, opadów, ciśnienia i wiatru. */
    QComboBox *cityComboBox; /*!< ComboBox z listą miast. */
    QComboBox *zmianaJezyka; /*!< ComboBox do zmiany języka. */
    QVector<QJsonArray> temperaturesArray, timesArray, rainsArray, pressuresArray, windsArray; /*!< Tablice danych do wykresów dla różnych miast. */

    /*!
     * \brief Metoda do skalowania widoku wykresu.
     * \param chartView Widok wykresu do skalowania.
     */
    void scaleChart(QChartView *chartView);

    /*!
     * \brief Metoda do aktualizacji rozmiaru czcionki etykiety.
     * \param Etykieta do aktualizacji.
     */
    void updateFontSize(QLabel *label);
};

#endif // WIZUALIZACJAPOGODY_H
