#ifndef IMAGEBASE_H
#define IMAGEBASE_H


#include <QQuickPaintedItem>
#include <QImage>
#include <QPainter>
#include <opencv2/imgcodecs.hpp>
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/imgproc/types_c.h"
#include <opencv2/core/cvstd.hpp>

#define CONNECT_IMAGEBASE_SIGNALS \
    QObject::connect(this,SIGNAL(baseImageChanged()),this,SLOT(update()));

class ImageBase
  : public QQuickPaintedItem
{
    Q_OBJECT
    Q_PROPERTY(QImage image READ image NOTIFY baseImageChanged)

    QImage image_;
    QString filename_;
    cv::Mat mat_;

public:
    ImageBase();
    virtual void paint(QPainter *painter)=0;

    QString filename() const;
    void setFilename(const QString &filename);

    QImage image() const;
    void setImage(const QImage &image);
    void setImage(const cv::Mat &mat);
   // cv::Mat matrix() const;


signals:
    void baseImageChanged();

};

#endif // IMAGEBASE_H
