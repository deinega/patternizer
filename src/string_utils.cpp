#include "string_utils.h"
#include <stdio.h>
#include <stdlib.h>

string fileToString(const string &fname){

    FILE *f = fopen (fname.c_str(), "rb");
    if(!f)
        return "";

    fseek (f, 0, SEEK_END);
    long length = ftell (f);
    if(!length){
        fclose(f);
        return "";
    }
    fseek (f, 0, SEEK_SET);
    char *buffer = new char[length];
    fread (buffer, 1, length, f);
    fclose(f);
    
    string str(buffer);
    delete []buffer;
    return str;
}