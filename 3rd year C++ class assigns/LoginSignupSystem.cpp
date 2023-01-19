#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

vector <string> userarr = {"ankush09", "jiya_001"};
vector <string> passarr = {"ankush1", "Jiya@89"};
string username, password;
int index;
bool flag = false;

//////////////// For login:

void checkusername(string username)
{
    for (int i = 0; i < userarr.size(); i++)
    {
        if (userarr[i] == username)
        {
            flag = true;
            index = i;
            return;
        }
    }
    cout << "This username doesn't exist!" << endl;
    cout << "Enter another username: ";
    cin >> username;
    checkusername(username);
}

void checkpassword()
{
    if (flag == true)
    {
        cout << "Enter your password: ";
        cin >> password;
        if (passarr[index] == password)
        {
            cout << "Successfully logged in!" << endl;
        }
        else
        {
            cout << "Wrong Password!!" << endl;
            cout << "Try another Password: " << endl;
            checkpassword();
        }
    }
}

/////////// For Signup:

void validatepassword(string s)
{
    int strength = 0;
    if (s.length() >= 8)
        strength++;

    int up = 0, low = 0, dig = 0, specialchar = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= 65 && s[i] <= 90)
            up++;
        else if (s[i] >= 97 && s[i] <= 122)
            low++;
        else if(s[i] >= 48 && s[i] <= 57)
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
        cout << "Signed up Successfully!" << endl;
        passarr.push_back(password);
    }
    else
    {
        cout << "Your password isn't strong!" << endl;
        cout << "Enter a password with at least one upper case char, digit & special char: ";
        cin >> password;
        validatepassword(password);
    }
}


void validateusername(string username)
{
    bool flag3 = true;
    for (int i = 0; i < userarr.size(); i++)
    {
        if (userarr[i] == username)
        {
            cout << "This username already exists!" << endl;
            cout << "Try another good username!" << endl;
            flag3 = false;
            break;
        }
    }
    if (flag3 == false)
    {
        cout << "Enter another good username: ";
        cin >> username;
        validateusername(username);
    }
    else
    {
        bool uflag = true;
        for (int i = 0; i < username.length(); i++)
        {
            if (!((username[i] >= 97 && username[i] <= 122) || (username[i] >= 48 && username[i] <= 56) || (username[i] == 95)))
            {
                uflag = false;
                break;
            }
        }
        if (uflag == false)
        {
            cout << "Invalid Username!" << endl;
            cout << "A username can only contain [a-z] or [0-9] or _" << endl;
            cout << "Enter another username: ";
            cin >> username;
            validateusername(username);
        }
        else
        {
            cout << "Username accepted :)" << endl;
            userarr.push_back(username);
            cout << "Enter one strong password: " << endl;
            cin >> password;
            validatepassword(password);
        }
    }
}

int main()
{

    cout << "Do you want to login or signup?" << endl;
    cout << "Enter 1 for login and 2 for signup: ";
    int n;
    cin >> n;

    if (n == 1)
    {
        cout << "Enter your username: ";
        cin >> username;
        checkusername(username);
        checkpassword();
    }
    else if (n == 2)
    {
        cout << "Enter one good username: ";
        cin >> username;
        validateusername(username);
    }

    return 0;
}