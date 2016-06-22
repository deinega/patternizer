#include <math.h>
#include <stdlib.h>
#include "series.h"

vector<double> generateMarkovProces(int sz, double start, const double mu, const double sigma){
    vector<double> vals;
    double prev = start;
    for(int i=0; i<sz; i++){
        double next = prev + normal(mu, sigma);
        vals.push_back(next);
        prev = next;
    }
    return vals;
}

double normal(double mu, double sigma){
    
    double x, y;    
    double s = 0;
    while(s==0 || s>1){
        x = -1 + ((double) rand () / RAND_MAX) * 2;
        y = -1 + ((double) rand () / RAND_MAX) * 2;;
        s = x*x + y*y;
    }
    
    s = sqrt(-2*log(s)/s);
    double val = x * s;
    
    return mu + sigma * val;
}

vector<double> calculateDistribution(vector<double> in, double min, double max, int sz){
    vector<double> distr;
    
    for(int i=0; i<sz; i++){
        distr.push_back(0);
    }
    
    for(size_t i=0; i<in.size(); i++){
        double val = in[i];
        int j = (val - min)/(max - min)*sz;
        if(j>=sz)
            j=sz-1;
        if(j<0)
            j=0;
        
        distr[j]++;
    }

    for(int i=0; i<sz; i++){
        distr[i] /= in.size();
    }
    
    return distr;
}
