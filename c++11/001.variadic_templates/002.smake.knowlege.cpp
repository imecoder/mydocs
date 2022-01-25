//
// Created by Administrator on 2022/1/23.
//

#include <list>
#include <vector>
using namespace std;

//1. 无空格支持
vector<list<int> > vl1; //Ok in each version
vector<list<int>> lv2;  //Ok since C++ 11


//2. nullptr代替0或NULL
void f(int){}
void f(void*){}


int main() {
    f(0);
    //f(NULL);  //此时调用上面两个函数都可以，因此产生了歧义
    f(nullptr); //只会调用 f(void*)

    return 0 ;
}
