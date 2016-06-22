#ifndef _QUOTE_H
#define _QUOTE_H

#include <string>

using namespace std;

struct Quote{

  string date;
  long timestamp;
  double open;
  double close;

  Quote(): timestamp(0), open(0), close(0){}
};

#endif
