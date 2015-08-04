#include "simplequeryresource.h"

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

using namespace Wt;
using namespace Wt::Http;
using namespace std;


SimpleQueryResource::SimpleQueryResource()
{

}

void SimpleQueryResource::handleRequest(const Http::Request &request, Http::Response &response)
{
    // only query images in oxford 5k, query in the 55 query images
    // load bow vector from folder and multiply
//    const std::string queryBowFolder = "./data/bow_query";
//    const std::string* imgName = request.getParameter("imgName");

//    std::string tmp = *imgName;
//    if (!imgName)
//    {
//        response.out() << "No image is selected sorry\n";
//        return;
//    }

//    std::string queryImageBowFile = queryBowFolder + "/" + *imgName;
//    arma::mat queryBow;
//    queryBow.load(queryImageBowFile);

}

void SimpleQueryResource::queryExpansion()
{

}

SimpleQueryResource::~SimpleQueryResource()
{

}

