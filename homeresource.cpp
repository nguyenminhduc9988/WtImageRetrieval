#include "homeresource.h"
#include <Wt/WApplication>
#include <Wt/Http/Request>
#include <Wt/Http/Response>
#include <string>
#include <Wt/Json/Parser>
#include <iostream>
#include <ostream>
#include <istream>
#include <streambuf>

#include "Core/configurations.h"
#include "Core/app/appdata.h"
#include "Core/extract/extract.h"
#include "Core/quantize/quantize.h"
#include "Core/query/query.h"
#include "Core/utils/score.h"
#include "Core/utils/utils.h"

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

