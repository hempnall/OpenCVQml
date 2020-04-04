#include "canny.h"
#include "ImageUtilities.h"

Canny::Canny(QObject* parent) : LinearFilter(parent), apertureSize_(3),L2Gradient_(false)
{

}

QImage Canny::transform(const QImage &im)
{
    cv::Mat in = matFromQimage(im);
    cv::Mat out;
    cv::Mat out2;
    cv::Canny(
        in,
        out,
        threshold1_,
        threshold2_,
        apertureSize_,
        L2Gradient_
    );
    cv::cvtColor(out,out2,cv::COLOR_GRAY2BGR);
    incrementTransformCount();
    return qimageFromMat(out2);
}

bool Canny::validateParameters()
{
    return true;
}

double Canny::threshold1() const
{
    return threshold1_;
}

void Canny::setThreshold1(double threshold1)
{
    if (threshold1 != threshold1_) {
        threshold1_ = threshold1;
        emit redraw();
    }
}

double Canny::threshold2() const
{
    return threshold2_;
}

void Canny::setThreshold2(double threshold2)
{
    if (threshold2 != threshold2_) {
        threshold2_ = threshold2;
        emit redraw();
    }
}

int Canny::apertureSize() const
{
    return apertureSize_;
}

void Canny::setApertureSize(int apertureSize)
{
    apertureSize_ = apertureSize;
}

bool Canny::L2Gradient() const
{
    return L2Gradient_;
}

void Canny::setL2Gradient(bool L2Gradient)
{
    L2Gradient_ = L2Gradient;
}
