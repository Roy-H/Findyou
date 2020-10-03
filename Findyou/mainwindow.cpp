#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->main_open_location_view_btn, SIGNAL(clicked()), this, SLOT(OpenLocationDataView()));
    

}

MainWindow::~MainWindow()
{
    if(pLocationDataView)
        delete pLocationDataView;


    
    delete ui;
}



void MainWindow::StartUpdated()
{
    
}

void MainWindow::StopUpdated()
{
   
}


void MainWindow::RequestUpdated()
{
    
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



