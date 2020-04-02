#include "linearfilter.h"
#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include <QDebug>
#include "opencv2/imgproc/types_c.h"

LinearFilter::LinearFilter(QObject* parent)
{

}



cv::Mat LinearFilter::matFromQimage(const QImage &im)
{
    return cv::Mat(
        im.height(),
        im.width(),
        CV_8UC3,
        const_cast<unsigned char*>(im.bits()),
        im.bytesPerLine()
    );
}

QImage LinearFilter::qimageFromMat(const cv::Mat &mat)
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





