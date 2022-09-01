#include <cstdlib>
#include <conio.h>
#include <iostream>
#include <time.h>
#include <windows.h>
#include <fstream>
#include "Laberinto.h"

using namespace std;
int destinox, puntox, puntoy;


void Laberinto::EmpezarGen ()
    {
        srand(unsigned(time(NULL)));
        Inicializar();
        int x=1+rand()%FIL-2;
        GenerarCamino(x, 1);
        lab[x][1]='I';
        GenerarParedes();
        FinGenerar();
        Imprimir();
        ImprimirA();
        system("PAUSE");
        system("cls");
    }
    void Laberinto::EmpezarJug ()
    {
        srand(unsigned(time(NULL)));
        Inicializar();
        int x=1+rand()%FIL-2;
        GenerarCamino(x, 1);
        lab[x][1]='I';
        GenerarParedes();
        FinGenerar();
        Imprimir();
        ImprimirA();
        int tecla;
        puntox=x;
        puntoy=1;
        while(true)
        {
            tecla=getch();
            if(tecla==27) break;
            else
            {

                mover(tecla);
                if(lab[puntox][puntoy+1]=='F')
                {
                    cout<<"Felicidades! Usted termino de resolver el laberinto :)"<<endl;
                    break;
                }

            }

        }

        system("pause");
    }

    void Laberinto::Inicializar()
    {
        for(int i=0; i<FIL; i++)
        {
            for(int j=0; j<COL; j++)
            {
                if(i==0 || j==0 || i==FIL-1 || j==COL-1) lab[i][j]='0';
                else lab[i][j]=' ';
            }
        }
    }

    void Laberinto::Imprimir()
    {
        for(int i=0; i<FIL; i++)
        {
            for(int j=0; j<COL; j++)
            {
                if(lab[i][j]=='0')cout<<(char)177;
                else cout<<lab[i][j];
            }
            cout<<endl;
        }
    }

    void Laberinto::ImprimirA()
    {
        ofstream archivo("Laberinto.txt");
        for(int i=0; i<FIL; i++)
        {
            for(int j=0; j<COL; j++)
            {
                if(lab[i][j]=='0')archivo<<0;
                else if (lab[i][j]=='I')archivo<<2;
                else if (lab[i][j]=='F')archivo<<3;
                else if (lab[i][j]==' ')archivo<<1;
            }
            archivo<<endl;
        }
        archivo.close();
    }


    void Laberinto::GenerarCamino(int i, int j)
    {
        while(j!=COL-2)
        {
            int a=rand()%3;
            switch(a)
            {
            case 0:
                if(i+1!=FIL-1 && lab[i+1][j]!='O')
                {
                    i++;
                    lab[i][j]='O';
                }
                break;
            case 1:
                if(i-1!=0 && lab[i-1][j]!='O')
                {
                    i--;
                    lab[i][j]='O';
                }
                break;
            case 2:
                if(j+1!=COL-1 && lab[i][j+1]!='O')
                {
                    j++;
                    lab[i][j]='O';
                    if(j==COL-2) lab[i][j]='F';
                }
                break;


            }
        }
    }
    void Laberinto::GenerarParedes()
    {
        int paredes=0;
        while(paredes<100)
        {
            int x=rand()%FIL;
            int y=rand()%COL;

            if(lab[x][y]==' ')
            {
                paredes++;
                int lim=1+rand()%10;
                int puestas=0;
                switch(rand()%4)
                {
                case 0:

                    while(lab[x][y]==' ')
                    {
                        if(puestas==lim)break;
                        puestas++;
                        lab[x][y]='0';
                        x--;
                    }
                    break;
                case 1:
                    while(lab[x][y]==' ')
                    {
                        if(puestas==lim)break;
                        puestas++;
                        lab[x][y]='0';
                        x++;
                    }
                    break;
                case 2:
                    while(lab[x][y]==' ')
                    {
                        if(puestas==lim)break;
                        puestas++;
                        lab[x][y]='0';
                        y--;
                    }
                    break;
                case 3:
                    while(lab[x][y]==' ')
                    {
                        if(puestas==lim)break;
                        puestas++;
                        lab[x][y]='0';
                        y++;
                    }
                    break;
                }
            }
        }
    }

    void Laberinto::FinGenerar()
    {
        for(int i=0; i<FIL; i++)
        {
            for(int j=0; j<COL-1; j++)
            {
                if(lab[i][j]=='O') lab[i][j]=' ';
                if(j==COL-2 && lab[i][j]!='F') lab[i][j]='0';
                if(lab[i][j]=='F')
                {
                    lab[i][j+1]='F';
                    lab[i][j]=' ';
                }
            }
        }
    }

    void Laberinto::mover(int tecla)
    {
        switch(tecla)
        {
        case 72:
            if(lab[puntox-1][puntoy]==' ')
            {
                system("cls");
                lab[puntox-1][puntoy]='*';
                puntox--;
                Imprimir();
            }
            else if(lab[puntox-1][puntoy]=='*' || lab[puntox-1][puntoy]=='I')
            {
                system("cls");
                lab[puntox][puntoy]=' ';
                puntox--;
                Imprimir();
            }
            break;

        case 80:
            if(lab[puntox+1][puntoy]=='*' || lab[puntox+1][puntoy]=='I')
            {
                system("cls");
                lab[puntox][puntoy]=' ';
                puntox++;
                Imprimir();
            }
            else if(lab[puntox+1][puntoy]==' ')
            {
                system("cls");
                lab[puntox+1][puntoy]='*';
                puntox++;
                Imprimir();
            }
            break;

        case 75:
            if(lab[puntox][puntoy-1]==' ')
            {
                system("cls");
                lab[puntox][puntoy-1]='*';
                puntoy--;
                Imprimir();
            }
            else if(lab[puntox][puntoy-1]=='*' || lab[puntox][puntoy-1]=='I')
            {
                system("cls");
                lab[puntox][puntoy]=' ';
                puntoy--;
                Imprimir();
            }
            break;

        case 77:
            if(lab[puntox][puntoy+1]=='*' || lab[puntox][puntoy+1]=='I')
            {
                system("cls");
                lab[puntox][puntoy]=' ';
                puntoy++;
                Imprimir();
            }
            else if(lab[puntox][puntoy+1]==' ')
            {
                system("cls");
                lab[puntox][puntoy+1]='*';
                puntoy++;
                Imprimir();
            }
            break;
        }
    }





