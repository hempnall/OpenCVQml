#ifndef LINEARFILTER_H
#define LINEARFILTER_H

#include <QQuickItem>

class LinearFilter : public QQuickItem
{
    Q_OBJECT
    Q_PROPERTY(int transformCount READ transformCount  NOTIFY transformCountChanged)
    Q_PROPERTY(QSize size READ size WRITE setSize NOTIFY sizeChanged)
    Q_PROPERTY(int height READ height WRITE setHeight  NOTIFY heightChanged)
    Q_PROPERTY(int width READ width WRITE setWidth  NOTIFY widthChanged)

public:
    LinearFilter(QObject* parent = nullptr) ;
    virtual QImage transform(const QImage& input) = 0;

    int transformCount() const;
    void setTransformCount(int transformCount);
    virtual bool validateParameters() =0;

    int width() const;
    void setWidth(const int &width);

    int height() const;
    void setHeight(const int &height);

    QSize size() const;
    void setSize(const QSize &size);


protected:
    void incrementTransformCount();
    int width_;
    int height_;
    QSize size_;

signals:
    void sourceChanged();
    void imageChanged(const QImage&);
    void redraw();
    void transformCountChanged();
    void heightChanged();
    void widthChanged();
    void sizeChanged();

private:
    int transformCount_;

};

#endif // LINEARFILTER_H
