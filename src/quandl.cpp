#include <stdio.h>
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"

#include "quandl.h"
#include "web.h"

using namespace rapidjson;

vector<Quote> Quandl::getQuotes(const string &dataset, const string &symb, 
        const string &start, const string &end){
    vector<Quote> quotes;
    
    string api_key = "-xCLbyy36qbT5583CtoS";
    
    string url = "https://www.quandl.com/api/v3/datasets/" + dataset + "/" + 
            symb + ".json?api_key=" + api_key + (start == "" ? "" : string("&start_date=") + start);
    
    string out;
    printf("Sending get request to %s\n", url.c_str());
    int res = getRequest(url, out);
    if(res<0)
        return quotes;
    printf("Done...\n");
    
    //printf("%s\n", out.c_str());
    
    rapidjson::Document d;
    d.Parse(out.c_str());
  
    rapidjson::Value &ds =  d["dataset"];
    rapidjson::Value &data =  ds["data"];
  
  
    for (rapidjson::SizeType i = 0; i < data.Size(); i++){
        const rapidjson::Value &val = data[i];
        Quote quote;
        quote.date = val[0].GetString();
        quote.open = val[1].GetDouble();
        quote.close = val[4].GetDouble();
        
        quotes.push_back(quote);
    }
    
    return quotes;
    
}