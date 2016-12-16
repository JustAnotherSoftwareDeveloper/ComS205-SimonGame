#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "settings_container.h"
#include "run.h"
#include "board.h"

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    run* r;

private slots:
    void on_startGame_clicked();

    void on_settings_clicked();

    void on_nameField_textChanged(const QString &arg1);

    void on_ageField_textChanged(const QString &arg1);

    void on_idField_textChanged(const QString &arg1);

    void on_classyearField_textChanged(const QString &arg1);

    void on_comboBox_currentIndexChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
    settings_container params;
};

#endif // MAINWINDOW_H
