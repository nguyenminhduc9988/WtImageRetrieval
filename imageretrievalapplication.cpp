#include "imageretrievalapplication.h"
#include <Wt/WApplication>
#include <Wt/WResource>
#include <Wt/WEnvironment>
#include <Wt/WTextArea>
#include <string>
#include <iostream>
using namespace Wt;
using namespace std;


ImageRetrievalApplication::ImageRetrievalApplication(const WEnvironment& env) : WApplication(env)
{
    setTitle("Image retrieval");
    outputArea = new WTextArea(root());
    const string* urlParam = this->environment().getParameter("param");

    if (urlParam)
    {
        cout << urlParam << endl;
        outputArea->setText(*urlParam);
    }
    else
    {
        outputArea->setText(L"no param sorry");
    }


}


ImageRetrievalApplication::~ImageRetrievalApplication()
{

}



