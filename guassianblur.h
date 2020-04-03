#ifndef GUASSIANBLUR_H
#define GUASSIANBLUR_H

#include <QQuickItem>
#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include <QImage>
#include "linearfilter.h"

class GuassianBlur : public LinearFilter
{
    Q_OBJECT

public:
    GuassianBlur(QObject* parent = nullptr);
    QImage transform(const QImage& im);
    bool validateParameters();
};

#endif // GUASSIANBLUR_H
