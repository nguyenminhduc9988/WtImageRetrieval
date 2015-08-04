#include <iostream>
#include <random>
#include <time.h>
#include <stdlib.h>
#include <Wt/WApplication>
#include <Wt/WBreak>
#include <Wt/WContainerWidget>
#include <Wt/WLineEdit>
#include <Wt/WPushButton>
#include <Wt/WText>
#include <Wt/WServer>
#include <Wt/Utils>
#include <Wt/WGlobal>
#include "imageretrievalapplication.h"
#include "imageresource.h"
#include "homeresource.h"
#include "Core/configurations.h"
#include "Core/initialize.h"
#include "Core/runserver.h"
#include "Core/test.h"

#include "Core/app/appdata.h"
#include "Core/extract/extract.h"
#include "Core/quantize/quantize.h"
#include "Core/query/query.h"
#include "Core/utils/score.h"
#include "Core/utils/utils.h"

using namespace std;
using namespace Wt;


WApplication* createApplication(const WEnvironment& env)
{
    return new ImageRetrievalApplication(env);
}

int main(int argc, char** argv)
{
    srand(time(NULL));
//    extractAll();
//    quantizeAllData();
    extractAndQuantizeAll();

    try
    {
        WServer server(argv[0]);
        server.setServerConfiguration(argc, argv, WTHTTP_CONFIGURATION);
        ImageResource* resource = new ImageResource();
        HomeResource* homeresource = new HomeResource();


        server.addResource(homeresource, "/");
        server.addResource(resource, "/api");

        //server.addEntryPoint(Wt::EntryP, createApplication);
        if (server.start()) {
            WServer::waitForShutdown();
            server.stop();
        }
    }
    catch (WServer::Exception& e)
    {
        cerr << e.what() << endl;
    }
    catch (std::exception & e)
    {
        cerr << e.what() << endl;
    }

//    return WRun(argc,argv, &createApplication);
//    return WRun(argc , argv, [](const WEnvironment& env) -> WApplication* {

//    });
}
