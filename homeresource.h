#ifndef HOMERESOURCE_H
#define HOMERESOURCE_H
#include <Wt/WApplication>
#include <Wt/WResource>

using namespace Wt;
using namespace std;

class HomeResource : public WResource
{
public:
    HomeResource();
    virtual void handleRequest(const Http::Request &request, Http::Response &response);
    ~HomeResource();
};

#endif // HOMERESOURCE_H
