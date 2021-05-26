#pragma once
#include "Header.h"
#include "Ksiazka.h"
#include "Film.h"
#include "Album_muzyczny.h"

void dodaj_ksiazke(std::vector<Ksiazka>& k);
void dodaj_film(std::vector<Film>& f);
void dodaj_album(std::vector<Album_muzyczny>& a);

void edytujKsiazki(std::vector<Ksiazka>& ksiazki);
void edytujFilmy(std::vector<Film>& filmy);
void edytujAlbumMuzyczny(std::vector<Album_muzyczny>& muzyka);

void szukajKsiazki(std::vector<Ksiazka>& ksiazki);
void szukajFilmu(std::vector<Film>& filmy);
void szukajAlbumuMuzycznego(std::vector<Album_muzyczny>& muzyka);