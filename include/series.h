#ifndef _SERIES_H
#define _SERIES_H

#include "quandl.h"
#include <stdio.h>

using namespace std;

template<class it_t>
double calculateAverage(it_t it, int sz){
    double av = 0;
    for(int i=0; i<sz; i++, it++){
        av += *it;
    }
    av /= sz;
    return av;
}

template<class it_t>
double calculateAutocorrelation(it_t it, int sz, int shift, double *av_calculated){
    double av = av_calculated ? *av_calculated : calculateAverage(it, sz);
    
    double aut = 0;
    
    for(int i = 0; i<sz-shift; i++, it++){
        aut += (*(it + shift) - av) * (*it - av);
    }
    aut /= sz - 1 - shift;
    
    return aut;
}

template<class it1_t, class it2_t>
double calculateCorrelation(it1_t it1, it2_t it2, int sz){
    double av1 = calculateAverage(it1, sz);
    double av2 = calculateAverage(it2, sz);
    double corr = 0;
    for(int i=0; i<sz; i++, it1++, it2++){
        corr += (*it1 - av1) * (*it2 - av2);
    }
    return corr;
}

template<class it1_t, class it2_t>
double record(const char *fname, it1_t it1, it2_t it2, int sz){
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
