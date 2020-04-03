#include "convert.h"
#include "ImageUtilities.h"
#include "opencv2/imgproc/types_c.h"

Convert::Convert(QObject* parent): LinearFilter(parent)
{

}



bool Convert::validateParameters()
{
    return true ;
}

QImage Convert::transform(const QImage &input)
{
    cv::Mat in = matFromQimage(input);
    cv::Mat out1;
    cv::Mat out2;
    cv::cvtColor(in,out1,cv::COLOR_BGR2GRAY);
    cv::cvtColor(out1,out2,cv::COLOR_GRAY2BGR);
    incrementTransformCount();
    return qimageFromMat(out2);
}

