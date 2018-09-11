#ifndef DVECTOR_H
#define DVECTOR_H
#include <iostream>
using namespace std;
//This is my custom vector class
template <typename T>
class DVector
{
private:
    int size;
    int capacity;
    T * data;       //This is the data member that stores our vector
    void resize();
public:
    typedef T value;        //these four values will be used later in our methods to access and add locations within vector
    typedef T & location;
    typedef T * pointer;
    typedef T * iterator;
    inline DVector();              //three constructors, one default, one for when adding an inital value
    DVector(T&);
    DVector(const DVector&); //Copy constructor
    inline ~DVector();
    void push_back(T&);     //T& is a when data is stored in a variable
    int getsize();
    T& operator [](const int);
    iterator begin();  //these return iterators to parts of the vector
    iterator end();


};
//rule of 3 destrcutor copy constructor and overloaded = sign
template<typename T>        //SPECIAL LARGE VECTOR FOR SORTING CONTEST
inline DVector<T>::DVector() {
    size = 0;
    capacity = 1000;
    data = new T[capacity];
    }

template<typename T>
DVector<T>::DVector(T& n) {
    T temp;
    capacity = n <<2;       //since were dealing with data we need to add to capacity
    data = new T[capacity];
    for (temp =0; temp<n; temp++)
        data[temp] =T();    //Create our new vector of n elements
    size = n;
}

template <typename T>
DVector<T>::DVector(const DVector& copy) {
    capacity = copy.capacity;
    size = copy.size;           //We are simply looping through 1 vector and putting it in another
    data = new T[capacity];
    for (int i =0; i < size; i++) {
        data[i] = copy.data[i];
    }
}
template<typename T>
inline DVector<T>::~DVector() {
    delete [] data;
   }

template<typename T>
void DVector<T>::push_back(T& p) {
    if(size == capacity) {
        this->resize();   //once we reach capacity we will have to double our capacity
    }
    data[size] = p;       //once size is avaliable, add it
    size++;
}

template<typename T>
int DVector<T>::getsize() {
    return size;
}
template<typename T>
T& DVector<T>::operator [](const int index) {
    return data[index];
}

template<typename T>
void DVector<T>::resize(){
    capacity *= 2;
    T * temp = data;
    data = new T [capacity];  //create new data array now twice the size!
    for (int i = 0; i < size; i++) {
        data[i] = temp[i];   //place all saved temp elements into new array
    }
    delete [] temp;
}

//These two functions return iterators to start and end
template<typename T>
typename DVector<T>::iterator DVector<T>::begin()  {
    return data;
}
//These methods are vital for vector to be compatible w/ std functions
template<typename T>
typename DVector<T>::iterator DVector<T>::end()  {
    return data + size;
}
#endif // DVECTOR_H
