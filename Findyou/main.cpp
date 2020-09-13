#include "mainwindow.h"
#include "LocationDataView.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    //LocationDataView w;
    w.show();
    return a.exec();
}
