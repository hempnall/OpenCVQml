#ifndef REGION_H
#define REGION_H

#include <QQuickItem>

class Region : public QQuickItem
{
    Q_OBJECT
    Q_PROPERTY(QRect region READ region WRITE setRegion NOTIFY regionChanged)

public:
    Region();

    QRect region() const;
    void setRegion(const QRect &region);

signals:
    void regionChanged();

public slots:

private:
    QRect region_;
};

#endif // REGION_H
