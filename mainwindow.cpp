#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <QtNetwork>
#include <QtGui>
#include <QtCore>

#include <QTableWidget>
#include <QVBoxLayout>



int WhichCity = 0;


WizualizacjaPogody::WizualizacjaPogody(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::WizualizacjaPogody)
{
    ui->setupUi(this);

    // Dodanie obrazku mapy
    QPixmap mapa(":/images/mapa.jpg");

    // Użycie QLabel do wyświetlania obrazu
    ui->mapa->setPixmap(mapa);
    TempChart = ui->TempChart;
    WindChart = ui->WindChart;
    PressChart = ui->PressChart;
    RainChart = ui->RainChart;
    cityComboBox = ui->cityComboBox;

    // Ukrywanie i pokazywanie elementów
    ui->WroclawTemp->hide();
    ui->WroclawTemp->setHidden(0);


    // Dodanie miast do comboboxa
    cityComboBox->addItem("Wroclaw");
    cityComboBox->addItem("Warszawa");
    cityComboBox->addItem("Szczecin");
    cityComboBox->addItem("Gdansk");
    cityComboBox->addItem("Rzeszow");

    zmianaJezyka = ui->zmianaJezyka;


    zmianaJezyka->addItem("PL");
    zmianaJezyka->addItem("ENG");

    connect(ui->zmianaJezyka, SIGNAL(currentIndexChanged(int)), this, SLOT(languageChanged(int)));

    languageChanged(0);

    // Inicjalizacja tablic danych dla miast
    int numCities = cityComboBox->count();
    temperaturesArray.resize(numCities);
    timesArray.resize(numCities);
    rainsArray.resize(numCities);
    pressuresArray.resize(numCities);
    windsArray.resize(numCities);

    // Połączenie sygnału zmiany miasta z odpowiednim slotem
    connect(cityComboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(CityChanged(int)));

    // Dodanie elementów do layoutu głównego
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(ui->mapa);
    mainLayout->addWidget(ui->TempChart);
    mainLayout->addWidget(ui->WindChart);
    mainLayout->addWidget(ui->PressChart);
    mainLayout->addWidget(ui->RainChart);
    mainLayout->addWidget(ui->cityComboBox);

    mainLayout->setContentsMargins(0, 0, 0, 0);
    mainLayout->setSpacing(0);

    ui->centralwidget->setLayout(mainLayout); //odpal resize ve

}

void WizualizacjaPogody::languageChanged(int index)
{
    QString language = ui->zmianaJezyka->itemText(index);

    if (language == "PL")
    {
        // Zmiana tekstu dla labeli na polski
        ui->napiswykres->setText("Zmiany pogodowe w");
        ui->napismapa->setText("Aktualna pogoda w Polsce");
    }
    else if (language == "ENG")
    {
        // Zmiana tekstu dla labeli na angielski
        ui->napiswykres->setText("Weather changes in");
        ui->napismapa->setText("Current weather in Poland");
    }
}

void WizualizacjaPogody::resizeEvent(QResizeEvent *event)
{
    QMainWindow::resizeEvent(event);
    qDebug() << "resizeEvent called";


    // Skalowanie wykresów
    scaleChart(ui->TempChart);
    scaleChart(ui->WindChart);
    scaleChart(ui->PressChart);
    scaleChart(ui->RainChart);
    updateFontSize(ui->napiswykres);
}

void WizualizacjaPogody::scaleChart(QChartView *chartView)
{
    QChart *chart = chartView->chart();
    QSize newSize = chartView->parentWidget()->size();
    chart->resize(newSize);
    chart->update();
}

void WizualizacjaPogody::updateFontSize(QLabel *label){

    QWidget *parentWidget = label->parentWidget();

    int parentWidth = parentWidget->width();
    int parentHeight = parentWidget->height();


    // Określenie nowego rozmiaru czcionki
    int newFontSize = qMin(parentWidth / 12, parentHeight / 2);

    qDebug() << "Parent Width:" << parentWidth;
    qDebug() << "Parent Height:" << parentHeight;


    QFont font = label->font();
    font.setPointSize(newFontSize);
    label->setFont(font);
}

void WizualizacjaPogody::updateTemperature(double temperature, const QString &city)
{
    // Znajdź obiekt QLabel w interfejsie użytkownika, który będzie wyświetlał temperaturę

    QString labelName = city + "Temp";

    QLabel *cityTempLabel = findChild<QLabel*>(labelName);
    if (!cityTempLabel) {
        qDebug() << "Nie udało się znaleźć QLabel o nazwie" << labelName << "!";
        return;
    }

    qDebug() << "Odebrano sygnał temperatureReady z wartością:" << temperature;

    // Sprawdź, czy obiekt QLabel został znaleziony
    if (cityTempLabel) {
        // Ustaw tekst w QLabel, wyświetlając temperaturę
        cityTempLabel->setText(QString("%1°C").arg(temperature));
        cityTempLabel->update();
    }
}

void WizualizacjaPogody::updateCharts(const QJsonArray &temperatures, const QJsonArray &timeArray, const QJsonArray &rainArray, const QJsonArray &pressArray, const QJsonArray &windArray, const QString &city){

    int cityIndex = cityComboBox->findText(city);

    if (cityIndex != -1) {
        temperaturesArray[cityIndex] = temperatures;
        timesArray[cityIndex] = timeArray;
        rainsArray[cityIndex] = rainArray;
        pressuresArray[cityIndex] = pressArray;
        windsArray[cityIndex] = windArray;
    }

    updateTempChart(temperatures, timeArray);
    updateRainChart(rainArray, timeArray);
    updateWindChart(windArray, timeArray);
    updatePressChart(pressArray, timeArray);
}

void WizualizacjaPogody::CityChanged(int index)
{
    QString city = cityComboBox->itemText(index);
    qDebug() << "Wybrano miasto:" << city;

    // Update the charts based on the selected city
    updateCharts(temperaturesArray[index], timesArray[index], rainsArray[index], pressuresArray[index], windsArray[index], city);

    resizeEvent(nullptr);
}

void WizualizacjaPogody::updateTempChart(const QJsonArray &temperatures, const QJsonArray &timeArray){

    QLineSeries *series = new QLineSeries();

    for (int i = 0; i < temperatures.size(); ++i) {
        QDateTime dateTime = QDateTime::fromString(timeArray[i].toString(), Qt::ISODate);
        double temperature = temperatures[i].toDouble();
        series->append(dateTime.toMSecsSinceEpoch(), temperature);
    }

    QChart *chart = new QChart();
    chart->legend()->hide();
    chart->addSeries(series);
    chart->setTitle("Zmiany temperaturowe");


    // Ustawienia osi X (czas)
    QDateTime minDateTime = QDateTime::fromString(timeArray.first().toString(), Qt::ISODate);
    QDateTime maxDateTime = QDateTime::fromString(timeArray.last().toString(), Qt::ISODate);
    QDateTimeAxis *axisX = new QDateTimeAxis;
    axisX->setTickCount(8);
    axisX->setFormat("MM-dd hh:mm");
    axisX->setTitleText("Data");
    axisX->setRange(minDateTime, maxDateTime);
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    // Ustawienia osi Y (temperatura)
    double minTemperature = std::numeric_limits<double>::max();
    double maxTemperature = std::numeric_limits<double>::min();
    for (const QJsonValue &value : temperatures) {
        double temperature = value.toDouble();
        minTemperature = qMin(minTemperature, temperature);
        maxTemperature = qMax(maxTemperature, temperature);
    }
    QValueAxis *axisY = new QValueAxis;
    axisY->setLabelFormat("%.1f");
    axisY->setTitleText("Temperatura (°C)");
    axisY->setRange(minTemperature - 1, maxTemperature + 1); // Rozszerz zakres o 1 stopień w obu kierunkach
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    // Tworzenie widoku wykresu
    TempChart->setChart(chart);
    QSize newSize = TempChart->parentWidget()->size();
    chart->resize(newSize);
    TempChart->update();
}


void WizualizacjaPogody::updateWindChart(const QJsonArray &winds, const QJsonArray &timeArray){

    QLineSeries *series = new QLineSeries();

    for (int i = 0; i < winds.size(); ++i) {
        QDateTime dateTime = QDateTime::fromString(timeArray[i].toString(), Qt::ISODate);
        double wind = winds[i].toDouble();
        series->append(dateTime.toMSecsSinceEpoch(), wind);
    }

    QChart *chart = new QChart();
    chart->legend()->hide();
    chart->addSeries(series);
    chart->setTitle("Zmiany prędkości wiatru");


    // Ustawienia osi X (czas)
    QDateTime minDateTime = QDateTime::fromString(timeArray.first().toString(), Qt::ISODate);
    QDateTime maxDateTime = QDateTime::fromString(timeArray.last().toString(), Qt::ISODate);
    QDateTimeAxis *axisX = new QDateTimeAxis;
    axisX->setTickCount(8);
    axisX->setFormat("MM-dd hh:mm");
    axisX->setTitleText("Data");
    axisX->setRange(minDateTime, maxDateTime);
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    // Ustawienia osi Y (temperatura)
    double minTemperature = std::numeric_limits<double>::max();
    double maxTemperature = std::numeric_limits<double>::min();
    for (const QJsonValue &value : winds) {
        double temperature = value.toDouble();
        minTemperature = qMin(minTemperature, temperature);
        maxTemperature = qMax(maxTemperature, temperature);
    }
    QValueAxis *axisY = new QValueAxis;
    axisY->setLabelFormat("%.1f");
    axisY->setTitleText("wiatr (km/h)");
    axisY->setRange(0, maxTemperature + 1); // Rozszerz zakres o 1 stopień w obu kierunkach
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    // Tworzenie widoku wykresu
    WindChart->setChart(chart);
    QSize newSize = WindChart->parentWidget()->size();
    chart->resize(newSize);
    WindChart->update();
}


void WizualizacjaPogody::updatePressChart(const QJsonArray &pressS, const QJsonArray &timeArray){

    QLineSeries *series = new QLineSeries();

    for (int i = 0; i < pressS.size(); ++i) {
        QDateTime dateTime = QDateTime::fromString(timeArray[i].toString(), Qt::ISODate);
        double press = pressS[i].toDouble();
        series->append(dateTime.toMSecsSinceEpoch(), press);
    }

    QChart *chart = new QChart();
    chart->legend()->hide();
    chart->addSeries(series);
    chart->setTitle("Zmiany ciśnienia");


    // Ustawienia osi X (czas)
    QDateTime minDateTime = QDateTime::fromString(timeArray.first().toString(), Qt::ISODate);
    QDateTime maxDateTime = QDateTime::fromString(timeArray.last().toString(), Qt::ISODate);
    QDateTimeAxis *axisX = new QDateTimeAxis;
    axisX->setTickCount(8);
    axisX->setFormat("MM-dd hh:mm");
    axisX->setTitleText("Data");
    axisX->setRange(minDateTime, maxDateTime);
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    // Ustawienia osi Y (temperatura)
    double minTemperature = std::numeric_limits<double>::max();
    double maxTemperature = std::numeric_limits<double>::min();
    for (const QJsonValue &value : pressS) {
        double temperature = value.toDouble();
        minTemperature = qMin(minTemperature, temperature);
        maxTemperature = qMax(maxTemperature, temperature);
    }
    QValueAxis *axisY = new QValueAxis;
    axisY->setLabelFormat("%.1f");
    axisY->setTitleText("Ciśnienie (hPa)");
    axisY->setRange(minTemperature - 1, maxTemperature + 1); // Rozszerz zakres o 1 stopień w obu kierunkach
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    // Tworzenie widoku wykresu
    PressChart->setChart(chart);
    QSize newSize = PressChart->parentWidget()->size();
    chart->resize(newSize);
    PressChart->update();
}


void WizualizacjaPogody::updateRainChart(const QJsonArray &rains, const QJsonArray &timeArray){

    QLineSeries *series = new QLineSeries();

    for (int i = 0; i < rains.size(); ++i) {
        QDateTime dateTime = QDateTime::fromString(timeArray[i].toString(), Qt::ISODate);
        double rain = rains[i].toDouble();
        series->append(dateTime.toMSecsSinceEpoch(), rain);
    }

    QChart *chart = new QChart();
    chart->legend()->hide();
    chart->addSeries(series);
    chart->setTitle("Zmiany ilości opadów");


    // Ustawienia osi X (czas)
    QDateTime minDateTime = QDateTime::fromString(timeArray.first().toString(), Qt::ISODate);
    QDateTime maxDateTime = QDateTime::fromString(timeArray.last().toString(), Qt::ISODate);
    QDateTimeAxis *axisX = new QDateTimeAxis;
    axisX->setTickCount(8);
    axisX->setFormat("MM-dd hh:mm");
    axisX->setTitleText("Data");
    axisX->setRange(minDateTime, maxDateTime);
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    // Ustawienia osi Y (temperatura)
    double minTemperature = std::numeric_limits<double>::max();
    double maxTemperature = std::numeric_limits<double>::min();
    for (const QJsonValue &value : rains) {
        double temperature = value.toDouble();
        minTemperature = qMin(minTemperature, temperature);
        maxTemperature = qMax(maxTemperature, temperature);
    }
    QValueAxis *axisY = new QValueAxis;
    axisY->setLabelFormat("%.1f");
    axisY->setTitleText("Opady (mm)");
    axisY->setRange(0, maxTemperature + 1); // Rozszerz zakres o 1 stopień w obu kierunkach
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    // Tworzenie widoku wykresu
    RainChart->setChart(chart);
    QSize newSize = RainChart->parentWidget()->size();
    chart->resize(newSize);
    RainChart->update();
}




WizualizacjaPogody::~WizualizacjaPogody()
{
    delete ui;
}
