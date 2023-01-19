#include<iostream>
#include<bits/stdc++.h>
using namespace std;


///////////// Sum of first n numbers using Recursion ///////////

int sum(int n){
        if(n==0){
            return 0;
        }else{
            return sum(n-1)+n;
        }
    };

//////////// Factorial of a no using Recursion ///////////////

int fact(int n){
    if(n==0) return 1;
    else return fact(n-1)*n;
}

//////////// Exponent of a no: (m)^n ///////////
////////// Normal Method with recursion

int expnormal(int m, int n){
    if(n==0) return 1;
    else return pow(m,n-1)*m;
}

////////// Reduced Time Method with Recursion

int expnew(int m, int n){
    if(n==0) return 1;
    if(n%2==0) return pow(m*m, n/2);
    else return m*pow(m*m, (n-1)/2);
}

/////////////// Taylor Series ///////////////////

//////////// Iterative Method

double e(int x, int n){
    double sum=1;
    double num=1, den=1;
    for(int i=1;i<=n;i++){
        num=num*x;
        den=den*i;
        sum=sum+(num/den);
    }
    return sum;
}

///////////// Normal Recursion

double e2(int x, int n){
    static double p=1, f=1;
    double res;
    
    if(n==0) return 1;
    else{
        res = e2(x, n-1);
        p=p*x;
        f=f*n;
        return res+p/f;
    }
}

///////////// Recursion with Common (Horner's Rule)

double e3(int x, int n){
    static double res=1;
    if(n==0) return res;
    res = 1 + x/n*res;
    return e(x, n-1);
}

///////////// Recursion with Common (Horner's Rule) - Iterative Approach

double e4(int x, int n){
    double res = 1;
    for(; n>0; n--){                                     // while(n>0){..........  n--;}
        res = 1 + x/(double)n*res;
    }
    return res;
}

/////////////// Taylor Series Ends ///////////////////

////////////// Fibonacci Series ////////////

///////////// Normal Recursion

int fib(int n){
    if(n<=1) return n;
    return fib(n-2)+fib(n-1);
}

///////////// Memoization
int fibarr[10];

int fib2(int n){

    if(n<=1){
        fibarr[n] = n;
        return n;
    }else{
        if(fibarr[n-2]==-1)
            fibarr[n-2] = fib2(n-2);
        if(fibarr[n-1]==-1)
            fibarr[n-1] = fib2(n-1);
        return fibarr[n-2]+fibarr[n-1];
    }
}

///////// ncr Recurion with Factorial function ////////////

int ncr(int n , int r){
    return fact(n)/(fact(r)*fact(n-r));
}

//////////// ncr using Pascal's Triangle /////////////

int ncr2(int n, int r){
    if(r==0 || r==n)
        return 1;
    else
        return ncr2(n-1,r-1)+ncr2(n-1,r);
}

////////////// TOWER OF HANOI //////////////

void TOH(int n, int a, int b, int c){
    if(n>0){
        TOH(n-1,a,c,b);
        cout<<"from "<<a<<" to "<<c<<endl;
        TOH(n-1,b,a,c);
    }
}

////////////////// main() function /////////////////////

int main(){

    int s = sum(5);
    cout<<"Sum of n no's: "<<s<<endl;

    int f = fact(3);
    cout<<"Factorial: "<<f<<endl;

    int exp1 = expnormal(2,4);
    int exp2 = expnew(2,4);
    cout<<"Exponent normal with recurion: "<<exp1<<endl;
    cout<<"Exponent reduced with recurion: "<<exp2<<endl;
    
    double t1 = e(1,10);
    cout<<"Taylor by Iteration: "<<t1<<endl;

    double t2 = e2(1,10);
    cout<<"Taylor by Recursion: "<<t2<<endl;

    double t3 = e3(1,10);
    cout<<"Taylor by Recursion Horner's Rule: "<<t3<<endl;

    double t4 = e4(1,10);
    cout<<"Taylor by Recursion Horner's Rule - Iterative: "<<t4<<endl;

    int fb = fib(5);
    cout<<"Fibonacci no: "<<fb<<endl;

    for(int i=0;i<10;i++){
        fibarr[i]=-1;
    }

    int fb2 = fib2(5);
    cout<<"Fibonacci no with Memoization: "<<fb2<<endl;

    int nc = ncr(5,2);
    cout<<"ncr using factorial: "<<nc<<endl;

    int nc2 = ncr2(5,2);
    cout<<"ncr using Pascal's Triangle: "<<nc2<<endl;

    cout<<"TOH Output"<<endl;
    TOH(3,1,2,3);

    return 0;
}