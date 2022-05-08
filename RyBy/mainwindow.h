#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
    void on_PlayButton_clicked();

    void on_SettingsButton_clicked();

    void on_ExitButton_clicked();

    void on_SettingsToMenuButton_clicked();

    void on_GameToMenuButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
