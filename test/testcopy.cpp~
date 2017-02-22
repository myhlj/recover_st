#include <iostream>
#include <string.h>
using namespace std;

class c{
    public:
    c(){
       p_first = NULL;
       n = 0;
       cout<<"c()"<<endl;
    }
    ~c(){
        if(p_first != NULL){
            delete [] p_first;
            p_first = NULL;
        }
        cout<<"~c()"<<endl;
    }
    c(const c& obj){
        n = obj.n;
        p_first = new char[n+1];
        memcpy(p_first,obj.p_first,n);
        cout<<"copy"<<endl;
    }
    c& operator=(const c& obj){
        n = obj.n;
        if(&obj == this){
            return *this;
        }
        if(p_first != NULL){
           delete [] p_first;
           p_first = NULL;
        }
        p_first = new char[n+1];
        memcpy(p_first,obj.p_first,n);
        cout<<"="<<endl;
        return *this;
    }
    char* p_first;
    int n;
};

void input_test(const c obj){
/*    cout<<obj.n<<endl;*/
    //if(obj.p_first !=NULL)
        /*cout<<obj.p_first<<endl;*/
    cout<<"input_test"<<endl;
}

int main()
{
    c test1;
    test1.n = 10;
    test1.p_first = new char[test1.n+1];
    strcpy(test1.p_first,"123456789");
    cout<<test1.p_first<<endl;


    input_test(test1);
    input_test(test1);
    return 0;
}
