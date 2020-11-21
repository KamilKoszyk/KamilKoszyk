#include "tstring.h"
#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

TString::TString(const char* s) : ptr(nullptr), len(0) {
    if (s != nullptr) {
        len = strlen(s);
        ptr = new char[len+1]; // +1 żeby się zmieścił \0 kończący łańcuch znakowy
        strcpy(ptr, s);
    }
    #ifdef DEBUG
        cout << "TString c-tor [" << (ptr ? ptr : "pusty") <<"]" << endl;
    #endif
}

TString::~TString() {
    #ifdef DEBUG
        cout << "TString d-tor [" << (ptr ? ptr : "pusty") <<"]" << endl;
    #endif
    delete [] ptr;
}

TString::TString(const TString& s) : ptr(nullptr), len(s.len) {
    if (len>0) {
        ptr = new char[len+1]; 
        strcpy(ptr,s.ptr);
    }
    #ifdef DEBUG
        cout << "TString cc-tor [" << (ptr ? ptr : "pusty") <<"]" << endl;
    #endif
}

TString& TString::operator=(const TString& s) {
    if (this != &s) { // if (*this != s)
        delete [] ptr;
        ptr = nullptr;
        len = s.len;
        if (len>0) {
            ptr = new char[len+1];
            strcpy(ptr,s.ptr);
        }
    }
    #ifdef DEBUG
        cout << "TString copy operator= [" << (ptr ? ptr : "pusty") <<"]" << endl;
    #endif
    return *this;
}

TString::TString(TString&& s) : ptr(s.ptr), len(s.len) {
    s.ptr = nullptr;
    s.len = 0;

#ifdef DEBUG
    cout << "TString move c-tor [" << (ptr ? ptr : "pusty") <<"]" << endl;
#endif
}

TString& TString::operator=(TString&& s) {
    if (this != &s) {
        delete [] ptr;
        len = s.len;
        ptr = s.ptr;
        s.len = 0;
        s.ptr = nullptr;       
    }

    #ifdef DEBUG
        cout << "TString move operator= [" << (ptr ? ptr : "pusty") <<"]" << endl;
    #endif   
    return *this;
}

 char& TString::operator[](size_t n)  {
    if (ptr==nullptr)
    {
        throw "zwykly lancuch znakowy";

    }
    
    if(n < len) {return ptr[n];}
    throw out_of_range("TString::operator[]: argument spoza zakresu");

}

char* TString::insert(size_t pos, const char* c){
    if(pos <= len ) {
        size_t oldlen = len;
        len = len + strlen(c);
        char* tmp = new char[len+1];
        strcpy(tmp, ptr);
        for(size_t i = pos; i<pos+strlen(c); ++i){
            tmp[i] = c[i-pos];
        }

        for(size_t i = pos; i<oldlen; ++i) {
            tmp[i+strlen(c)] = ptr[i];
        }
        tmp[len] = '\0';
        delete [] ptr;
        ptr = tmp;
        return ptr+pos;


        
    } else {
        throw out_of_range("zly argument");
    }
return ptr;
}

char* TString::insert(size_t pos, char c){
    return insert(pos, string( { c } ).c_str() );

}


char* TString::erase(size_t pos, size_t dlg){
    if(pos<len){
        size_t stara_dlg = len;
        len = len - dlg;
        char* tym = new char[len+1];
        strcpy(tym, ptr);
        if(dlg == 0 ) dlg++;
        
        for(size_t i = pos; i < stara_dlg-pos; ++i){
            tym[i] = ptr[i+dlg];
            
        }
        cout<<endl;
        tym[len+1] = '\0';
        delete [] ptr;
        ptr = tym;
        return ptr;
    
    }else{
        throw out_of_range("zly argument");
    }
return ptr;
}

