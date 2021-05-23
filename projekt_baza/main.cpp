#include "Header.h"
#include "Utwor.cpp"
#include "Ksiazka.cpp"
#include "Film.cpp"
#include "Album_muzyczny.cpp"
#include "funkcje.cpp"

int main()
{
    SetConsoleOutputCP(65001);

    Utwor* wsk;
    std::vector<Ksiazka> ksiazki;
    std::vector<Film> filmy;
    std::vector<Album_muzyczny> muzyka;

    std::cout << "Hello World!\n";
    /*dodaj_ksiazke(ksiazki);
    system("cls");
    wsk=&ksiazki.at(0);
    wsk->wyswietl();

    dodaj_film(filmy);
    system("cls");
    wsk = &filmy.at(0);
    wsk->wyswietl();*/

    dodaj_album(muzyka);
    system("cls");
    wsk = &muzyka.at(0);
    wsk->wyswietl();
}