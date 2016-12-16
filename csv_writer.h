#ifndef CSV_WRITER_H
#define CSV_WRITER_H

#include <fstream>
#include <settings_container.h>
#include <string>
#include "run.h"

class csv_writer
{
public:
    csv_writer(settings_container configuration);
    void write_demographcis();

private:
	string filename;
    settings_container config;
};

#endif // CSV_WRITER_H
