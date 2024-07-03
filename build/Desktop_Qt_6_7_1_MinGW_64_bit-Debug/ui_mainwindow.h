/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCharts/QChartView>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WizualizacjaPogody
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QFrame *frame;
    QComboBox *cityComboBox;
    QFrame *frameChart1;
    QChartView *TempChart;
    QFrame *frameChart4;
    QChartView *RainChart;
    QFrame *frameChart2;
    QChartView *PressChart;
    QFrame *frameNapis;
    QLabel *napismapa;
    QFrame *frameChart3;
    QChartView *WindChart;
    QFrame *frameComboBox;
    QLabel *napiswykres;
    QFrame *frame_2;
    QFrame *frameMapa;
    QLabel *kropkaWroclaw;
    QLabel *napisWroclaw;
    QLabel *WroclawTemp;
    QLabel *napisSzczecin;
    QLabel *SzczecinTemp;
    QLabel *kropkaSzczecin;
    QLabel *kropkaGdansk;
    QLabel *napisGdansk;
    QLabel *GdanskTemp;
    QLabel *napisWarszawa;
    QLabel *WarszawaTemp;
    QLabel *kropkaWarszawa;
    QLabel *napisRzeszow;
    QLabel *RzeszowTemp;
    QLabel *kropkaRzeszow;
    QLabel *mapa;
    QComboBox *zmianaJezyka;

    void setupUi(QMainWindow *WizualizacjaPogody)
    {
        if (WizualizacjaPogody->objectName().isEmpty())
            WizualizacjaPogody->setObjectName("WizualizacjaPogody");
        WizualizacjaPogody->resize(1242, 724);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(WizualizacjaPogody->sizePolicy().hasHeightForWidth());
        WizualizacjaPogody->setSizePolicy(sizePolicy);
        WizualizacjaPogody->setMinimumSize(QSize(0, 0));
        QFont font;
        font.setPointSize(20);
        WizualizacjaPogody->setFont(font);
        WizualizacjaPogody->setAutoFillBackground(false);
        centralwidget = new QWidget(WizualizacjaPogody);
        centralwidget->setObjectName("centralwidget");
        sizePolicy.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        frame = new QFrame(centralwidget);
        frame->setObjectName("frame");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::MinimumExpanding, QSizePolicy::Policy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy1);
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        cityComboBox = new QComboBox(frame);
        cityComboBox->setObjectName("cityComboBox");
        cityComboBox->setGeometry(QRect(0, 0, 151, 50));
        QSizePolicy sizePolicy2(QSizePolicy::Policy::MinimumExpanding, QSizePolicy::Policy::MinimumExpanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(cityComboBox->sizePolicy().hasHeightForWidth());
        cityComboBox->setSizePolicy(sizePolicy2);
        cityComboBox->setMinimumSize(QSize(50, 0));
        cityComboBox->setLayoutDirection(Qt::LeftToRight);
        cityComboBox->setAutoFillBackground(true);

        gridLayout->addWidget(frame, 0, 2, 1, 1);

        frameChart1 = new QFrame(centralwidget);
        frameChart1->setObjectName("frameChart1");
        sizePolicy.setHeightForWidth(frameChart1->sizePolicy().hasHeightForWidth());
        frameChart1->setSizePolicy(sizePolicy);
        frameChart1->setMinimumSize(QSize(250, 100));
        frameChart1->setFrameShape(QFrame::StyledPanel);
        frameChart1->setFrameShadow(QFrame::Raised);
        TempChart = new QChartView(frameChart1);
        TempChart->setObjectName("TempChart");
        TempChart->setGeometry(QRect(0, 9, 1621, 801));
        QSizePolicy sizePolicy3(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(TempChart->sizePolicy().hasHeightForWidth());
        TempChart->setSizePolicy(sizePolicy3);
        TempChart->setMinimumSize(QSize(250, 100));

        gridLayout->addWidget(frameChart1, 2, 1, 1, 2);

        frameChart4 = new QFrame(centralwidget);
        frameChart4->setObjectName("frameChart4");
        sizePolicy.setHeightForWidth(frameChart4->sizePolicy().hasHeightForWidth());
        frameChart4->setSizePolicy(sizePolicy);
        frameChart4->setMinimumSize(QSize(250, 125));
        frameChart4->setFrameShape(QFrame::StyledPanel);
        frameChart4->setFrameShadow(QFrame::Raised);
        RainChart = new QChartView(frameChart4);
        RainChart->setObjectName("RainChart");
        RainChart->setGeometry(QRect(0, -1, 1481, 661));
        sizePolicy.setHeightForWidth(RainChart->sizePolicy().hasHeightForWidth());
        RainChart->setSizePolicy(sizePolicy);
        RainChart->setMinimumSize(QSize(250, 100));

        gridLayout->addWidget(frameChart4, 4, 1, 1, 2);

        frameChart2 = new QFrame(centralwidget);
        frameChart2->setObjectName("frameChart2");
        sizePolicy.setHeightForWidth(frameChart2->sizePolicy().hasHeightForWidth());
        frameChart2->setSizePolicy(sizePolicy);
        frameChart2->setMinimumSize(QSize(250, 100));
        frameChart2->setFrameShape(QFrame::StyledPanel);
        frameChart2->setFrameShadow(QFrame::Raised);
        PressChart = new QChartView(frameChart2);
        PressChart->setObjectName("PressChart");
        PressChart->setGeometry(QRect(0, 0, 911, 551));
        sizePolicy.setHeightForWidth(PressChart->sizePolicy().hasHeightForWidth());
        PressChart->setSizePolicy(sizePolicy);
        PressChart->setMinimumSize(QSize(250, 100));

        gridLayout->addWidget(frameChart2, 4, 4, 1, 2);

        frameNapis = new QFrame(centralwidget);
        frameNapis->setObjectName("frameNapis");
        QSizePolicy sizePolicy4(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(frameNapis->sizePolicy().hasHeightForWidth());
        frameNapis->setSizePolicy(sizePolicy4);
        frameNapis->setMinimumSize(QSize(250, 50));
        frameNapis->setFrameShape(QFrame::StyledPanel);
        frameNapis->setFrameShadow(QFrame::Raised);
        napismapa = new QLabel(frameNapis);
        napismapa->setObjectName("napismapa");
        napismapa->setGeometry(QRect(0, 0, 571, 51));
        sizePolicy.setHeightForWidth(napismapa->sizePolicy().hasHeightForWidth());
        napismapa->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setPointSize(15);
        napismapa->setFont(font1);
        napismapa->setScaledContents(true);

        gridLayout->addWidget(frameNapis, 0, 4, 1, 1);

        frameChart3 = new QFrame(centralwidget);
        frameChart3->setObjectName("frameChart3");
        sizePolicy.setHeightForWidth(frameChart3->sizePolicy().hasHeightForWidth());
        frameChart3->setSizePolicy(sizePolicy);
        frameChart3->setMinimumSize(QSize(250, 100));
        frameChart3->setFrameShape(QFrame::StyledPanel);
        frameChart3->setFrameShadow(QFrame::Raised);
        WindChart = new QChartView(frameChart3);
        WindChart->setObjectName("WindChart");
        WindChart->setGeometry(QRect(0, 0, 1351, 621));
        sizePolicy.setHeightForWidth(WindChart->sizePolicy().hasHeightForWidth());
        WindChart->setSizePolicy(sizePolicy);
        WindChart->setMinimumSize(QSize(250, 100));

        gridLayout->addWidget(frameChart3, 3, 1, 1, 2);

        frameComboBox = new QFrame(centralwidget);
        frameComboBox->setObjectName("frameComboBox");
        QSizePolicy sizePolicy5(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(frameComboBox->sizePolicy().hasHeightForWidth());
        frameComboBox->setSizePolicy(sizePolicy5);
        frameComboBox->setMinimumSize(QSize(50, 50));
        frameComboBox->setFrameShape(QFrame::StyledPanel);
        frameComboBox->setFrameShadow(QFrame::Raised);
        napiswykres = new QLabel(frameComboBox);
        napiswykres->setObjectName("napiswykres");
        napiswykres->setGeometry(QRect(0, 0, 521, 41));
        sizePolicy4.setHeightForWidth(napiswykres->sizePolicy().hasHeightForWidth());
        napiswykres->setSizePolicy(sizePolicy4);
        napiswykres->setScaledContents(true);

        gridLayout->addWidget(frameComboBox, 0, 1, 1, 1, Qt::AlignTop);

        frame_2 = new QFrame(centralwidget);
        frame_2->setObjectName("frame_2");
        QSizePolicy sizePolicy6(QSizePolicy::Policy::MinimumExpanding, QSizePolicy::Policy::Preferred);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(frame_2->sizePolicy().hasHeightForWidth());
        frame_2->setSizePolicy(sizePolicy6);
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);

        gridLayout->addWidget(frame_2, 0, 5, 1, 1);

        frameMapa = new QFrame(centralwidget);
        frameMapa->setObjectName("frameMapa");
        sizePolicy.setHeightForWidth(frameMapa->sizePolicy().hasHeightForWidth());
        frameMapa->setSizePolicy(sizePolicy);
        frameMapa->setMinimumSize(QSize(250, 250));
        frameMapa->setFrameShape(QFrame::StyledPanel);
        frameMapa->setFrameShadow(QFrame::Raised);
        kropkaWroclaw = new QLabel(frameMapa);
        kropkaWroclaw->setObjectName("kropkaWroclaw");
        kropkaWroclaw->setGeometry(QRect(180, 170, 49, 91));
        sizePolicy.setHeightForWidth(kropkaWroclaw->sizePolicy().hasHeightForWidth());
        kropkaWroclaw->setSizePolicy(sizePolicy);
        QFont font2;
        font2.setPointSize(72);
        kropkaWroclaw->setFont(font2);
        kropkaWroclaw->setScaledContents(true);
        napisWroclaw = new QLabel(frameMapa);
        napisWroclaw->setObjectName("napisWroclaw");
        napisWroclaw->setGeometry(QRect(160, 200, 101, 41));
        sizePolicy.setHeightForWidth(napisWroclaw->sizePolicy().hasHeightForWidth());
        napisWroclaw->setSizePolicy(sizePolicy);
        QFont font3;
        font3.setPointSize(16);
        napisWroclaw->setFont(font3);
        napisWroclaw->setScaledContents(true);
        WroclawTemp = new QLabel(frameMapa);
        WroclawTemp->setObjectName("WroclawTemp");
        WroclawTemp->setGeometry(QRect(200, 230, 51, 41));
        sizePolicy.setHeightForWidth(WroclawTemp->sizePolicy().hasHeightForWidth());
        WroclawTemp->setSizePolicy(sizePolicy);
        QFont font4;
        font4.setPointSize(14);
        WroclawTemp->setFont(font4);
        WroclawTemp->setScaledContents(true);
        napisSzczecin = new QLabel(frameMapa);
        napisSzczecin->setObjectName("napisSzczecin");
        napisSzczecin->setGeometry(QRect(110, 110, 101, 41));
        sizePolicy.setHeightForWidth(napisSzczecin->sizePolicy().hasHeightForWidth());
        napisSzczecin->setSizePolicy(sizePolicy);
        napisSzczecin->setFont(font3);
        napisSzczecin->setScaledContents(true);
        SzczecinTemp = new QLabel(frameMapa);
        SzczecinTemp->setObjectName("SzczecinTemp");
        SzczecinTemp->setGeometry(QRect(120, 140, 51, 31));
        sizePolicy.setHeightForWidth(SzczecinTemp->sizePolicy().hasHeightForWidth());
        SzczecinTemp->setSizePolicy(sizePolicy);
        SzczecinTemp->setFont(font4);
        SzczecinTemp->setScaledContents(true);
        kropkaSzczecin = new QLabel(frameMapa);
        kropkaSzczecin->setObjectName("kropkaSzczecin");
        kropkaSzczecin->setGeometry(QRect(90, 80, 49, 91));
        sizePolicy.setHeightForWidth(kropkaSzczecin->sizePolicy().hasHeightForWidth());
        kropkaSzczecin->setSizePolicy(sizePolicy);
        kropkaSzczecin->setFont(font2);
        kropkaSzczecin->setScaledContents(true);
        kropkaGdansk = new QLabel(frameMapa);
        kropkaGdansk->setObjectName("kropkaGdansk");
        kropkaGdansk->setGeometry(QRect(250, 0, 49, 91));
        sizePolicy.setHeightForWidth(kropkaGdansk->sizePolicy().hasHeightForWidth());
        kropkaGdansk->setSizePolicy(sizePolicy);
        kropkaGdansk->setFont(font2);
        kropkaGdansk->setScaledContents(true);
        napisGdansk = new QLabel(frameMapa);
        napisGdansk->setObjectName("napisGdansk");
        napisGdansk->setGeometry(QRect(180, 60, 101, 41));
        napisGdansk->setFont(font3);
        napisGdansk->setScaledContents(true);
        GdanskTemp = new QLabel(frameMapa);
        GdanskTemp->setObjectName("GdanskTemp");
        GdanskTemp->setGeometry(QRect(250, 90, 51, 31));
        sizePolicy.setHeightForWidth(GdanskTemp->sizePolicy().hasHeightForWidth());
        GdanskTemp->setSizePolicy(sizePolicy);
        GdanskTemp->setFont(font4);
        GdanskTemp->setScaledContents(true);
        napisWarszawa = new QLabel(frameMapa);
        napisWarszawa->setObjectName("napisWarszawa");
        napisWarszawa->setGeometry(QRect(280, 150, 101, 41));
        sizePolicy.setHeightForWidth(napisWarszawa->sizePolicy().hasHeightForWidth());
        napisWarszawa->setSizePolicy(sizePolicy);
        napisWarszawa->setFont(font3);
        napisWarszawa->setScaledContents(true);
        WarszawaTemp = new QLabel(frameMapa);
        WarszawaTemp->setObjectName("WarszawaTemp");
        WarszawaTemp->setGeometry(QRect(310, 190, 51, 31));
        sizePolicy.setHeightForWidth(WarszawaTemp->sizePolicy().hasHeightForWidth());
        WarszawaTemp->setSizePolicy(sizePolicy);
        WarszawaTemp->setFont(font4);
        WarszawaTemp->setScaledContents(true);
        kropkaWarszawa = new QLabel(frameMapa);
        kropkaWarszawa->setObjectName("kropkaWarszawa");
        kropkaWarszawa->setGeometry(QRect(350, 110, 49, 91));
        sizePolicy.setHeightForWidth(kropkaWarszawa->sizePolicy().hasHeightForWidth());
        kropkaWarszawa->setSizePolicy(sizePolicy);
        kropkaWarszawa->setFont(font2);
        kropkaWarszawa->setScaledContents(true);
        napisRzeszow = new QLabel(frameMapa);
        napisRzeszow->setObjectName("napisRzeszow");
        napisRzeszow->setGeometry(QRect(330, 260, 101, 41));
        sizePolicy.setHeightForWidth(napisRzeszow->sizePolicy().hasHeightForWidth());
        napisRzeszow->setSizePolicy(sizePolicy);
        napisRzeszow->setFont(font3);
        napisRzeszow->setScaledContents(true);
        RzeszowTemp = new QLabel(frameMapa);
        RzeszowTemp->setObjectName("RzeszowTemp");
        RzeszowTemp->setGeometry(QRect(350, 300, 61, 31));
        sizePolicy.setHeightForWidth(RzeszowTemp->sizePolicy().hasHeightForWidth());
        RzeszowTemp->setSizePolicy(sizePolicy);
        RzeszowTemp->setFont(font4);
        RzeszowTemp->setScaledContents(true);
        kropkaRzeszow = new QLabel(frameMapa);
        kropkaRzeszow->setObjectName("kropkaRzeszow");
        kropkaRzeszow->setGeometry(QRect(410, 220, 49, 91));
        sizePolicy.setHeightForWidth(kropkaRzeszow->sizePolicy().hasHeightForWidth());
        kropkaRzeszow->setSizePolicy(sizePolicy);
        kropkaRzeszow->setFont(font2);
        kropkaRzeszow->setScaledContents(true);
        mapa = new QLabel(frameMapa);
        mapa->setObjectName("mapa");
        mapa->setGeometry(QRect(0, 0, 591, 441));
        sizePolicy.setHeightForWidth(mapa->sizePolicy().hasHeightForWidth());
        mapa->setSizePolicy(sizePolicy);
        mapa->setMinimumSize(QSize(0, 0));
        mapa->setMaximumSize(QSize(1600, 900));
        mapa->setPixmap(QPixmap(QString::fromUtf8(":/images/mapa.jpg")));
        mapa->setScaledContents(true);
        zmianaJezyka = new QComboBox(frameMapa);
        zmianaJezyka->setObjectName("zmianaJezyka");
        zmianaJezyka->setGeometry(QRect(10, 10, 81, 31));
        mapa->raise();
        kropkaWroclaw->raise();
        napisWroclaw->raise();
        WroclawTemp->raise();
        napisSzczecin->raise();
        SzczecinTemp->raise();
        kropkaSzczecin->raise();
        kropkaGdansk->raise();
        napisGdansk->raise();
        GdanskTemp->raise();
        napisWarszawa->raise();
        WarszawaTemp->raise();
        kropkaWarszawa->raise();
        napisRzeszow->raise();
        RzeszowTemp->raise();
        kropkaRzeszow->raise();
        zmianaJezyka->raise();

        gridLayout->addWidget(frameMapa, 2, 3, 2, 3);

        WizualizacjaPogody->setCentralWidget(centralwidget);

        retranslateUi(WizualizacjaPogody);

        QMetaObject::connectSlotsByName(WizualizacjaPogody);
    } // setupUi

    void retranslateUi(QMainWindow *WizualizacjaPogody)
    {
        WizualizacjaPogody->setWindowTitle(QCoreApplication::translate("WizualizacjaPogody", "WizualizacjaPogody", nullptr));
        napismapa->setText(QCoreApplication::translate("WizualizacjaPogody", "Aktualana Pogoda w Polsce", nullptr));
        napiswykres->setText(QCoreApplication::translate("WizualizacjaPogody", "Zmiany pogodowe w", nullptr));
        kropkaWroclaw->setText(QCoreApplication::translate("WizualizacjaPogody", ".", nullptr));
        napisWroclaw->setText(QCoreApplication::translate("WizualizacjaPogody", "Wroc\305\202aw", nullptr));
        WroclawTemp->setText(QCoreApplication::translate("WizualizacjaPogody", "x *C", nullptr));
        napisSzczecin->setText(QCoreApplication::translate("WizualizacjaPogody", "Szczecin", nullptr));
        SzczecinTemp->setText(QCoreApplication::translate("WizualizacjaPogody", "x *C", nullptr));
        kropkaSzczecin->setText(QCoreApplication::translate("WizualizacjaPogody", ".", nullptr));
        kropkaGdansk->setText(QCoreApplication::translate("WizualizacjaPogody", ".", nullptr));
        napisGdansk->setText(QCoreApplication::translate("WizualizacjaPogody", "Gda\305\204sk", nullptr));
        GdanskTemp->setText(QCoreApplication::translate("WizualizacjaPogody", "x *C", nullptr));
        napisWarszawa->setText(QCoreApplication::translate("WizualizacjaPogody", "Warszawa", nullptr));
        WarszawaTemp->setText(QCoreApplication::translate("WizualizacjaPogody", "x *C", nullptr));
        kropkaWarszawa->setText(QCoreApplication::translate("WizualizacjaPogody", ".", nullptr));
        napisRzeszow->setText(QCoreApplication::translate("WizualizacjaPogody", "Rzesz\303\263w", nullptr));
        RzeszowTemp->setText(QCoreApplication::translate("WizualizacjaPogody", "x *C", nullptr));
        kropkaRzeszow->setText(QCoreApplication::translate("WizualizacjaPogody", ".", nullptr));
        mapa->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class WizualizacjaPogody: public Ui_WizualizacjaPogody {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
