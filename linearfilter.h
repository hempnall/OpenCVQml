#ifndef LINEARFILTER_H
#define LINEARFILTER_H

#include <QQuickItem>
#include "mat.h"



class LinearFilter : public ImageBase
{
    Q_OBJECT
    Q_PROPERTY(Mat* source WRITE setSource READ source NOTIFY sourceChanged)

public:
    LinearFilter();

    Mat *source() const;
    void setSource(Mat *source);

    QImage image() const;
    void paint(QPainter *painter);

private slots:
    void updateSource();

signals:
    void sourceChanged();
    void imageChanged(const QImage&);

private:

    Mat* source_;

};

#endif // LINEARFILTER_H
