#ifndef LOCATIONDATAVIEW_H
#define LOCATIONDATAVIEW_H
#include "ui_LocationDataView.h"
#include <QWidget>
#include <QObject>
#include <memory>

QT_BEGIN_NAMESPACE

namespace Ui
{
    class LocationDataView;
}
QT_END_NAMESPACE

class LocationDataGenerator;
struct ST_LocationData;

class LocationDataView:public QWidget
{
    Q_OBJECT
public:
    LocationDataView(QWidget *parent=nullptr);
    ~LocationDataView();
    void InsertData();


public slots:
    void LocationDataView::OnLocationCome(const ST_LocationData& data);
    
private:
    Ui::LocationDataView *ui;
    std::shared_ptr<LocationDataGenerator> m_pLocationDataGenerator;
};


#endif // LOCATIONDATAVIEW_H
