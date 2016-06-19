#ifndef _SERIES_H
#define _SERIES_H

#include "quandl.h"



double calculateAverage(vector<double> &vals);

double calculateAutocorrelation(vector<double> &vals, int shift, double *av);

#endif
