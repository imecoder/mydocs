#include <iostream>

using namespace std;

void print() {        //����պ����Ǳ���ģ�û�оͱ���ʧ��
    cout << "print(), ģ��ݹ���õ��õ�����Ŷ��" << endl;
}

//�����ǵݹ���ò���������ģ��
template<typename T, typename ... Types>
void print(const T& firstArg, const Types&... args) {
    cout << firstArg << endl;
    print(args...);   //��Ϊprint�ݹ��ǣ����Ĳ���Ϊ0�������Ի���õ������print()
}

int main() {
    print(7, "hello", 2);
    return 0;
}

//---------------------------------
//7
//hello
//2
//print(), ģ��ݹ���õ��õ�����Ŷ��