#ifndef FLUJO_PANTALLAS_H
#define FLUJO_PANTALLAS_H

#include <iostream>
#include <string>
#include "Interfaz"

enum EstadoJuego {
    BIENVENIDA,
    EN_JUEGO,
    MISION_EXITOSA,
    MISION_FRACASADA,
    CREDITOS,
    SALIR
};

EstadoJuego pantallaBienvenida() {
    mostrarBienvenida();
    return EN_JUEGO;
}

EstadoJuego pantallaExito() {
    mostrarMisionCompleta();
    char respuesta;
    std::cin >> respuesta;
    std::cin.ignore();
    if (respuesta == 'S' || respuesta == 's')
        return EN_JUEGO;
    else
        return CREDITOS;
}

EstadoJuego pantallaFracaso(std::string causa, int rescatados) {
    mostrarMisionFracasada(causa, rescatados);
    char respuesta;
    std::cin >> respuesta;
    std::cin.ignore();
    if (respuesta == 'S' || respuesta == 's')
        return EN_JUEGO;
    else
        return CREDITOS;
}

EstadoJuego pantallaCreditos(std::string n1, std::string n2, std::string n3) {
    mostrarCreditos(n1, n2, n3);
    return SALIR;
}

#endif
