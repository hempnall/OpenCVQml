#ifndef CANNY_H
#define CANNY_H

#include <QImage>
#include "linearfilter.h"



class Canny : public LinearFilter
{
    Q_OBJECT
    Q_PROPERTY(double threshold1 WRITE setThreshold1 READ threshold1  NOTIFY threshold1Changed)
    Q_PROPERTY(double threshold2 WRITE setThreshold2 READ threshold2  NOTIFY threshold2Changed)
    Q_PROPERTY(int apertureSize WRITE setApertureSize READ apertureSize  NOTIFY apertureSizeChanged)
    Q_PROPERTY(bool L2Gradient READ L2Gradient WRITE setL2Gradient NOTIFY L2GradientChanged)

public:
    Canny(QObject* parent = nullptr);
    QImage transform(const QImage& im);
    virtual bool validateParameters();

    double threshold1() const;
    void setThreshold1(double threshold1);

    double threshold2() const;
    void setThreshold2(double threshold2);

    int apertureSize() const;
    void setApertureSize(int apertureSize);

    bool L2Gradient() const;
    void setL2Gradient(bool L2Gradient);

signals:
    void threshold1Changed();
    void threshold2Changed();
    void apertureSizeChanged();
    void L2GradientChanged();

private:
    double threshold1_;
    double threshold2_;
    int apertureSize_;
    bool L2Gradient_;
};

#endif // CANNY_H
