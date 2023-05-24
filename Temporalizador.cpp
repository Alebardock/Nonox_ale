#include <iostream>
#include "Temporalizador.h"

//Inicializo en un constructor
Temporalizador::Temporalizador(int minutos, int segundos){
    _tiempoTotal = minutos * 60 + segundos;
    _tiempoRestante = _tiempoTotal;
    clock.restart();
    font.loadFromFile("Fuente.ttf");
    text.setFont(font);
    text.setCharacterSize(30);
    text.setFillColor(sf::Color::White);
    text.setPosition(185, 35);
    actualizarTiempo();
}
void Temporalizador::actualizarTiempo() {
    int minutosRestantes = _tiempoRestante / 60;
    int segundosRestantes = _tiempoRestante % 60;
    text.setString("Time: " + std::to_string(minutosRestantes) + ":" + std::to_string(segundosRestantes));
}


void Temporalizador::actualizar() {
    sf::Time elapsed = clock.getElapsedTime();
    int segundosTranscurridos = elapsed.asSeconds();
    _tiempoRestante = _tiempoTotal - segundosTranscurridos;
    actualizarTiempo();
}

void Temporalizador::parar() {
    _estaCorriendo = false;
}


void Temporalizador::dibujar(sf::RenderWindow& window) {
    window.draw(text);
}

bool Temporalizador::tiempoTerminado() {
    return _tiempoRestante <= 0;
}

int Temporalizador::segundosTranscurridos() {
    return _tiempoTotal - _tiempoRestante;
}

void Temporalizador::agregarTiempo(int minutos, int segundos) {
    _tiempoTotal += minutos * 60 + segundos;
}

void Temporalizador::reiniciar() {
    clock.restart();
    _tiempoRestante = _tiempoTotal;
    actualizarTiempo();
}



int Temporalizador::getTiempoTotal(){
    return _tiempoTotal;
}

int Temporalizador::getTiempoRestante(){
    return _tiempoRestante;
}

void Temporalizador::tiempoTotal(int minutos, int segundos) {
    minutos= std::max(0, minutos);
    segundos = std::max(0, segundos);
    _tiempoTotal = minutos * 60 + segundos;
    _tiempoRestante = _tiempoTotal;
}

void Temporalizador::setTiempoRestante(int segundos) {
    segundos = std::max(0, segundos);
    _tiempoRestante = segundos;
    _tiempoTotal = _tiempoRestante;
    clock.restart();
}
