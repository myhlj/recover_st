#include "two.h"
#include <string.h>

template<class Elem> Array<Elem>::Array(int sz){
    size = sz;
    data = new Elem[size];
}

template <class Elem> int Array<Elem>::GetSize(){
    return size;
}


template <unsigned Size> unsigned int String<Size>::length(){
    int len = 0;
    while(len < Size && data[len] != '\0')
        len++;
    return len;
}

template <unsigned Size> String<Size>::String(char* initial){
    strncpy(data,initial,Size);
    if(length() == Size)
        overflows++;
}

template<unsigned Size> int String<Size>::overflows = 0;


int main()
{
    Array<int> int_arry(100);
    String<8> short_string("hello");

    int x = int_arry.GetSize();
    std::cout<<x<<std::endl;

    x = short_string.length();
    std::cout<<x<<std::endl;
    return 0;
}
