#include "guassianblur.h"
#include "ImageUtilities.h"
#include <opencv2/core/base.hpp>

GuassianBlur::GuassianBlur(QObject* parent): LinearFilter(parent)
{

}


bool GuassianBlur::validateParameters()
{
    return size_.width() > 0 && size_.height() > 0 ;
}


QImage GuassianBlur::transform(const QImage &input)
{
    auto makeOdd =  [](uint64_t num) {
        return num + ( !( num % 2 ) ? 1 : 0 );
    };
    cv::Mat in = matFromQimage(input);
    cv::Mat out;
    cv::GaussianBlur(
        in,
        out,
        cv::Size( makeOdd(size_.width()),makeOdd(size_.height())),
        0,
        0,
        cv::BorderTypes::BORDER_DEFAULT);
    incrementTransformCount();
    return qimageFromMat(out);
}


