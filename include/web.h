#ifndef _WEB_H
#define _WEB_H

#include <string>

using namespace std;

    int getRequest(const string &url, string &out);
  
    int postRequest(const string &url, string &out); // TODO

#endif
