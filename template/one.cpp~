#include <iostream>



template <class Nu>
Nu twice(Nu original){
    return original << 1;
}
template <class Nu>
Nu min(Nu x,Nu y){
    return (x < y) ? x : y;
}

int main(){
    int n1 = 2,n2 = 10;

    
    int re = twice(n1);
    re = min<int>(n1,n2);
    std::cout<<re<<std::endl;
    return 0;
}
