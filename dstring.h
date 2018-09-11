#ifndef DSTRING
#define DSTRING

#include <cstring>
#include <iostream>
class DString{
                /**
                 * This is my string class, youll see it is very similar to the handout
                 * the most important thing i added was a < operator I used to sort vectors
                 **/
    private:
     char * Name;
    public:

        DString();  //These constructors/destrctors handle memory allocation
        DString(const char*);
        DString(const DString&);
        ~DString();

        bool operator <(const DString&) const;  //Less than operator I used to sort vectors
        inline DString& operator= (const char*) ;
        DString& operator= (const DString&);
        bool operator> (const DString&) const;
        bool operator!=(const DString&) const;
        char& operator[] (const int) const;
        int getLength() const;
        char* c_str() const;

        friend std::ostream& operator<< (std::ostream&, const DString&);
        friend std::istream& operator >>(std::istream&, DString&);
};


#endif
