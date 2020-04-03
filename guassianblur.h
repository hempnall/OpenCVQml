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
    Q_PROPERTY(QRect size READ size WRITE setSize NOTIFY sizeChanged)
    Q_PROPERTY(int width READ width WRITE setWidth NOTIFY widthChanged)
    Q_PROPERTY(int height READ height WRITE setHeight NOTIFY heightChanged)


public:
    GuassianBlur(QObject* parent = nullptr);
    QImage transform(const QImage& im);

    int width() const;
    void setWidth(const int &width);

    int height() const;
    void setHeight(const int &height);

    QRect size() const;
    void setSize(const QRect &size);

signals:
    void heightChanged();
    void widthChanged();
    void sizeChanged();


private:
    int width_;
    int height_;
    QRect size_;
};

#endif // GUASSIANBLUR_H
