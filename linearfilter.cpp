#include "linearfilter.h"
#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include <QDebug>


LinearFilter::LinearFilter(QObject* parent)
    : transformCount_(0)
{

}


int LinearFilter::width() const
{
    return width_;
}

void LinearFilter::setWidth(const int &width)
{
    QSize newRect = size_;
    newRect.setWidth( width );
    setSize(newRect);
}

int LinearFilter::height() const
{
    return height_;
}

void LinearFilter::setHeight(const int &height)
{
    QSize newRect = size_;
    newRect.setHeight( height );
    setSize(newRect);
}

QSize LinearFilter::size() const
{
    return size_;
}

void LinearFilter::setSize(const QSize &size)
{
    if (! (size == size_)) {
        size_ = size;
        emit redraw();
    }
}


void LinearFilter::incrementTransformCount()
{
    transformCount_++;
    emit transformCountChanged();
}



int LinearFilter::transformCount() const
{
    return transformCount_;
}

void LinearFilter::setTransformCount(int transformCount)
{
    transformCount_ = transformCount;
}







