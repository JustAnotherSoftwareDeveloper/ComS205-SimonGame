#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "settings.h"
#include "settings_container.h"
#include "run.h"
#include "board.h"

#include <QRect>
#include <QApplication>
#include <QDesktopWidget>


/*!
 * \brief MainWindow::MainWindow
 * \param parent
 * Makes a new main window appear.
 */
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QRect screenGeometry = QApplication::desktop()->screenGeometry();
    int x = (screenGeometry.width()-this->width()) / 2;
    int y = (screenGeometry.height()-this->height()) / 2;
    this->move(x, y);
    this->show();

}

/*!
 * \brief MainWindow::~MainWindow
 * Deletes the main window
 */
MainWindow::~MainWindow()
{
    delete ui;
}

/*!
 * \brief MainWindow::on_startGame_clicked
 * Hides the Main Window, makes a new board,
 * and shows the Simon Game.
 */
void MainWindow::on_startGame_clicked()
{
    std::cout << " before game colors: " << params.color_mode();
    for (int i = 0; i < params.return_trialnumber(); i++)
    {
        r = new run(params);
        QMessageBox::information(r->gb, tr("Gameplay Instructions"),
                                 "Press the buttons in the order that they appear.\n\nTo press a button use slow deliberate pokes.\n\nWhen you are hovering over a button, it will be outlined.\n\nWhen you press a button, it will light up.\n\nGood Luck!");

        if (params.leap_mode()) {
            r->game_loop();
        }
        else {
            r->keyboard_loop();
        }
        delete r;
    }
    this->show();
}

/*!
 * \brief MainWindow::on_settings_clicked
 * Hides the Main Window and brings user to settings screen.
 */
void MainWindow::on_settings_clicked()
{
    settings* simongame = new settings(params,this);
    simongame->show();
    this->hide();
}

void MainWindow::on_nameField_textChanged(const QString &arg1)
{
    params.set_demographic(0,arg1);
}

void MainWindow::on_ageField_textChanged(const QString &arg1)
{
    params.set_demographic(1, arg1);
}

void MainWindow::on_idField_textChanged(const QString &arg1)
{
    params.set_demographic(2,arg1);
}


void MainWindow::on_classyearField_textChanged(const QString &arg1)
{
    params.set_demographic(3,arg1);
}

void MainWindow::on_comboBox_currentIndexChanged(const QString &arg1)
{
    params.set_demographic(4,arg1);
}
