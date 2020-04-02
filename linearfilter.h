#ifndef LINEARFILTER_H
#define LINEARFILTER_H

#include <QQuickItem>

class LinearFilter : public QQuickItem
{
    Q_OBJECT

public:
    LinearFilter(QObject* parent = nullptr) ;
    virtual QImage transform(const QImage& input) = 0;

protected:


signals:
    void sourceChanged();
    void imageChanged(const QImage&);

};

#endif // LINEARFILTER_H
