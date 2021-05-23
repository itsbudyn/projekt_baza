#include "Ksiazka.h"

void Ksiazka::wyswietl() {
    std::cout << "Tytu�:\t\t\t" << this->tytul << std::endl;
    std::cout << "Autorzy:\t\t" << this->autor << std::endl;
    std::cout << "Wydawnictwo:\t\t" << this->wydawnictwo << std::endl;
    std::cout << "Gatunek: \t\t" << this->gatunek << std::endl;
    std::cout << "Rok wydania:\t\t" << this->rok_wydania << std::endl;
    std::cout << std::endl;
    std::cout << "Stron:\t\t\t" << this->strony << std::endl;
    std::cout << "Ograniczenia wiekowe:\t" << this->min_wiek << std::endl;
    std::cout << std::endl;
    std::cout << "Ocena:\t\t\t" << this->ocena << std::endl;
    std::cout << "Ulubione:\t\t";
    if (this->ulubione == true) std::cout << "Tak";
    else std::cout << "Nie";
    std::cout << std::endl;
}

Ksiazka::Ksiazka(std::string u_tytul, unsigned short u_rok_wydania, double u_ocena, unsigned short u_min_wiek, bool u_ulubione, unsigned short u_strony, std::string u_autor, std::string u_wydawnictwo, std::string u_gatunek) :Utwor(u_tytul, u_rok_wydania, u_ocena, u_min_wiek, u_ulubione) {
    this->strony = u_strony;
    this->autor = u_autor;
    this->wydawnictwo = u_wydawnictwo;
    this->gatunek = u_gatunek;
}

Ksiazka::Ksiazka(const Ksiazka& x) :Utwor(x.tytul, x.rok_wydania, x.ocena, x.min_wiek, x.ulubione) {
    this->strony = x.strony;
    this->autor = x.autor;
    this->wydawnictwo = x.wydawnictwo;
    this->gatunek = x.gatunek;
}