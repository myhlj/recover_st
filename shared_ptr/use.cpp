#include <tr1/memory>

class B;
class A{
    public:
        std::tr1::shared_ptr<B> m_b;
};

class B{
    public:
        std::tr1::shared_ptr<A> m_a;
};


int main(){
    std::tr1::shared_ptr<A> a(new A);
    std::tr1::shared_ptr<B> b(new B);

    a->m_b = b;
    b->m_a = a;
    return 0;
}
