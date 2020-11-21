#ifndef TSTRING_H
#define TSTRING_H
#include <cstring>

class TString {
    public:
        TString(const char* s = nullptr); // c-tor
        TString(const TString& s); // cc-tor
        TString(TString&& s); // move c-tor
        ~TString(); // d-tor
        TString& operator=(const TString& s); // copy operator=
        TString& operator=(TString&& s); // move operator=

        char& operator[](size_t n);
        const char& operator[](size_t n) const;

        char* begin() { return ptr;}
        char* end() {return ptr+len;}
        char* cbegin() const {return ptr;}
        char* cend()const {return ptr+len;}
        size_t length() const { return len;}
        size_t size()const{ return len; }
        void clear() {delete [] ptr; ptr = nullptr; len=0;}
        bool empty()const { return len ? false : true ;}
        char& front() { return *ptr; }
        const char& front() const { return *ptr; }
        char& back() { return *(ptr+len-1); }
        const char& back() const { return *(ptr+len-1);}
        
        char* insert(size_t pos, const char* c );
        char* insert(size_t pos, char c);
        char* erase(size_t pos, size_t len = 0);
        

    
    private:
        char* ptr { nullptr };
        size_t len { 0 };
};


#endif // TSTRING_H