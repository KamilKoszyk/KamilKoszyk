#include <iostream>
#include <string>
#include "tstring.h"
using namespace std;

auto fun(const char* c) {
    return TString(c);
}

auto main() -> int {
    TString s;
    TString s2{"abrakadabra"};
    TString kamil{"Kamil Koszyk"};
    TString s3 { s2 };
    s = s3;
    TString s4 = fun("pierwszy obiekt"); 
    s2 = std::move( s );
    for(auto i = 0ul; i<s4.size(); ++i) cout<< s4[i] << "-";
    cout<<endl;

    for(const auto& c: s2) {
        //c = toupper(c);
        cout<< c << " ";
    }


    cout<<endl;

    for(const auto& d: kamil){
        cout<< d << " ";
    }
    cout<<endl;


    s2.insert(0, 'A');
    
    s2.insert(s2.size(), 'B');
    s2.insert(s2.size(), 'C');
    s2.insert(s2.size(), 'D');
    //s2.insert(s2.size()/2, 'C');
    kamil.erase(2);
    

    for(size_t i = 0; i<kamil.size(); ++i){
        cout<< kamil[i]<<" ";
    }
    cout<<endl;
    for(size_t i = 0; i<s2.size(); ++i) cout<< s2[i] << " ";
    cout << "-------------------" << endl;
}