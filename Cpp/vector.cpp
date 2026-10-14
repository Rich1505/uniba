#include<vector>
#include<iostream>

class A{
    public:
        std::vector<int> a;

        A(){
            a.push_back(1);
        }
};

int main()
{
    A a;
    A b = a;

    a.a[0] = 2;

    std::cout << b.a[0] << std::endl;
    std::cout << a.a[0] << std::endl;
}