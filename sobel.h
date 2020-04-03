#ifndef SOBEL_H
#define SOBEL_H

#include "linearfilter.h"

class Sobel : public LinearFilter
{
    Q_OBJECT
    Q_PROPERTY(int ddepth READ ddepth WRITE setDDepth  NOTIFY ddepthChanged)
    Q_PROPERTY(int dx READ dx WRITE setDx  NOTIFY dxChanged)
    Q_PROPERTY(int dy READ dy WRITE setDy  NOTIFY dyChanged)
    Q_PROPERTY(int ksize READ ksize WRITE setKSize  NOTIFY ksizeChanged)
    Q_PROPERTY(double scale READ scale WRITE setScale  NOTIFY scaleChanged)
    Q_PROPERTY(double delta READ delta WRITE setDelta  NOTIFY deltaChanged)
    Q_PROPERTY(double borderType READ borderType WRITE setBorderType  NOTIFY borderTypeChanged)

public:
    Sobel();

    int ddepth() const;
    void setDDepth(int ddepth);

    int dx() const;
    void setDx(int dx);

    int dy() const;
    void setDy(int dy);

    int ksize() const;
    void setKSize(int ksize);

    double scale() const;
    void setScale(double scale);

    double delta() const;
    void setDelta(double delta);

    int borderType() const;
    void setBorderType(int borderType);

    bool validateParameters() override;
    QImage transform(const QImage &input) override;

signals:
    void ddepthChanged();
    void dxChanged();
    void dyChanged();
    void ksizeChanged();
    void scaleChanged();
    void deltaChanged();
    void borderTypeChanged();

private:
    int 	ddepth_;
    int 	dx_;
    int 	dy_;
    int 	ksize_;
    double 	scale_;
    double 	delta_;
    int 	borderType_;

};

#endif // SOBEL_H
