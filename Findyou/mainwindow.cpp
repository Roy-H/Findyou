#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QGeoPositionInfo>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    pQGeoPositionInfoSource = QGeoPositionInfoSource::createDefaultSource(0);
    if(pQGeoPositionInfoSource)
    {
        pQGeoPositionInfoSource->setUpdateInterval(1000);

        connect(pQGeoPositionInfoSource,SIGNAL(positionUpdated(const QGeoPositionInfo & )),this,SLOT(OnPositionUpdated(const QGeoPositionInfo &)));
        connect(ui->main_open_location_view_btn,SIGNAL(clicked()),this,SLOT(OpenLocationDataView()));
        //connect(ui->stop_update_btn,SIGNAL(clicked()),this,SLOT(StopUpdate()));
        connect(ui->request_update_btn,SIGNAL(clicked()),this,SLOT(RequestUpdated()));

    }

}

MainWindow::~MainWindow()
{

    if(pLocationDataView)
        delete pLocationDataView;


    pQGeoPositionInfoSource->stopUpdates();
    delete ui;
}

void MainWindow::OnPositionUpdated(const QGeoPositionInfo &info)
{
    ui->location_info->setText(info.coordinate().toString());
    
}

void MainWindow::StartUpdated()
{
    if(pQGeoPositionInfoSource)
    {
        pQGeoPositionInfoSource->startUpdates();
    }
}

void MainWindow::StopUpdated()
{
    if(pQGeoPositionInfoSource)
    {
        pQGeoPositionInfoSource->stopUpdates();
    }
}


void MainWindow::RequestUpdated()
{
    if(pQGeoPositionInfoSource)
    {
        pQGeoPositionInfoSource->requestUpdate();
    }
}

void MainWindow::OpenLocationDataView()
{
    if(pLocationDataView == nullptr)
    {
        pLocationDataView = new LocationDataView(this);
    }

    if(pLocationDataView != nullptr)
    pLocationDataView->show();
}



