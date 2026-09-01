// z2.cpp
// Implementation of of the Z2 group (consisting of the elements +,- and the group operation * )
# include <iostream>
using namespace std;

enum Z2 { Plus, Minus };

Z2 operator*(Z2 a, Z2 b) { return (a == b ? Plus : Minus); }

ostream& operator<<(ostream& os, Z2 a) {
    if (a == Plus) {
        os << "+";
    } else {
        os << "-";
    }
    return os;
}

template <class T> T identity_element() { return T(1); }

template <> Z2 identity_element() { return Plus; }

template <class T> T operator*(T a, Z2 b) { return (b == Plus ? a : -a); }

template <class T> T operator*(Z2 a, T b) { return (a == Plus ? b : -b); }

template <class T> T mypow(T a, unsigned int n) {
    T result = identity_element<T>();
    if (n > 0) {
        for(unsigned int i = 0; i < n; ++i){
            result = result*a;
        }
    }
    return result;
}

int main() {
    Z2 a = Plus;
    Z2 b = Minus;
    cout << "a * b = " << (a * b) << endl; // Output: a * b = -
    cout << "b * a = " << (b * a) << endl; // Output: b * a = -
    cout << "a * a = " << (a * a) << endl; // Output: a * a = +
    cout << "b * b = " << (b * b) << endl; // Output: b * b = +

    int x = 3;
    cout << "x * a = " << (x * a) << endl; // Output: x * a = 3
    cout << "x * b = " << (x * b) << endl; // Output: x * b = -3

    double y = 2.5;
    cout << "y * a = " << (y * a) << endl; // Output: y * a = 2.5
    cout << "y * b = " << (y * b) << endl; // Output: y * b = -2.5

    unsigned int n = 3;
    cout << "mypow(x, n) = " << mypow(x, n) << endl; // Output: mypow(x, n) = 27
    cout << "mypow(y, n) = " << mypow(y, n) << endl; // Output: mypow(y, n) = 15.625
    cout << "mypow(a, n) = " << mypow(a, n) << endl; // Output: mypow(a, n) = +
    cout << "mypow(b, n) = " << mypow(b, n) << endl; // Output: mypow(b, n) = -

    return 0;
}