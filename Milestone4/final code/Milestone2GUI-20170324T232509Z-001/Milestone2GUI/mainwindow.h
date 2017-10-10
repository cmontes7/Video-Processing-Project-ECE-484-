#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <iostream>
#include <cmath>
#include "image.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_inputOriginal_clicked();

    void on_inputOverlay_clicked();

    void on_contrastSlider_valueChanged(int value);

    void on_brightnessSlider_valueChanged(int value);

    void on_saveHistoImage_clicked();

    void on_saveOverlaidImage_clicked();

    void on_saveContrastImage_clicked();

    void on_saveBrightnessImage_clicked();

private:
    Ui::MainWindow *ui;
    QString originalFilename;
    Image original;
    int minLevelOrigImage;
    int maxLevelOrigImage;
    int previousValue;

    QImage imageOverlaid;
    QImage histogramEqualized;
    QImage imageEdits;
    QImage imageBrightness;
};

#endif // MAINWINDOW_H
