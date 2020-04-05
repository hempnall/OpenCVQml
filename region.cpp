#include "region.h"

Region::Region()
{

}

QRect Region::region() const
{
    return region_;
}

void Region::setRegion(const QRect &region)
{
    region_ = region;
}
