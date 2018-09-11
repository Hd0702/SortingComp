#include "dsort.h"
using namespace std;
/**
*  This is Hayden Donofrio's sorting project for CSE 2341
*  It is essentially a bucket sort and a quicksort algorithim
**/
int main(int argc, char * argv[])
{
    Dsort A(argv[1]);
    A.MakeFile(argv[2]);
    return 0;
}
