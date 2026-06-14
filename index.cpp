#include <iostream>
#include <Windows.h>
#include "interfaz"

using namespace std;

void Gotoxy(int x, int y);

int main() {
    int vidas, tiempo, salvados;    
    bool x;

    mostrarBienvenida();

    /*
        si jugador selecciona si, comenzar el juego

        punto inicial: luna

        cin controles
            if derecha, reininio de pantalla
            if arriba 
            if izquierda
            if abajo
    
    */

    return 0;

}

void Gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

