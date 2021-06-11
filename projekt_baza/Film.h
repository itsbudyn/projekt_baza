#pragma once
#include "Header.h"
#include "Utwor.h"

class Film : public Utwor {
private:
    unsigned short czas_trwania = 0;
    std::string rezyser;
    std::string gatunek;
    static unsigned int liczbaFilmow;

public:
    void wyswietl();
    friend void edytujFilmy(std::vector<Film>& filmy);
    friend void szukajFilmu(std::vector<Film>& filmy);
    friend void zapiszFilmy(const std::vector<Film>& db, const std::string name);
    unsigned int zwrocLiczbeFilmow();
    
    Film();
    Film(std::string u_tytul, unsigned short u_rok_wydania, double u_ocena, unsigned short u_min_wiek, bool u_ulubione, unsigned short u_czas_trwania, std::string u_rezyser, std::string u_gatunek);
    Film(const Film& x);
    ~Film();
    Film& operator=(const Film& x);
};