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

    while (true) {
        system("cls");
        std::cout << "Menu g��wne" << std::endl;
        std::cout << std::endl;
        std::cout << "1. Dodaj przedmiot do bazy." << std::endl;
        std::cout << "2. Przegl�daj baz�." << std::endl;
        std::cout << std::endl;
        std::cout << "0. Wyjd�." << std::endl;
        std::cout << std::endl;
        std::cout << "Statystyki" << std::endl;
        std::cout << "Przedmiot�w:\t" << ksiazki.size() + filmy.size() + muzyka.size() << std::endl;
        std::cout << "Ksi��ek:\t" << ksiazki.size() << std::endl;
        std::cout << "Film�w:\t\t" << filmy.size() << std::endl;
        std::cout << "Album�w muz.:\t" << muzyka.size() << std::endl;
        std::cout << std::endl;
        std::cout << "Wyb�r: ";
        unsigned short choice;
        unsigned short choice1;
        std::cin >> choice;
        std::cin.ignore(256, '\n');
        system("cls");

        switch (choice) {
            case 1: {
                std::cout << "Dodawanie przedmiot�w." << std::endl;
                std::cout << "1. Dodaj ksi��k�." << std::endl;
                std::cout << "2. Dodaj film." << std::endl;
                std::cout << "3. Dodaj album muzyczny." << std::endl;
                std::cout << std::endl;
                std::cout << "0. Anuluj.";
                std::cout << std::endl;
                std::cout << "Wyb�r: ";
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
                if (choice1 == 0) break;
            }
            case 2: {
                std::cout << "Przegl�danie przedmiot�w." << std::endl;
                std::cout << "1. Przegl�daj ksi��ki." << std::endl;
                std::cout << "2. Przegl�daj filmy." << std::endl;
                std::cout << "3. Przegl�daj albumy muzyczne." << std::endl;
                std::cout << std::endl;
                std::cout << "0. Anuluj.";
                std::cout << std::endl;
                std::cout << "Wyb�r: ";
                std::cin >> choice1;
                std::cin.ignore(256, '\n');
                system("cls");
                switch (choice1) {
                    case 1: {
                        for (unsigned int i = 0; i < ksiazki.size(); i++) {
                            std::cout << std::endl;
                            std::cout << "Ksi��ka nr. " << i << std::endl;
                            wsk = &ksiazki.at(i);
                            wsk->wyswietl();
                        }
                        system("pause");
                        break;
                    }
                    case 2: {
                        for (unsigned int i = 0; i < filmy.size(); i++) {
                            std::cout << std::endl;
                            std::cout << "Film nr. " << i << std::endl;
                            wsk = &filmy.at(i);
                            wsk->wyswietl();
                        }
                        system("pause");
                        break;
                    }
                    case 3: {
                        for (unsigned int i = 0; i < ksiazki.size(); i++) {
                            std::cout << std::endl;
                            std::cout << "Album muzyczny nr. " << i << std::endl;
                            wsk = &filmy.at(i);
                            wsk->wyswietl();
                        }
                        system("pause");
                        break;
                    }
                }
                if (choice1 == 0) break;
            }
        }
        if (choice == 0) break;
    }
}