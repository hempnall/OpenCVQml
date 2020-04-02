#ifndef IMAGEUTILITIES_H
#define IMAGEUTILITIES_H

#include "opencv2/imgproc/imgproc.hpp"
#include <QImage>

cv::Mat matFromQimage(const QImage& im);
QImage qimageFromMat( const cv::Mat& m);

#endif // IMAGEUTILITIES_H