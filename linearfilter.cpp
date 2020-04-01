#include "linearfilter.h"
#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include <QDebug>


LinearFilter::LinearFilter()
{

}

Mat *LinearFilter::source() const
{
    return source_;
}

void LinearFilter::setSource(Mat *source)
{
    source_ = source;
    setImage(source->image());
    QObject::connect(source_,SIGNAL(baseImageChanged()),this,SLOT(transform()));
}



void LinearFilter::paint(QPainter *painter)
{
    QRectF rect = boundingRect();
    painter->drawImage(rect,ImageBase::image());
}


void LinearFilter::transform()
{
    cv::Mat input = source_->matrix();
    cv::Mat output;
    cv::blur( input,output,cv::Size(15,15));

    setImage(output);
    update();
}




