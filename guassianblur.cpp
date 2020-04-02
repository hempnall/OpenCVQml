#include "guassianblur.h"
#include "ImageUtilities.h"
#include <opencv2/core/base.hpp>

GuassianBlur::GuassianBlur(QObject* parent): LinearFilter(parent)
{

}


int GuassianBlur::width() const
{
    return width_;
}

void GuassianBlur::setWidth(const int &width)
{
    QRect newRect = size_;
    newRect.setWidth( width );
    setSize(newRect);
}

int GuassianBlur::height() const
{
    return height_;
}

void GuassianBlur::setHeight(const int &height)
{
    QRect newRect = size_;
    newRect.setHeight( height );
    setSize(newRect);
}

QRect GuassianBlur::size() const
{
    return size_;
}

void GuassianBlur::setSize(const QRect &size)
{
    if (! (size == size_)) {
        size_ = size;
        emit redraw();
    }
}



QImage GuassianBlur::transform(const QImage &input)
{
    if (size_.width() == 0 || size_.height() == 0) {
        return input;
    }
    auto makeOdd =  [](uint64_t num) {
        return num + ( !( num % 2 ) ? 1 : 0 );
    };
    cv::Mat in = matFromQimage(input);
    cv::Mat out;
    cv::GaussianBlur(in,out,cv::Size( makeOdd(size_.width()),makeOdd(size_.height())),0,0,cv::BorderTypes::BORDER_DEFAULT);
    return qimageFromMat(out);
}


