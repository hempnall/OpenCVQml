#ifndef MAT_H
#define MAT_H

#include <QQuickPaintedItem>
#include <QImage>
#include <QPainter>
#include <opencv2/imgcodecs.hpp>
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/imgproc/types_c.h"
#include <opencv2/core/cvstd.hpp>
#include "linearfilter.h"
#include "region.h"

class Mat :
    public QQuickPaintedItem
{
    Q_OBJECT
    Q_PROPERTY(QString filename READ filename WRITE setFilename NOTIFY filenameChanged)
    Q_PROPERTY(QImage image READ image WRITE setImage  NOTIFY imageChanged)
    Q_PROPERTY(LinearFilter* filter WRITE setFilter READ filter NOTIFY filterChanged)
    Q_PROPERTY(QQmlListProperty<Region> regions READ regions)
    Q_PROPERTY(Region* region WRITE setRegion READ region NOTIFY regionChanged)


    QImage image_;
    mutable QImage cachedTransformedImage_;
    QString filename_;
    cv::Mat mat_;
    LinearFilter *filter_;
    mutable bool cacheValid_;

public:
    Mat();
    void paint(QPainter *painter);

    LinearFilter *filter() const;
    void setFilter(LinearFilter *filter);

    cv::Mat matrix() const;

    QString filename() const;
    void setFilename(const QString &filename);

    QImage image() const;
    void setImage(const QImage &image);
    void setImage(const cv::Mat &mat);

    QQmlListProperty<Region> regions();

    Region *region() const;
    void setRegion(Region *region);

public slots:
    void invalidateImage();

signals:
    void baseImageChanged();
    void imageChanged();
    void filterChanged();
    void filenameChanged();
    void regionChanged();

private:
    Region* region_;
    QList<Region *> regions_;
    static void append_region(QQmlListProperty<Region> *list, Region *reg);

};

#endif // MAT_H
