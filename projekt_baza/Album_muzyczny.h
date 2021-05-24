#pragma once
#include "Header.h"
#include "Utwor.h"

class Album_muzyczny : private Utwor {
private:
    unsigned short czas_trwania = 0;
    unsigned short utworow = 0;
    bool czy_single = false;
    std::string autor;
    std::string gatunek;

public:
    inline void wyswietl();
    friend void edytujAlbumMuzyczny(std::vector<Album_muzyczny>& muzyka);
    inline Album_muzyczny(std::string u_tytul, unsigned short u_rok_wydania, double u_ocena, unsigned short u_min_wiek, bool u_ulubione, unsigned short u_czas_trwania, unsigned short u_utworow, bool u_czy_single, std::string u_autor, std::string u_gatunek);
    inline Album_muzyczny(const Album_muzyczny& x);
};