#include "LocationDataView.h"


LocationDataView::LocationDataView(QWidget* parent):QWidget(parent), ui(new Ui::LocationDataView)
{
    ui->setupUi(this);

    connect(ui->LocaDataView_CloseBtn,SIGNAL(clicked()),this,SLOT(close()));
}

LocationDataView::~LocationDataView()
{}

void LocationDataView::InsertData()
{}




