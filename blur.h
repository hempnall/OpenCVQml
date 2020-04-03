#ifndef BLUR_H
#define BLUR_H

#include <QQuickItem>
#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include <QImage>
#include "linearfilter.h"

class Blur : public LinearFilter
{
    Q_OBJECT

public:
    Blur(QObject* parent = nullptr);
    QImage transform(const QImage& im);
    virtual bool validateParameters();
};

#endif // BLUR_H
