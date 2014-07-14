#include <cstdlib>
#include <iostream>
#include <windows.h>
#include <time.h>
#include <stdio.h>
#include <math.h>
#include <conio.h>

// author: Aiyion Prime
// lastedit: 28.02.12 19:36
// v1.6.0


using namespace std;

enum Colors { blue=1, green, cyan, red, purple, yellow, grey, dgrey, hblue, hgreen, hred, hpurple, hyellow, hwhite };
enum mobs {chicken=0, cow, mooshroom, pig, sheep, squid, enderman, wolf, zombiepigman, blaze, creeper, ghast, silverfish, skeleton, spider, zombie, enderdragon};


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

void spinstep(int akt, int step)
{
    int i=0; //Counter
    int Position [18] [2];
    
    for(i=0;i<18;i++)
    {
        Position [i] [0]=0;
    }
    for(i=0;i<18;i++)
    {
        Position [i] [1]=0;
    }
}

void coutc(int color, char* output) //farbiges schreiben
{
    HANDLE handle= GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute( handle, color);
    cout<< output;
    color=15;
    SetConsoleTextAttribute( handle, color);
}


void startscreen()
{
    gotoxy(31, 3);
    cout << "PrimeSoft presents:";
    wait(1);
    gotoxy(34, 5);
    cout << "ExpCalc v1.6.0";
    wait(1);
    gotoxy(30, 7);
    cout << "Aiyion Prime - 2012- C";
    wait(2);
    system("cls");
}

int getKey()
{
    int result=getch();
    if(result==0)
    {
        result=256+getch();
    }
    if (result==224)
    {
        result=512+getch();
    }
      
   return result;
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

void mobname(int aktmob)
{
    switch(aktmob)
    {
        case 0:
            {
                cout << "Huhn";
                break;
            }
        case 1:
            {
                cout << "Kuh";
                break;
            }
        case 2:
            {
                cout << "Pilzkuh";
                break;
            }
        case 3:
            {
                cout << "Schwein";
                break;
            }
        case 4:
            {
                cout << "Schaf";
                break;
            }
        case 5:
            {
                cout << "Tintenfisch";
                break;
            }
        case 6:
            {
                cout << "Enderman";
                break;
            }
        case 7:
            {
                cout << "Wolf";
                break;
            }
        case 8:
            {
                cout << "Zombie Pigman";
                break;
            }
        case 9:
            {
                cout << "Blaze";
                break;
            }
        case 10:
            {
                cout << "Creeper";
                break;
            }
        case 11:
            {
                cout << "Ghast";
                break;
            }
        case 12:
            {
                cout << "Silverfish";
                break;
            }
        case 13:
            {
                cout << "Skelett";
                break;
            }
        case 14:
            {
                cout << "Spinne";
                break;
            }
        case 15:
            {
                cout << "Zombie";
                break;
            }
        case 16:
            {
                cout << "Enderdrache";
                break;
            }
        default:
            {
                cout << "Error.";
            }
    }
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
    int secondtry=0; // wird statt einer Zahl ein Buchstabe eingegeben wird die Levelabfrage Wiederholt (secondtry wird 1)
    int key=0; //Variable, in der Der "Ascii" Wert einer Taste gespeichert wird
    int i; //Counter
    int akt=0; //Aktueller Mob (Im roll screen)
    int aktvor=0; //Mob vor dem aktuellen mob (im roll screen)
    int aktvorvor=0; //nonused
    int aktnach=0; //Mob nach dem aktuellen mob
    int aktnachnach=0; //nonused
    int div=0;
    
    int mob [17] [3];
    
    //Mob exp definition
    
    mob [0] [0] = 1; //huhn min = 1
    mob [0] [1] = 2; //huhn Durchschnitt = 2
    mob [0] [2] = 3; //huhn max = 3
    
    mob [1] [0] = 1; //Kuh min = 1
    mob [1] [1] = 2; //Kuh Durchschnitt = 2
    mob [1] [2] = 3; //Kuh max = 3
    
    mob [2] [0] = 1; //mooshroom min = 1
    mob [2] [1] = 2; //mooshroom Durchschnitt = 2
    mob [2] [2] = 3; //mooshroom max = 3
    
    mob [3] [0] = 1; //pig min = 1
    mob [3] [1] = 2; //pig Durchschnitt = 2
    mob [3] [2] = 3; //pig max = 3
    
    mob [4] [0] = 1; //sheep min = 1
    mob [4] [1] = 2; //sheep Durchschnitt = 2
    mob [4] [2] = 3; //sheep max = 3
    
    mob [5] [0] = 1; //squid min = 1
    mob [5] [1] = 2; //squid Durchschnitt = 2
    mob [5] [2] = 3; //squid max = 3
    
    mob [6] [0] = 5; //Enderman min = 5
    mob [6] [1] = 5; //Enderman Durchschnitt = 5
    mob [6] [2] = 5; //Enderman max = 5
    
    mob [7] [0] = 1; //wolf min = 1
    mob [7] [1] = 2; //wolf Durchschnitt = 2
    mob [7] [2] = 3; //wolf max = 3
    
    mob [8] [0] = 5; //zombiepigman min = 5
    mob [8] [1] = 5; //zombiepigman Durchschnitt = 5
    mob [8] [2] = 5; //zombiepigman max = 5
    
    mob [9] [0] = 10; //blaze min = 10
    mob [9] [1] = 10; //blaze Durchschnitt = 10
    mob [9] [2] = 10; //blaze max = 10
    
    mob [10] [0] = 5; //creeper min = 5
    mob [10] [1] = 5; //creeper Durchschnitt = 5
    mob [10] [2] = 5; //creeper max = 5
    
    mob [11] [0] = 5; //ghast min = 5
    mob [11] [1] = 5; //ghast Durchschnitt = 5
    mob [11] [2] = 5; //ghast max = 5
    
    mob [12] [0] = 5; //silverfish min = 5
    mob [12] [1] = 5; //silverfish Durchschnitt = 5
    mob [12] [2] = 5; //silverfish max = 5
    
    mob [13] [0] = 3; //skeleton min = 3
    mob [13] [1] = 3; //skeleton Durchschnitt = 3
    mob [13] [2] = 3; //skeleton max = 3
    
    mob [14] [0] = 5; //spider min = 5
    mob [14] [1] = 5; //spider Durchschnitt = 5
    mob [14] [2] = 5; //spider max = 5
    
    mob [15] [0] = 5; //Zombie min = 5
    mob [15] [1] = 5; //Zombie Durchschnitt = 5
    mob [15] [2] = 5; //Zombie max = 5
    
    mob [16] [0] = 20000; //enderdragon min = 20000
    mob [16] [1] = 20000; //enderdragon Durchschnitt = 20000
    mob [16] [2] = 20000; //enderdragon max = 20000
    
    //Mob definition Ende
    
    startscreen();
    
    while(1)
    {
    err=0;
    lvl=0;
    goal=0;
    exp=0;
    getchvar=0;
    
    
    info(); 
    
    i=0;
    do
    {
        
    do
    {
    secondtry=0;
    system("cls");
    
    if(i>=5)
    {
        cout << "Ihr aktueller angegebener Level liegt im 5 stelligen Bereich" << endl;
        cout << "Ein Berechnung eines so hohen Levels wuerde sehr lange dauern." << endl;
        cout << "Geben sie einen realistischen Level ein." << endl;
        system("pause");
        system("cls");
        lvl=0;
        i=0;
    }
    cout << "Aktueller Level:" << endl;
    if (i>0)
        {
            cout << lvl << endl;
        }
    key=getKey();
    if((key<48 || key>57) && key!=13 && key != 8)
    {
        cout << endl << endl << "Bitte gib nur Zahlen ein." << endl;
        system("pause");
        secondtry=1;
        key=0;
    }
    
    } while (secondtry==1);
    if (key==8)
    {
        if (i>0)
        {
        i=i-1;
        lvl=lvl / 10;
        }
    }
    
    if(key!=13 && key!=8 && key!=48)
    {
    key=key-48; //"Umformung" vom Ascii Wert zum eigentlichen Ziffern Wert
    lvl=lvl*10+key; //Anhängen der neuen Ziffer an die Ursprüngliche Zahl
    i=i+1;
    }
    if(key==48 && i>0)
    {
        key=key-48; //"Umformung" vom Ascii Wert zum eigentlichen Ziffern Wert
        lvl=lvl*10+key; //Anhängen der neuen Ziffer an die Ursprüngliche Zahl
        i=i+1;
    }
    if(key==48 && i==0)
    {
        //soll nichts machen
    }
    }while (key!=13);
    
    i=0;
    do
    {
        
    do
    {
    secondtry=0;
    system("cls");
    
    if(i>=5)
    {
        cout << "Ihr aktueller angegebener Level liegt im 5 stelligen Bereich" << endl;
        cout << "Ein Berechnung eines so hohen Levels wuerde sehr lange dauern." << endl;
        cout << "Geben sie einen realistischen Level ein." << endl;
        system("pause");
        system("cls");
        goal=0;
        i=0;
    }
    cout << "Zu erreichender Level:" << endl;
    if (i>0)
        {
            cout << goal << endl;
        }
    key=getKey();
    if((key<48 || key>57) && key!=13 && key != 8)
    {
        cout << endl << endl << "Bitte gib nur Zahlen ein." << endl;
        system("pause");
        secondtry=1;
        key=0;
    }
    
    } while (secondtry==1);
    if (key==8)
    {
        if (i>0)
        {
        i=i-1;
        goal=goal / 10;
        }
    }
    
    if(key!=13 && key!=8 && key!=48)
    {
    key=key-48; //"Umformung" vom Ascii Wert zum eigentlichen Ziffern Wert
    goal=goal*10+key; //Anhängen der neuen Ziffer an die Ursprüngliche Zahl
    i=i+1;
    }
    if(key==48 && i>0)
    {
        key=key-48; //"Umformung" vom Ascii Wert zum eigentlichen Ziffern Wert
        goal=goal*10+key; //Anhängen der neuen Ziffer an die Ursprüngliche Zahl
        i=i+1;
    }
    if(key==48 && i==0)
    {
        //soll nichts machen
    }
    
    }while (key!=13);
    
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
        cout << "Warnung: Sie sollten Ihre Erfahrungslevel erst aufbrauchen,"<< endl <<"bevor sie weitere aufbauen." << endl;
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
    
    if (err>0)
    {
        cout << "Es wurde(n) bei der Eingabe der Level " << err << " Fehler gemacht." << endl << "Geben sie reelle und realistische Werte ein." << endl ;
          
    }
    if (err==0)
    {
        do
        {
        system("cls");
        exp=experiencecalc(lvl, goal);
        cout << "Vom Level " << lvl << " bis zum Level " << goal << " werden " << exp << " Erfahrungspunkte benoetigt." << endl ;
    
        cout << endl <<"Zur Neuberechnung r(estart) druecken.";
        
        if (akt>16)
        {
            akt=akt-17;
        }
        if (akt<0)
        {
            akt=akt+17;
        }
        
        aktvor=akt-1;
        aktnach=akt+1;
        
        if (aktvor<0)
        {
            aktvor=aktvor+17;
        }
        if (aktnach>16)
        {
            aktnach=aktnach-17;
        }
        
        gotoxy(0,3);
        // ab hier wird das Raster gezeichnet
        cout << "--------------------------------------------------------------------------------";
    
        for(i=4;i<25;i++)
        {
            gotoxy(19,i);
            cout << "|";
        }
        
        // ab hier wird der aktuell sichtbare Mob eingeblendet
        gotoxy(25, 14);
        mobname(akt); //Funktion gibt an dieser Stelle den Mobnamen abhängig von akt aus
        gotoxy(45,14);
        
        cout << " EP (ugf): " << mob [akt] [1] << " | Mobs: " << (exp/mob[akt][1]+1) << endl; // Gibt EP des akt Mobs aus und die Anzahl der Mobns, die man braucht, um Das Ziellevel zuerreichen (Details)
        
        // hier werden die beiden halbtransparenten Mobs angezeigt (ohne Details)
        gotoxy(32,21);
        mobname(aktvor);
        
        gotoxy(32,7);
        mobname(aktnach);
        
        key=getKey();
        if (key == 592)
        {
            akt=akt+1;
        }
        if (key == 584)
        {
            akt=akt-1;
        }
        
        }while(key==584 || key==592);
        
        
    }
    /*
    gotoxy(25,14);
    cout << "Böses Monster akt";
    gotoxy(45,14);
    cout << "Werte Mob akt";
    
    gotoxy(32,7);
    coutc(8,"Böses Monster akt-1");
    
    gotoxy(32,21);
    coutc(8,"Böses Monster akt+1");
    */
    
    if (key!=114)
    {
        system("cls");
        cout << "Aiyion Prime.";
        wait(1);
        
     
        return EXIT_SUCCESS;
    }
}
}
