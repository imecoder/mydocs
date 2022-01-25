//
// auto类型自动推导，常用在以下情况中
// 1. 类型名比较长，如 vector<string>::iterator
// 2. 不太清晰类型，如 函数的返回值
// 3. 通过查看代码无法确定类型，如 下溯时，子类对象类型
//
// auto 其他情况，没有意义， 比如 auto i = 32 ;
// - 不能用作函数参数。
// - 不能用作类或结构体中的非static成员变量。
//

#include <vector>
#include <string>
using namespace std;

// 1. 变量在声明时必须马上初始化。
auto a = 5;				//a->int, auto->int
auto a1 = a;			//a1->int, auto->int
const auto *a2=&a;		//a2->const int*, auto->int

auto b = new auto(10);	//a->int*, auto->int*

int c = 10;
auto* c1=&c;			//c1->int*, auto->int
auto& c2=c;				//c2->int&, auto->int

auto d = 0.0;			//d->double, auto->double

//2. 赋值时去掉const属性，指针和引用会保留const属性(因为指向同一个对象)
const auto e=6;			//e->const int, auto->int
auto e1=e;				//b为新对象，const不保留, b->int, auto->int
auto& e2=e;				//const保留, e2->const int&, auto->int
auto* e3=&e;		    //const保留, e3->const int*, auto->int

void fun() {
    // 替代iterator
    vector<string> v;
    for (std::vector<string>::const_iterator itr = v.cbegin(); itr != v.cend(); ++itr);
    for (auto itr = v.cbegin(); itr != v.cend(); ++itr);

}

int main() {
    fun();
    return 0 ;
}


