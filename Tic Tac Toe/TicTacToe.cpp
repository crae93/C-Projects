#include <iostream>
#include <vector>
#include <string>

using namespace std;

char row1[] = "...";
char row2[] = "...";
char row3[] = "...";

void drawBoard()
{
    //change
cout << row1 << endl;
cout << row2 << endl;
cout << row3 << endl;
}

bool resolveConflict(int row, int column)
{
    char selection;
if (row == 1)
{
    selection = row1[column - 1];
} else if (row == 2)
{
    selection = row2[column - 1]; 
} else {
    selection = row3[column - 1];
}

if (selection == 'X' || selection == 'O')
{
    cout << "This spot is taken! Try Again!" << endl;
   return true;
} else {return false;}
}

void takeTurn(bool lastTurn)
{ 
int row = 0; 
int column = 0;
char player;

    if (lastTurn == 1)
    {  
        player = 'X';
        lastTurn = lastTurn - 1;

    } else {
        player = 'O';
        lastTurn = lastTurn + 1;
    }
        while (row < 1 || row > 3)
        {
     cout << player <<"'s Turn. Which row do you want?" << endl;
     cin >> row;
         if (row > 0 && row < 4)
         {
             while (column < 1 || column > 3)
             {
            cout << "Which Column do you want?" << endl;
            cin >> column;
            

            if (column < 1 || column > 3)
            {
                cout << "Invalid Column Number!" << endl;
            }
             }
             
         } else {cout << "Invalid Row Number" << endl;}

         if (resolveConflict(row, column) == 1)
             {
                 row = 0;
                 column = 0;
             }
        }

if(row == 1)
{
    row1[column - 1] = player;
} else if (row == 2)
{
    row2[column - 1] = player;
} else
{
    row3[column - 1] = player;
}
     
}

bool checkRows()
{
    string X = "XXX";
    string O = "OOO";

if(row1 == X || row1 == O)
{
    return true;
} else if(row2 == X || row2 == O)
{
    return true;
} else if(row3 == X || row3 == O)
{
    return true;
} else {return false;}
}

bool checkCols()
{
    char p = '.';
    for(int i = 0; i <= 2; i++)
    {
        char a = row1[i];
        char b = row2[i];
        char c = row3[i];

        if (a == b && b == c)
        {
            if(b == p)
            {
                return false;
            } else { return true;}
        }
    }
return false;
}

bool checkDiags()
{
    char p = '.';
    char a = row1[0];
    char b = row2[1];
    char c = row3[2];
    char d = row1[2];
    char e = row3[0];

    if(a == b && b == c && b !=p)
    {
        return true;
    } else if(d == b && b == e && d != p)
        {
        return true;
        } else {return false;}
}

bool checkWinner(int turns, int lastTurn)
{
   
if (turns > 0)
{
if(checkRows() == true||checkCols() == true||checkDiags() == true)
{
    return true;
}else {
    return false;}
} else {
    return false;}
}

int main()
{
    bool lastTurn = 1;
    int turns = 0;

while (checkWinner(turns, lastTurn) == false)
{
drawBoard();
takeTurn(lastTurn);
turns++;
if (checkWinner(turns, lastTurn) == true || turns == 9)
{
    break;
} else{
lastTurn = 1 - lastTurn;
cout << endl;
}
}

if (turns == 9)
{
    drawBoard();
    cout << "Cats Game!" << endl;
} else if (lastTurn == 1)
{
    drawBoard();
    cout << "Congratulations X wins!" << endl; 
} else {
    drawBoard();
    cout << "Congratulations O wins!" << endl;
}
}