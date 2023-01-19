#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool win = false;
string p1, p2;  // Player Names
char arr[3][3] = {{-1, -1, -1}, {-1, -1, -1}, {-1, -1, -1}};
int m, n; // Input Indexes


void callPlayer(string p)
{
    cout << "It's your turn " << p << endl;
}

bool checkWin()
{
    win = true;
}

void printArr(char arr[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << "|" << arr[i][j] << "|"
                 << " ";
        }
        cout << endl;
    }
}

void Game()
{
    while (win == false)
    {

        for (int i = 0; i < 9; i++)
        {
            cout << i << endl;
            if (i % 2 == 0)
            {
                cout << "Inside if" << endl;
                callPlayer(p1);
                cin >> m >> n;
                if (arr[m][n] == -1 && arr[m][n] != 'O')
                {
                    arr[m][n] = 'X';
                }
                else
                {
                    Game();
                }
                printArr(arr);
            }
            else
            {
                cout << "Inside else" << endl;
                callPlayer(p2);
                cin >> m >> n;
                if (arr[m][n] == -1 && arr[m][n] != 'X')
                {
                    arr[m][n] = 'O';
                }else{
                    Game();
                }
                printArr(arr);
            }
            checkWin();
        }
    }
}

int main()
{

    cout << "Namaste!" << endl;
    cout << "Enter Player 1's name: ";
    cin >> p1;
    cout << "Enter Player 2's name: ";
    cin >> p2;

    cout << "Welcome " << p1 << " & " << p2 << " to the TIC-TAC-TOE game, We wish you both Good luck :)" << endl;


    cout << "This will be your base: " << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << "|" << i << "," << j << "|"
                 << " ";
        }
        cout << endl;
    }

    cout << p1 << ", Your char will be 'X' and " << p2 << " yours will be 'O' respectively!" << endl;
    cout << "To insert your char at desired position, give respective indices :)" << endl;

    Game();


    return 0;
}