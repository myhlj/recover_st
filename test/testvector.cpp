#include <vector>
#include <iostream>
using namespace std;

int main()
{
    std::vector<int> test;
    test.push_back(1);
    std::vector<int>::const_iterator itera = test.begin();
    for(;itera != test.end();++itera){
       cout<<*itera<<endl; 
    }
    return 0;
}
