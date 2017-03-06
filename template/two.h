#include <iostream>

template <class Elem> class Array{
        Elem* data;
        int size;
    public:
        Array(int sz);
        int GetSize();
        Elem& operator[](int idx);

};

template <unsigned Size> class String{
    char data[Size];
    static int overflows;
    public:
    String(char* initial);
    unsigned int length();
};
