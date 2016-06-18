#include <curl/curl.h>
#include <string>
#include "web.h"

using namespace std;

static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp){
    ((string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

int getRequest(const string &url, string &out){
        
    int res = -1;
    
    CURL *curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());

        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &out);    

        CURLcode curlres = curl_easy_perform(curl);
        if(curlres != CURLE_OK){
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                 curl_easy_strerror(curlres));
        }
        else{
            res = 1;
        }

        curl_easy_cleanup(curl);
    }
    
    return res;
    
}

