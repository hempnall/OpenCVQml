#include "blur.h"


Blur::Blur(QObject* parent): LinearFilter(parent)
{

}


int Blur::width() const
{
    return width_;
}

void Blur::setWidth(const int &width)
{
    width_ = width;
}

int Blur::height() const
{
    return height_;
}

void Blur::setHeight(const int &height)
{
    height_ = height;
}

void Blur::heightChanged()
{

}

void Blur::widthChanged()
{

}

QImage Blur::transform(const QImage &input)
{
    cv::Mat in = matFromQimage(input);
    cv::Mat out;
    cv::blur( in,out,cv::Size(width_,height_));
    return qimageFromMat(out);
}


