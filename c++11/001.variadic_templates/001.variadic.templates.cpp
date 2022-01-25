#include <iostream>

using namespace std;

void print() {        //这个空函数是必须的，没有就编译失败
    cout << "print(), 模板递归最好调用到这里哦。" << endl;
}

//这里是递归调用不定参数的模板
template<typename T, typename ... Types>
void print(const T& firstArg, const Types&... args) {
    cout << firstArg << endl;
    print(args...);   //因为print递归是，最后的参数为0个，所以会调用到上面的print()
}

int main() {
    print(7, "hello", 2);
    return 0;
}

//---------------------------------
//7
//hello
//2
//print(), 模板递归最好调用到这里哦。