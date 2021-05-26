#pragma once
#include "Header.h"
#include "Utwor.h"

class Album_muzyczny : public Utwor {
private:
    unsigned short czas_trwania = 0;
    unsigned short utworow = 0;
    std::string autor;
    std::string gatunek;
    static unsigned int liczbaAlbumow;

public:
    inline void wyswietl();
    friend void edytujAlbumMuzyczny(std::vector<Album_muzyczny>& muzyka);
    friend void szukajAlbumuMuzycznego(std::vector<Album_muzyczny>& muzyka);
    inline unsigned int zwrocLiczbeAlbumow();

    inline Album_muzyczny(std::string u_tytul, unsigned short u_rok_wydania, double u_ocena, unsigned short u_min_wiek, bool u_ulubione, unsigned short u_czas_trwania, unsigned short u_utworow, std::string u_autor, std::string u_gatunek);
    inline Album_muzyczny(const Album_muzyczny& x);
    inline ~Album_muzyczny();

    inline Album_muzyczny& operator=(const Album_muzyczny& x);
};