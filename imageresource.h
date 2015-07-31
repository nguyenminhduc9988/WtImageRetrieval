#ifndef IMAGERESOURCE_H
#define IMAGERESOURCE_H
#include <Wt/WApplication>
#include <Wt/WResource>

using namespace Wt;
using namespace std;

class ImageResource : public WResource
{
public:
    ImageResource();
    virtual void handleRequest(const Http::Request &request, Http::Response &response);
    virtual void queryExpansion();
    ~ImageResource();
};

#endif // IMAGERESOURCE_H
