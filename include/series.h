#ifndef _SERIES_H
#define _SERIES_H

#include "quandl.h"
#include <stdio.h>
#include <math.h>

using namespace std;

template<class it_t>
double calculateAverage(it_t it, int sz){
    if(sz == 0)
        return 0;
    double av = 0;
    for(int i=0; i<sz; i++, it++){
        av += *it;
    }
    av /= sz;
    return av;
}

template<class it1_t, class it2_t>
double calculateCorrelation(it1_t it1, it2_t it2, int sz){
    if(sz == 0)
        return 0;
    double av1 = calculateAverage(it1, sz);
    double av2 = calculateAverage(it2, sz);
    double sigma1 = 0, sigma2 = 0, cov = 0;
    for(int i=0; i<sz; i++, it1++, it2++){
        sigma1 += (*it1 - av1) * (*it1 - av1);
        sigma2 += (*it2 - av2) * (*it2 - av2);
        cov += (*it1 - av1) * (*it2 - av2);
    }
    if(sigma1 == 0 || sigma2 == 0)
        return 0;
    double corr = cov/sqrt(sigma1 * sigma2);
    return corr;
}

template<class it_t>
double calculateAutocorrelation(it_t it, int sz, int shift){
    return calculateCorrelation(it, it+shift, sz);
}

template<class it1_t, class it2_t>
void record(const char *fname, it1_t it1, it2_t it2, int sz){
    FILE *f = fopen(fname, "w");
    for(int i=0; i<sz; i++, it1++, it2++){
        fprintf(f, "%d\t%g\t%g\n", i, *it1, *it2);
    }
    fclose(f);
}

vector<double> generateMarkovProces(int sz, const double start, const double mu, const double sigma);

double normal(double mu, double sigma);

vector<double> calculateDistribution(vector<double> in, double min, double max, int sz);

#endif
