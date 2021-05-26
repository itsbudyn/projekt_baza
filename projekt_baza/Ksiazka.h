#pragma once
#include "Header.h"
#include "Utwor.h"

class Ksiazka : public Utwor {
private:
    unsigned short strony = 0;
    std::string autor;
    std::string wydawnictwo;
    std::string gatunek;

public:
    inline void wyswietl();
    friend void edytujKsiazki(std::vector<Ksiazka>& ksiazki);
    friend void szukajKsiazki(std::vector<Ksiazka>& ksiazki);
    inline Ksiazka(std::string u_tytul, unsigned short u_rok_wydania, double u_ocena, unsigned short u_min_wiek, bool u_ulubione, unsigned short u_strony, std::string u_autor, std::string u_wydawnictwo, std::string u_gatunek);
    inline Ksiazka(const Ksiazka& x);
    inline Ksiazka& operator=(const Ksiazka& x);
};