#include "game.h"


Game::Game(QApplication *a, QWidget *parent)
{
    this->setCacheMode(QGraphicsView::CacheBackground);
    appPointer = a;

    gameTranslator = new QTranslator();

    KeyPressEventFilter * filter = new KeyPressEventFilter(this);
    this->installEventFilter(filter);
    menuScene = new QGraphicsScene();
    gameScene = new QGraphicsScene();
    frontScene = new QGraphicsScene();

    currentSceneImage = new QImage(":/images/fishing_bcg.png");

    fishingBackground = new QImage(":/images/fishing_bcg.png");
    casualFishing = new QImage(":/images/casualFishing.png");
    szarlotkaFishing = new QImage(":/images/szarlotkaFishing.png");
    palmaFishing = new QImage(":/images/palmaFishing.png");
    lawaFishing = new QImage(":/images/lawaFishing.png");


    settings = new Settings();

    scoreLabel = new QLabel();
    QFont temp1 = scoreLabel->font();
    temp1.setPointSize(40);
    scoreLabel->setFont(temp1);
    scoreLabel->setText("Score: " + QString::number(settings->score));

    QGraphicsProxyWidget* proxyScoreLabel = new QGraphicsProxyWidget();
    proxyScoreLabel->setWidget(scoreLabel);

    titleLabel = new QLabel();
    titleLabel->setText("RyBy");
    QFont temp = titleLabel->font();
    temp.setPointSize(120);
    titleLabel->setFont(temp);
    titleLabel->setAlignment(Qt::AlignCenter);
    titleLabel->setStyleSheet("color: white");
    titleLabel->setAttribute(Qt::WA_TranslucentBackground);

    startGameButton = new QPushButton();
    startGameButton->setText(tr("Start"));
    connect(startGameButton, SIGNAL(clicked(bool)), this, SLOT(setGameScene()));

    settingsButton = new QPushButton();
    settingsButton->setText(tr("Ustawienia"));
    connect(settingsButton, SIGNAL(clicked(bool)), this, SLOT(setMenuScene()));


    backToFrontButton = new QPushButton();
    backToFrontButton->setText(tr("Powrót"));
    backToFrontButton->setMaximumWidth(50);
    connect(backToFrontButton, SIGNAL(clicked(bool)), this, SLOT(setFrontScene()));


    exitButton = new QPushButton();
    exitButton->setText(tr("Wyjdź"));
    connect(exitButton, SIGNAL(clicked(bool)), this, SLOT(close()));

    this->setScene(frontScene);

    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);


    //QObject::connect(button, SIGNAL(clicked(bool)), this, SLOT(changeScenes()));

    //QObject::connect(button2, SIGNAL(clicked(bool)), this, SLOT(changeScenes()));
   // proxyButton->setWidget(button2);
    QGraphicsProxyWidget * proxyLabel = new QGraphicsProxyWidget();
    proxyLabel->setWidget(titleLabel);


    QGraphicsProxyWidget * proxyTab = new QGraphicsProxyWidget();
    proxyTab->setWidget(settings->menuTab);

    QGraphicsProxyWidget * proxyButtonStart = new QGraphicsProxyWidget();
    proxyButtonStart->setWidget(startGameButton);

    QGraphicsProxyWidget * proxyButtonSettings = new QGraphicsProxyWidget();
    proxyButtonSettings->setWidget(settingsButton);

    QGraphicsProxyWidget * proxyButtonBackToMenu = new QGraphicsProxyWidget();
    proxyButtonBackToMenu->setWidget(backToFrontButton);

    QGraphicsProxyWidget * proxyButtonExit = new QGraphicsProxyWidget();
    proxyButtonExit->setWidget(exitButton);


    QGraphicsGridLayout *frontGrid = new QGraphicsGridLayout();
    frontGrid->addItem(proxyLabel,0,0);
    frontGrid->addItem(proxyButtonStart,1,0);
    frontGrid->addItem(proxyButtonSettings,2,0);
    frontGrid->addItem(proxyButtonExit, 3, 0);
    frontGrid->setAlignment(proxyButtonExit, Qt::AlignCenter);


    QGraphicsGridLayout *menuGrid = new QGraphicsGridLayout;
    menuGrid->addItem(proxyTab, 0, 0);
    menuGrid->addItem(proxyButtonBackToMenu, 1, 0);
    menuGrid->setAlignment(proxyButtonBackToMenu, Qt::AlignCenter);

    QGraphicsGridLayout *gameGrid = new QGraphicsGridLayout;
    gameGrid->addItem(proxyScoreLabel, 0,0);

    QGraphicsWidget * menuForm = new QGraphicsWidget;
    menuForm->setLayout(menuGrid);

    QGraphicsWidget * frontForm = new QGraphicsWidget;
    frontForm->setLayout(frontGrid);

    QGraphicsWidget * gameForm = new QGraphicsWidget;
    gameForm->setLayout(gameGrid);

    connect(settings->polishButton, SIGNAL(clicked(bool)), this, SLOT(retranslateGame()));
    connect(settings->englishButton, SIGNAL(clicked(bool)), this, SLOT(translateGame()));


    frontScene->addItem(frontForm);
    menuScene->addItem(menuForm);
    gameScene->addItem(gameForm);

    gameSerial = new QSerialPort(this);
    qDebug() << "Number of ports: " << QSerialPortInfo::availablePorts().length() << endl;
    foreach (const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts()) {
        qDebug() << "Description: " << serialPortInfo.description() << endl;
        qDebug() << "Has vendor id: " << serialPortInfo.hasVendorIdentifier() << endl;
        qDebug() << "Vendor id: " << serialPortInfo.vendorIdentifier() << endl;
    }
    bool isSerialAvailable = false;
    QString portName;

    foreach (const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts()) {
        isSerialAvailable = true;
        portName = serialPortInfo.portName();
    }

    if(isSerialAvailable)
    {
        qDebug() << "Found the serial port" << endl;
        gameSerial->setPortName(portName);
        gameSerial->open(QSerialPort::ReadOnly);
        gameSerial->setBaudRate(QSerialPort::Baud57600);
        gameSerial->setDataBits(QSerialPort::Data8);
        gameSerial->setFlowControl(QSerialPort::NoFlowControl);
        gameSerial->setParity(QSerialPort::NoParity);
        gameSerial->setStopBits(QSerialPort::OneStop);
        QObject::connect(gameSerial, SIGNAL(readyRead()), this, SLOT(readSerial()));
    }else
    {
        qDebug() << "Couldnt find the port" << endl;
    }

}

Game::~Game()
{
    if(gameSerial->isOpen())
        gameSerial->close();
}

void Game::setText()
{
    startGameButton->setText(tr("Start"));
    settingsButton->setText(tr("Ustawienia"));
    backToFrontButton->setText(tr("Powrót"));
    exitButton->setText(tr("Wyjdź"));
}

void Game::updateText()
{
    settings->score++;
    scoreLabel->setText("Score: " + QString::number(settings->score));

}

void Game::translateGame()
{
    gameTranslator->load(":/english.qm");
    qApp->installTranslator(gameTranslator);

}

void Game::retranslateGame()
{
    qApp->removeTranslator(gameTranslator);
}

void Game::drawBackground(QPainter *painter, const QRectF &rect)
{
    painter->save();
    painter->drawImage(rect, *currentSceneImage);
    painter->restore();
}

void Game::changeEvent(QEvent *event)
{
    if(event->type() == QEvent::LanguageChange)
    {
        this->setText();
        settings->setText();
    }
}



void Game::setFrontScene()
{
    this->setScene(frontScene);
    this->resetCachedContent();
}

void Game::setMenuScene()
{
    this->setScene(menuScene);
}

void Game::setGameScene()
{
    this->show();
    this->currentSceneImage = this->casualFishing;
    this->setScene(gameScene);
}

void Game::readSerial()
{
    qDebug() << "Serial port read" << endl;
}
