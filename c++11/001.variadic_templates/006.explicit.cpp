//
// Created by Administrator on 2022/1/24.
//

class Complex {
public:
    explicit
    Complex(int real_, int imag_=0) : real(real_), imag(imag_){}

    Complex operator+(const Complex& x) {
        return Complex(real+x.real, imag+x.imag);
    }
private:
    int real{0};
    int imag{0};
};

int main() {
    Complex c1(12,5);
//! Complex c2 = c1 + 5;    //error
    Complex c3 = c1 + Complex(5);
    //在不加explicit的情况下，这里的5被强制隐式转换为Complex
    //带上explicit的情况下，这里的5不能强制转换，应该用Complex(5)的方式。

    return 0 ;
}

