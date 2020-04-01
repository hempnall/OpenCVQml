#include "mat.h"

Mat::Mat()
{

}


void Mat::paint(QPainter *painter)
{
    QRectF rect = boundingRect();
    painter->drawImage(rect,image());
}
