#ifndef _ANALYSIS_H
#define _ANALYSIS_H

#include <vector>

using namespace std;

class Analysis{
public:
    
    int length;
    int length_future;
    double corr_min;
    
    void analize(const vector<double> &process);
};

#endif
