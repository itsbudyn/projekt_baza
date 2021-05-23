#include "Album_muzyczny.h"

void Album_muzyczny::wyswietl() {
    std::cout << "Tytu³:\t" << this->tytul << std::endl;
    std::cout << "Autorzy:\t" << this->autor << std::endl;
    std::cout << "Gatunek:\t" << this->gatunek << std::endl;
    std::cout << "Single?:\t" << this->czy_single << std::endl;
    std::cout << "Rok wydania:\t" << this->rok_wydania << std::endl;
    std::cout << std::endl;
    std::cout << "Czas trwania [m]:\t" << this->czas_trwania << std::endl;
    std::cout << "Liczba utworów:\t" << this->utworow << std::endl;
    std::cout << "Ograniczenia wiekowe:\t" << this->min_wiek << std::endl;
    std::cout << std::endl;
    std::cout << "Ocena:\t" << this->ocena << std::endl;
    std::cout << "Ulubione:\t" << this->ulubione << std::endl;
}

Album_muzyczny::Album_muzyczny(std::string u_tytul, unsigned short u_rok_wydania, double u_ocena, unsigned short u_min_wiek, bool u_ulubione, unsigned short u_czas_trwania, unsigned short u_utworow, bool u_czy_single, std::string u_autor, std::string u_gatunek) :Utwor(u_tytul, u_rok_wydania, u_ocena, u_min_wiek, u_ulubione) {
    this->czas_trwania = u_czas_trwania;
    this->utworow = utworow;
    this->czy_single = u_czy_single;
    this->autor = autor;
    this->gatunek = gatunek;
}

Album_muzyczny::Album_muzyczny(const Album_muzyczny& x) :Utwor(x.tytul, x.rok_wydania, x.ocena, x.min_wiek, x.ulubione) {
    this->czas_trwania = x.czas_trwania;
    this->utworow = x.utworow;
    this->autor = x.autor;
    this->gatunek = x.gatunek;
}