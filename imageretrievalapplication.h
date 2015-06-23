#ifndef IMAGERETRIEVALAPPLICATION_H
#define IMAGERETRIEVALAPPLICATION_H
#include <Wt/WApplication>

using namespace Wt;

class ImageRetrievalApplication : public WApplication
{
private:
    WTextArea *outputArea;
public:
    ImageRetrievalApplication(const WEnvironment& env);


    ~ImageRetrievalApplication();

};

#endif // IMAGERETRIEVALAPPLICATION_H
