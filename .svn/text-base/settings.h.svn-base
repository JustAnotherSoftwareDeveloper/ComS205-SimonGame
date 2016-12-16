#ifndef SETTINGS_H
#define SETTINGS_H

#include "settings_container.h"
#include "mainwindow.h"
#include "testrun.h"
#include <QDialog>
#include <QDoubleSpinBox>

namespace Ui {
class settings;
}

class settings : public QDialog
{
    Q_OBJECT

public:
    explicit settings(settings_container& param,MainWindow* m,QWidget *parent = 0);
    ~settings();
    testRun* r;

private slots:
    void on_saveButton_clicked();

    void on_OKbutton_clicked();

    void on_numOfTrials_valueChanged(int arg1);

    void on_LoadButton_clicked();

    void on_SaveOutput_clicked();

    void on_Leap_toggled(bool checked);

    void on_Sounds_toggled(bool checked);

    void on_Colors_toggled(bool checked);

    void on_TestGame_clicked();

    void on_Timeoutspinner_valueChanged(double arg1);

    void on_Timeoutbool_toggled(bool checked);

private:
    Ui::settings *ui;
    settings_container* params;
    settings_container testparams;
    MainWindow* main;

};

#endif // SETTINGS_H
