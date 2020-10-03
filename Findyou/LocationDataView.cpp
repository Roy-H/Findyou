#include "LocationDataView.h"
#include <QThread>
#include <LocationDataGenerator.h>
#include "StructData.h"

LocationDataView::LocationDataView(QWidget* parent):QWidget(parent), ui(new Ui::LocationDataView)
{
    ui->setupUi(this);
    m_pLocationDataGenerator = std::make_shared<LocationDataGenerator>();
    connect(m_pLocationDataGenerator.get(),SIGNAL(OnLocationDataUpdated(const ST_LocationData &)),this,SLOT(OnLocationCome(const ST_LocationData &)));
    m_pLocationDataGenerator->start();
    connect(ui->LocaDataView_CloseBtn,SIGNAL(clicked()),this,SLOT(close()));

    ui->LocationTableView->setColumnCount(3);
    ui->LocationTableView->setAlternatingRowColors(true);
    
}

LocationDataView::~LocationDataView()
{
    if (m_pLocationDataGenerator)
    {       
        m_pLocationDataGenerator->WaitToQuit();
    }
}

void LocationDataView::OnLocationCome(const ST_LocationData& data)
{
    ui->LocationTableView->insertRow(0);
    ui->LocationTableView->item(0, 0)->setData(Qt::NoTextInteraction, data.lat);
    ui->LocationTableView->item(0, 1)->setData(Qt::NoTextInteraction, data.lon);
    ui->LocationTableView->item(0, 2)->setData(Qt::NoTextInteraction, data.alt);

    if (ui->LocationTableView->rowCount() > 300)
    {
        ui->LocationTableView->removeRow(300);
    }
}

void LocationDataView::InsertData()
{}




