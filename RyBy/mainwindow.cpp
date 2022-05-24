#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);




    //QPixmap background("/home/hubert/Pobrane/fishing3.png");
    //background = background.scaled(this->size(), Qt::IgnoreAspectRatio);
    //QPalette palette;
    //palette.setBrush(QPalette::Background, background);
    //this->setPalette(palette);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_PlayButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_SettingsButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);

}

void MainWindow::on_GameToMenuButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);

}

void MainWindow::on_SettingsToMenuButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);


}

void MainWindow::on_ExitButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);

}

void MainWindow::on_BrightnessSlider_valueChanged(int value)
{
    this->sounD = ui->BrightnessSlider->value();
    QString temp = QString::number(sounD);
    ui->SoundLabel->setText(temp);

}
