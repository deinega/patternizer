#include <stdio.h>
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"

#include "yahoo.h"

#include "web.h"

using namespace rapidjson;

vector<Quote> Yahoo::getIntradayQuotes(const string &symb, const int days){
    
    vector<Quote> quotes;
    
    char daysString[10];
    sprintf(daysString, "%d", days);
    
    string url = string("http://chartapi.finance.yahoo.com/instrument/1.0/") + symb +
            "/chartdata;type=quote;range=" + daysString + "d/json";
            
    string out;
    printf("Sending get request to %s\n", url.c_str());
    int res = getRequest(url, out);
    if(res<0)
        return quotes;
    printf("Done...\n");
   
    
    int ind1 = out.find("{");
    int ind2 = out.rfind("}");
    out = out.substr(ind1, ind2 - ind1 + 1);
   
    //printf("%s\n", out.c_str());
        
    rapidjson::Document d;
    d.Parse(out.c_str());
  
    rapidjson::Value &data =  d["series"];
  
    for (rapidjson::SizeType i = 0; i < data.Size(); i++){
        const rapidjson::Value &val = data[i];
        Quote quote;
        quote.timestamp = val["Timestamp"].GetDouble();
        quote.open = val["open"].GetDouble();
        quote.close = val["close"].GetDouble();
        
        quotes.push_back(quote);
    }
    
    return quotes;
    
    
}
