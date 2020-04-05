#ifndef MATCHTEMPLATE_H
#define MATCHTEMPLATE_H

#include <QQuickItem>
#include <QImage>

class MatchTemplate : public QQuickItem
{
    Q_OBJECT
    Q_PROPERTY(QImage image READ image WRITE setImage  NOTIFY imageChanged)
    Q_PROPERTY(QImage matchTemplate READ matchTemplate WRITE setMatchTemplate  NOTIFY matchTemplateChanged)

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

private:
    QImage image_;
    QImage matchTemplate_;
};



#endif // MATCHTEMPLATE_H
