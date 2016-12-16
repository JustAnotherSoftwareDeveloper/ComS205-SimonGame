#ifndef BOARD_H
#define BOARD_H

#include <stdio.h>
#include <iostream>
#include <settings_container.h>

#include <QWidget>
#include <QKeyEvent>
#include <QTimer>
#include <QSoundEffect>
#include <QMediaPlayer>

namespace Ui {
class board;
}

class board : public QWidget
{

public:
    explicit board(settings_container &config, QWidget *parent = 0);
    ~board();
    void upperRightClick();
    void upperLeftClick();
    void lowerLeftClick();
    void lowerRightClick();

    void upperRightHover();
    void upperLeftHover();
    void lowerLeftHover();
    void lowerRightHover();
    
    void clearButtons();
    void delay();

    int return_key_input();
    void clear_key_input();

    void keyboard_input(QKeyEvent* input);

    int getLastButtonPressed();
    bool checkLastButtonPressed();

private:
    Q_OBJECT

    Ui::board *ui;

    QPixmap *redHover;
    QPixmap *redClick;

    QPixmap *greenHover;
    QPixmap *greenClick;

    QPixmap *blueHover;
    QPixmap *blueClick;

    QPixmap *yellowHover;
    QPixmap *yellowClick;

    QPixmap *bckgrnd;

    QSoundEffect redSound;
    QSoundEffect greenSound;
    QSoundEffect blueSound;
    QSoundEffect yellowSound;

    bool sounds,leap;

    int lastButtonPressed;
    int key_input;
signals:
    void input_detected(QKeyEvent e);



};

#endif // BOARD_H
