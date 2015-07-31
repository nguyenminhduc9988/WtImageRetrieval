#include "imageresource.h"
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


ImageResource::ImageResource()
{

}

void ImageResource::handleRequest(const Http::Request &request, Http::Response &response)
{
    const string* imgPath = request.getParameter("imgPath");
    const string* imgName = request.getParameter("imgName");

    AppData *app = AppData::getInstance();

    string tmp = *imgName;
    tmp.replace(tmp.size() - 3, 3, "mat");

    string kpPath = kpFolder + "/" + tmp;
    string siftPath = siftFolder + "/" + tmp;
    string tempPath = tempFolder + "/" + tmp;
    //imgPath = queryFolder + "/" + *imgPath;

    mat _kp, _sift;
    extractFeatures(*imgPath + "/" + *imgName, _kp, _sift, kpPath, siftPath, tempPath);

    int nDocs = app->path.size();
    vec _weights;
    uvec _termID;
    string weightPath = weightFolder + "/" + tmp;
    string termIDPath = termIDFolder + "/" + tmp;

    buildBoW(_sift, _weights, _termID, weightPath, termIDPath, true);

    vector<double> qTfidf = app->ivt.makeQueryTfidf(_weights, _termID);

    Score score(computeAllScores(qTfidf));

    vector<int> rankedList(nDocs);
    for (int i = 0; i < nDocs; i++)
        rankedList[i] = i;
    sort(rankedList.begin(), rankedList.end(), score);
    for (int i=0; i<nDocs; ++i)
        response.out() << app->path[rankedList[i]];


//    Read post data if you want to get the structure parse manually
//    const istream *reqBody = &request.in();
//    while (temp = request.in().peek())
//    {
//         request.in() >> inputName;
//         if (inputName.compare(prevString) == 0)
//         {
//            break;
//         }
//         prevString = inputName;
    //    }
}

void ImageResource::queryExpansion()
{

}

ImageResource::~ImageResource()
{

}

