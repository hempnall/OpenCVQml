#ifndef REGION_H
#define REGION_H

#include <QQuickItem>
#include <QImage>

class Region : public QQuickItem
{
    Q_OBJECT
    Q_PROPERTY(QRect region READ region WRITE setRegion NOTIFY regionChanged)

public:
    Region();
    void paint(QPainter *painter,const QImage& im,const QRectF& boundRect);
    QRect region() const;
    void setRegion(const QRect &region);

signals:
    void regionChanged();

public slots:

private:
    QRect region_;
    QRectF scaledRectangle(const QImage& im, const QRect& rect,const QRectF& boundRect);
};

#endif // REGION_H
