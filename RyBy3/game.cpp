#include "game.h"


Game::Game(QWidget *parent)
{
    gameTranslator = new QTranslator();
   // gameTranslator->load("qt_" + QLocale::system().name(), QLibraryInfo::TranslationsPath);


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


    QGraphicsWidget * menuForm = new QGraphicsWidget;
    menuForm->setLayout(menuGrid);

    QGraphicsWidget * frontForm = new QGraphicsWidget;
    frontForm->setLayout(frontGrid);

    QGraphicsWidget * gameForm = new QGraphicsWidget;
    gameForm->setLayout(gameGrid);


    frontScene->addItem(frontForm);
    menuScene->addItem(menuForm);
    gameScene->addItem(gameForm);
}

void Game::drawBackground(QPainter *painter, const QRectF &rect)
{
    painter->save();
    painter->drawImage(rect, *currentSceneImage);
    painter->restore();
}



void Game::setFrontScene()
{
    this->setScene(frontScene);
}

void Game::setMenuScene()
{
    this->setScene(menuScene);
}

void Game::setGameScene()
{
    this->setScene(gameScene);
}
