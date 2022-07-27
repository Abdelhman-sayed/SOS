/*FACULTY OF COMPUTERS AND ARTIFICIAL INTELLIGENCE, CAIRO UNIVERSITY
Author : Abdelrhman sayed ali
Program Name: SOS Game.c plus plus*/
#include <iostream>
#include <string>
#include <regex>
#include <iomanip>
#include <cstring>
#include <cmath>
#include <cctype>
#include <cstdlib>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <array>
#include<windows.h>

using namespace std;

int counterP1 = 0;
int counterP2 = 0;

bool flag1 = true, flag2 = true, flag3 = true, flag4 = true, flag5 = true, flag6 = true,
flag7 = true, flag8 = true;
bool swtich_count = true;  

void functionPlay(int& counterP1, int& counterP2, string board[9]);
void drawBoard(int& counterP1, int& counterP2, string board[9]);
void funPlayer1(string board[9]);
void checkPlayer(int& counterP1, int& counterP2, string board[9]);
void funPlayer2(string board[9]);
int winner(int& counterP1, int& counterP2, string board[9]);
void setTextColor(int n);

int main()
{
    setTextColor(9);
    system("cls");
    cout << "\n\n                                    <<-------WELCOME USER IN THIS GAME------->>\n" << endl;
    cout << "\n                                            ***** SOS Game*****\n" << endl;

    string board[9] = {"1", "2", "3", "4", "5", "6", "7", "8", "9"};
    cout << "\t Player[1] : [S OR O]\n\t Player[2] : [O OR S]\n\n";
    functionPlay(counterP1, counterP2, board);
    
}

void functionPlay(int& counterP1, int& counterP2, string board[9])
{
   
    drawBoard(counterP1, counterP2, board);
    funPlayer1(board);
    checkPlayer(counterP1, counterP2, board);
    drawBoard(counterP1, counterP2, board);
    funPlayer2(board);  
}

void drawBoard(int& counterP1, int& counterP2, string board[9]) 
{
    cout << "\n\t Score Of Player[1] is : " << counterP1
         << "\n\t Score Of Player[2] is : " << counterP2 << "\n\n";
    
    cout << "\t\t******************\n";
    cout << "\t\t|    ||    ||    |\n";
    cout << "\t\t|  " << board[0] << " ||  " << board[1] << " ||  " << board[2] << " |\n";
    cout << "\t\t ____||____||____|\n";
    cout << "\t\t|    ||    ||    |\n";
    cout << "\t\t|  " << board[3] << " ||  " << board[4] << " ||  " << board[5] << " |\n";
    cout << "\t\t ____||____||____\n";
    cout << "\t\t|    ||    ||    |\n";
    cout << "\t\t|  " << board[6] << " ||  " << board[7] << " ||  " << board[8] << " |\n";
    cout << "\t\t|    ||    ||    |\n";
    cout << "\t\t******************\n";
 
}

void funPlayer1(string board[9])
{

    string Position_Player1, Played1;
    regex filter1("[1-9]?");
    regex filter2("(S|O){1}");
   
    while (true)
    {
        cout << "\n<<<Please first Player, Enter the position you want to play in it : \n>>>";
        cin >> Position_Player1;
        if (!regex_match(Position_Player1, filter1))
        {
            cout << "     **** invaild input! ****"<< endl;
            continue;
        }
        else
        {
            break;
        }  
    
    }
    int p1 = stoi(Position_Player1);
    if ((Position_Player1 != board[p1-1]) && ((board[p1-1] == "S") || (board[p1-1] == "O")))
    {
        cout << "       **** This position is not available because it was previously played ****\n" 
        << "                      <<<[----Please, play in another position----]>>>\n";
        funPlayer1(board);   
    }
  
    cout << "\n";
    while (true)
    {
        cout << "<<<Please first Player, Enter S or O : \n>>>";
        cin >> Played1;
        if (!regex_match(Played1, filter2))
        {
            cout << "     **** invaild input! ****"<< endl;
            continue;
        }
        else
        {
            board[p1-1] = Played1;
            break;
        }  
    }
    swtich_count = true;
}


void funPlayer2(string board[9])
{
    string Position_Player2, Played2;
    regex filter1("[1-9]?");
    regex filter2("(S|O){1}");
    
    if (board[0] != "1" && board[1] != "2" && board[2] != "3" && board[3] != "4" && board[4] != "5" &&
    board[5] != "6" && board[6] != "7" && board[7] != "8" && board[8] != "9")
    {
        winner(counterP1, counterP2, board);
    }
    else
    {
        while (true)
        {
            cout << "<<<Please second Player, Enter the position you want to play in it : \n>>>";
            cin >> Position_Player2;
        if (!regex_match(Position_Player2, filter1))
            {
                cout << "     **** invaild input! ****"<< endl;
                continue;
            }
        else
            {
                break;
            }  
        
        }
        int p2 = stoi(Position_Player2);
        if ((Position_Player2 != board[p2-1]) && ((board[p2-1] == "S") || (board[p2-1] == "O")))
        {
            cout << "       **** This position is not available because it was previously played ****\n" 
            << "                      <<<[----Please, play in another position----]>>>\n";
            funPlayer2(board);   
        }
    
        cout << "\n";
        while (true)
        {
            cout << "<<<Please second Player, Enter S or O : \n>>>";
            cin >> Played2;
            if (!regex_match(Played2, filter2))
            {
                cout << "     **** invaild input! ****"<< endl;
                continue;
            }
            else
            {
                board[p2-1] = Played2;
                break;
            }  
        }
        swtich_count = false;
        checkPlayer(counterP1, counterP2, board);
        functionPlay(counterP1, counterP2, board);
    }

}

void checkPlayer(int& counterP1, int& counterP2, string board[9])
{
    if(((board[0] == "S") && (board[1] == "O") && (board[2] == "S")) && (flag1 == true))
    {
       
        if (swtich_count)
        {
            counterP1 += 1;
            
        }
        else if(!swtich_count)
        {
            counterP2 += 1;
        } 
        flag1 = false;
    }
    else if(((board[3] == "S") && (board[4] == "O") && (board[5] == "S")) && (flag2 == true))
    {
        
        if (swtich_count)
        { 
            counterP1 += 1;
        
        }
        else if(!swtich_count)
        {
            counterP2 += 1;
        } 
        flag2 = false;
    }
    else if(((board[6] == "S") && (board[7] == "O") && (board[8] == "S")) && (flag3 == true))
    {
       
        if (swtich_count)
        {
            counterP1 += 1;
        }
        else if(!swtich_count)
        {
            counterP2 += 1;
        } 
        flag3 = false;
    }
    else if(((board[0] == "S") && (board[3] == "O") && (board[6] == "S")) && (flag4 == true))
    {
      
        if (swtich_count)
        {
            counterP1 += 1;
        }
        else if(!swtich_count)
        {
            counterP2 += 1;
        } 
        flag4 = false;
    }
    else if(((board[1] == "S") && (board[4] == "O") && (board[7] == "S")) && (flag5 == true))
    {
        
        if (swtich_count)
        {
            counterP1 += 1;
           
        }
        else if(!swtich_count)
        {
            counterP2 += 1;
        }
        flag5 = false; 
    }
    else if(((board[2] == "S") && (board[5] == "O") && (board[8] == "S")) && (flag6 ==true))
    {
        if (swtich_count)
        {
            counterP1 += 1;
           
        }
        else if(!swtich_count)
        {
            counterP2 += 1;
         
        } 
        flag6 = false;
    }
    else if(((board[0] == "S") && (board[4] == "O") && (board[8] == "S")) && (flag7 == true))
    {
        if (swtich_count)
        {
            counterP1 += 1;
         
        }
        else if(!swtich_count)
        {
            counterP2 += 1;
        }  
        flag7 = false;
    }
    else if(((board[2] == "S") && (board[4] == "O") && (board[6] == "S")) && (flag8 == true))
    {
        if (swtich_count)
        {
            counterP1 += 1;
        }
        else if(!swtich_count)
        {
            counterP2 += 1;
        }

        flag8 = false;
    }

    else
    {
        if (swtich_count)
        {
            counterP1 += 0;

        }
        else if (!swtich_count)
        {
            counterP2 += 0;
        }
    }
}

int winner(int& counterP1, int& counterP2, string board[9])
{
   
    if (counterP1 > counterP2)
    {
        cout << "\n\n               *** Score Of Player[1] is : " << counterP1 << " ***";
        cout << "\n\n               *** Score Of Player[2] is : " << counterP2 << " *** \n";
        cout << "\n         ***** PLAYER NUMBER ONE --->>>  IS WINNER *****\n\n" << endl;
        return 0;
    }
    else if (counterP2 > counterP1)
    {
        cout << "\n\n               *** Score Of Player[1] is : " << counterP1 << " ***";
        cout << "\n\n               *** Score Of Player[2] is : " << counterP2 << " *** \n";
        cout << "\n         *****PLAYER NUMBER TWO --->>> IS WINNER*****\n\n" << endl;
        return 0;
    }
    else
    {
        cout << "\n\n           *** Score Of Player[1] is : " << counterP1 << " ***";
        cout << "\n\n           *** Score Of Player[2] is : " << counterP2 << " *** \n";
        cout << "\n              [(*****The players are Draw*****)]\n\n";
        return 0;

    }
}
void setTextColor(int n)
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, n);
}

