#include<bits/stdc++.h>
using namespace std;

/*#ifndef COMPLEX_H_INCLUDED
#define COMPLEX_H_INCLUDED */

class Complex
{
    public:
    Complex();
    Complex(double, double);
    Complex operator+(Complex);
    bool operator!=(Complex);
    Complex operator*(Complex);
    void Print();
    private:
    double Real, Imaginary;
};
//#endif

/*-------------------------------------------*/
Complex operator+(Complex);

Complex::Complex()
{
    Real = 0;
    Imaginary = 0;
}
Complex::Complex(double r, double i)
{
    Real = r;
    Imaginary = i;
}
Complex Complex::operator+(Complex a)
{
    Complex t;
    t.Real = Real + a.Real;
    t.Imaginary = Imaginary + a.Imaginary;
    return t;
}
void Complex::Print()
{
    cout << Real << endl;
    cout << Imaginary << endl;
}

bool Complex::operator!=(Complex obj){
    if((Real!=obj.Real)||(Imaginary!=obj.Imaginary)) 
        return true;
    return false;
}

Complex Complex::operator*(Complex obj){
    Complex temp;

    temp.Real= (Real*obj.Real-Imaginary*obj.Imaginary);
    temp.Imaginary= (Real*obj.Imaginary+Imaginary*obj.Real);

    return temp;
}


int main()
{
    Complex a(2, 5);
    Complex b(5, 3);

    cout<<(a!=b)<<endl;
    
    Complex c=a*b;
    c.Print();
  
}


