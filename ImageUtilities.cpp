#include "ImageUtilities.h"
#include "opencv2/imgproc/types_c.h"

cv::Mat matFromQimage(const QImage &im)
{
    cv::Mat outRGB;
    cv::Mat out(
        im.height(),
        im.width(),
        CV_8UC3,
        const_cast<unsigned char*>(im.bits()),
        im.bytesPerLine()
    );
    cv::cvtColor(out,outRGB,CV_RGB2BGR);
    return outRGB;
}

QImage qimageFromMat(const cv::Mat &mat)
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
    return img;
}

cv::Mat grayScaleMatFromQimage(const QImage& im)
{
    cv::Mat outRGB;
    cv::Mat out(
        im.height(),
        im.width(),
        CV_8UC3,
        const_cast<unsigned char*>(im.bits()),
        im.bytesPerLine()
    );
    cv::cvtColor(out,outRGB,CV_RGB2GRAY);
    return outRGB;
}

QSize qsizeFromCVSize(const cv::Size &sz)
{
    return QSize(sz.width,sz.height);
}

QPoint qpointFromCVPoint(const cv::Point &pt)
{
    return QPoint( pt.x , pt.y);
}
