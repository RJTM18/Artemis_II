#ifndef CRONOMETRO_H
#define CRONOMETRO_H

#include <cstdlib>
#include <ctime>

int generarTiempoMision() {
    srand((unsigned int)time(NULL));
    return 80 + rand() % 41;
}

int tiempoTranscurrido(time_t inicio) {
    return (int)difftime(time(NULL), inicio);
}

int tiempoRestante(time_t inicio, int tiempoTotal) {
    int restante = tiempoTotal - tiempoTranscurrido(inicio);
    if (restante < 0) restante = 0;
    return restante;
}

bool tiempoAgotado(time_t inicio, int tiempoTotal) {
    return tiempoTranscurrido(inicio) >= tiempoTotal;
}

#endif
