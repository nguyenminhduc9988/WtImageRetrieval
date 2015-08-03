#ifndef UTILS_H_INCLUDED
#define UTILS_H_INCLUDED

#include "../configurations.h"
#include <string>
using namespace std;

inline string getFileBaseName(string fileName) {
    return fileName.substr(0, fileName.rfind("."));
}

inline int parseInt(string s) {
    return atoi(s.c_str());
}

inline string vectorToJson(vector<string> v, string name) {
    string json = "{\n\t" + name + ": [\n";
    for (int i = 0; i < v.size(); i++) {
        json += "\t\t" + v[i];
        if (i + 1 < v.size())
            json += ",";
        json += "\n";
    }
    json += "\t]\n}";
    return json;
}

//inline void gen_random(string &s, const int len) {
//    static const char alphanum[] =
//        "0123456789"
//        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
//        "abcdefghijklmnopqrstuvwxyz";
//    s = "";
//    for (int i = 0; i < len; ++i) {
//        s += alphanum[rand() % (sizeof(alphanum) - 1)];
//    }
//}

#endif
