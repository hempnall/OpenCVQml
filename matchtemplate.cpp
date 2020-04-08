#include "matchtemplate.h"
#include "ImageUtilities.h"
#include <QDebug>

MatchTemplate::MatchTemplate(QObject* parent)
    :    threshold1_(50),threshold2_(200), region_(nullptr)
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

QImage MatchTemplate::gsimage() const
{
    if (gsimage_.empty()) return QImage();
    cv::Mat out;
    cv::cvtColor(gsimage_,out,cv::COLOR_GRAY2BGR);
    return qimageFromMat(out);
}

QImage MatchTemplate::gsmatchTemplate() const
{
    if (gsmatchTemplate_.empty()) return QImage();
    cv::Mat out;
    cv::cvtColor(gsmatchTemplate_,out,cv::COLOR_GRAY2BGR);
    return qimageFromMat(out);
}


void MatchTemplate::match()
{
}

void MatchTemplate::matchScale()
{
    cv::Mat grayEdgeImage;
    cv::Mat grayEdgeTemplate;

    getCannyImage(grayScaleMatFromQimage(image_),grayEdgeImage);
    getCannyImage(grayScaleMatFromQimage(matchTemplate_),grayEdgeTemplate);

    gsimage_ = grayEdgeImage;
    gsmatchTemplate_ = grayEdgeTemplate;
    emit gsimageChanged();
    emit gsmatchTemplateChanged();

    double max = -10.0;
    double maxScale = 0.0;
    cv::Point matchLoc;
    cv::Point maxPoint;
    for (int i=0;i<10; ++i) {

        double scale = 0.2 + ( ( 1.2 - 0.2 ) / 10 ) * i;
        cv::Size newSize(
            grayEdgeImage.cols * scale ,
            grayEdgeImage.rows * scale
        );
        cv::Mat scaledImage(newSize,grayEdgeImage.type());
        cv::resize(grayEdgeImage,scaledImage,newSize);
        double scaleMax = matchInternal(scaledImage,grayEdgeTemplate,matchLoc);

        if (scaleMax > max) {
            max = scaleMax;
            maxScale = scale;
            maxPoint = matchLoc;
        }
    }

    region_ = new Region;
    region_->setRegion( QRect( qpointFromCVPoint(matchLoc),QSize(templateWidth,templateHeight) ) );
    emit regionChanged();

}

void MatchTemplate::getCannyImage(const cv::Mat &in,cv::Mat &out)
{
    cv::Canny(
        in,
        out,
        threshold1_,
        threshold2_
    );
}

double MatchTemplate::threshold2() const
{
    return threshold2_;
}

void MatchTemplate::setThreshold2(double threshold2)
{
    threshold2_ = threshold2;
}

Region *MatchTemplate::region()
{
    return region_;
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

double MatchTemplate::matchInternal(
    const cv::Mat &gsImage,
    const cv::Mat &gsTemplate,
    cv::Point& matchLoc
)
{

    cv::Mat result;
    int result_cols =  gsImage.cols - gsTemplate.cols + 1;
    int result_rows = gsImage.rows - gsTemplate.rows + 1;

    if (result_cols < 0 || result_rows < 0 ) {
        return 0.0;
    }

    result.create( result_rows, result_cols, CV_32FC1 );

    int match_method = cv::TM_CCOEFF;
    cv::matchTemplate(gsImage,gsTemplate,result,cv::TM_CCOEFF);
  //  cv::normalize( result, result, 0, 1, cv::NORM_MINMAX, -1, cv::Mat() );

    /// Localizing the best match with minMaxLoc
    double minVal; double maxVal;
    cv::Point minLoc;
    cv::Point maxLoc;

    cv::minMaxLoc( result, &minVal, &maxVal, &minLoc, &maxLoc, cv::Mat() );
    if( match_method  == cv::TM_SQDIFF || match_method == cv::TM_SQDIFF_NORMED )
      { matchLoc = minLoc; }
    else
      { matchLoc = maxLoc; }

    return maxVal;
}




