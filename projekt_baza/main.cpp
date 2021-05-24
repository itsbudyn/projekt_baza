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
        unsigned short choice;
        std::cout << "Menu g��wne" << std::endl;
        std::cout << std::endl;
        std::cout << "1. Dodaj przedmiot do bazy." << std::endl;
        std::cout << "2. Przegl�daj baz�.\t\t[do zrobienia]" << std::endl;
        std::cout << "3. Wyszukiwanie." << std::endl;
        std::cout << "4. Edytuj/Usu� przedmiot z bazy." << std::endl;
        std::cout << std::endl;
        std::cout << "5. Zapisz stan bazy. \t\t[do zrobienia] " << std::endl;
        std::cout << "6. Wczytaj stan bazy.\t\t[do zrobienia] " << std::endl;
        std::cout << std::endl;
        std::cout << "9. WYCZY�� BAZ�" << std::endl;
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
        std::cin >> choice;
        std::cin.ignore(256, '\n');
        system("cls");

        switch (choice) {
            case 1: {
                unsigned short choice1;
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
                break;
            }
            case 2: {
                unsigned short choice1;
                unsigned short choice2;
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
                if (choice1 == 0)break;
                std::cout << "Pokazywa� tylko ulubione? (1 - Tak, Reszta - Nie)" << std::endl;
                std::cout << "Wyb�r: ";
                std::cin >> choice2;
                std::cin.ignore(256, '\n');
                system("cls");
                switch (choice1) {
                    case 1: {
                        for (unsigned int i = 0; i < ksiazki.size(); i++) {
                            if (choice2 == 1) {
                                if (!ksiazki.at(i).czyUlubione())continue;
                            }
                            std::cout << std::endl;
                            std::cout << "Ksi��ka nr. " << i+1 << std::endl;
                            wsk = &ksiazki.at(i);
                            wsk->wyswietl();
                        }
                        system("pause");
                        break;
                    }
                    case 2: {
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
                    case 3: {
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
            case 3: {
                unsigned short choice1;
                std::cout << "Wyszukiwanie: " << std::endl;
                std::cout << std::endl;
                std::cout << "1. Szukaj w ksi��kach" << std::endl;
                std::cout << "2. Szukaj w filmach" << std::endl;
                std::cout << "3. Szukaj w albumach muzycznych" << std::endl;
                std::cout << std::endl;
                std::cout << "0. Anuluj" << std::endl;
                std::cout << std::endl;
                std::cout << "Wyb�r: ";
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
            case 4: {
                unsigned short choice1;
                std::cout << "Edytowa�/Usun�� sk�d?" << std::endl;
                std::cout << std::endl;
                std::cout << "1. Ksi��ki" << std::endl;
                std::cout << "2. Filmy" << std::endl;
                std::cout << "3. Albumy muzyczne" << std::endl;
                std::cout << std::endl;
                std::cout << "0. Anuluj" << std::endl;
                std::cout << std::endl;
                std::cout << "Wyb�r: ";
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
            case 9: {
                unsigned char wybor;
                std::cout << "CZY NA PEWNO WYCZY�� BAZ� DANYCH W PAMI�CI PODR�CZNEJ?" << std::endl;
                std::cout << "Niezapisane zmiany zostan� utracone!" << std::endl;
                std::cout << std::endl;
                std::cout << "Wyczy�ci�? [t/N]: ";
                std::cin >> wybor;
                std::cin.ignore(256, '\n');
                if (tolower(wybor) == 't') {
                    ksiazki.clear();
                    filmy.clear();
                    muzyka.clear();
                    std::cout << "Wyczyszczono" << std::endl;
                }
                else std::cout << "Nic nie zosta�o usuni�te." << std::endl;
                system("pause");
                break;
            }
        }
        if (choice == 0) break;
    }
}