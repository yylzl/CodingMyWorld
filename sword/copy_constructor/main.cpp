#include <iostream>
#include <cstdint>
#include <climits>
#include <string>
#include <stack>


class A
{
    private:
        int a;
    public:
        A()
        {
            a = 0;
        }
        //形参名字不能和成员变量名字一样
        A(int b)
        {
            a = b;
        }
        //拷贝构造函数，复制的时候调用：传参数
        A(const A& other)
        {
            a = other.a;
        }

        int geta(void)
        {
            return a;
        }
};

using namespace std;

int main(int argc, char *argv[])
{
    //A a;
    A a1(1);
    A b = a1;
    //cout << a.geta() << endl;
    cout << a1.geta() << endl;
    cout << b.geta() << endl;
    return 0;
}

