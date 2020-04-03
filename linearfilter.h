#ifndef LINEARFILTER_H
#define LINEARFILTER_H

#include <QQuickItem>

class LinearFilter : public QQuickItem
{
    Q_OBJECT
    Q_PROPERTY(int transformCount READ transformCount  NOTIFY transformCountChanged)

public:
    LinearFilter(QObject* parent = nullptr) ;
    virtual QImage transform(const QImage& input) = 0;

    int transformCount() const;
    void setTransformCount(int transformCount);

protected:
    void incrementTransformCount();

signals:
    void sourceChanged();
    void imageChanged(const QImage&);
    void redraw();
    void transformCountChanged();

private:
    int transformCount_;
};

#endif // LINEARFILTER_H
