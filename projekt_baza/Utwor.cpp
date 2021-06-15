#include "Utwor.h"

unsigned int Utwor::liczbaUtworow = 0;

bool Utwor::czyUlubione() {
    return this->ulubione;
}

unsigned int Utwor::zwrocLiczbeUtworow(){
    return liczbaUtworow;
}

std::string Utwor::zwrocTytul() const {
    return tytul;
}
unsigned short Utwor::zwrocRokWydania() const {
    return rok_wydania;
}
double Utwor::zwrocOcene() const {
    return ocena;
}
unsigned short Utwor::zwrocMinWiek() const {
    return min_wiek;
}

// konstruktor bezargumentowy
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