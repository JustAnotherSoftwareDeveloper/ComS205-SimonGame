#include "settings_container.h"

#include <iostream>

 /*!
  * A costum container for the settings.
  * It stores the configuration for the game.
  */
//settings possibly use enum
//settings need to load??

/*!
 * \brief settings_container::settings_container
 * Sets all the class variables to their default values
 */
 settings_container::settings_container() {
    trialnumber=1;
    filename="simondata.csv";
    leap=true;
    sound=true;
    colors=true;
    configured=false;
    timeout=true;
    timeoutsec=5.0;
}

/*!
 * \brief settings_container::colors_onoff
 * Toggles the colors on the board.
 */
 void settings_container::colors_onoff(bool state) {
    colors=state;
}

/*!
 * \brief settings_container::color_mode
 * \return -- True if colors are on; false if not
 */
 bool settings_container::color_mode() {
    return colors;
}

/*!
 * \brief settings_container::sound_onoff
 * Toggles sound on and off
 */
 void settings_container::sound_onoff(bool state) {
     sound=state;
 }

/*!
 * \brief settings_container::sound_mode
 * \return -- True if sound is on; false if it is off.
 */
 bool settings_container::sound_mode() {
    return sound;
}

/*!
 * \brief settings_container::leap_onoff
 * Toggles the leap controller on and off.
 */
 void settings_container::leap_onoff(bool state) {
    leap=state;
}

/*!
 * \brief settings_container::leap_mode
 * \return -- True if the leap is on; false if not.
 */
 bool settings_container::leap_mode() {
    return leap;
}

/*!
 * \brief settings_container::set_filename
 * \param name -- the name of the file
 */
 void settings_container::set_filename(string name) {
    filename=name;
}

/*!
 * \brief settings_container::return_filename
 * \return -- The name of the file
 */
 string settings_container::return_filename() {
    return filename;
}

/*!
  * \brief settings_container::save_config
  * \param configname -- The name of the settings configuration
  * Makes an outfile stream and saves the configuration in it.
  */
  void settings_container::save_config(QString configname) {
    string cname = configname.toStdString();
    cout << cname;
    ofstream save;
    save.open(cname.c_str());
    save << "APDYNCONFIG"<<endl;
    save << this->colors<<endl;
    save << this->filename<<endl;
    save << this->sound<<endl;
    save << this->trialnumber<<endl;
    save << this->leap<<endl;
    save << this->timeout<<endl;
    save <<this->timeoutsec<<endl;

    save.close();
}

 /*!
  * \brief settings_container::set_gesture
  * \param choice -- Numerical value to represent which gesture is desired.
  */


/*!
 * \brief settings_container::return_trialnumber
 * \return -- The trail number
 */
 int settings_container::return_trialnumber() {
    return trialnumber;
}

/*!
 * \brief settings_container::set_trialnumber
 * \param number -- The trial number
 */
 void settings_container::set_trialnumber(int number) {
    trialnumber=number;
}

/*!
 * \brief settings_container::loadnew
 * \param filename -- The name of the file
 * \return -- True if the correct configuration files loads; false if not.
 * Loads a configuration file and makes a new settings container based on that file.
 */
 bool settings_container::loadnew(string filename) {
    ifstream load;
    load.open(filename.c_str());
    string correct_config, file, sounds, colorsb, leapm,timebool;
    int trials;
    double timesec;
    load>>correct_config;
    if (correct_config!="APDYNCONFIG") {
        return false;
    }
    else {
        load>>colorsb;
        if (colorsb=="0") {
            colors=false;
        }
        else {
            colors=true;
        }
        load>>file;
        this->set_filename(file);
        load>>sound;
        if (sounds=="0") {
            sound=false;
        }
        else {
            sound=true;
        }
        load>>trials;
        this->set_trialnumber(trials);
        load>>leapm;
        if (leapm=="0") {
            leap=false;
        }
        else {
            leap=true;
        }
        load>>timebool;
        if (timebool=="0") {
            timeout=false;
        }
        else {
            timeout=true;
        }

        load>>timesec;
        timeoutsec=timesec;

        return true;
    }
}

/*!
 * \brief settings_container::set_configured
 * \param value -- Bool of whether the settings have been configured
 */
 void settings_container::set_configured(bool value) {
    configured=value;
}

/*!
 * \brief settings_container::return_configured
 * \return -- True if configured; false if not
 */
 bool settings_container::return_configured() {
    return configured;
}
 string settings_container::return_demographic(int field) {
     return demographics[field];
 }
 void settings_container::set_demographic(int field, QString input) {
     demographics[field]=input.toStdString();
 }
 void settings_container::toggle_timeout(bool state) {
     timeout=state;
 }
 void settings_container::set_timeoutsec(double num) {
     timeoutsec=num;
 }
 bool settings_container::return_timeout() {
     return timeout;
 }
 double settings_container::return_timeoutsec() {
     return timeoutsec;
 }
