#include "series.h"

double calculateAverage(vector<double> &vals){
    double av = 0;
    for(size_t i=0; i<vals.size(); i++){
        av += vals[i];
    }
    av /= vals.size();
    return av;
}

double calculateAutocorrelation(vector<double> &vals, int shift, double *av_calculated){
    double av = av_calculated ? *av_calculated : calculateAverage(vals);
    
    double aut = 0;
    
    for(size_t i = shift; i<vals.size(); i++){
        aut += (vals[i] - av) * (vals[i-shift] - av);
    }
    aut /= vals.size() - 1 - shift;
    
    return aut;
}