#include <consoleapi2.h>
#include <iostream>
#include <Windows.h>

using namespace std;

//pantallasos
void Inicio();
void ganaste();
void perdiste();

void Gotoxy(int x, int y);


int main() {
    int vidas, tiempo, salvados;    
    bool x;

    Inicio();

    return 0;
}

void Gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle( STD_OUTPUT_HANDLE), coord);
}

void Inicio() {
    cout << "######################################################\n";
    cout << "######################################################\n";
    cout << "                                                      \n";
    cout << "                                                      \n";
    cout << "                 RESCUE TO THE MOON                   \n";
    cout << "                                                      \n";
    cout << "         JUGAR?          SI           NO              \n";
    cout << "                                                      \n";
    cout << "                                                      \n";
    cout << "######################################################\n";
    cout << "######################################################\n";
}

void ganaste() {
    cout << "######################################################\n";
    cout << "######################################################\n";
    cout << "                                                      \n";
    cout << "                                                      \n";
    cout << "                       GANASTE                        \n";
    cout << "                                                      \n";
    cout << "         DE NUEVO?          SI           NO           \n";
    cout << "                                                      \n";
    cout << "                                                      \n";
    cout << "######################################################\n";
    cout << "######################################################\n";
}

void perdiste() {
    cout << "######################################################\n";
    cout << "######################################################\n";
    cout << "                                                      \n";
    cout << "                                                      \n";
    cout << "                      PERDISTE                        \n";
    cout << "                                                      \n";
    cout << "         DE NUEVO?          SI           NO           \n";
    cout << "                                                      \n";
    cout << "                                                      \n";
    cout << "######################################################\n";
    cout << "######################################################\n";
}