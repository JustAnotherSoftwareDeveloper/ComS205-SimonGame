#include "settings.h"
#include "ui_settings.h"
#include "mainwindow.h"
#include "board.h"

#include <iostream>
#include <QMessageBox>
#include <QFileDialog>
#include <QString>

/*!
 * \brief settings::settings
 * \param param -- The settings container
 * \param m -- The main window
 * \param parent
 * Sets up the user interface based on the settings container
 */
settings::settings(settings_container& param, MainWindow* m, QWidget *parent) :  // passing main window in so settings can see it
    QDialog(parent),
    ui(new Ui::settings)
{
    ui->setupUi(this);
    params=&param;
    testparams = *params;
    main=m;
}

/*!
 * \brief settings::~settings
 * Deletes the object
 *
 */
settings::~settings()
{
    delete ui;
}

/*!
 * \brief settings::on_saveButton_clicked
 * Saves the settings
 */
void settings::on_saveButton_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this,
                                                    tr("Save As"), "", tr("Apenture Dyanamic Files Files (*.apdyn)"));

    if (fileName.isEmpty())
    {
        return;
    }
    else
    {
        fileName.append(".apdyn");
        params->save_config(fileName);
    }
}

/*!
 * \brief settings::on_OKbutton_clicked
 * Hides this window and display the main window.
 */
void settings::on_OKbutton_clicked()
{
    std::cout << "ok";
    params->set_configured(true);
    std::cout << " after click ok: " << params->color_mode();
    this->hide();
    main->show();
    this->close();
}

/*!
 * \brief settings::on_numOfTrials_valueChanged
 * \param arg1 -- The trial number
 * Sets the trial number to the value of arg1.
 */
void settings::on_numOfTrials_valueChanged(int arg1)
{
    params->set_trialnumber(arg1);
}

/*!
 * \brief settings::on_LoadButton_clicked
 * Loads a configuration file
 */
void settings::on_LoadButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,
                                                    tr("Open Configuration File"), "",
                                                    tr("Apenture Dynamics File (*.apdyn);;All Files (*)"));
    if (!fileName.isEmpty())
    {
        bool successful=params->loadnew(fileName.toStdString());
        if (successful)
        {
            QMessageBox::information(this, tr("Information"),
                                     "Settings sucessfully loaded");
            params->set_configured(true);
            this->hide();
            main->show();
            this->close();
        }
        else
        {
            QMessageBox::information(this, tr("Information"),
                                     "Cannot load settings from file");
        }
    }
}

/*!
 * \brief settings::on_SaveOutput_clicked
 * Saves output as a .csv file
 */
void settings::on_SaveOutput_clicked()
{
    QString selfilter=tr("Comma Seperated Values (*.csv)");
    QString fileName = QFileDialog::getSaveFileName(this,
                                                    tr("Save As"), "", tr("Comma Seperated Values (*.csv)"),&selfilter,QFileDialog::DontConfirmOverwrite);
    params->set_filename(fileName.toStdString());
}

void settings::on_Leap_toggled(bool checked)
{
    params->leap_onoff(checked);
}

void settings::on_Sounds_toggled(bool checked)
{
    params->sound_onoff(checked);
}

void settings::on_Colors_toggled(bool checked)
{
    params->colors_onoff(checked);
}

void settings::on_TestGame_clicked()
{
    this->hide();
    std::cout << "Press 5 buttons to exit.\n";
    r = new testRun(*params);
    r->game_loop();
    this->show();
}

void settings::on_Timeoutspinner_valueChanged(double arg1)
{
    params->set_timeoutsec(arg1);
}

void settings::on_Timeoutbool_toggled(bool checked) {
    if (checked)
    {
        params->toggle_timeout(true);
    }
    else
    {
        params->toggle_timeout(false);
    }
}
