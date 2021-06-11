#include "Film.h"

unsigned int Film::liczbaFilmow = 0;

void Film::wyswietl() {
    std::cout << "Tytuł:\t\t\t" << this->tytul << std::endl;
    std::cout << "Reżyser:\t\t" << this->rezyser << std::endl;
    std::cout << "Gatunek: \t\t" << this->gatunek << std::endl;
    std::cout << "Rok wydania:\t\t" << this->rok_wydania << std::endl;
    std::cout << std::endl;
    std::cout << "Czas trwania:\t\t" << this->czas_trwania << " minut" << std::endl;
    std::cout << "Ograniczenia wiekowe:\t" << this->min_wiek << "+" << std::endl;
    std::cout << std::endl;
    std::cout << "Ocena:\t\t\t" << this->ocena << " / 5" << std::endl;
    std::cout << "Ulubione:\t\t";
    if (this->ulubione == true) std::cout << "Tak";
    else std::cout << "Nie";
    std::cout << std::endl;
}

unsigned int Film::zwrocLiczbeFilmow() {
    return liczbaFilmow;
}

Film::Film() {
    liczbaFilmow++;
}

Film::Film(std::string u_tytul, unsigned short u_rok_wydania, double u_ocena, unsigned short u_min_wiek, bool u_ulubione, unsigned short u_czas_trwania, std::string u_rezyser, std::string u_gatunek) :Utwor(u_tytul, u_rok_wydania, u_ocena, u_min_wiek, u_ulubione) {
    liczbaFilmow++;
    this->czas_trwania = u_czas_trwania;
    this->rezyser = u_rezyser;
    this->gatunek = u_gatunek;
}

Film::Film(const Film& x) :Utwor(x.tytul, x.rok_wydania, x.ocena, x.min_wiek, x.ulubione) {
    liczbaFilmow++;
    this->czas_trwania = x.czas_trwania;
    this->rezyser = x.rezyser;
    this->gatunek = x.gatunek;
}

Film::~Film() {
    liczbaFilmow--;
}

Film& Film::operator=(const Film& x) {
    if (&x == this)return *this;

    tytul = x.tytul;
    rok_wydania = x.rok_wydania;
    ocena = x.ocena;
    min_wiek = x.min_wiek;
    ulubione = x.ulubione;
    czas_trwania = x.czas_trwania;
    rezyser = x.rezyser;
    gatunek=x.gatunek;

    return *this;
}