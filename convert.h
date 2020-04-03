#ifndef CONVERT_H
#define CONVERT_H

#include <QObject>
#include  "linearfilter.h"

class Convert : public LinearFilter
{
    Q_OBJECT

public:
    Convert(QObject* parent = nullptr);
    QImage transform(const QImage& im);
    virtual bool validateParameters();
};

#endif // CONVERT_H
