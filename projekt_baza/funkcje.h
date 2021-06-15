#pragma once
#include "Header.h"
#include "Ksiazka.h"
#include "Film.h"
#include "Album_muzyczny.h"

// funkcje do dodawania
void dodaj_ksiazke(std::vector<Ksiazka>& k);
void dodaj_film(std::vector<Film>& f);
void dodaj_album(std::vector<Album_muzyczny>& a);

// funkcje do edycji
void edytujKsiazki(std::vector<Ksiazka>& ksiazki);
void edytujFilmy(std::vector<Film>& filmy);
void edytujAlbumMuzyczny(std::vector<Album_muzyczny>& muzyka);

// funkcje do wyszukiwania
void szukajKsiazki(std::vector<Ksiazka>& ksiazki);
void szukajFilmu(std::vector<Film>& filmy);
void szukajAlbumuMuzycznego(std::vector<Album_muzyczny>& muzyka);

// funkcje odpowiedzialne za zapis bazy 
void zapiszKsiazki(const std::vector<Ksiazka>& db, const std::string name);
void zapiszFilmy(const std::vector<Ksiazka>& db, const std::string name);
void zapiszMuzyke(const std::vector<Album_muzyczny>& db, const std::string name);

// funkcje odpowiedzialne za wczytywanie bazy
void wczytajKsiazki(std::vector<Ksiazka>& db, const std::string name);
void wczytajFilmy(std::vector<Film>& db, const std::string name);
void wczytajMuzyke(std::vector<Album_muzyczny>& db, const std::string name);

// funkcja odpowidzialna za wyświetlanie statystyk
void statsMenu(const std::vector<Ksiazka> &k, const std::vector<Film> &f, const std::vector<Album_muzyczny> &m);

// funkcje potrzebne do statystyk
double findmin(const std::vector<double>& k);
double findavg(const std::vector<double>& k);
double findmax(const std::vector<double>& k);
double findsum(const std::vector<double>& k);