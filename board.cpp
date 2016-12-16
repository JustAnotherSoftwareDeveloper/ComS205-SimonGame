#include "board.h"
#include "ui_board.h"
#include "run.h"
#include "Leap.h"
#include "LeapMath.h"
#include "settings_container.h"
#include "run.h"
#include <QPixmap>
#include <QLabel>
#include <QTime>
#include <QMouseEvent>
#include <QtMultimedia/QSoundEffect>
#include <QMediaPlayer>


#include <QApplication>
#include <QDesktopWidget>

/*!
  Board will be passed a run class and a settings container class
  a click will call a method in run
  board will set icons and sounds according to settings container parameters
  */
using namespace std;

/*!
 * \brief board::board
 * \param parent
 * \param config -- A configuration container passed by reference.
 * Creates the visual gameboard that the player sees on screen
 * based on the config parameter
 */
board::board(settings_container &config, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::board)
{
    ui->setupUi(this);

    QRect screenGeometry = QApplication::desktop()->screenGeometry();
    int x = (screenGeometry.width()-this->width()) / 2;
    int y = (screenGeometry.height()-this->height()) / 2;
    this->move(x, y);
    this->show();

    if (config.color_mode() == true)
    {

        redHover       = new QPixmap(":/buttons/button_ur_h.png");
        redClick       = new QPixmap(":/buttons/button_ur_c.png");

        greenHover     = new QPixmap(":/buttons/button_ul_h.png");
        greenClick     = new QPixmap(":/buttons/button_ul_c.png");

        blueHover      = new QPixmap(":/buttons/button_lr_h.png");
        blueClick      = new QPixmap(":/buttons/button_lr_c.png");

        yellowHover    = new QPixmap(":/buttons/button_ll_h.png");
        yellowClick    = new QPixmap(":/buttons/button_ll_c.png");

        bckgrnd        = new QPixmap(":/buttons/full_board.png");

    }
    else
    {
        redHover       = new QPixmap(":/buttons/button_gray_ur_h.png");
        redClick       = new QPixmap(":/buttons/button_gray_ur_c.png");

        greenHover     = new QPixmap(":/buttons/button_gray_ul_h.png");
        greenClick     = new QPixmap(":/buttons/button_gray_ul_c.png");

        blueHover      = new QPixmap(":/buttons/button_gray_lr_h.png");
        blueClick      = new QPixmap(":/buttons/button_gray_lr_c.png");

        yellowHover    = new QPixmap(":/buttons/button_gray_ll_h.png");
        yellowClick    = new QPixmap(":/buttons/button_gray_ll_c.png");

        bckgrnd        = new QPixmap(":/buttons/buttons_gray.png");
    }

    ui->boardBckgrnd->setPixmap(*bckgrnd);

    greenSound.setSource(QUrl::fromLocalFile(":/sounds/c5"));
    redSound.setSource(QUrl::fromLocalFile(":/sounds/c6"));
    yellowSound.setSource(QUrl::fromLocalFile(":/sounds/g5"));
    blueSound.setSource(QUrl::fromLocalFile(":/sounds/g6"));

    greenSound.setVolume(.30);
    redSound.setVolume(.30);
    yellowSound.setVolume(.30);
    greenSound.setVolume(.30);
    sounds=config.sound_mode();
    leap=config.leap_mode();
    key_input=0;
    connect(this,SIGNAL(input_detected(QKeyEvent)),this,SLOT(keyboard_input(QKeyEvent)));

}

/*!
 * \brief board::~board
 * Deletes the board
 */
board::~board()
{
    delete ui;
}



/*!
 * \brief board::delay
 * Makes a 200 millisecond delay
 */
void board::delay()
{
    QTime dieTime = QTime::currentTime().addMSecs(200);
    //waits for current time to reach dieTime, while not processing user input
    while( QTime::currentTime() < dieTime )
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

/*!
 * \brief board::upperRightClick
 * Clicks the upper right button.
 * This is demonstrated by highlighting the button for 1 delay function
 */
void board::upperRightClick(){
    ui->upperRight->setPixmap(*redClick);
    if (sounds)
    {
        redSound.play();
    }
    delay();
    ui->upperRight->clear();

}

/*!
 * \brief board::upperLeftClick
 * Clicks the upper left button
 * This is demonstrated by highlighting the button for 1 delay function
 */
void board::upperLeftClick(){
    ui->upperLeft->setPixmap(*greenClick);
    if (sounds)
    {
        greenSound.play();
    }
    delay();
    ui->upperLeft->clear();

}

/*!
 * \brief board::lowerLeftClick
 * Clicks the lower left button
 * This is demonstrated by highlighting the button for 1 delay function
 */
void board::lowerLeftClick(){
    ui->lowerLeft->setPixmap(*yellowClick);
    if (sounds)
    {
        yellowSound.play();
    }
    delay();
    ui->lowerLeft->clear();
}

/*!
 * \brief board::lowerRightClick
 * Clicks the lower right button
 * This is demonstrated by highlighting the button for 1 delay function
 */
void board::lowerRightClick(){
    ui->lowerRight->setPixmap(*blueClick);
    if (sounds)
    {
        blueSound.play();
    }
    delay();
    ui->lowerRight->clear();
}

/*!
 * \brief board::getLastButtonPressed
 * \return -- an int representing the last button pressed
 * This function also sets the last button pressed to
 * zero (an invalid button number) for future events.
 */
int board::getLastButtonPressed()
{
    // resets the key input
    int tmp = lastButtonPressed;
    lastButtonPressed = 0;
    return tmp;
}

/*!
 * \brief board::checkLastButtonPressed
 * \return True if there has been a button pressed; false if not
 */
bool board::checkLastButtonPressed() {
    QWidget::grabKeyboard();
    if(lastButtonPressed != 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/*!
 * \brief board::clearButtons
 * Clears the board of all button presses/hovers
 */
void board::clearButtons() {
    ui->upperLeft->clear();
    ui->upperRight->clear();
    ui->lowerLeft->clear();
    ui->lowerRight->clear();
}

/*!
 * \brief board::lowerRightHover
 * Hovers over the lower right buttton
 * This is shown as outlining the button for 1 delay function
 */
void board::lowerRightHover(){
    ui->lowerRight->setPixmap(*blueHover);
    delay();
    ui->lowerRight->clear();
}

/*!
 * \brief board::lowerLeftHover
 * Hovers over the lower left buttton
 * This is shown as outlining the button for 1 delay function
 */
void board::lowerLeftHover(){
    ui->lowerLeft->setPixmap(*yellowHover);
    delay();
    ui->lowerLeft->clear();
}

/*!
 * \brief board::upperLeftHover
 * Hovers over the upper left buttton
 * This is shown as outlining the button for 1 delay function
 */
void board::upperLeftHover(){
    ui->upperLeft->setPixmap(*greenHover);
    delay();
    ui->upperLeft->clear();
}

/*!
 * \brief board::upperRightHover
 * Hovers over the upper right buttton
 * This is shown as outlining the button for 1 delay function
 */
void board::upperRightHover(){
    ui->upperRight->setPixmap(*redHover);
    delay();
    ui->upperRight->clear();
}
void board::keyboard_input(QKeyEvent *input) {
    if (leap!=true) {
        int keypress=input->key();
        switch(keypress) {
            case Qt::Key_A:
                key_input=1;
                break;
            case Qt::Key_S:
                key_input=2;
                break;
            case Qt::Key_Z:
                key_input=3;
                break;
            case Qt::Key_X:
                key_input=4;
                break;
            default:
                input->ignore();
                break;
        }
    }
    else {
        input->ignore();
    }
}
int board::return_key_input() {
    return key_input;
}
void board::clear_key_input() {
    key_input=0;
}


