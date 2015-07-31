TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c++11
CONFIG += -02

SOURCES += main.cpp \
    imageretrievalapplication.cpp \
    imageresource.cpp \
    Core/utils/hesaff/affine.cpp \
    Core/utils/hesaff/helpers.cpp \
    Core/utils/hesaff/hesaff.cpp \
    Core/utils/hesaff/pyramid.cpp \
    Core/utils/hesaff/siftdesc.cpp \
    Core/compute_map.cpp \
    Core/quantize/quantize.cpp \
    Core/app/appdata.cpp \
    homeresource.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    imageretrievalapplication.h \
    imageresource.h \
    Core/app/appdata.h \
    Core/extract/extract.h \
    Core/quantize/quantize.h \
    Core/query/query.h \
    Core/utils/hesaff/affine.h \
    Core/utils/hesaff/helpers.h \
    Core/utils/hesaff/pyramid.h \
    Core/utils/hesaff/siftdesc.h \
    Core/utils/geometric_verification.h \
    Core/utils/invertedindex.h \
    Core/utils/score.h \
    Core/utils/utils.h \
    Core/configurations.h \
    Core/initialize.h \
    Core/local_configurations.h \
    Core/runserver.h \
    Core/test.h \
    homeresource.h
LIBS += -lwthttp -lwt -lpthread -lhdf5 -lboost_system -lboost_filesystem `pkg-config --libs opencv` -lmysqlcppconn




