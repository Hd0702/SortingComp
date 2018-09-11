#include "dstring.h"
DString::DString() {
    Name = nullptr;  //Making sure we dont have a segfault, assign NO memory;
}
//Copy constructor for char*
 DString::DString(const char* NewStr) {
    Name = new char[strlen(NewStr)+1];
    strcpy(Name, NewStr);
}
//Copy constructor for Strings
DString::DString(const DString& CpyString){
    if(CpyString.Name == nullptr)
        Name = nullptr;
    else {
    Name = new char[strlen(CpyString.Name)+1];
    strcpy(Name, CpyString.Name);
    }
}
//   Destructor for memory handling
DString::~DString() {
    delete [] Name;
    Name = nullptr;
}
 //assigning string to equal a char
inline DString& DString::operator= (const char* Compr)  {
    delete[] Name;
    Name = new char[strlen(Compr)+1];
    strcpy(Name, Compr);
    return *this;
}
 //assigning string to equal a string
DString& DString::operator= (const DString& FinStr)  {
    delete[] Name;
    Name= new char[strlen(FinStr.Name)+1];
    strcpy(Name, FinStr.Name);
    return *this;
}
//If one string is indexed higher than another return true
bool DString::operator > (const DString& Scmp) const{
    if (strcmp(Name, Scmp.Name) > 0) {
        return true;
    }
    else {
        return false;
    }
}
//we use this operator to find a certain character
char& DString::operator[] (const int index) const{
    return Name[index];

}
 int DString::getLength() const{
    return strlen(Name);
}
 char* DString::c_str() const{
    return Name;
}
//This handles printing of a string
 std::ostream& operator<< (std::ostream& output, const DString& object) {
    if(object.Name != nullptr) {
         output << object.Name;
    }
   return output;
}
std::istream& operator >> (std::istream& input, DString& obj) {
    delete []obj.Name;
    char * temp = new char [256];
    input.getline(temp, 256, '\n');
    obj.Name = new char[strlen(temp)+1];  //name equals temp now and then we delete it for no mem leaks
    strcpy(obj.Name, temp);
    delete [] temp;
    return input;
}
//This returns true if Name is indexed lower
 bool DString::operator <(const DString & D2) const{
         if (strcmp(Name, D2.Name) < 0) {
           return true;
          }
         else
          return false;
}
