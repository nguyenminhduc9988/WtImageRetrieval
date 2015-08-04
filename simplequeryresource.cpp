#include "simplequeryresource.h"
#include <string>

SimpleQueryResource::SimpleQueryResource()
{

}

void SimpleQueryResource::handleRequest(const Http::Request &request, Http::Response &response)
{
    // only query images in oxford 5k, query in the 55 query images
    // load bow vector from folder and multiply
    const std::string queryBowFolder = "./data/bow_query";
    const std::string* imgName = request.getParameter("imgName");

    std::string tmp = *imgName;
    if (!imgName)
    {
        response.out() << "No image is selected sorry\n";
        return;
    }

    std::string queryImageBowFile = queryBowFolder + "/" + *imgName;
    arma::mat queryBow;
    queryBow.load(queryImageBowFile);

}

void SimpleQueryResource::queryExpansion()
{

}

SimpleQueryResource::~SimpleQueryResource()
{

}

