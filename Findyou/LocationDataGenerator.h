#pragma once
#include <qthread.h>
#include <memory>
#include<QGeoPositionInfo>
#include<QGeoPositionInfoSource>
#include <QObject>


//pre define
struct ST_LocationData;
//-------
class LocationDataGenerator :
    public QThread
{
    Q_OBJECT
public:
    LocationDataGenerator();
    virtual ~LocationDataGenerator();
    virtual void run()override;

    void WaitToQuit();
public slots:
    void OnPositionUpdated(const QGeoPositionInfo& info);

signals:
    void OnLocationDataUpdated(const ST_LocationData& data);
private:
    std::shared_ptr<QGeoPositionInfoSource> pQGeoPositionInfoSource = nullptr;
    bool IsRunning = true;
};

