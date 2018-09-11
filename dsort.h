#ifndef DSORT_H
#define DSORT_H
#include "dvector.h"
#include "dstring.h"
#include "fstream"
class Dsort
//this is my sorting algoritihm class
{
private:
    int filesize;
    int ExtractSize;
    ifstream read;
    DVector<DString> Words[30];  //Each element is a vector for word sizes

public:
    Dsort(DString);
    inline void ReadInput(DString);
    inline void FindArray(DString&);
    inline void quickSortI(DVector<DString> &);
    inline void QuickSort(int, int, DVector<DString> &);
    void MakeFile(DString);
};
#endif // DSORT_H
