#ifndef _SERIES_H
#define _SERIES_H

#include "quandl.h"

double calculateAverage(vector<double> &vals);

double calculateAutocorrelation(vector<double> &vals, int shift, double *av);

vector<double> generateMarkovProces(int sz, const double start, const double mu, const double sigma);

double normal(double mu, double sigma);

vector<double> calculateDistribution(vector<double> in, double min, double max, int sz);

#endif
