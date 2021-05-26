#include "Album_muzyczny.h"

unsigned int Album_muzyczny::liczbaAlbumow = 0;

void Album_muzyczny::wyswietl() {
    std::cout << "Tytu³:\t\t\t" << this->tytul << std::endl;
    std::cout << "Autorzy:\t\t" << this->autor << std::endl;
    std::cout << "Gatunek:\t\t" << this->gatunek << std::endl;
    std::cout << "Rok wydania:\t\t" << this->rok_wydania << std::endl;
    std::cout << std::endl;
    std::cout << "Czas trwania [m]:\t" << this->czas_trwania << std::endl;
    std::cout << "Liczba utworów:\t\t" << this->utworow << std::endl;
    std::cout << "Ograniczenia wiekowe:\t" << this->min_wiek << std::endl;
    std::cout << std::endl;
    std::cout << "Ocena:\t\t\t" << this->ocena << std::endl;
    std::cout << "Ulubione:\t\t";
    if (this->ulubione == true) std::cout << "Tak";
    else std::cout << "Nie";
    std::cout << std::endl;
}

unsigned int Album_muzyczny::zwrocLiczbeAlbumow() {
    return liczbaAlbumow;
}

Album_muzyczny::Album_muzyczny(std::string u_tytul, unsigned short u_rok_wydania, double u_ocena, unsigned short u_min_wiek, bool u_ulubione, unsigned short u_czas_trwania, unsigned short u_utworow, std::string u_autor, std::string u_gatunek) :Utwor(u_tytul, u_rok_wydania, u_ocena, u_min_wiek, u_ulubione) {
    this->czas_trwania = u_czas_trwania;
    this->utworow = u_utworow;
    this->autor = u_autor;
    this->gatunek = u_gatunek;
}

Album_muzyczny::Album_muzyczny(const Album_muzyczny& x) :Utwor(x.tytul, x.rok_wydania, x.ocena, x.min_wiek, x.ulubione) {
    this->czas_trwania = x.czas_trwania;
    this->utworow = x.utworow;
    this->autor = x.autor;
    this->gatunek = x.gatunek;
}

Album_muzyczny::~Album_muzyczny() {
    liczbaAlbumow--;
}

Album_muzyczny& Album_muzyczny::operator=(const Album_muzyczny& x) {
    Album_muzyczny n(x.tytul, x.rok_wydania, x.ocena, x.min_wiek, x.ulubione, x.czas_trwania, x.utworow, x.autor, x.gatunek);
    return n;
}