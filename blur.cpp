#include "blur.h"
#include "ImageUtilities.h"

Blur::Blur(QObject* parent): LinearFilter(parent)
{

}


int Blur::width() const
{
    return width_;
}

void Blur::setWidth(const int &width)
{
    QRect newRect = size_;
    newRect.setWidth( width );
    setSize(newRect);
}

int Blur::height() const
{
    return height_;
}

void Blur::setHeight(const int &height)
{
    QRect newRect = size_;
    newRect.setHeight( height );
    setSize(newRect);
}

QRect Blur::size() const
{
    return size_;
}

void Blur::setSize(const QRect &size)
{
    if (! (size == size_)) {
        size_ = size;
        emit redraw();
    }
}



QImage Blur::transform(const QImage &input)
{
    if (size_.width() == 0 || size_.height() == 0) {
        return input;
    }
    cv::Mat in = matFromQimage(input);
    cv::Mat out;
    cv::blur( in,out,cv::Size(size_.width(),size_.width()));
    incrementTransformCount();
    return qimageFromMat(out);
}


