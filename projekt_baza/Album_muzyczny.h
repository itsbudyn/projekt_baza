#pragma once
#include "Header.h"
#include "Utwor.h"

class Album_muzyczny : public Utwor {
private:
    // zmienne
    unsigned short czas_trwania = 0;
    unsigned short utworow = 0;
    std::string autor;
    std::string gatunek;
    static unsigned int liczbaAlbumow;

public:
    // metody
    void wyswietl() const;
    unsigned short zwrocCzasTrwania() const;
    unsigned short zwrocLiczbeUtworow() const;
    friend void edytujAlbumMuzyczny(std::vector<Album_muzyczny>& muzyka);
    friend void szukajAlbumuMuzycznego(std::vector<Album_muzyczny>& muzyka);
    friend void zapiszMuzyke(const std::vector<Album_muzyczny>& db, const std::string name);
    static unsigned int zwrocLiczbeAlbumow();

    // konstruktory i destruktor
    Album_muzyczny();
    Album_muzyczny(std::string u_tytul, unsigned short u_rok_wydania, double u_ocena, unsigned short u_min_wiek, bool u_ulubione, unsigned short u_czas_trwania, unsigned short u_utworow, std::string u_autor, std::string u_gatunek);
    Album_muzyczny(const Album_muzyczny& x);
    ~Album_muzyczny();

    // operatory
    Album_muzyczny& operator=(const Album_muzyczny& x);
};