#pragma once
#include "Header.h"

class Utwor {
protected:
    // zmienne, występujące także w klasach
    // "Książka", "Film" i "Album_Muzyczny"
    // dzięki dziedziczeniu. Metoda wyswietl
    // będzie zastępowana w każdej klasie
    // dziedziczącej po klasie utwór
    // i wyświetlanej przez wskaźnik
    // polimorficzny

    std::string tytul;
    unsigned short rok_wydania = 0;
    double ocena = 0;
    unsigned short min_wiek = 0;
    bool ulubione = false;

    static unsigned int liczbaUtworow;

public:
    // metody
    virtual void wyswietl() const = 0; // metoda wirtualna
    bool czyUlubione();
    static unsigned int zwrocLiczbeUtworow();

    std::string zwrocTytul() const;
    unsigned short zwrocRokWydania() const;
    double zwrocOcene() const;
    unsigned short zwrocMinWiek()const;

    // konstruktory i destruktor
    Utwor();
    Utwor(std::string u_tytul, unsigned short u_rok_wydania, double u_ocena, unsigned short u_min_wiek, bool u_ulubione);
    ~Utwor();
};