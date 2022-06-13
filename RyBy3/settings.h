#ifndef SETTINGS_H
#define SETTINGS_H

#include <QTabWidget>
#include <QGridLayout>
#include <QSlider>
#include <QPushButton>
#include <QCheckBox>
#include <QString>
#include <QLabel>
#include <QMediaPlayer>
#include <QMediaPlaylist>


class Settings : public QTabWidget
{
    Q_OBJECT

    QWidget * page1;
    QWidget * page2;
    QWidget * page3;
    QWidget * page4;


    QLabel * volumeLabel;
    QLabel * brightnessLabel;

    QGridLayout * soundLayout;
    QGridLayout * controlsLayout;
    QGridLayout * graphicsLayout;
    QGridLayout * languageLayout;


    QSlider * volumeSlider;

    QSlider * brightnessSlider;

    QCheckBox * invertedXAxisConCbox;
    QCheckBox * invertedYAxisConCbox;



    bool isXAxisInverted;
    bool isYAxisInverted;

    int brightness;
    int volume;
    QMediaPlayer * mediaPlayer;
    QMediaPlaylist * mediaPlaylist;


public:
    QTabWidget * menuTab;

    Settings();

    void setText();

    int score;

    QPushButton * polishButton;
    QPushButton * englishButton;


public slots:
    void setVolume();
    void setBrightness();
    void setIsXAxisInverted();
    void setIsYAxisInverted();


};


#endif // SETTINGS_H
