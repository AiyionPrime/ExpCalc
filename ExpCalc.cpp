#include <cstdlib>
#include <iostream>
#include <windows.h>
#include <time.h>
#include <stdio.h>
#include <math.h>
#include <conio.h>

// author: Aiyion Prime
// lastedit: 20.02.12 23:14
// v1.1


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
    cout << "ExpCalc v1.1";
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
    int err=0; // Error Variable für jeden Fehler, der Durch die Eingabe von unmöglichen Leveln entsteht, wir err=err+1
    
    
    startscreen();
    
    while(1)
    {
    err=0;
    lvl=0;
    goal=0;
    exp=0;
    getchvar=0;
    
    
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
        err=err+1;
    }
    if(goal==lvl)
    {
        cout << "Fehler: Ihr aktueller Level ist identisch mit ihrem Ziel." << endl;
        system("Pause");
        system("cls");
        err=err+1;
    }
    if(goal<0)
    {
        cout << "Fehler: Ihr Ziel ist ein negativer Level." << endl;
        system("Pause");
        system("cls");
        err=err+1;
    }
    if(lvl<0)
    {
        cout << "Fehler: Ihr aktueller Level ist negativ." << endl;
        system("Pause");
        system("cls");
        err=err+1;
    }
    if(lvl>=200)
    {
        cout << "Warnung: Sie sollten Ihre Erfahrungslevel erst aufbrauchen, bevor sie weitere aufbauen." << endl;
        system("Pause");
        system("cls");
    }
    if (goal>=200)
    {
        cout << "Warnung: Es gibt keine Verzauberung, die eine solch hohe Zielstufe erfordert." << endl << "Sie sollten sich ein niedrigeres Ziel setzen." << endl;
        system("pause");
        system("cls");
    }
    if (lvl>10000 || goal > 10000)
    {
        cout << "Fehler: Mindestens einer der beiden angegebenen Level liegt ueber 10000." << endl << "Einen solch hohen Level zu erreichen ist nahezu unmoeglich." << endl << "Eine Berechnung groesserer Zahlen wuerde erheblich mehr Zeit erfordern" << endl << "Anfrage wird abgebrochen."<< endl;
        system("pause");
        system("cls");
        err=err+1;
    }
    
    
    if (err==0)
    {
    exp=experiencecalc(lvl, goal);
    cout << "Vom Level " << lvl << " bis zum Level " << goal << " werden " << exp << " Erfahrungspunkte benoetigt." << endl;
    
    }
    if (err>0)
    {
        cout << "Es wurde(n) bei der Eingabe der Level " << err << " Fehler gemacht." << endl << "Geben sie reelle und realistische Werte ein." << endl << endl;
        
        
    }
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
