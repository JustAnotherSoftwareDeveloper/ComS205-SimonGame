#ifndef SETTINGS_CONTAINER_H
#define SETTINGS_CONTAINER_H

#include <vector>
#include <string>
#include <fstream>
#include <stdio.h>

#include <QString>
#include <QFile>
#include <QDataStream>

using namespace std;
class settings_container
{
public:
    settings_container();
    bool loadnew(string filename);
    void colors_onoff(bool state);
    bool color_mode();
    void sound_onoff(bool state);
    bool sound_mode();
    void leap_onoff(bool state);
    bool leap_mode();
    void set_filename(string name);
    string return_filename();
    void set_trialnumber(int number);
    int return_trialnumber();
    void save_config(QString configname);
    void colors_setvalue(bool value);
    void sound_setvalue(bool value);
    void leap_setvalue(bool value);
    void set_configured(bool value);
    bool return_configured();
    string return_demographic(int field);
    void set_demographic(int field,QString input);
    void toggle_timeout(bool state);
    bool return_timeout();
    void set_timeoutsec(double num);
    double return_timeoutsec();

    
private:
    int trialnumber;
    string filename;
    bool leap;
    bool sound;
    bool colors;
    bool configured;
    bool timeout;
    double timeoutsec;
    string demographics[5];
};

#endif // SETTINGS_CONTAINER_H
