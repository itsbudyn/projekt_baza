#include "Film.h"

void Film::wyswietl() {
    std::cout << "Tytu³:\t" << this->tytul << std::endl;
    std::cout << "Re¿yser:\t" << this->rezyser << std::endl;
    std::cout << "Gatunek: \t" << this->gatunek << std::endl;
    std::cout << "Rok wydania:\t" << this->rok_wydania << std::endl;
    std::cout << std::endl;
    std::cout << "Czas trwania [m]:\t" << this->czas_trwania << std::endl;
    std::cout << "Ograniczenia wiekowe:\t" << this->min_wiek << std::endl;
    std::cout << std::endl;
    std::cout << "Ocena:\t" << this->ocena << std::endl;
    std::cout << "Ulubione:\t" << this->ulubione << std::endl;
}

Film::Film(std::string u_tytul, unsigned short u_rok_wydania, double u_ocena, unsigned short u_min_wiek, bool u_ulubione, unsigned short u_czas_trwania, std::string u_rezyser, std::string u_gatunek) :Utwor(u_tytul, u_rok_wydania, u_ocena, u_min_wiek, u_ulubione) {
    this->czas_trwania = u_czas_trwania;
    this->rezyser = u_rezyser;
    this->gatunek = u_gatunek;
}

Film::Film(const Film& x) :Utwor(x.tytul, x.rok_wydania, x.ocena, x.min_wiek, x.ulubione) {
    this->czas_trwania = x.czas_trwania;
    this->rezyser = x.rezyser;
    this->gatunek = x.gatunek;
}