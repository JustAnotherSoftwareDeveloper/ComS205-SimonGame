#ifndef TESTRUN_H
#define TESTRUN_H

#include "board.h"
#include "ctime"
#include "Leap.h"
#include "csv_writer.h"

#include <iostream>
#include <cstdlib>
#include <vector>
#include <QObject>
#include <string>

using namespace std;

class testRun: public QObject
{
    Q_OBJECT

public:


    board* gb;
    Leap::Controller controller;
    testRun(settings_container configuration);
    void game_loop();
    int whichQuadrant(Leap::Finger f);
    int customZone(Leap::Finger f);
    float MID_THRESH;
    float HOVER_THRESH;
    float CLICK_THRESH;

private:
    QMediaPlayer GameOverSound;


};

#endif // TESTRUN_H






