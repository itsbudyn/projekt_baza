#include "Utwor.h"

Utwor::Utwor(std::string u_tytul, unsigned short u_rok_wydania, double u_ocena, unsigned short u_min_wiek, bool u_ulubione) {
    this->tytul = u_tytul;
    this->rok_wydania = u_rok_wydania;
    this->ocena = u_ocena;
    this->min_wiek = u_min_wiek;
    this->ulubione = u_ulubione;
}