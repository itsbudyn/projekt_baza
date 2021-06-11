#pragma once
#include "Header.h"
#include "Utwor.h"

class Film : public Utwor {
private:
    // zmienne
    unsigned short czas_trwania = 0;
    std::string rezyser;
    std::string gatunek;
    static unsigned int liczbaFilmow;

public:
    // metody
    void wyswietl();
    friend void edytujFilmy(std::vector<Film>& filmy);
    friend void szukajFilmu(std::vector<Film>& filmy);
    friend void zapiszFilmy(const std::vector<Film>& db, const std::string name);
    unsigned int zwrocLiczbeFilmow();
    
    // konstruktory i destruktor
    Film();
    Film(std::string u_tytul, unsigned short u_rok_wydania, double u_ocena, unsigned short u_min_wiek, bool u_ulubione, unsigned short u_czas_trwania, std::string u_rezyser, std::string u_gatunek);
    Film(const Film& x);
    ~Film();

    // operatory
    Film& operator=(const Film& x);
};