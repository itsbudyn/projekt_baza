#include "Utwor.h"

unsigned int Utwor::liczbaUtworow = 0;

bool Utwor::czyUlubione() {
    return this->ulubione;
}

unsigned int Utwor::zwrocLiczbeUtworow() {
    return liczbaUtworow;
}

// konstruktor domyślny
Utwor::Utwor() {
    liczbaUtworow++;
}

// konstruktor
Utwor::Utwor(std::string u_tytul, unsigned short u_rok_wydania, double u_ocena, unsigned short u_min_wiek, bool u_ulubione) {
    liczbaUtworow++;
    this->tytul = u_tytul;
    this->rok_wydania = u_rok_wydania;
    this->ocena = u_ocena;
    this->min_wiek = u_min_wiek;
    this->ulubione = u_ulubione;
}

// destruktor
Utwor::~Utwor() {
    liczbaUtworow--;
}