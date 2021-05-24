#pragma once
#include "Header.h"

class Utwor {
protected:
    std::string tytul;
    unsigned short rok_wydania = 0;
    double ocena = 0;
    unsigned short min_wiek = 0;
    bool ulubione = false;

public:
    virtual void wyswietl() = 0;
    inline bool czyUlubione();
    inline Utwor(std::string u_tytul, unsigned short u_rok_wydania, double u_ocena, unsigned short u_min_wiek, bool u_ulubione);
};