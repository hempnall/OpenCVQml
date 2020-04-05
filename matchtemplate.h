#ifndef MATCHTEMPLATE_H
#define MATCHTEMPLATE_H

#include <QQuickItem>
#include <QImage>
#include "opencv2/imgproc/imgproc.hpp"

class MatchTemplate : public QQuickItem
{
    Q_OBJECT
    Q_PROPERTY(QImage image READ image WRITE setImage  NOTIFY imageChanged)
    Q_PROPERTY(QImage matchTemplate READ matchTemplate WRITE setMatchTemplate  NOTIFY matchTemplateChanged)
    Q_PROPERTY(double threshold1 WRITE setThreshold1 READ threshold1  NOTIFY threshold1Changed)
    Q_PROPERTY(double threshold2 WRITE setThreshold2 READ threshold2  NOTIFY threshold2Changed)

public:
    MatchTemplate();

    QImage image() const;
    void setImage(const QImage &image);

    QImage matchTemplate() const;
    void setMatchTemplate(const QImage &matchTemplate);

signals:
    void imageChanged();
    void matchTemplateChanged();


public slots:
    void match();
    void matchScale();

private:
    QImage image_;
    QImage matchTemplate_;
    double threshold1_;
    double threshold2_;

    void performTemplateMatch(
        const cv::Mat& image,
        const cv::Mat& tmplt
    );
};



#endif // MATCHTEMPLATE_H
