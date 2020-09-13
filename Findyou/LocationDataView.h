#ifndef LOCATIONDATAVIEW_H
#define LOCATIONDATAVIEW_H
#include "ui_location_data_view.h"
#include <QWidget>
#include <QObject>

QT_BEGIN_NAMESPACE

namespace Ui
{
    class LocationDataView;
}
QT_END_NAMESPACE

class LocationDataView:public QWidget
{
    Q_OBJECT
public:
    LocationDataView(QWidget *parent=nullptr);
    ~LocationDataView();
    void InsertData();


public slots:
private:
Ui::LocationDataView *ui;
};


#endif // LOCATIONDATAVIEW_H
