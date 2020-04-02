#ifndef BLUR_H
#define BLUR_H

#include <QQuickItem>
#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "linearfilter.h"

class Blur : public LinearFilter
{
    Q_OBJECT
    Q_PROPERTY(int width READ width WRITE setWidth NOTIFY widthChanged)
    Q_PROPERTY(int height READ height WRITE setHeight NOTIFY heightChanged)

public:
    Blur(QObject* parent = nullptr);
    QImage transform(const QImage& im);

    int width() const;
    void setWidth(const int &width);

    int height() const;
    void setHeight(const int &height);

public slots:
    void heightChanged();
    void widthChanged();

private:
    int width_;
    int height_;
};

#endif // BLUR_H
