//
// 统一用{}来做初始化
//
#include <vector>
#include <string>
#include <map>
using namespace std;

//带不带等号都行
namespace a{
    int a[] {1,2,3};
    int b[] = {1,2,3};
    vector<int> c {1,2,3};
    vector<int> d = {1,2,3};
    map<int, string> mis = {{1,"a"}, {2,"b"}, {3,"c"}};

    int* e = new int{123};          //指针
    int* f = new int[3] {1, 2, 3};  //堆上动态分配数组
}


//允许在类声明时使用 {}或= 来初始化非静态数据成员。
namespace b{
    struct A{
        int a = 3;      //类中直接初始化
        float b{3.5};   //类中直接初始化
    };
    A   aa{3, 5.5}; //定义对象
    A   func() {
        return {3, 5.5};     //返回值
    }
}

//小知识点

//1. 初始化0
namespace c{
    int i;      //初值未知
    int j{};    //初始化为0

    int* p;     //野指针，未定义的指针
    int* q{};   //初始化为 nullptr
}

//2. 要求不超出范围，防止类型收窄

namespace d{
    char c1{7};     //Ok
    char c2 = 9999; //Ok, warning
//! char c3{9999};  //不同的编译器，有的error，有的warning。
}

//3. 要求类型一致
namespace e{
    int x1(5.3);    //Ok, c++11之前的初始化方式
    int x2 = 5.3;   //Ok, warning
    int x3 = 5.3;   //Ok
//! int x4{5.3};    //error，编译不通过，跟initializtion_list有关系。
//! int x5 = {5.3}; //error

    vector<int> v1 {1,2,3}; //Ok
//! vector<int> v2 {1, 2.0, 3.5};   //error
}

int main() {
    return 0 ;
}