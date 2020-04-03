#include "linearfilter.h"
#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include <QDebug>


LinearFilter::LinearFilter(QObject* parent)
    : transformCount_(0)
{

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







