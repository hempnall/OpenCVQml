#include "blur.h"
#include "ImageUtilities.h"

Blur::Blur(QObject* parent): LinearFilter(parent)
{

}


bool Blur::validateParameters()
{
    return size_.width() > 0 && size_.height() > 0 ;
}

QImage Blur::transform(const QImage &input)
{
    cv::Mat in = matFromQimage(input);
    cv::Mat out;
    cv::blur( in,out,cv::Size(size_.width(),size_.width()));
    incrementTransformCount();
    return qimageFromMat(out);
}


