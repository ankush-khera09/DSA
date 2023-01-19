#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int cuindex;
bool cuflag = false;
string password;
int n; // First Input for welcome()

void checkusername(string username, vector <string> userarr)
{
    for (int i = 0; i < userarr.size(); i++)
    {
        if (userarr[i] == username)
        {
            cuflag = true;
            cuindex = i;
            return;
        }
    }
    cout << "This username doesn't exist!" << endl;
    cout << "Enter another username: ";
    cin >> username;
    checkusername(username, userarr);
}

void checkpassword(vector <string> passarr)
{
    if (cuflag == true)
    {
        cout << "Enter your password: ";
        cin >> password;
        if (passarr[cuindex] == password)
        {
            cout << "Successfully logged in!" << endl;
            cout<<endl;
        }
        else
        {
            cout << "Wrong Password!!" << endl;
            cout << "Try another Password: " << endl;
            checkpassword(passarr);
        }
    }
}

string login(vector <string> userarr, vector <string> passarr){
    cout<<"Enter Username: ";
    string username;
    cin>>username;
    checkusername(username, userarr);
    checkpassword(passarr);
    return username;
}

class Student{
    public:
    vector <string> Studuserarr = {"ankush09", "bob_1"};
    vector <string> Studpassarr = {"ankush1", "Bob@89"};
    vector <string> Studname = {"Ankush", "Bob"};
    vector <string> Studage = {"19", "20"};
    vector <string> Studrollno = {"1826", "1989"};
    vector <string> Studgroup = {"1", "2"};
    
};

class Teacher{
    public:
    vector <string> Teauserarr = {"pankaj09", "prateek_1"};
    vector <string> Teapassarr = {"pankaj1", "Prateek@89"};
    vector <string> Teaname = {"Pankaj", "Prateek"};
    vector <string> Teaage = {"39", "28"};
    vector <string> Teaid = {"T1", "T2"};
    vector <string> Teasubject = {"OOPS", "Python"};
};

class Staff{
    public:
    vector <string> Staffuserarr = {"ram09", "aman_1"};
    vector <string> Staffpassarr = {"ram1", "Aman@89"};
    vector <string> Staffname = {"Ram", "Aman"};
    vector <string> Staffage = {"29", "32"};
    vector <string> Staffid = {"S1", "S2"};
    vector <string> Staffwork = {"Accountant", "Receptionist"};
};

Teacher t;
Student s;
Staff st;

string u;

void validatepassword(string, vector<string>);           // Forward Declaration
void welcomeinfo();
void welcome();


void updatepass(vector <string> passarr){
    bool upd = false;
    cin>>password;
    if(passarr[cuindex]==password){
        upd = true;
    }

    if(upd==true){
        cout<<"Enter one new good password: ";
        cin>>password;
        validatepassword(password, passarr);
    }else{
        cout<<"Password didn't match!"<<endl;
        cout<<"Enter old Password again: "<<endl;
        updatepass(passarr);
    }
}

void loginStu(){
    cout<<"Enter: ";
    cin>>n;
    switch (n)
    {
    case 1:
        cout<<"Name: "<<s.Studname[cuindex]<<endl;
        cout<<"Age: "<<s.Studage[cuindex]<<endl;
        cout<<"Roll No: "<<s.Studrollno[cuindex]<<endl;
        cout<<"Group: "<<s.Studgroup[cuindex]<<endl;
        break;
    
    case 2:
        cout<<"Enter old password: ";
        updatepass(s.Studpassarr);
        break;

    case 3:
        cout<<"Logged out Successfully!"<<endl;
        cout<<"Thank You, Will meet you again :)"<<endl;
        cout<<endl;
        welcomeinfo();
        welcome();
        break;
    
    default:
        cout<<"Invalid Input :("<<endl;
        loginStu();
        break;
    }
}

void loginTea(){
    cout<<"Enter: ";
    cin>>n;
    switch (n)
    {
    case 1:
        cout<<"Name: "<<t.Teaname[cuindex]<<endl;
        cout<<"Age: "<<t.Teaage[cuindex]<<endl;
        cout<<"Id: "<<t.Teaid[cuindex]<<endl;
        cout<<"Subject: "<<t.Teasubject[cuindex]<<endl;
        break;
    
    case 2:
        cout<<"Enter old password: ";
        updatepass(t.Teapassarr);
        break;

    case 3:
        cout<<"Logged out Successfully!"<<endl;
        cout<<"Thank You, Will meet you again :)"<<endl;
        cout<<endl;
        welcomeinfo();
        welcome();
        break;
    
    default:
        cout<<"Invalid Input :("<<endl;
        loginTea();
        break;
    }
}

void loginStaff(){
    cout<<"Enter: ";
    cin>>n;
    switch (n)
    {
    case 1:
        cout<<"Name: "<<st.Staffname[cuindex]<<endl;
        cout<<"Age: "<<st.Staffage[cuindex]<<endl;
        cout<<"Id: "<<st.Staffid[cuindex]<<endl;
        cout<<"Subject: "<<st.Staffwork[cuindex]<<endl;
        break;
    
    case 2:
        cout<<"Enter old password: ";
        updatepass(st.Staffpassarr);
        break;

    case 3:
        cout<<"Logged out Successfully!"<<endl;
        cout<<"Thank You, Will meet you again :)"<<endl;
        cout<<endl;
        welcomeinfo();
        welcome();
        break;
    
    default:
        cout<<"Invalid Input :("<<endl;
        loginStaff();
        break;
    }
}

void welcomeinfo(){
    cout<<"Welcome to the Khera's University :)"<<endl;
    cout<<"Input 1, 2 or 3 accordingly:"<<endl;
    cout<<"1: Login as a Teacher"<<endl;
    cout<<"2: Login as a Student"<<endl;
    cout<<"3: Login as a Staff Member"<<endl;
    cout<<"4: Exit"<<endl;
}


void welcome(){
    cin>>n;

    switch (n)
    {
    case 1:
        u = login(t.Teauserarr, t.Teapassarr);
        cout<<"Welcome "<<u<<" !"<<endl;
        cout<<"What do you want to do?"<<endl;
        cout<<endl;
        cout<<"Enter input accordingly: "<<endl;
        cout<<"1: View my personal details"<<endl;
        cout<<"2: Change Password"<<endl;
        cout<<"3: Logout"<<endl;

        loginTea();
        break;

    case 2:
        u =login(s.Studuserarr, s.Studpassarr);
        cout<<"Welcome "<<u<<" :)"<<endl;
        cout<<"What do you want to do?"<<endl;
        cout<<endl;
        cout<<"Enter input accordingly: "<<endl;
        cout<<"1: View my personal details"<<endl;
        cout<<"2: Change Password"<<endl;
        cout<<"3: Logout"<<endl;
        
        loginStu();
        break;

    case 3:
        u = login(st.Staffuserarr, st.Staffpassarr);
        cout<<"Welcome "<<u<<" :)"<<endl;
        cout<<"What do you want to do?"<<endl;
        cout<<endl;
        cout<<"Enter input accordingly: "<<endl;
        cout<<"1: View my personal details"<<endl;
        cout<<"2: Change Password"<<endl;
        cout<<"3: Logout"<<endl;

        loginStaff();
        break;

    case 4:
        return;
    
    default:
        cout<<"Invalid Input!"<<endl;
        cout<<"Enter again: ";
        welcome();
        break;
    }
}

void validatepassword(string strp, vector <string> passarr)
{
    int strength = 0;
    if (strp.length() >= 8)
        strength++;

    int up = 0, low = 0, dig = 0, specialchar = 0;
    for (int i = 0; i < strp.length(); i++)
    {
        if (strp[i] >= 65 && strp[i] <= 90)
            up++;
        else if (strp[i] >= 97 && strp[i] <= 122)
            low++;
        else if(strp[i] >= 48 && strp[i] <= 57)
            dig++;
        else
            specialchar++;
        if (up >= 1 && low >= 1 && dig>=1 && specialchar>=1)
        {
            strength++;
            break;
        }
    }

    if (strength == 2)
    {
        cout << "Password Updated Successfully!" << endl;

        if(passarr[cuindex] == s.Studpassarr[cuindex])
        {
            s.Studpassarr[cuindex] = strp;
        }
        else if(passarr[cuindex] == t.Teapassarr[cuindex]){
            t.Teapassarr[cuindex] = strp;
        }
        else if(passarr[cuindex] == st.Staffpassarr[cuindex]){
            st.Staffpassarr[cuindex] = strp;
        }

        // passarr[cuindex] = strp;
        // cout<<passarr[cuindex]<<endl;
        // cout<<t.Teapassarr[cuindex]<<endl;
        // cout<<s.Studpassarr[cuindex]<<endl;
        cout<<"You have been logged out! Login again with new password ;)"<<endl;
        cout<<endl;
        welcomeinfo();
        welcome();
    }
    else
    {
        cout << "Your password isn't strong!" << endl;
        cout << "Enter a password with at least one upper case char, digit & special char: ";
        cin >> password;
        validatepassword(password, passarr);
    }
}


int main(){
    
    welcomeinfo();
    welcome();

    return 0;
}
