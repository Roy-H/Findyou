#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <LocationDataView.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    //void OnPositionUpdated(const QGeoPositionInfo &info);
    void RequestUpdated();
    void StartUpdated();
    void StopUpdated();
    void OpenLocationDataView();

private:
    Ui::MainWindow *ui;
   

//controller or view
private:
    LocationDataView *pLocationDataView = nullptr;
};
#endif // MAINWINDOW_H
