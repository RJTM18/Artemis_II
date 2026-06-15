#ifndef REINICIO_REPLAY_H
#define REINICIO_REPLAY_H

#include <iostream>
#include <cstdlib>
#include <ctime>

#ifdef _WIN32
  #include <windows.h>
  #include <conio.h>
  #define LIMPIAR system("cls")
  #define PAUSA(ms) Sleep(ms)
#else
  #include <unistd.h>
  #define LIMPIAR system("clear")
  #define PAUSA(ms) usleep((ms)*1000)
#endif

#include "cronometro.h"
#include "flujo_pantallas.h"

struct EstadoPartida {
    int  personasRescatadas;
    int  vidas;
    int  tiempoTotal;
    int  velocidad;
    int  personasEnCabina;
    bool enCabina;
    bool juegoTerminado;
};

EstadoPartida iniciarPartida() {
    srand((unsigned int)time(NULL));
    EstadoPartida p;
    p.personasRescatadas = 0;
    p.vidas              = 3;
    p.tiempoTotal        = generarTiempoMision();
    p.velocidad          = 5 + rand() % 16;
    p.personasEnCabina   = 0;
    p.enCabina           = false;
    p.juegoTerminado     = false;
    return p;
}

bool registrarColision(EstadoPartida& p) {
    p.vidas--;
    p.personasEnCabina = 0;
    p.enCabina = false;
    if (p.vidas <= 0) {
        p.juegoTerminado = true;
        return false;
    }
    return true;
}

void rescatarPersonas(EstadoPartida& p, int cantidad) {
    if (cantidad > 2) cantidad = 2;
    p.personasEnCabina = cantidad;
    p.enCabina = true;
}

void descargarPersonas(EstadoPartida& p) {
    p.personasRescatadas += p.personasEnCabina;
    p.personasEnCabina    = 0;
    p.enCabina            = false;
    if (p.personasRescatadas >= 12)
        p.juegoTerminado = true;
}

void bucleJuego(std::string n1, std::string n2, std::string n3) {
    EstadoJuego estado = pantallaBienvenida();

    while (estado == EN_JUEGO) {
        EstadoPartida partida = iniciarPartida();
        time_t inicio = time(NULL);

        while (!partida.juegoTerminado) {
            int restante = tiempoRestante(inicio, partida.tiempoTotal);

            if (tiempoAgotado(inicio, partida.tiempoTotal)) {
                estado = pantallaFracaso("Tiempo agotado", partida.personasRescatadas);
                break;
            }

            LIMPIAR;
            dibujarTierra();
            dibujarNave();
            dibujarLuna();
            mostrarHUD(partida.personasEnCabina, restante, partida.vidas, partida.velocidad);

            std::cout << "\n Rescatadas: " << partida.personasRescatadas << " / 12\n";
            std::cout << " [R] Rescatar  [D] Descargar  [C] Colision  [ESC] Salir\n";

            #ifdef _WIN32
            if (_kbhit()) {
                char tecla = _getch();
            #else
            {
                char tecla;
                std::cin >> tecla;
            #endif
                if (tecla == 27) {
                    estado = pantallaFracaso("Mision abandonada", partida.personasRescatadas);
                    partida.juegoTerminado = true;
                } else if (tecla == 'r' || tecla == 'R') {
                    int disponibles = 12 - partida.personasRescatadas - partida.personasEnCabina;
                    if (disponibles > 0 && !partida.enCabina)
                        rescatarPersonas(partida, disponibles >= 2 ? 2 : disponibles);
                } else if (tecla == 'd' || tecla == 'D') {
                    if (partida.enCabina) {
                        descargarPersonas(partida);
                        if (partida.personasRescatadas >= 12)
                            estado = pantallaExito();
                    }
                } else if (tecla == 'c' || tecla == 'C') {
                    if (!registrarColision(partida))
                        estado = pantallaFracaso("Sin vidas", partida.personasRescatadas);
                }
            #ifdef _WIN32
            }
            #endif

            PAUSA(500);
        }

        if (estado != EN_JUEGO) break;
    }

    pantallaCreditos(n1, n2, n3);
}

#endif
