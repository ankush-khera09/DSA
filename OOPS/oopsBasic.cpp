// Topics Covered:
// 1. size of class, empty class, padding for alignment
// 2. getters and setters
// 3. Default & Parameterised Constructors
// 4. 'this' keyword
// 5. Copy Constructor
// 6. Shallow & deep copy
// 7. Destructors
// 8. Static members

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// size of empty class is 1 byte & its given only for identification and tracking
class Sample{};
// size of this class with one int var would be 4 bytes
class Sample2{int x;};
// size of class = sum of all non-static data members + padding
// to ensure proper alignment, the compiler adds 3 bytes of padding after char y to make the total size 8 bytes.
// This is because most compilers align int to a 4-byte boundary for efficient access.
class Sample3{int x; char y;};

// To access private members of a class, we need getter and setter functions
class GetSet{
    int x;         // private member

    public:
        int getx(){ return x;};
        void setx(int data){x = data;};

        ~GetSet(){
            cout<<"GetSet destructor called"<<endl;
        }
};

class Hero{
    int health;

    public:
        char* name;
        
        Hero(){
            name = new char[100];     // initialising size of char array
            cout<<"Default constructor called!"<<endl;
        }

        // 'this' keyword => it is a pointer which refers to current calling object
        // it stores the address of an object;
        Hero(int h){
            this->health = h;
            // cout<<this<<endl;       // will print address of object
        }

        // Copy Constructor
        // we used & as when we don't use & => it will be 'Pass by value'
        // and in pass by value, a copy is made => so, a copy of that parameter object will be
        // made in temp & for this copy to be made, copy const will be called & it will see temp again
        // it will be a kind of infinite loop
        // Hero(Hero& temp){
        //     this->health = temp.health;
        // }

        // Deep Copy:
        Hero(Hero& temp){
            char* ch = new char[strlen(temp.name)+1];    // taking same length as temp
            strcpy(ch, temp.name);      // copy temp.name to newly made ch
            this->name = ch;           // assign ch to 'name'

            this->health = temp.health;
        }

        void printHealth(){
            cout<<health<<endl;
        }

        Hero(char* name){
            this->name = name;
        }

        void printName(){
            cout<<name<<endl;
        }

        // Destrutors are also automatically created and called to deallocate memory
        // In case of static allocation => destructor is called automatically
        // In case of dynamic allocation => destructor is called manually
        ~Hero(){
            cout<<"Destructor called"<<endl;
        }

        static int timeToComplete;
};

int Hero::timeToComplete = 5;      // static member's associativity is with class and not object
// static functions can access only static variables

int main(){
    
    cout<<"Size of empty class: "<<sizeof(Sample)<<endl;
    cout<<"Size of class with one int var: "<<sizeof(Sample2)<<endl;
    cout<<"Size of class with padding: "<<sizeof(Sample3)<<endl;

    GetSet g;
    g.setx(3);
    cout<<"Using Getters & Setters: "<<g.getx()<<endl;

    // Dynamic Allocation in Heap
    GetSet *dynamic = new GetSet;
    (*dynamic).setx(5);          // can either use this dereference operator
    cout<<"Dynamic Allocation: "<<dynamic->getx()<<endl;       // or this arrow operator

    cout<<"Copy Constructor:"<<endl;
    Hero ankush(100);
    ankush.printHealth();

    // Two syntax of using copy constructor:
    // Hero copied(ankush);
    Hero copied = ankush;
    copied.printHealth();

    // Shallow & Deep Copy:

    // Default copy constructor always make shallow copy
    // here if we change Babbar to Gabbar so for both objects shallow and copiedShallow
    // it will be changed as copiedShallow will also be referring the same 'name'
    char name[7] = "Babbar";
    Hero shallow(name);
    shallow.printName();

    Hero copiedShallow(shallow);
    copiedShallow.name[0] = 'G';
    copiedShallow.printName();

    // For deep copy, we make our own copy constructor and make a separate char arr
    // See above code in class

    // we need to call destructor manually in case of dynamic allocation
    // delete it then destructor will be called to free up memory space
    delete dynamic;

    cout<<Hero::timeToComplete<<endl;       // static members

    return 0;
}