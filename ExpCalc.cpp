#include <cstdlib>
#include <iostream>
#include <windows.h>
#include <time.h>
#include <stdio.h>
#include <math.h>
#include <conio.h>

// author: Aiyion Prime
// lastedit: 14.02.12 16:42
// v1.0


using namespace std;

void gotoxy(int x, int y)
{
COORD coord;
coord.X = x; coord.Y = y;
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int wait ( int seconds )
{
    clock_t endwait;
    endwait = clock () + seconds * CLK_TCK ;
    while (clock() < endwait)
    {}
  
}


void startscreen()
{
    gotoxy(31, 3);
    cout << "PrimeSoft presents:";
    wait(1);
    gotoxy(34, 5);
    cout << "ExpCalc v1.0";
    wait(1);
    gotoxy(30, 7);
    cout << "Aiyion Prime - 2012- C";
    wait(2);
    system("cls");
}

int experiencecalc (int lvl, int goal)
{
    double dexp;
    int exp;
    int i; //counter
    for(i=lvl; i<=(goal-1); i++)
    {
        dexp = 7 + floor(i * 3.5)+dexp;
        exp = (int) dexp;
        
    }
    return exp;
}
        
void info ()
{
    system("cls");
    gotoxy(18, 7);
    cout << "Das Programm ExperienceCalc geht davon aus,";
    gotoxy(3, 9);
    cout<< "dass der als Ausgangslevel angegebene Level gerade erst erreicht wurde.";
    gotoxy(4, 11);
    cout << "Das bedeutet, der levelinterne Fortschritt wird nicht beruecksichtigt.";
    gotoxy(23, 13);
    system("pause");
    system("cls");
    
}

int main(int argc, char *argv[])
{
    int lvl;
    int goal;
    int exp;
    int getchvar;
    
    
    startscreen();
    
    while(1)
    {
    info();
      
    cout << "Aktueller Level:";
    cin >> lvl;
    cout << endl << "Zu erreichender Level:";
    cin >> goal;
    
    system("cls");
    
    if(goal<lvl)
    {
        cout << "Fehler: Ihr aktueller Level ist groesser als ihr Ziel." << endl;
        system("Pause");
        system("cls");
    }
    if(goal==lvl)
    {
        cout << "Fehler: Ihr aktueller Level identisch mit ihrem Ziel." << endl;
        system("Pause");
        system("cls");
    }
    if(goal<0)
    {
        cout << "Fehler: Ihr Ziel ist ein negativer Level." << endl;
        system("Pause");
        system("cls");
    }
    if(lvl<0)
    {
        cout << "Fehler: Ihr aktueller Level ist negativ." << endl;
        system("Pause");
        system("cls");
    }
    exp=experiencecalc(lvl, goal);
    cout << "Vom Level " << lvl << " bis zum Level " << goal << " werden " << exp << " Erfahrungspunkte benoetigt." << endl;
    cout << endl << "Zur Neuberechnung r(estart) druecken. Jede andere Taste beendet das Programm." << endl;
    
    getchvar = getch();
    system("cls");
    
    if (getchvar!=114)
    {
        cout << "Aiyion Prime.";
        wait(1);
        
        
        return EXIT_SUCCESS;
    }
}
    
    
    
}
