#ifndef LINEARFILTER_H
#define LINEARFILTER_H

#include <QQuickItem>
#include "opencv2/imgproc/imgproc.hpp"
#include <QImage>

class LinearFilter : public QQuickItem
{
    Q_OBJECT

public:
    LinearFilter(QObject* parent = nullptr) ;
    virtual QImage transform(const QImage& input) = 0;

protected:
    static cv::Mat matFromQimage(const QImage& im);
    static QImage qimageFromMat( const cv::Mat& m);

signals:
    void sourceChanged();
    void imageChanged(const QImage&);

};

#endif // LINEARFILTER_H
