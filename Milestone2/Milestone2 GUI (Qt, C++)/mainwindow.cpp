#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_inputOriginal_clicked()
{
    originalFilename = QFileDialog::getOpenFileName(this, tr("Choose"), "", tr("Images (*.bmp)"));

     if(QString::compare(originalFilename, QString()) != 0)
     {
         QImage image;
         bool valid = image.load(originalFilename);

         if(valid)
         {
             image = image.scaledToWidth(ui->displayOriginal->width(), Qt::SmoothTransformation);
             ui->displayOriginal->setPixmap(QPixmap::fromImage(image));

             imageEdits.load(originalFilename);
             imageEdits = imageEdits.scaledToWidth(ui->displayEdits->width(), Qt::SmoothTransformation);
             ui->displayEdits->setPixmap(QPixmap::fromImage(imageEdits));

             imageBrightness.load(originalFilename);
             imageBrightness = imageBrightness.scaledToWidth(ui->displayBrightness->width(), Qt::SmoothTransformation);
             ui->displayBrightness->setPixmap(QPixmap::fromImage(imageBrightness));

             // Convert QString to Char array for input to the readBM() function
             QByteArray ba = originalFilename.toLatin1();
             char *ca = ba.data();
             original.readBM(ca);

             original.histogramEqualization();
             histogramEqualized.load("out2.bmp");
             histogramEqualized = histogramEqualized.scaledToWidth(ui->displayHisto->width(), Qt::SmoothTransformation);
             ui->displayHisto->setPixmap(QPixmap::fromImage(histogramEqualized));

             original.calculateMinMax();
             minLevelOrigImage = original.getMinLevel();
             maxLevelOrigImage = original.getMaxLevel();
             cout << "Min: " << minLevelOrigImage << " Max: " << maxLevelOrigImage << endl;
         }
         else
         {
             // Error handling
         }
         previousValue = -1;
     }
}

void MainWindow::on_inputOverlay_clicked()
{
    QString overlayFilename = QFileDialog::getOpenFileName(this, tr("Choose"), "", tr("Images (*.bmp)"));

     if(QString::compare(overlayFilename, QString()) != 0)
     {
         QImage imageOriginal;
         QImage imageOverlay;
         imageOverlaid;

         bool originalValid = imageOriginal.load(originalFilename);
         bool overlayValid = imageOverlay.load(overlayFilename);

         if(originalValid && overlayValid)
         {
             imageOverlay = imageOverlay.scaledToWidth(ui->displaySubtitle->width(), Qt::SmoothTransformation);
             ui->displaySubtitle->setPixmap(QPixmap::fromImage(imageOverlay));

             // Convert QString to Char array for input to the readBM() function
             QByteArray ba = overlayFilename.toLatin1();
             char *ca = ba.data();
             original.overlay(ca);

             imageOverlaid.load("out1.bmp");
             imageOverlaid = imageOverlaid.scaledToWidth(ui->displayOverlay->width(), Qt::SmoothTransformation);
             ui->displayOverlay->setPixmap(QPixmap::fromImage(imageOverlaid));
         }
         else
         {
             // Error handling
         }
     }
}

void MainWindow::on_contrastSlider_valueChanged(int value)
{
    ui->contrastSlider->setDisabled(true);

    imageEdits.load(originalFilename);

    int newPixelValue = 0;

    int newMinLevel = 0;
    int newMaxLevel = 0;

    cout << "Slider value: " << value << endl;

    /*int difference;

    if ((maxLevelOrigImage - minLevelOrigImage) > 250)
        difference = 1;
    else
         difference = (maxLevelOrigImage - minLevelOrigImage)/50;

    int change = value * difference;
*/

    if( minLevelOrigImage == 0 && previousValue == -1 )
        newMinLevel = 50;
    else if( (newMinLevel + (value - 50) <= 50) && (previousValue < value) )
        newMinLevel = newMinLevel--;
    else if( (newMinLevel + (value - 50) <= 50) && (previousValue > value) )
        newMinLevel = newMinLevel++;
    else
        newMinLevel = minLevelOrigImage + (value - 50);

    if( maxLevelOrigImage >= 205 && previousValue == -1 )
        newMaxLevel = 205;
    else if( (newMaxLevel + (value - 50) >= 205) && (previousValue < value) )
        newMaxLevel = newMaxLevel++;
    else if( (newMaxLevel + (value - 50) >= 205) && (previousValue > value) )
        newMaxLevel = newMaxLevel--;
    else
        newMaxLevel = maxLevelOrigImage + (value - 50);

    previousValue = value;

    for( int i=0; i<imageEdits.width(); i++ )
    {
        for ( int j=0; j<imageEdits.height(); j++ )
        {
            //newPixelValue = round(change + (2*change + difference) * ((imageEdits.pixel(i, j) & 0xff) - minLevelOrigImage)/(maxLevelOrigImage - minLevelOrigImage));

            newPixelValue = round((newMinLevel) + (newMaxLevel - newMinLevel) * ((imageEdits.pixel(i, j) & 0xff) - minLevelOrigImage)/(maxLevelOrigImage - minLevelOrigImage));
            if (newPixelValue > 255)
            {
                newPixelValue = 255;
            }
            else if(newPixelValue < 0)
            {
                newPixelValue = 0;
            }
            imageEdits.setPixel(i, j, newPixelValue);
        }
    }

    imageEdits = imageEdits.scaledToWidth(ui->displayEdits->width(), Qt::SmoothTransformation);
    ui->displayEdits->setPixmap(QPixmap::fromImage(imageEdits));

    ui->contrastSlider->setDisabled(false);
}

void MainWindow::on_brightnessSlider_valueChanged(int value)
{
    ui->brightnessSlider->setDisabled(true);

    imageBrightness.load(originalFilename);

    int newPixelValue = 0;

    cout << "Slider value: " << value << endl;
    int difference;

    if ((maxLevelOrigImage - minLevelOrigImage) > 250)
        difference = 1;
    else
         difference = (maxLevelOrigImage - minLevelOrigImage)/50;

    int change = value * difference;

    for( int i=0; i<imageBrightness.width(); i++ )
    {
        for ( int j=0; j<imageBrightness.height(); j++ )
        {
            newPixelValue = (imageBrightness.pixel(i, j) & 0xff) + change;
            if (newPixelValue > 255)
            {
                newPixelValue = 255;
            }
            else if(newPixelValue < 0)
            {
                newPixelValue = 0;
            }
            imageBrightness.setPixel(i, j, newPixelValue);
        }
    }

    imageBrightness = imageBrightness.scaledToWidth(ui->displayBrightness->width(), Qt::SmoothTransformation);
    ui->displayBrightness->setPixmap(QPixmap::fromImage(imageBrightness));

    ui->brightnessSlider->setDisabled(false);
}

void MainWindow::on_saveHistoImage_clicked()
{
    bool savedFile = histogramEqualized.save("HistogramEqualizedImage.bmp", 0, 100);
    //cout << "Saved File? " << savedFile << endl;
}

void MainWindow::on_saveOverlaidImage_clicked()
{
    bool savedFile = imageOverlaid.save("OverlaidImage.bmp", 0, 100);
    //cout << "Saved File? " << savedFile << endl;
}

void MainWindow::on_saveContrastImage_clicked()
{
    bool savedFile = imageEdits.save("ContrastEditsImage.bmp", 0, 100);
    //cout << "Saved File? " << savedFile << endl;
}

void MainWindow::on_saveBrightnessImage_clicked()
{
    bool savedFile = imageBrightness.save("BrightnessEditsImage.bmp", 0, 100);
    //cout << "Saved File? " << savedFile << endl;
}
