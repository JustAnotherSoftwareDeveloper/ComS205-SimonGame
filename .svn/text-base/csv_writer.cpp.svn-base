#include "csv_writer.h"

/*!
 * \brief csv_writer::csv_writer
 * \param config
 * This creates an outfile stream to the settings container.
 */
csv_writer::csv_writer(settings_container configuration)
{
    filename=config.return_filename();
    config=configuration;
}
void csv_writer::write_demographcis(){
    ofstream settings_write;
    settings_write.open(filename.c_str(),ios::app);

    settings_write << "Colors,";
    settings_write << config.color_mode() << endl;

    settings_write << "Sound,";
    settings_write << config.sound_mode() << endl;

    settings_write << "Leap Motion,";
    settings_write << config.leap_mode() << endl;

    settings_write << "Trials,";
    settings_write << config.return_trialnumber() << endl;

    settings_write<<"Timeout,";
    settings_write<<config.return_timeout()<<",";
    settings_write<<config.return_timeoutsec()<<endl;
}
