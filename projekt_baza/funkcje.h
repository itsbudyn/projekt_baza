#pragma once
#include "Header.h"
#include "Ksiazka.h"
#include "Film.h"
#include "Album_muzyczny.h"

inline void dodaj_ksiazke(std::vector<Ksiazka>& k);
inline void dodaj_film(std::vector<Film>& f);
inline void dodaj_album(std::vector<Album_muzyczny>& a);

inline void edytujKsiazki(std::vector<Ksiazka>& ksiazki);
inline void edytujFilmy(std::vector<Film>& filmy);
inline void edytujAlbumMuzyczny(std::vector<Album_muzyczny>& muzyka);

inline void szukajKsiazki(std::vector<Ksiazka>& ksiazki);
inline void szukajFilmu(std::vector<Film>& filmy);
inline void szukajAlbumuMuzycznego(std::vector<Album_muzyczny>& muzyka);