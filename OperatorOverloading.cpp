#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Complex{
    int real;
    int imag;

    public:
    Complex(){
        real = imag = 0;
    }
    Complex(int r, int i){
        real = r;
        imag = i;
    }

    void print(){
        cout<<real<<" + "<<imag<<"i"<<endl;
    }

    Complex operator +(Complex c){           // Binary operator Overloading
        Complex ans;
        ans.real = real + c.real;
        ans.imag = imag + c.imag;
        return ans;
    }
};

class Weight{
    int kg;

    public:
    Weight(){
        kg=0;
    }
    Weight(int k){
        kg = k;
    }

    void print(){
        cout<<"Weight: "<<kg<<endl;
    }

    void operator ++(){                    // Unary Operator Overloading
        ++kg;                              // Pre-Increment
    }
    
    void operator ++(int){                 // Post-Increment (give parameter)
        kg++;
    }
};

int main(){
    Complex c1(1,2);
    Complex c2(3,4);
    Complex c3;
    c3 = c1+c2;          // c3 = c1.add(c2)

    c3.print();


    Weight w(7);
    ++w;                        // w.operator++();
    w.print();
    w++;
    w.print();

    return 0;
}