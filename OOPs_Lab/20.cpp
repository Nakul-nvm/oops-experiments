#include <iostream>
using namespace std;

class Complex;

class FriendFunction {
public:
    static Complex add(const Complex&, const Complex&);
};

class Complex {
private:
    float real;
    float imaginary;

public:
    Complex(float r = 0, float i = 0) : real(r), imaginary(i) {}

    friend Complex FriendFunction::add(const Complex&, const Complex&);
    
    Complex addFriend(const Complex& other) {
        return Complex(real + other.real, imaginary + other.imaginary);
    }

    void display() {
        cout << "Complex Number: " << real << " + " << imaginary << "i" << endl;
    }
};

Complex FriendFunction::add(const Complex& c1, const Complex& c2) {
    return Complex(c1.real + c2.real, c1.imaginary + c2.imaginary);
}

int main() {
    Complex c1(3.5, 2.5), c2(4.5, 1.5);
    
    cout << "First ";
    c1.display();
    
    cout << "Second ";
    c2.display();
    
    Complex sum1 = FriendFunction::add(c1, c2);
    cout << "Sum using friend function: ";
    sum1.display();
    
    Complex sum2 = c1.addFriend(c2);
    cout << "Sum using member function as friend: ";
    sum2.display();

    return 0;
}
