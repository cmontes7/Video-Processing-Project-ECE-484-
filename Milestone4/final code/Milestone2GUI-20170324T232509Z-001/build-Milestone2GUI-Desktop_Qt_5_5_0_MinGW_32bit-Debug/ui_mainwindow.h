/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *displayOriginal;
    QPushButton *inputOriginal;
    QPushButton *inputOverlay;
    QLabel *displayOverlay;
    QSlider *contrastSlider;
    QLabel *displayEdits;
    QSlider *brightnessSlider;
    QLabel *displayHisto;
    QLabel *displaySubtitle;
    QLabel *displayBrightness;
    QPushButton *saveHistoImage;
    QPushButton *saveOverlaidImage;
    QPushButton *saveContrastImage;
    QPushButton *saveBrightnessImage;
    QPushButton *textEditContrast;
    QPushButton *textEditBrightness;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1040, 683);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        displayOriginal = new QLabel(centralWidget);
        displayOriginal->setObjectName(QStringLiteral("displayOriginal"));
        displayOriginal->setGeometry(QRect(10, 20, 231, 191));
        inputOriginal = new QPushButton(centralWidget);
        inputOriginal->setObjectName(QStringLiteral("inputOriginal"));
        inputOriginal->setGeometry(QRect(10, 250, 161, 23));
        inputOverlay = new QPushButton(centralWidget);
        inputOverlay->setObjectName(QStringLiteral("inputOverlay"));
        inputOverlay->setGeometry(QRect(280, 250, 171, 23));
        displayOverlay = new QLabel(centralWidget);
        displayOverlay->setObjectName(QStringLiteral("displayOverlay"));
        displayOverlay->setGeometry(QRect(270, 320, 231, 191));
        contrastSlider = new QSlider(centralWidget);
        contrastSlider->setObjectName(QStringLiteral("contrastSlider"));
        contrastSlider->setGeometry(QRect(840, 100, 160, 22));
        contrastSlider->setContextMenuPolicy(Qt::ActionsContextMenu);
        contrastSlider->setSliderPosition(50);
        contrastSlider->setOrientation(Qt::Horizontal);
        displayEdits = new QLabel(centralWidget);
        displayEdits->setObjectName(QStringLiteral("displayEdits"));
        displayEdits->setGeometry(QRect(550, 20, 231, 191));
        brightnessSlider = new QSlider(centralWidget);
        brightnessSlider->setObjectName(QStringLiteral("brightnessSlider"));
        brightnessSlider->setGeometry(QRect(840, 420, 160, 22));
        brightnessSlider->setValue(50);
        brightnessSlider->setOrientation(Qt::Horizontal);
        displayHisto = new QLabel(centralWidget);
        displayHisto->setObjectName(QStringLiteral("displayHisto"));
        displayHisto->setGeometry(QRect(10, 320, 231, 191));
        displaySubtitle = new QLabel(centralWidget);
        displaySubtitle->setObjectName(QStringLiteral("displaySubtitle"));
        displaySubtitle->setGeometry(QRect(280, 20, 231, 191));
        displayBrightness = new QLabel(centralWidget);
        displayBrightness->setObjectName(QStringLiteral("displayBrightness"));
        displayBrightness->setGeometry(QRect(550, 320, 231, 191));
        saveHistoImage = new QPushButton(centralWidget);
        saveHistoImage->setObjectName(QStringLiteral("saveHistoImage"));
        saveHistoImage->setGeometry(QRect(10, 530, 221, 23));
        saveOverlaidImage = new QPushButton(centralWidget);
        saveOverlaidImage->setObjectName(QStringLiteral("saveOverlaidImage"));
        saveOverlaidImage->setGeometry(QRect(270, 530, 211, 23));
        saveContrastImage = new QPushButton(centralWidget);
        saveContrastImage->setObjectName(QStringLiteral("saveContrastImage"));
        saveContrastImage->setGeometry(QRect(580, 250, 191, 23));
        saveBrightnessImage = new QPushButton(centralWidget);
        saveBrightnessImage->setObjectName(QStringLiteral("saveBrightnessImage"));
        saveBrightnessImage->setGeometry(QRect(580, 530, 221, 23));
        textEditContrast = new QPushButton(centralWidget);
        textEditContrast->setObjectName(QStringLiteral("textEditContrast"));
        textEditContrast->setGeometry(QRect(880, 130, 75, 23));
        textEditBrightness = new QPushButton(centralWidget);
        textEditBrightness->setObjectName(QStringLiteral("textEditBrightness"));
        textEditBrightness->setGeometry(QRect(890, 460, 75, 23));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1040, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        displayOriginal->setText(QString());
        inputOriginal->setText(QApplication::translate("MainWindow", "Choose an Image", 0));
        inputOverlay->setText(QApplication::translate("MainWindow", "Choose an Overlay Image", 0));
        displayOverlay->setText(QString());
        displayEdits->setText(QString());
        displayHisto->setText(QString());
        displaySubtitle->setText(QString());
        displayBrightness->setText(QString());
        saveHistoImage->setText(QApplication::translate("MainWindow", "Save Histogram Equalized Image", 0));
        saveOverlaidImage->setText(QApplication::translate("MainWindow", "Save Overlaid Image", 0));
        saveContrastImage->setText(QApplication::translate("MainWindow", "Save Contrast Changes", 0));
        saveBrightnessImage->setText(QApplication::translate("MainWindow", "Save Brightness Changes", 0));
        textEditContrast->setText(QApplication::translate("MainWindow", "Contrast", 0));
        textEditBrightness->setText(QApplication::translate("MainWindow", "Brightness", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
