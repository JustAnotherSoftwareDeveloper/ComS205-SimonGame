#ifndef RUN_H
#define RUN_H

#include "board.h"
#include "ctime"
#include "Leap.h"
#include "csv_writer.h"
#include "time.h"
#include <iostream>
#include <cstdlib>
#include <QMessageBox>
#include <QObject>
#include <string>

using namespace std;

class run: public QObject
{
    Q_OBJECT

public:
    string input; // users input
    int numInput;
    clock_t Oclock;
    int last_correct; // keeps track of how much of the sequence you did correct
    board* gb;
    int sequence_size;
    int* sequence;      // allow for dynamic array programming
    list<double> timeList;
    double seconds;
    time_t beginTime, endTime;


    Leap::Controller controller;
    float millitime();

    void writedata();
    run(settings_container &configuration);
    void print_sequence(int x);
    void gen_sequence();
    void game_loop();
    void keyboard_loop();
    void fail(int x);
    string return_demographic(int choice);



    int whichQuadrant(Leap::Finger f);
    int customZone(Leap::Finger f);

    int return_sequence_size();
    int return_saved_sequence(int index);

    float MID_THRESH;
    float HOVER_THRESH;
    float CLICK_THRESH;
private:
    QSoundEffect GameOverSound;
    string demographics[5];
    string filename;

};

#endif // RUN_H
