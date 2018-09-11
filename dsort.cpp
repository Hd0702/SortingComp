#include "dsort.h"
using namespace std;
Dsort::Dsort(DString filename)
{
    ReadInput(filename);
}
inline void Dsort::ReadInput(DString fName) {
    read.open(fName.c_str());
    read >> filesize;   //read the first two lines and store them
    read >> ExtractSize;
    char Reader[30];
    while (read >> Reader) {
       DString nStr = Reader; //Bucket sort each single word
       FindArray(nStr);
    }
    read.close();
    for(int i =0; i <30; i ++) {
        if(Words[i].getsize() != 0) {
            quickSortI(Words[i]);    //quicksort each vector
        }
    }
}
/**
 * This large switch statement is my first sort method, which is a type of bucket-sort
 * However, normal GCC compilers turn this into a Jump table, which is O(1) Rather than O(n)
 * this allows for much faster sorting because we know our range of numbers
 **/
inline void Dsort::FindArray(DString & Place) {
    switch(Place.getLength()) {
    case 1:
        Words[0].push_back(Place);
        break;
    case 2:
        Words[1].push_back(Place);
        break;
    case 3:
        Words[2].push_back(Place);
        break;
    case 4:
        Words[3].push_back(Place);
        break;
    case 5:
        Words[4].push_back(Place);
        break;
    case 6:
        Words[5].push_back(Place);
        break;
    case 7:
        Words[6].push_back(Place);
        break;
    case 8:
        Words[7].push_back(Place);
        break;
    case 9:
        Words[8].push_back(Place);
        break;
    case 10:
        Words[9].push_back(Place);
        break;
    case 11:
        Words[10].push_back(Place);
        break;
    case 12:
        Words[11].push_back(Place);
        break;
    case 13:
        Words[12].push_back(Place);
        break;
    case 14:
        Words[13].push_back(Place);
        break;
    case 15:
        Words[14].push_back(Place);
        break;
    case 16:
        Words[15].push_back(Place);
        break;
    case 17:
        Words[16].push_back(Place);
        break;
    case 18:
        Words[17].push_back(Place);
        break;
    case 19:
        Words[18].push_back(Place);
        break;
    case 20:
        Words[19].push_back(Place);
        break;
    case 21:
        Words[20].push_back(Place);
        break;
    case 22:
        Words[21].push_back(Place);
        break;
    case 23:
        Words[22].push_back(Place);
        break;
    case 24:
        Words[23].push_back(Place);
        break;
    case 25:
        Words[24].push_back(Place);
        break;
    case 26:
        Words[25].push_back(Place);
        break;
    case 27:
        Words[26].push_back(Place);
        break;
    case 28:
        Words[27].push_back(Place);
        break;
    case 29:
        Words[28].push_back(Place);
        break;
    case 30:
        Words[29].push_back(Place);
        break;
    default:
        std::cout << "WRONG" << std::endl;
    }
}
// initial quicksort
inline void Dsort::quickSortI(DVector<DString> & Loc) {
    this->QuickSort(0,Loc.getsize()-1, Loc);
}
//Quicksort method, similar to the one discussed in class
inline void Dsort::QuickSort(int start, int end, DVector<DString> & Data) {
    int a = start;
    int b = end;
    DString piv = Data[(start+end)/2];  //set pivot as current last
    while( a < b) {
        while(Data[a] < piv) {   //index up until we earliest value that is not < pivot
            a++;
        }
        while(Data[b] > piv) { //Vice versa for right side
            b--;
        }
        if( a <= b) {
            swap(Data[a],Data[b]);   //Once we find proper index, swap the two to correct sides
            b--;
            a++;
        }
    }
    if(a < end) {                  //sort recursively up the right
        QuickSort(a, end, Data);
    }
    if (start < b) {            //sort recursively down the left
        QuickSort(start, b, Data);
    }
}
//this creates the output file
void Dsort::MakeFile(DString Name) {
    ofstream out;
    out.open(Name.c_str());
    int in =0;
    auto iter = Words[0].begin();  //Set iterator to first vector
    for(int counter =0; counter < ExtractSize; counter++) {
        out << *iter << "\n";
        iter++;
        if(iter == Words[in].end()) {   //if we reach the end of vector set it to a new vector
           in++;
           iter = Words[in].begin();
        }
    }
    out.close();
}
