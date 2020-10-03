#include "LocationDataGenerator.h"
#include "StructData.h"
#include <QDatetime>
LocationDataGenerator::LocationDataGenerator()
{
    pQGeoPositionInfoSource.reset(QGeoPositionInfoSource::createDefaultSource(0));
    if (pQGeoPositionInfoSource)
    {
        pQGeoPositionInfoSource->setUpdateInterval(1000);

        connect(pQGeoPositionInfoSource.get(), SIGNAL(positionUpdated(const QGeoPositionInfo&)), this, SLOT(OnPositionUpdated(const QGeoPositionInfo&)));        
    }
}

LocationDataGenerator::~LocationDataGenerator()
{
}

void LocationDataGenerator::OnPositionUpdated(const QGeoPositionInfo& info)
{
    //ui->location_info->setText(info.coordinate().toString());
    ST_LocationData data;
    data.lat = info.coordinate().latitude();
    data.lon = info.coordinate().longitude();
    data.alt = info.coordinate().altitude();
    auto time = QDateTime::currentDateTime();
    data.year = time.date().year();
    data.month = time.date().month();
    data.day = time.date().day();
    data.hour = time.time().hour();
    data.min = time.time().minute();
    data.sec = time.time().second();
    emit OnLocationDataUpdated(data);
}
void LocationDataGenerator::run()
{
    while (IsRunning)
    {
        if (pQGeoPositionInfoSource)
        {
            pQGeoPositionInfoSource->requestUpdate();
        }
        msleep(10);
    }
}
void LocationDataGenerator::WaitToQuit()
{
    IsRunning = false;
    this->wait();
    this->quit();
}
