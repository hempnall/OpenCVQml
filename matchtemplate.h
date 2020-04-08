#ifndef MATCHTEMPLATE_H
#define MATCHTEMPLATE_H

#include <QQuickItem>
#include <QImage>
#include "opencv2/imgproc/imgproc.hpp"
#include "region.h"

class MatchTemplate : public QQuickItem
{
    Q_OBJECT
    Q_PROPERTY(QImage image READ image WRITE setImage  NOTIFY imageChanged)
    Q_PROPERTY(QImage matchTemplate READ matchTemplate WRITE setMatchTemplate  NOTIFY matchTemplateChanged)
    Q_PROPERTY(QImage gsimage READ gsimage  NOTIFY gsimageChanged)
    Q_PROPERTY(QImage gsmatchTemplate READ gsmatchTemplate  NOTIFY gsmatchTemplateChanged)
    Q_PROPERTY(double threshold1 WRITE setThreshold1 READ threshold1  NOTIFY threshold1Changed)
    Q_PROPERTY(double threshold2 WRITE setThreshold2 READ threshold2  NOTIFY threshold2Changed)
    Q_PROPERTY(Region* region READ region NOTIFY regionChanged)

public:
    MatchTemplate(QObject* parent = nullptr);

    QImage image() const;
    void setImage(const QImage &image);

    QImage matchTemplate() const;
    void setMatchTemplate(const QImage &matchTemplate);

    QImage gsimage() const;
    QImage gsmatchTemplate() const;

    double threshold1() const;
    void setThreshold1(double threshold1);

    double threshold2() const;
    void setThreshold2(double threshold2);
    Region* region();

signals:
    void imageChanged();
    void matchTemplateChanged();
    void gsimageChanged();
    void gsmatchTemplateChanged();
    void threshold1Changed();
    void threshold2Changed();
    void regionChanged();

public slots:
    void match();
    void matchScale();

private:
    QImage image_;
    QImage matchTemplate_;
    cv::Mat gsimage_;
    cv::Mat gsmatchTemplate_;
    double threshold1_;
    double threshold2_;
    Region * region_;
    void getCannyImage(const cv::Mat& in,cv::Mat& out);
    void performTemplateMatch(
        const cv::Mat& image,
        const cv::Mat& tmplt
    );
    double matchInternal(
        const  cv::Mat&  gsImage,
        const cv::Mat& gsTemplate,
        cv::Point& matchLoc);
};



#endif // MATCHTEMPLATE_H
