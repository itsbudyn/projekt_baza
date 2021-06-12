#include "Album_muzyczny.h"

unsigned int Album_muzyczny::liczbaAlbumow = 0;

void Album_muzyczny::wyswietl() const{
    std::cout << "Tytuł:\t\t\t" << this->tytul << std::endl;
    std::cout << "Autorzy:\t\t" << this->autor << std::endl;
    std::cout << "Gatunek:\t\t" << this->gatunek << std::endl;
    std::cout << "Rok wydania:\t\t" << this->rok_wydania << std::endl;
    std::cout << std::endl;
    std::cout << "Czas trwania:\t\t" << this->czas_trwania << " minut" << std::endl;
    std::cout << "Liczba utworów:\t\t" << this->utworow << std::endl;
    std::cout << "Ograniczenia wiekowe:\t" << this->min_wiek << "+" << std::endl;
    std::cout << std::endl;
    std::cout << "Ocena:\t\t\t" << this->ocena << " / 5" << std::endl;
    std::cout << "Ulubione:\t\t";
    if (this->ulubione == true) std::cout << "Tak";
    else std::cout << "Nie";
    std::cout << std::endl;
}

// metoda zwracająca wartość składnika statycznego
unsigned int Album_muzyczny::zwrocLiczbeAlbumow() {
    return liczbaAlbumow;
}

// konstruktor bezargumentowy
Album_muzyczny::Album_muzyczny() {
    liczbaAlbumow++;
}

// konstruktor uzupełniający wszystkie zmienne
Album_muzyczny::Album_muzyczny(std::string u_tytul, unsigned short u_rok_wydania, double u_ocena, unsigned short u_min_wiek, bool u_ulubione, unsigned short u_czas_trwania, unsigned short u_utworow, std::string u_autor, std::string u_gatunek) :Utwor(u_tytul, u_rok_wydania, u_ocena, u_min_wiek, u_ulubione) {
    liczbaAlbumow++;
    this->czas_trwania = u_czas_trwania;
    this->utworow = u_utworow;
    this->autor = u_autor;
    this->gatunek = u_gatunek;
}

// konstruktor kopiujący
Album_muzyczny::Album_muzyczny(const Album_muzyczny& x) :Utwor(x.tytul, x.rok_wydania, x.ocena, x.min_wiek, x.ulubione) {
    liczbaAlbumow++;
    this->czas_trwania = x.czas_trwania;
    this->utworow = x.utworow;
    this->autor = x.autor;
    this->gatunek = x.gatunek;
}

// destruktor
Album_muzyczny::~Album_muzyczny() {
    liczbaAlbumow--;
}

// przeciążony operator przypisywania
Album_muzyczny& Album_muzyczny::operator=(const Album_muzyczny& x) {
    if (&x == this)return *this;

    Album_muzyczny n(x.tytul, x.rok_wydania, x.ocena, x.min_wiek, x.ulubione, x.czas_trwania, x.utworow, x.autor, x.gatunek);
    tytul = x.tytul;
    rok_wydania = x.rok_wydania;
    ocena = x.ocena;
    min_wiek = x.min_wiek;
    ulubione = x.ulubione;
    czas_trwania = x.czas_trwania;
    utworow = x.utworow;
    autor = x.autor;
    gatunek = x.gatunek;

    return *this;
}