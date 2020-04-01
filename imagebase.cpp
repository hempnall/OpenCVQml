#include "imagebase.h"
#include <QDebug>


ImageBase::ImageBase()
{

}


QString ImageBase::filename() const
{
    return filename_;
}

void ImageBase::setFilename(const QString &filename)
{
    if ( filename != filename_ )  {
        filename_ = filename;
        std::string str = filename_.toStdString();
        const char* p = str.c_str();
        mat_ = cv::imread( p );
        setImage(mat_);
        update();
    }
}

QImage ImageBase::image() const
{
    return image_;
}

void ImageBase::setImage(const QImage &image)
{
    image_ = image;
    emit baseImageChanged();
    update();
}

void ImageBase::setImage(const cv::Mat &mat)
{
   cv::Mat rgbMat;
   QImage img;
   if (mat.channels() == 1) {
     img =  QImage(
        (uchar*)mat.data,
        mat.cols,
        mat.rows,
        (int)mat.step,
        QImage::Format_Indexed8
     ).copy();
   } else if (mat.channels() == 3) {
     cv::cvtColor(mat, rgbMat, CV_BGR2RGB);
     img =  QImage(
        (uchar*)rgbMat.data,
        mat.cols,
        mat.rows,
        (int)mat.step,
        QImage::Format_RGB888
     ).copy();
   }
   setImage(img);
}

cv::Mat ImageBase::matrix() const
{
    return cv::Mat(
        image_.height(),
        image_.width(),
        CV_8UC3,
        const_cast<unsigned char*>(image_.bits()),
        image_.bytesPerLine()
    );
}
