#include "settings.h"


Settings::Settings()
{
    page1 = new QWidget();
    page2 = new QWidget();
    page3 = new QWidget();
    page4 = new QWidget();

    score = 0;

    menuTab = new QTabWidget();

    volumeLabel = new QLabel();
    volumeLabel->setText(tr("Głośność"));
    volumeLabel->setAlignment(Qt::AlignCenter);

    brightnessLabel = new QLabel();
    brightnessLabel->setText(tr("Jasność"));
    brightnessLabel->setAlignment(Qt::AlignCenter);


    soundLayout = new QGridLayout();
    controlsLayout = new QGridLayout();
    graphicsLayout = new QGridLayout();

    volumeSlider = new QSlider();
    volumeSlider->setRange(0,100);
    volumeSlider->setValue(20);
    volumeSlider->setOrientation(Qt::Horizontal);
    connect(volumeSlider, SIGNAL(valueChanged(int)), this, SLOT(setVolume()));

    brightnessSlider = new QSlider();
    brightnessSlider->setRange(0,100);
    brightnessSlider->setOrientation(Qt::Horizontal);
    connect(brightnessSlider, SIGNAL(valueChanged(int)), this, SLOT(setBrightness()));

    polishButton = new QPushButton();
    englishButton = new QPushButton();

    polishButton->setText("Polski");
    englishButton->setText("English");

    languageLayout = new QGridLayout();
    languageLayout->addWidget(polishButton);
    languageLayout->addWidget(englishButton);

    invertedXAxisConCbox = new QCheckBox();
    invertedXAxisConCbox->setText(tr("Odwrócona oś X kontrolera"));
    connect(invertedXAxisConCbox, SIGNAL(clicked(bool)), this, SLOT(setIsXAxisInverted()));

    invertedYAxisConCbox = new QCheckBox();
    invertedYAxisConCbox->setText(tr("Odwrócona oś Y kontrolera"));
    connect(invertedYAxisConCbox, SIGNAL(clicked(bool)), this, SLOT(setIsYAxisInverted()));


    // --------------------------------------
    soundLayout->addWidget(volumeLabel, 0, 0);
    soundLayout->addWidget(volumeSlider, 1, 0);


    controlsLayout->addWidget(invertedXAxisConCbox, 0, 0);
    controlsLayout->addWidget(invertedYAxisConCbox, 1, 0);

    graphicsLayout->addWidget(brightnessLabel, 0, 0);
    graphicsLayout->addWidget(brightnessSlider, 1, 0);

    page1->setLayout(soundLayout);
    page2->setLayout(controlsLayout);
    page3->setLayout(graphicsLayout);
    page4->setLayout(languageLayout);

    menuTab->addTab(page1, tr("Dźwięk"));
    menuTab->addTab(page2, tr("Sterowanie"));
    menuTab->addTab(page3, tr("Grafika"));
    menuTab->addTab(page4, tr("Język"));
    menuTab->setMinimumSize(330,100);

    mediaPlayer = new QMediaPlayer();
    mediaPlayer->setMedia(QUrl("qrc:/music/rain_music.mp3"));
    mediaPlayer->setVolume(20);
    mediaPlayer->play();
}

void Settings::setText()
{
    volumeLabel->setText(tr("Głośność"));
    brightnessLabel->setText(tr("Jasność"));
    invertedXAxisConCbox->setText(tr("Odwrócona oś X kontrolera"));
    invertedYAxisConCbox->setText(tr("Odwrócona oś Y kontrolera"));
    menuTab->addTab(page1, tr("Dźwięk"));
    menuTab->addTab(page2, tr("Sterowanie"));
    menuTab->addTab(page3, tr("Grafika"));
    menuTab->addTab(page4, tr("Język"));

}

void Settings::setVolume()
{
    volume = volumeSlider->value();
    mediaPlayer->setVolume(volume);
    //volumeLabel->setText(QString::number(volume));
}

void Settings::setBrightness()
{
    brightness = brightnessSlider->value();
}

void Settings::setIsXAxisInverted()
{
    isXAxisInverted = invertedXAxisConCbox->checkState();
}

void Settings::setIsYAxisInverted()
{
    isYAxisInverted = invertedYAxisConCbox->checkState();

}
