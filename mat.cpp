#include "mat.h"
#include <QDebug>

Mat::Mat()
    : filter_(nullptr), cacheValid_(false)
{

}

void Mat::paint(QPainter *painter)
{
    QRectF rect = boundingRect();
    painter->drawImage(rect, image());
}

LinearFilter *Mat::filter() const
{
    return filter_;
}

void Mat::setFilter(LinearFilter *filter)
{
    if (! (filter == nullptr)) {
       QObject::connect(filter,SIGNAL(redraw()),this,SLOT(invalidateImage()));
       filter_ = filter;
    }

}

QImage Mat::image() const
{
    if (filter_ == nullptr)    {
        return image_;
    } else {
        if (!cacheValid_) {
            if (filter_->validateParameters()) {
                cachedTransformedImage_ = filter_->transform(image_);
                cacheValid_ = true;
            } else {
                cachedTransformedImage_ = image_;
            }
        }
        return cachedTransformedImage_;
    }
}

void Mat::setImage(const QImage &image)
{
    image_ = image;
    cacheValid_ = false;
    update();
    emit imageChanged();
}



QString Mat::filename() const
{
    return filename_;
}

void Mat::setFilename(const QString &filename)
{
    if ( filename != filename_ )  {
        filename_ = filename;
        std::string str = filename_.toStdString();
        const char* p = str.c_str();
        mat_ = cv::imread( p );
        setImage(mat_);
        emit filenameChanged();
    }
}

void Mat::setImage(const cv::Mat &mat)
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

void Mat::invalidateImage()
{
    cacheValid_ = false;
    update();
    emit imageChanged();
}

cv::Mat Mat::matrix() const
{
    return cv::Mat(
        image_.height(),
        image_.width(),
        CV_8UC3,
        const_cast<unsigned char*>(image_.bits()),
        image_.bytesPerLine()
    );
}
