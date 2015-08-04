#ifndef SIMPLEQUERYRESOURCE_H
#define SIMPLEQUERYRESOURCE_H
#include <Wt/WApplication>
#include <Wt/WResource>

using namespace Wt;
using namespace std;

class SimpleQueryResource :  public WResource
{
public:
    SimpleQueryResource();
    virtual void handleRequest(const Http::Request &request, Http::Response &response);
    virtual void queryExpansion();
    ~SimpleQueryResource();
};

#endif // SIMPLEQUERYRESOURCE_H
