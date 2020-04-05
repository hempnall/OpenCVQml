#include "matchtemplate.h"

MatchTemplate::MatchTemplate()
{

}

QImage MatchTemplate::image() const
{
    return image_;
}

void MatchTemplate::setImage(const QImage &image)
{
    image_ = image;
}

QImage MatchTemplate::matchTemplate() const
{
    return matchTemplate_;
}

void MatchTemplate::setMatchTemplate(const QImage &matchTemplate)
{
    matchTemplate_ = matchTemplate;
}


void MatchTemplate::match()
{

}
