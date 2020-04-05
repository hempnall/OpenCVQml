#include "matchtemplate.h"
#include "ImageUtilities.h"

MatchTemplate::MatchTemplate()
    : threshold1_(50),threshold2_(200)
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

void MatchTemplate::matchScale()
{
    cv::Mat grayImage = grayScaleMatFromQimage(image_);
    cv::Mat grayEdgeImage;
    cv::Canny(
        grayImage,
        grayEdgeImage,
        threshold1_,
        threshold2_
    );

    int templateWidth = matchTemplate_.width();
    int templateHeight = matchTemplate_.height();
    cv::Mat grayTemplate = grayScaleMatFromQimage(image_);
    cv::Mat grayEdgeTemplate;
    cv::Canny(
        grayTemplate,
        grayEdgeTemplate ,
        threshold1_,
        threshold2_
    );

    for (int i=0;i<20;++i) {
        float scale = 0.2 + (1.0 - 0.2) * ( i / 20  );
        cv::Mat resized
        cv::resize(grayEdgeImage,resized,grayEdgeImage.cols * scale);
        if ( resized.cols < templateWidth || resized.rows < templateHeight) {
            break;
        }
        cv::Mat result;
        cv::matchTemplate(resized,grayEdgeTemplate,result,cv::TM_CCOEFF);

    }
    cv::Mat result
    cv::resize(outImg, outImg, cv::Size(inImg.cols * 0.75,inImg.rows * 0.75), 0, 0, CV_INTER_LINEAR);

}

double MatchTemplate::threshold2() const
{
    return threshold2_;
}

void MatchTemplate::setThreshold2(double threshold2)
{
    threshold2_ = threshold2;
}

double MatchTemplate::threshold1() const
{
    return threshold1_;
}

void MatchTemplate::setThreshold1(double threshold1)
{
    threshold1_ = threshold1;
}

void MatchTemplate::performTemplateMatch(
const cv::Mat &image,
const cv::Mat &tmplt
)
    {

}
