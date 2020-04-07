#include "region.h"
#include <QPainter>

Region::Region()
{

}

void Region::paint(
    QPainter *painter,
    const QImage &im,
    const QRectF &boundRect)
{
    painter->setPen(Qt::red);
    painter->drawRect(
        scaledRectangle(
            im,
            region() ,
            boundRect
    ));
}

QRect Region::region() const
{
    return region_;
}

void Region::setRegion(const QRect &region)
{
    region_ = region;
}


QRectF Region::scaledRectangle(
    const QImage& im,
    const QRect &rect,
    const QRectF &boundRect
)
{
    float widthScale = boundRect.width() / im.width();
    float heightScale = boundRect.height() / im.height();
    QRectF ret(
        rect.x() * widthScale ,
        rect.y() * heightScale,
        rect.width() * widthScale,
        rect.height() * heightScale
    );
    return ret;
}
