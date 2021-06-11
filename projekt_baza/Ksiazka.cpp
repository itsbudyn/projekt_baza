#include "Ksiazka.h"

unsigned int Ksiazka::liczbaKsiazek = 0;

void Ksiazka::wyswietl() {
    std::cout << "Tytu³:\t\t\t" << this->tytul << std::endl;
    std::cout << "Autorzy:\t\t" << this->autor << std::endl;
    std::cout << "Wydawnictwo:\t\t" << this->wydawnictwo << std::endl;
    std::cout << "Gatunek: \t\t" << this->gatunek << std::endl;
    std::cout << "Rok wydania:\t\t" << this->rok_wydania << std::endl;
    std::cout << std::endl;
    std::cout << "Stron:\t\t\t" << this->strony << std::endl;
    std::cout << "Ograniczenia wiekowe:\t" << this->min_wiek << "+" << std::endl;
    std::cout << std::endl;
    std::cout << "Ocena:\t\t\t" << this->ocena << " / 5" << std::endl;
    std::cout << "Ulubione:\t\t";
    if (this->ulubione == true) std::cout << "Tak";
    else std::cout << "Nie";
    std::cout << std::endl;
}

unsigned int Ksiazka::zwrocLiczbeKsiazek() {
    return liczbaKsiazek;
}

Ksiazka::Ksiazka() {
    liczbaKsiazek++;
}

Ksiazka::Ksiazka(std::string u_tytul, unsigned short u_rok_wydania, double u_ocena, unsigned short u_min_wiek, bool u_ulubione, unsigned short u_strony, std::string u_autor, std::string u_wydawnictwo, std::string u_gatunek) :Utwor(u_tytul, u_rok_wydania, u_ocena, u_min_wiek, u_ulubione) {
    liczbaKsiazek++;
    this->strony = u_strony;
    this->autor = u_autor;
    this->wydawnictwo = u_wydawnictwo;
    this->gatunek = u_gatunek;
}

Ksiazka::Ksiazka(const Ksiazka& x) :Utwor(x.tytul, x.rok_wydania, x.ocena, x.min_wiek, x.ulubione) {
    liczbaKsiazek++;
    this->strony = x.strony;
    this->autor = x.autor;
    this->wydawnictwo = x.wydawnictwo;
    this->gatunek = x.gatunek;
}

Ksiazka::~Ksiazka() {
    liczbaKsiazek--;
}

Ksiazka& Ksiazka::operator=(const Ksiazka& x) {
    if (&x == this)return *this;

    tytul = x.tytul;
    rok_wydania = x.rok_wydania;
    ocena = x.ocena;
    min_wiek = x.min_wiek;
    ulubione = x.ulubione;
    strony = x.strony;
    autor = x.autor;
    wydawnictwo = x.wydawnictwo;
    gatunek = x.gatunek;

    return *this;
}