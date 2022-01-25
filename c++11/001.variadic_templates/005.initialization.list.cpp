//
// Created by Administrator on 2022/1/23.
//
#include <iostream>
#include <initializer_list>
#include <set>
#include <map>
#include <vector>
using namespace std;

//1. 初始化列表实现
namespace a{
    void f1() {
        std::initializer_list<int> list = {1,2,3};

        cout << list.size() << endl ;		//3
        cout << *list.begin() << endl ;		//1
        cout << *(list.begin()+1) << endl ;	//2
        cout << *(list.begin()+2) << endl ;	//3
        for(auto it = list.begin(); it != list.end() ; it++ )
            cout << *it << endl ;				//1,2,3
    }
}

//2.1 类的构造函数
namespace b{
    struct Foo {
        Foo(std::initializer_list<int> list) {}
        //就是因为有这种方式的构造函数，所以后面的的对象，才能用初始化列表功能。
    };

    Foo f({ 1, 2, 3, 4, 5 });
    Foo f1 = { 1, 2, 3, 4, 5 };
}

//stl中的对象，都实现了初始化列表形式的构造函数，所以有如下形式的使用方式
set<int> ss			 = {1,2,3};
vector<int> sv		 = {1,2,3,4,5};
map<int, string> mis = {{1,"a"}, {2,"b"}, {3,"c"}};


//vector初始化列表的基本实现思路。

class FooVector {
    std::vector<int> content_;
public:
    FooVector(std::initializer_list<int> list) {}
};

FooVector f = {1,2,3,4,5};


//2.2 函数参数
void foo(std::initializer_list<int> list) {}
void t() {
    foo({1,2,3}) ;
}



//4. 效率

//initializer_list中存储的是引用，它不存储对象本身。因此它的效率比较高。对于stl的对象，它会把引用指向的真实对象，完全赋值一遍。
namespace {
    initializer_list<int> f1() {
        int a = 1;
        int b = 3;
        return {a,b};					//此处只是返回a,b的引用，放到另外一个初始化列表中，并未进行a,b的值拷贝
    }
    initializer_list<int> l = f1();	//编译能通过，但无法得到正确结果，因为func调用结束后，a,b空间都已经释放


    //解决办法：进行值拷贝。

    vector<int> f2() {
        int a = 1;
        int b = 3;
        return {a,b};					//对vector会进行a,b的值拷贝
    }
    vector<int> v = f2();
}

//5. 防止类型收窄

//类型收窄，一个宽精度数值赋值给一个低精度变量时，引起了数据丢失，即类型收窄。

//c99、c++98/03、c++11都可以编译通过，不会进行判断。但c++11可以通过初始化列表来防止此类事件发生。

namespace {
    int a = 1.1 ;	//ok, 无告警
//! int a1 = {1.1};	//error

    char b = 1024;		//ok, warning
//! char b1 = {1024};	//error

    char c = {100};					//ok, const常量
    int d=100;	char e = {d};		//ok, warning
    int d1=1000;char e1 = {d1};		//不同的编译器，可能warning,可以error
}

int main() {
    return 0 ;
}

