#include "homeresource.h"

HomeResource::HomeResource()
{

}

void HomeResource::handleRequest(const Http::Request &request, Http::Response &response)
{
    response.out() << "Welcome to the image retrieval server. This is a test page\n";
}

HomeResource::~HomeResource()
{

}

