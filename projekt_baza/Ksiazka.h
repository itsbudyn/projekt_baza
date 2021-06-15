#pragma once
#include "Header.h"
#include "Utwor.h"

class Ksiazka : public Utwor {
private:
    // zmienne
    unsigned short strony = 0;
    std::string autor;
    std::string wydawnictwo;
    std::string gatunek;
    static unsigned int liczbaKsiazek;

public:
    // metody
    void wyswietl() const;
    unsigned short zwrocStrony() const;
    friend void edytujKsiazki(std::vector<Ksiazka>& ksiazki);
    friend void szukajKsiazki(std::vector<Ksiazka>& ksiazki);
    friend void zapiszKsiazki(const std::vector<Ksiazka>& db, const std::string filename);
    static unsigned int zwrocLiczbeKsiazek();

    // konstruktory i destruktory
    Ksiazka();
    Ksiazka(std::string u_tytul, unsigned short u_rok_wydania, double u_ocena, unsigned short u_min_wiek, bool u_ulubione, unsigned short u_strony, std::string u_autor, std::string u_wydawnictwo, std::string u_gatunek);
    Ksiazka(const Ksiazka& x);
    ~Ksiazka();
    
    // operatory
    Ksiazka& operator=(const Ksiazka& x);
};