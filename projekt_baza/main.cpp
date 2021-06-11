#include "Header.h"
#include "Utwor.h"
#include "Ksiazka.h"
#include "Film.h"
#include "Album_muzyczny.h"
#include "funkcje.h"

int main()
{
    //przygotowanie programu
    SetConsoleOutputCP(65001);

    Utwor* wsk;
    std::vector<Ksiazka> ksiazki;
    std::vector<Film> filmy;
    std::vector<Album_muzyczny> muzyka;

    //menu główne
    while (true) {
        system("cls");
        unsigned short choice;
        std::cout << "Menu główne" << std::endl;
        std::cout << std::endl;
        std::cout << "1. Dodaj przedmiot do bazy." << std::endl;
        std::cout << "2. Przeglądaj bazę." << std::endl;
        std::cout << "3. Wyszukiwanie." << std::endl;
        std::cout << "4. Edytuj przedmiot z bazy." << std::endl;
        std::cout << std::endl;
        std::cout << "5. Zapisz stan bazy." << std::endl;
        std::cout << "6. Wczytaj stan bazy." << std::endl;
        std::cout << std::endl;
        std::cout << "9. WYCZYŚĆ BAZĘ" << std::endl;
        std::cout << std::endl;
        std::cout << "0. Wyjdź." << std::endl;
        std::cout << std::endl;
        std::cout << "Statystyki" << std::endl;
        std::cout << "Przedmiotów:\t" << ksiazki.size() + filmy.size() + muzyka.size() << std::endl;
        std::cout << "Książek:\t" << ksiazki.size() << std::endl;
        std::cout << "Filmów:\t\t" << filmy.size() << std::endl;
        std::cout << "Albumów muz.:\t" << muzyka.size() << std::endl;
        std::cout << std::endl;
        std::cout << "Wybór: ";
        std::cin >> choice;
        std::cin.ignore(256, '\n');
        system("cls");

        switch (choice) {
            case 1: { // dodawanie do bazy
                unsigned short choice1;
                std::cout << "Dodawanie przedmiotów." << std::endl;
                std::cout << "1. Dodaj książkę." << std::endl;
                std::cout << "2. Dodaj film." << std::endl;
                std::cout << "3. Dodaj album muzyczny." << std::endl;
                std::cout << std::endl;
                std::cout << "0. Anuluj.";
                std::cout << std::endl;
                std::cout << "Wybór: ";
                std::cin >> choice1;
                std::cin.ignore(256, '\n');
                system("cls");
                switch (choice1) {
                    case 1: {
                        dodaj_ksiazke(ksiazki);
                        break;
                    }
                    case 2: {
                        dodaj_film(filmy);
                        break;
                    }
                    case 3: {
                        dodaj_album(muzyka);
                        break;
                    }
                }
                break;
            }
            case 2: { // przeglądanie bazy
                unsigned short choice1;
                unsigned short choice2;
                std::cout << "Przeglądanie przedmiotów." << std::endl;
                std::cout << "1. Przeglądaj książki." << std::endl;
                std::cout << "2. Przeglądaj filmy." << std::endl;
                std::cout << "3. Przeglądaj albumy muzyczne." << std::endl;
                std::cout << std::endl;
                std::cout << "0. Anuluj.";
                std::cout << std::endl;
                std::cout << "Wybór: ";
                std::cin >> choice1;
                std::cin.ignore(256, '\n');
                system("cls");
                if (choice1 == 0)break;
                std::cout << "Pokazywać tylko ulubione? (1 - Tak, Reszta - Nie)" << std::endl;
                std::cout << "Wybór: ";
                std::cin >> choice2;
                std::cin.ignore(256, '\n');
                system("cls");
                switch (choice1) {
                    case 1: { // przeglądanie książek
                        for (unsigned int i = 0; i < ksiazki.size(); i++) {
                            if (choice2 == 1) {
                                if (!ksiazki.at(i).czyUlubione())continue;
                            }
                            std::cout << std::endl;
                            std::cout << "Książka nr. " << i+1 << std::endl;
                            wsk = &ksiazki.at(i);
                            wsk->wyswietl();
                        }
                        system("pause");
                        break;
                    }
                    case 2: { // przeglądanie filmów
                        for (unsigned int i = 0; i < filmy.size(); i++) {
                            if (choice2 == 1) {
                                if (!filmy.at(i).czyUlubione())continue;
                            }
                            std::cout << std::endl;
                            std::cout << "Film nr. " << i+1 << std::endl;
                            wsk = &filmy.at(i);
                            wsk->wyswietl();
                        }
                        system("pause");
                        break;
                    }
                    case 3: { // przeglądanie albumów muzycznych
                        for (unsigned int i = 0; i < muzyka.size(); i++) {
                            if (choice2 == 1) {
                                if (!muzyka.at(i).czyUlubione())continue;
                            }
                            std::cout << std::endl;
                            std::cout << "Album muzyczny nr. " << i+1 << std::endl;
                            wsk = &muzyka.at(i);
                            wsk->wyswietl();
                        }
                        system("pause");
                        break;
                    }
                }
                break;
            }
            case 3: { // wyszukiwanie
                unsigned short choice1;
                std::cout << "Wyszukiwanie: " << std::endl;
                std::cout << std::endl;
                std::cout << "1. Szukaj w książkach" << std::endl;
                std::cout << "2. Szukaj w filmach" << std::endl;
                std::cout << "3. Szukaj w albumach muzycznych" << std::endl;
                std::cout << std::endl;
                std::cout << "0. Anuluj" << std::endl;
                std::cout << std::endl;
                std::cout << "Wybór: ";
                std::cin >> choice1;
                std::cin.ignore(256, '\n');
                switch (choice1) {
                    case 1: {
                        szukajKsiazki(ksiazki);
                        break;
                    }
                    case 2: {
                        szukajFilmu(filmy);
                        break;
                    }
                    case 3: {
                        szukajAlbumuMuzycznego(muzyka);
                        break;
                    }
                }
                break;
            }
            case 4: { // edycja / usuwanie
                unsigned short choice1;
                std::cout << "Edytować/Usunąć skąd?" << std::endl;
                std::cout << std::endl;
                std::cout << "1. Książki" << std::endl;
                std::cout << "2. Filmy" << std::endl;
                std::cout << "3. Albumy muzyczne" << std::endl;
                std::cout << std::endl;
                std::cout << "0. Anuluj" << std::endl;
                std::cout << std::endl;
                std::cout << "Wybór: ";
                std::cin >> choice1;
                std::cin.ignore(256, '\n');
                system("cls");
                switch (choice1) {
                    case 1: {
                        edytujKsiazki(ksiazki);
                        break;
                    }
                    case 2: {
                        edytujFilmy(filmy);
                        break;
                    }
                    case 3: {
                        edytujAlbumMuzyczny(muzyka);
                        break;
                    }
                }
                break;
            }
            case 5: { // zapisywanie bazy
                std::string name;
                std::cout << "Podaj nazwę, pod którą chcesz zapisać bazę." << std::endl;
                std::cout << "Bazy zostaną zapisane jako 3 pliki .csv" << std::endl;
                std::cout << std::endl;
                std::cout << "[NAZWA]_k.csv\tBaza ksiązek" << std::endl;
                std::cout << "[NAZWA]_f.csv\tBaza filmów" << std::endl;
                std::cout << "[NAZWA]_m.csv\tBaza albumów muzycznych" << std::endl;
                std::cout << std::endl;
                std::cout << "Nazwa: ";
                std::getline(std::cin, name);
                zapiszKsiazki(ksiazki, name);
                zapiszFilmy(filmy, name);
                zapiszMuzyke(muzyka, name);
                std::cout << "Ukończono zapisywanie!" << std::endl;
                system("pause");
                break;
            }
            case 6: { // wczytywanie bazy
                std::string name;
                std::cout << "Podaj nazwę bazy, którą chcesz wczytać." << std::endl;
                std::cout << "Należy podać nazwę bazy przed znakiem _." << std::endl;
                std::cout << "Zostaną wczytane 3 bazy naraz." << std::endl;
                std::cout << std::endl;
                std::cout << "[NAZWA]_k.csv\tBaza ksiązek" << std::endl;
                std::cout << "[NAZWA]_f.csv\tBaza filmów" << std::endl;
                std::cout << "[NAZWA]_m.csv\tBaza albumów muzycznych" << std::endl;
                std::cout << std::endl;
                std::cout << "Nazwa: ";
                std::getline(std::cin, name);
                wczytajKsiazki(ksiazki, name);
                wczytajFilmy(filmy, name);
                wczytajMuzyke(muzyka, name);
                std::cout << "Ukończono wczytywanie!" << std::endl;
                system("pause");
                break;
            }
            case 9: { // czyszczenie bazy w pamięci ram
                unsigned char wybor;
                std::cout << "CZY NA PEWNO WYCZYŚĆ BAZĘ DANYCH W PAMIĘCI PODRĘCZNEJ?" << std::endl;
                std::cout << "Niezapisane zmiany zostaną utracone!" << std::endl;
                std::cout << std::endl;
                std::cout << "Wyczyścić? [t/N]: ";
                std::cin >> wybor;
                std::cin.ignore(256, '\n');
                if (tolower(wybor) == 't') {
                    ksiazki.clear();
                    filmy.clear();
                    muzyka.clear();
                    std::cout << "Wyczyszczono" << std::endl;
                }
                else std::cout << "Nic nie zostało usunięte." << std::endl;
                system("pause");
                break;
            }
        }
        if (choice == 0) break; // wyjście
    }
}