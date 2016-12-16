#include "mainwindow.h"
#include <QApplication>
#include "board.h"
#include "run.h"
#include <QObject>



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    w.show();

    return a.exec();
}
