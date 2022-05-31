#ifndef SETTINGS_H
#define SETTINGS_H

#include <QTabWidget>
#include <QGridLayout>
#include <QSlider>
#include <QPushButton>
#include <QCheckBox>
#include <QString>
#include <QLabel>

class Settings : public QTabWidget
{
    Q_OBJECT

    QWidget * page1;
    QWidget * page2;
    QWidget * page3;

    QLabel * volumeLabel;
    QLabel * brightnessLabel;

    QGridLayout * soundLayout;
    QGridLayout * controlsLayout;
    QGridLayout * graphicsLayout;

    QSlider * volumeSlider;

    QSlider * brightnessSlider;

    QCheckBox * invertedXAxisConCbox;
    QCheckBox * invertedYAxisConCbox;

    bool isXAxisInverted;
    bool isYAxisInverted;

    int brightness;
    int volume;

public:
    QTabWidget * menuTab;

    Settings();

public slots:
    void setVolume();
    void setBrightness();
    void setIsXAxisInverted();
    void setIsYAxisInverted();


};


#endif // SETTINGS_H
