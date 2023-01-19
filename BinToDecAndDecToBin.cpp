#include<iostream>
#include<bits/stdc++.h>
using namespace std;
                                                   // Binary to Decimal
// int main(){
//     int n;
//     cin>>n;

//     int dec=0, i=0;

//     while(n!=0){
//         int rem = n%10;
//         dec = dec + rem*pow(2,i);
//         ++i;
//         n=n/10;
//     }
//     cout<<dec;

//     return 0;
// }

                                                        // Decimal to Binary


// void decToBinary(int n)
// {
//     int binary[32];
//     int i = 0;
//     while (n != 0)
//     {
//         binary[i] = n % 2;
//         n = n / 2;
//         i++;
//     }
//     for (int j = i - 1; j >= 0; j--)
//     {
//         cout << binary[j];
//     }
// }
// int main()
// {
//     decToBinary(9);

//     return 0;
// }


                                                    // Decimal to Binary

int main(){
    string s = "";
    int n;
    cin>>n;

    while(n!=0){
        int rem = n%2;
        s = s + to_string(rem);
        n=n/2;
    }

    for(int i=s.length() - 1; i>=0; i--){
        cout<<s[i];
    }

    return 0;
}