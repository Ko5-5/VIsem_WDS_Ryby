#ifndef GAME_H
#define GAME_H
#include <QGraphicsView>
#include <QObject>
#include <QWidget>
#include <QGraphicsScene>
#include <QPushButton>
#include <QGraphicsProxyWidget>
#include <QGraphicsGridLayout>
#include <QGraphicsWidget>
#include <QImage>
#include <QBrush>
#include <QPixmap>
#include <QPainter>
#include "settings.h"
#include "key_press_event_filter.h"

/*!
 * \brief The Game class
 *
 * Klasa Game() dziedziczy z klasy QGraphicsView,
 * służy do wyświetlania elementów na ekranie,
 * a także przechowuje wskaźniki do tych elementów.
 */


class Game : public QGraphicsView
{
    Q_OBJECT
public:
    /*!
     *  \brief Konstruktor klasy Game
     *
     *  Tworzy instancje wszystkich obiektów znajdujących się na ekranie
     * i wyświetla je.
     */
    Game(QWidget * parent = 0);
    virtual ~Game() {};

    /*!
     * \brief Wskaźnik na scenę frontową
     */
    QGraphicsScene * frontScene;
    /*!
     * \brief Wskaźnik na scenę ustawień
     */
    QGraphicsScene * menuScene;
    /*!
     * \brief Wskaźnik na scenę gry
     */
    QGraphicsScene * gameScene;

    /*!
     * \brief Wskaźnik na przycisk rozpoczynający grę
     */
    QPushButton * startGameButton;
    /*!
     * \brief Wskaźnik na przycisk przenoszący do ustawień
     */
    QPushButton * settingsButton;
    /*!
     * \brief Wskaźnik na przycisk powrotu do menu startowego
     */
    QPushButton * backToFrontButton;
    /*!
     * \brief Wskaźnik na przycisk wyjścia z gry
     */
    QPushButton * exitButton;

    /*!
     * \brief Wskaźnik na tytuł gry
     */
    QLabel * titleLabel;

    /*!
     * \brief Wskaźnik na obiekt settings, odpowiedzialny za ustawienia
     */
    Settings * settings;

    /*!
     * \brief Wskaźnik na obraz aktualnie wyświetlany
     */
    QImage * currentSceneImage;

    /*!
     * \brief Wskaźnik na obraz tła
     */
    QImage * fishingBackground;

    /*!
     * \brief Wskaźnik na obraz zwykłej mapy
     */
    QImage * casualFishing;

    /*!
     * \brief Wskaźnik na obraz mapy szarlotka
     */
    QImage * szarlotkaFishing;
    /*!
     * \brief Wskaźnik na obraz mapy palma
     */
    QImage * palmaFishing;
    /*!
     * \brief Wskażnik na obraz mapy lawa
     */
    QImage * lawaFishing;

    /*!
     * \brief drawBackground
     * \param painter
     * \param rect
     *
     * Reimplementacja funkcji służącej do rysowania tła, w celu dostosowania jej do tej gry
     */
    void drawBackground(QPainter *painter, const QRectF &rect) override;
public slots:
    /*!
     * \brief setFrontScene
     *
     * Slot gry, pozwalający na zmianę sceny na scenę frontową
     */
    void setFrontScene();

    /*!
     * \brief setMenuScene
     *
     * Slot gry, pozwalający na zmianę sceny na scenę ustawień
     */
    void setMenuScene();

    /*!
     * \brief setGameScene
     *
     * Slot gry, pozwalający na zmianę sceny na scenę gry
     */
    void setGameScene();
    // SLot update Signal resize
};

#endif // GAME_H
