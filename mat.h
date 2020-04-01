#ifndef MAT_H
#define MAT_H

#include <QQuickPaintedItem>
#include <QImage>
#include <QPainter>
#include <opencv2/imgcodecs.hpp>
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/imgproc/types_c.h"
#include <opencv2/core/cvstd.hpp>
#include "imagebase.h"

class Mat :
        public ImageBase
{
    Q_OBJECT
    Q_PROPERTY(QString filename READ filename WRITE setFilename )
    Q_PROPERTY(QImage image READ image WRITE setImage  NOTIFY imageChanged)

public:
    Mat();
    void paint(QPainter *painter);

signals:
    void imageChanged(const QImage& img);
};

#endif // MAT_H
