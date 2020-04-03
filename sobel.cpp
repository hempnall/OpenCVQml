#include "sobel.h"
#include "ImageUtilities.h"

Sobel::Sobel()
    : ksize_(3),scale_(1),delta_(0),borderType_(cv::BORDER_DEFAULT),ddepth_(-1)
{

}

int Sobel::ddepth() const
{
    return ddepth_;
}

void Sobel::setDDepth(int ddepth)
{
    ddepth_ = ddepth;
}

int Sobel::dx() const
{
    return dx_;
}

void Sobel::setDx(int dx)
{
    dx_ = dx;
}

int Sobel::dy() const
{
    return dy_;
}

void Sobel::setDy(int dy)
{
    dy_ = dy;
}

int Sobel::ksize() const
{
    return ksize_;
}

void Sobel::setKSize(int ksize)
{
    ksize_ = ksize;
}

double Sobel::scale() const
{
    return scale_;
}

void Sobel::setScale(double scale)
{
    scale_ = scale;
}

double Sobel::delta() const
{
    return delta_;
}

void Sobel::setDelta(double delta)
{
    delta_ = delta;
}

int Sobel::borderType() const
{
    return borderType_;
}

void Sobel::setBorderType(int borderType)
{
    borderType_ = borderType;
}

bool Sobel::validateParameters()
{
    return true;
}


QImage Sobel::transform(const QImage &input)
{
    cv::Mat in = matFromQimage(input);
    cv::Mat out;
    cv::Sobel(
        in,
        out,
        ddepth_,
        dx_,
        dy_,
        ksize_,
        scale_,
        delta_,
        borderType_
    );
    incrementTransformCount();
    return qimageFromMat(out);
}
