#include "funkcje.h"

void dodaj_ksiazke(std::vector<Ksiazka>& k) {
    std::string tytul;
    unsigned short rok_wydania;
    double ocena;
    unsigned short min_wiek;
    bool ulubione;
    unsigned short strony;
    std::string autor;
    std::string wydawnictwo;
    std::string gatunek;

    std::cout << "Podaj tytu³ ksi¹¿ki: ";
    std::getline(std::cin, tytul);

    std::cout << "Podaj autora ksi¹¿ki: ";
    std::getline(std::cin, autor);

    std::cout << "Podaj wydawnictwo ksi¹¿ki: ";
    std::getline(std::cin, wydawnictwo);

    std::cout << "Podaj rok wydania ksi¹¿ki: ";
    std::cin >> rok_wydania;
    std::cin.ignore(256, '\n');

    std::cout << "Podaj gatunek ksi¹¿ki: ";
    std::getline(std::cin, gatunek);

    std::cout << "Podaj iloœæ stron: ";
    std::cin >> strony;
    std::cin.ignore(256, '\n');

    std::cout << "Podaj minimalne ograniczenie wiekowe: ";
    std::cin >> min_wiek;
    std::cin.ignore(256, '\n');

    std::cout << "Ocena? (0-5)";
    std::cin >> ocena;
    std::cin.ignore(256, '\n');

    std::cout << "Oznaczyæ jako ulubione? [t/N]";
    char wybor;
    std::cin >> wybor;
    std::cin.ignore(256, '\n');
    if (tolower(wybor) == 't') ulubione = true;
    else ulubione = false;

    Ksiazka x(tytul, rok_wydania, ocena, min_wiek, ulubione, strony, autor, wydawnictwo, gatunek);
    x.wyswietl();
    k.push_back(x);
    system("pause");
}

void dodaj_film(std::vector<Film>& f) {
    std::string tytul;
    unsigned short rok_wydania;
    double ocena;
    unsigned short min_wiek;
    bool ulubione;
    unsigned short czas_trwania;
    std::string rezyser;
    std::string gatunek;

    std::cout << "Podaj tytu³ filmu: ";
    std::getline(std::cin, tytul);

    std::cout << "Podaj re¿ysera filmu: ";
    std::getline(std::cin, rezyser);

    std::cout << "Podaj rok wydania filmu: ";
    std::cin >> rok_wydania;
    std::cin.ignore(256, '\n');

    std::cout << "Podaj gatunek filmu: ";
    std::getline(std::cin, gatunek);

    std::cout << "Podaj czas trwania filmu [m]: ";
    std::cin >> czas_trwania;
    std::cin.ignore(256, '\n');

    std::cout << "Podaj minimalne ograniczenie wiekowe: ";
    std::cin >> min_wiek;
    std::cin.ignore(256, '\n');

    std::cout << "Ocena? (0-5)";
    std::cin >> ocena;
    std::cin.ignore(256, '\n');

    std::cout << "Oznaczyæ jako ulubione? [t/N]";
    char wybor;
    std::cin >> wybor;
    std::cin.ignore(256, '\n');
    if (tolower(wybor) == 't') ulubione = true;
    else ulubione = false;

    Film x(tytul, rok_wydania, ocena, min_wiek, ulubione, czas_trwania, rezyser, gatunek);
    x.wyswietl();
    f.push_back(x);
    system("pause");
}

void dodaj_album(std::vector<Album_muzyczny>& a) {
    std::string tytul; 
    unsigned short rok_wydania; 
    double ocena; 
    unsigned short min_wiek; 
    bool ulubione; 
    unsigned short czas_trwania; 
    unsigned short utworow; 
    std::string autor; 
    std::string gatunek; 

    std::cout << "Podaj tytu³ albumu: ";
    std::getline(std::cin, tytul);

    std::cout << "Podaj autorów albumu: ";
    std::getline(std::cin, autor);

    std::cout << "Podaj rok wydania albumu: ";
    std::cin >> rok_wydania;
    std::cin.ignore(256, '\n');

    std::cout << "Podaj gatunek muzyczny albumu: ";
    std::getline(std::cin, gatunek);

    std::cout << "Podaj czas trwania albumu [m]: ";
    std::cin >> czas_trwania;
    std::cin.ignore(256, '\n');

    std::cout << "Podaj iloœæ utworów w albumie: ";
    std::cin >> utworow;
    std::cin.ignore(256, '\n');

    std::cout << "Podaj minimalne ograniczenie wiekowe: ";
    std::cin >> min_wiek;
    std::cin.ignore(256, '\n');

    std::cout << "Ocena? (0-5)";
    std::cin >> ocena;
    std::cin.ignore(256, '\n');

    std::cout << "Oznaczyæ jako ulubione? [t/N]";
    char wybor;
    std::cin >> wybor;
    std::cin.ignore(256, '\n');
    if (tolower(wybor) == 't') ulubione = true;
    else ulubione = false;

    Album_muzyczny x(tytul, rok_wydania, ocena, min_wiek, ulubione, czas_trwania, utworow, autor, gatunek);
    x.wyswietl();
    a.push_back(x);
    system("pause");
}

void edytujKsiazki(std::vector<Ksiazka>& ksiazki) {
    Utwor* wsk;
    unsigned short int choice;
    for (unsigned int i = 0; i < ksiazki.size(); i++) {
        std::cout << std::endl;
        std::cout << "Ksi¹¿ka nr. " << i + 1 << std::endl;
        wsk = &ksiazki.at(i);
        wsk->wyswietl();
    }
    std::cout << std::endl;
    std::cout << "Wybierz przedmiot do edycji (0 aby anulowaæ): ";
    std::cin >> choice;
    std::cin.ignore(256, '\n');
    if (choice != 0 && choice<=ksiazki.size()) {
        wsk = &ksiazki.at(choice - 1);
        wsk->wyswietl();
        std::cout << std::endl;
        std::cout << "Co zrobiæ z powy¿szym przedmiotem?" << std::endl;
        std::cout << "1. Edytuj pole" << std::endl;
        std::cout << "2. Utwórz kopiê przedmiotu " << std::endl;
        std::cout << "3. Utwórz kopiê przedmiotu (operator =)" << std::endl;
        std::cout << "4. Usuñ przedmiot" << std::endl;
        std::cout << std::endl;
        std::cout << "0. Nic" << std::endl;
        std::cout << std::endl;
        std::cout << "Wybór: ";
        unsigned short int choice1;
        std::cin >> choice1;
        std::cin.ignore(256, '\n');
        switch (choice1) {
            case 1: {
                unsigned short int field;
                std::cout << "Wybierz pole do zmiany: " << std::endl;
                std::cout << "1. Zmieñ tytu³: " << std::endl;
                std::cout << "2. Zmieñ rok wydania: " << std::endl;
                std::cout << "3. Zmieñ ocenê: " << std::endl;
                std::cout << "4. Zmieñ ograniczenie wiekowe: " << std::endl;
                std::cout << "5. Dodaj/Usuñ z ulubionych: " << std::endl;
                std::cout << "6. Zmieñ iloœæ stron: " << std::endl;
                std::cout << "7. Zmieñ autora: " << std::endl;
                std::cout << "8. Zmieñ wydawnictwo: " << std::endl;
                std::cout << "9. Zmieñ gatunek: " << std::endl;
                std::cout << std::endl;
                std::cout << "Inne - Anuluj: " << std::endl;
                std::cout << std::endl;
                std::cout << "Wybór: ";
                std::cin >> field;
                std::cin.ignore(256, '\n');
                switch (field) {
                    case 1: {
                        std::string tytul;
                        std::cout << "Podaj nowy tytu³: ";
                        std::getline(std::cin, tytul);
                        ksiazki.at(choice - 1).tytul = tytul;
                        std::cout << "Zmieniono!" << std::endl;
                        system("pause");
                        break;
                    }
                    case 2: {
                        unsigned short rok_wydania;
                        std::cout << "Podaj nowy rok wydania: ";
                        std::cin >> rok_wydania;
                        std::cin.ignore(256, '\n');
                        ksiazki.at(choice - 1).rok_wydania = rok_wydania;
                        std::cout << "Zmieniono!" << std::endl;
                        system("pause");
                        break;
                    }
                    case 3: {
                        double ocena;
                        std::cout << "Podaj now¹ ocenê (0 aby usun¹æ ocenê): ";
                        std::cin >> ocena;
                        std::cin.ignore(256, '\n');
                        if (ocena > 5) ocena = 5;
                        else if (ocena < 0) ocena = 1;
                        ksiazki.at(choice - 1).ocena = ocena;
                        std::cout << "Zmieniono!" << std::endl;
                        system("pause");
                        break;
                    }
                    case 4: {
                        unsigned short min_wiek;
                        std::cout << "Podaj nowe ograniczenie wiekowe: ";
                        std::cin >> min_wiek;
                        std::cin.ignore(256, '\n');
                        ksiazki.at(choice - 1).min_wiek = min_wiek;
                        std::cout << "Zmieniono!" << std::endl;
                        system("pause");
                        break;
                    }
                    case 5: {
                        bool ulubione;
                        char taknie='n';
                        std::cout << "Czy przedmiot ma byæ w ulubionych? [t/N]: ";
                        std::cin >> taknie;
                        std::cin.ignore(256, '\n');
                        if (tolower(taknie) == 't') ulubione = true;
                        else ulubione = false;
                        ksiazki.at(choice - 1).ulubione = ulubione;
                        std::cout << "Zmieniono!" << std::endl;
                        system("pause");
                        break;
                    }
                    case 6: {
                        unsigned short strony;
                        std::cout << "Ile stron ma ksi¹¿ka?: ";
                        std::cin >> strony;
                        std::cin.ignore(256, '\n');
                        ksiazki.at(choice - 1).strony = strony;
                        std::cout << "Zmieniono!" << std::endl;
                        system("pause");
                        break;
                    }
                    case 7: {
                        std::string autor;
                        std::cout << "Podaj nowego autora/autorów ksi¹¿ki: ";
                        std::getline(std::cin, autor);
                        ksiazki.at(choice - 1).autor = autor;
                        std::cout << "Zmieniono!" << std::endl;
                        system("pause");
                        break;
                    }
                    case 8: {
                        std::string wydawnictwo;
                        std::cout << "Podaj nowe wydawnictwo ksi¹¿ki: ";
                        std::getline(std::cin, wydawnictwo);
                        ksiazki.at(choice - 1).wydawnictwo = wydawnictwo;
                        std::cout << "Zmieniono!" << std::endl;
                        system("pause");
                        break;
                    }
                    case 9: {
                        std::string gatunek;
                        std::cout << "Podaj nowy gatunek ksi¹¿ki: ";
                        std::getline(std::cin, gatunek);
                        ksiazki.at(choice - 1).gatunek = gatunek;
                        std::cout << "Zmieniono!" << std::endl;
                        system("pause");
                        break;
                    }
                }
                break;
            }
            case 2: {
                std::cout << "Powy¿szy wpis zostanie skopiowany. Czy kontynuowaæ? (1 - Tak, Reszta - Nie)" << std::endl;
                std::cout << "Wybór: ";
                unsigned short wybor;
                std::cin >> wybor;
                std::cin.ignore(256, '\n');
                if (wybor == 1) {
                    Ksiazka nowa(ksiazki.at(choice - 1));
                    ksiazki.push_back(nowa);
                    std::cout << "Skopiowano!" << std::endl; 
                }
                else std::cout << "Nic nie zosta³o skopiowane." << std::endl;
                system("pause");
                break;
            }
            case 3: {
                std::cout << "Powy¿szy wpis zostanie skopiowany (operator =). Czy kontynuowaæ? (1 - Tak, Reszta - Nie)" << std::endl;
                std::cout << "Wybór: ";
                unsigned short wybor;
                std::cin >> wybor;
                std::cin.ignore(256, '\n');
                if (wybor == 1) {
                    Ksiazka nowa;
                    nowa = ksiazki.at(choice - 1);
                    ksiazki.push_back(nowa);
                    std::cout << "Skopiowano!" << std::endl;
                }
                else std::cout << "Nic nie zosta³o skopiowane." << std::endl;
                system("pause");
                break;
            }
            case 4: {
                std::cout << "Powy¿szy wpis zostanie usuniêty. Czy kontynuowaæ? (1 - Tak, Reszta - Nie)" << std::endl;
                std::cout << "Wybór: ";
                unsigned short wybor;
                std::cin >> wybor;
                std::cin.ignore(256, '\n');
                if (wybor == 1) {
                    wsk = nullptr;
                    ksiazki.erase(ksiazki.begin() + (choice - 1));
                    std::cout << "Usuniêto!" << std::endl;
                }
                else std::cout << "Nic nie zosta³o usuniête." << std::endl;
                system("pause");
                break;
            }
        }
    }
    else {
    system("cls");
    std::cout << "Anulowano edycjê." << std::endl;
    system("pause");
}
}

void edytujFilmy(std::vector<Film>& filmy) {
    Utwor* wsk;
    unsigned short int choice;
    for (unsigned int i = 0; i < filmy.size(); i++) {
        std::cout << std::endl;
        std::cout << "Film nr. " << i + 1 << std::endl;
        wsk = &filmy.at(i);
        wsk->wyswietl();
    }
    std::cout << std::endl;
    std::cout << "Wybierz przedmiot do edycji (0 aby anulowaæ): ";
    std::cin >> choice;
    std::cin.ignore(256, '\n');
    if (choice != 0 && choice <= filmy.size()) {
        wsk = &filmy.at(choice - 1);
        wsk->wyswietl();
        std::cout << std::endl;
        std::cout << "Co zrobiæ z powy¿szym przedmiotem?" << std::endl;
        std::cout << "1. Edytuj pole" << std::endl;
        std::cout << "2. Utwórz kopiê przedmiotu " << std::endl;
        std::cout << "3. Utwórz kopiê przedmiotu (operator =)" << std::endl;
        std::cout << "4. Usuñ przedmiot" << std::endl;
        std::cout << std::endl;
        std::cout << "0. Nic" << std::endl;
        std::cout << std::endl;
        std::cout << "Wybór: ";
        unsigned short int choice1;
        std::cin >> choice1;
        std::cin.ignore(256, '\n');
        switch (choice1) {
        case 1: {
            unsigned short int field;
            std::cout << "Wybierz pole do zmiany: " << std::endl;
            std::cout << "1. Zmieñ tytu³: " << std::endl;
            std::cout << "2. Zmieñ rok wydania: " << std::endl;
            std::cout << "3. Zmieñ ocenê: " << std::endl;
            std::cout << "4. Zmieñ ograniczenie wiekowe: " << std::endl;
            std::cout << "5. Dodaj/Usuñ z ulubionych: " << std::endl;
            std::cout << "6. Zmieñ czas trwania: " << std::endl;
            std::cout << "7. Zmieñ re¿ysera: " << std::endl;
            std::cout << "8. Zmieñ gatunek: " << std::endl;
            std::cout << std::endl;
            std::cout << "Inne - Anuluj: " << std::endl;
            std::cout << std::endl;
            std::cout << "Wybór: ";
            std::cin >> field;
            std::cin.ignore(256, '\n');
            switch (field) {
            case 1: {
                std::string tytul;
                std::cout << "Podaj nowy tytu³: ";
                std::getline(std::cin, tytul);
                filmy.at(choice - 1).tytul = tytul;
                std::cout << "Zmieniono!" << std::endl;
                system("pause");
                break;
            }
            case 2: {
                unsigned short rok_wydania;
                std::cout << "Podaj nowy rok wydania: ";
                std::cin >> rok_wydania;
                std::cin.ignore(256, '\n');
                filmy.at(choice - 1).rok_wydania = rok_wydania;
                std::cout << "Zmieniono!" << std::endl;
                system("pause");
                break;
            }
            case 3: {
                double ocena;
                std::cout << "Podaj now¹ ocenê (0 aby usun¹æ ocenê): ";
                std::cin >> ocena;
                std::cin.ignore(256, '\n');
                if (ocena > 5) ocena = 5;
                else if (ocena < 0) ocena = 1;
                filmy.at(choice - 1).ocena = ocena;
                std::cout << "Zmieniono!" << std::endl;
                system("pause");
                break;
            }
            case 4: {
                unsigned short min_wiek;
                std::cout << "Podaj nowe ograniczenie wiekowe: ";
                std::cin >> min_wiek;
                std::cin.ignore(256, '\n');
                filmy.at(choice - 1).min_wiek = min_wiek;
                std::cout << "Zmieniono!" << std::endl;
                system("pause");
                break;
            }
            case 5: {
                bool ulubione;
                char taknie='n';
                std::cout << "Czy przedmiot ma byæ w ulubionych? [t/N]: ";
                std::cin >> taknie;
                std::cin.ignore(256, '\n');
                if (tolower(taknie) == 't') ulubione = true;
                else ulubione = false;
                filmy.at(choice - 1).ulubione = ulubione;
                std::cout << "Zmieniono!" << std::endl;
                system("pause");
                break;
            } 
            case 6: {
                unsigned short czas_trwania;
                std::cout << "Podaj nowy czas trwania filmu w minutach: ";
                std::cin >> czas_trwania;
                std::cin.ignore(256, '\n');
                filmy.at(choice - 1).czas_trwania = czas_trwania;
                std::cout << "Zmieniono!" << std::endl;
                system("pause");
                break;
            }
            case 7: {
                std::string rezyser;
                std::cout << "Podaj nowego re¿ysera filmu: ";
                std::getline(std::cin, rezyser);
                filmy.at(choice - 1).rezyser = rezyser;
                std::cout << "Zmieniono!" << std::endl;
                system("pause");
                break;
            }
            case 8: {
                std::string gatunek;
                std::cout << "Podaj nowy gatunek filmu: ";
                std::getline(std::cin, gatunek);
                filmy.at(choice - 1).gatunek = gatunek;
                std::cout << "Zmieniono!" << std::endl;
                system("pause");
                break;
            }
            }
            break;
        }
        case 2: {
            std::cout << "Powy¿szy wpis zostanie skopiowany. Czy kontynuowaæ? (1 - Tak, Reszta - Nie)" << std::endl;
            std::cout << "Wybór: ";
            unsigned short wybor;
            std::cin >> wybor;
            std::cin.ignore(256, '\n');
            if (wybor == 1) {
                Film nowy(filmy.at(choice - 1));
                filmy.push_back(nowy);
                std::cout << "Skopiowano!" << std::endl;
            }
            else std::cout << "Nic nie zosta³o skopiowane." << std::endl;
            system("pause");
            break;
        }
        case 3: {
            std::cout << "Powy¿szy wpis zostanie skopiowany (operator =). Czy kontynuowaæ? (1 - Tak, Reszta - Nie)" << std::endl;
            std::cout << "Wybór: ";
            unsigned short wybor;
            std::cin >> wybor;
            std::cin.ignore(256, '\n');
            if (wybor == 1) {
                Film nowy;
                nowy = filmy.at(choice - 1);
                filmy.push_back(nowy);
                std::cout << "Skopiowano!" << std::endl;
            }
            else std::cout << "Nic nie zosta³o skopiowane." << std::endl;
            system("pause");
            break;
        }
        case 4: {
            std::cout << "Powy¿szy wpis zostanie usuniêty. Czy kontynuowaæ? (1 - Tak, Reszta - Nie)" << std::endl;
            std::cout << "Wybór: ";
            unsigned short wybor;
            std::cin >> wybor;
            std::cin.ignore(256, '\n');
            if (wybor == 1) {
                wsk = nullptr;
                filmy.erase(filmy.begin() + (choice - 1));
                std::cout << "Usuniêto!" << std::endl;
            }
            else std::cout << "Nic nie zosta³o usuniête." << std::endl;
            system("pause");
            break;
        }
        }
    }
    else {
    system("cls");
    std::cout << "Anulowano edycjê." << std::endl;
    system("pause");
}
}

void edytujAlbumMuzyczny(std::vector<Album_muzyczny>& muzyka) {
    Utwor* wsk;
    unsigned short int choice;
    for (unsigned int i = 0; i < muzyka.size(); i++) {
        std::cout << std::endl;
        std::cout << "Album muzyczny nr. " << i + 1 << std::endl;
        wsk = &muzyka.at(i);
        wsk->wyswietl();
    }
    std::cout << std::endl;
    std::cout << "Wybierz przedmiot do edycji (0 aby anulowaæ): ";
    std::cin >> choice;
    std::cin.ignore(256, '\n');
    if (choice != 0 && choice <= muzyka.size()) {
        wsk = &muzyka.at(choice - 1);
        wsk->wyswietl();
        std::cout << std::endl;
        std::cout << "Co zrobiæ z powy¿szym przedmiotem?" << std::endl;
        std::cout << "1. Edytuj pole" << std::endl;
        std::cout << "2. Utwórz kopiê przedmiotu " << std::endl;
        std::cout << "3. Utwórz kopiê przedmiotu (operator =)" << std::endl;
        std::cout << "4. Usuñ przedmiot" << std::endl;
        std::cout << std::endl;
        std::cout << "0. Nic" << std::endl;
        std::cout << std::endl;
        std::cout << "Wybór: ";
        unsigned short int choice1;
        std::cin >> choice1;
        std::cin.ignore(256, '\n');
        switch (choice1) {
        case 1: {
            unsigned short int field;
            std::cout << "Wybierz pole do zmiany: " << std::endl;
            std::cout << "1. Zmieñ tytu³: " << std::endl;
            std::cout << "2. Zmieñ rok wydania: " << std::endl;
            std::cout << "3. Zmieñ ocenê: " << std::endl;
            std::cout << "4. Zmieñ ograniczenie wiekowe: " << std::endl;
            std::cout << "5. Dodaj/Usuñ z ulubionych: " << std::endl;
            std::cout << "6. Zmieñ czas trwania: " << std::endl;
            std::cout << "7. Zmieñ iloœc utworów: " << std::endl;
            std::cout << "8. Zmieñ autora/autorów: " << std::endl;
            std::cout << "9. Zmieñ gatunek: " << std::endl;
            std::cout << std::endl;
            std::cout << "Inne - Anuluj: " << std::endl;
            std::cout << std::endl;
            std::cout << "Wybór: ";
            std::cin >> field;
            std::cin.ignore(256, '\n');
            switch (field) {
            case 1: {
                std::string tytul;
                std::cout << "Podaj nowy tytu³: ";
                std::getline(std::cin, tytul);
                muzyka.at(choice - 1).tytul = tytul;
                std::cout << "Zmieniono!" << std::endl;
                system("pause");
                break;
            }
            case 2: {
                unsigned short rok_wydania;
                std::cout << "Podaj nowy rok wydania: ";
                std::cin >> rok_wydania;
                std::cin.ignore(256, '\n');
                muzyka.at(choice - 1).rok_wydania = rok_wydania;
                std::cout << "Zmieniono!" << std::endl;
                system("pause");
                break;
            }
            case 3: {
                double ocena;
                std::cout << "Podaj now¹ ocenê (0 aby usun¹æ ocenê): ";
                std::cin >> ocena;
                std::cin.ignore(256, '\n');
                if (ocena > 5) ocena = 5;
                else if (ocena < 0) ocena = 1;
                muzyka.at(choice - 1).ocena = ocena;
                std::cout << "Zmieniono!" << std::endl;
                system("pause");
                break;
            }
            case 4: {
                unsigned short min_wiek;
                std::cout << "Podaj nowe ograniczenie wiekowe: ";
                std::cin >> min_wiek;
                std::cin.ignore(256, '\n');
                muzyka.at(choice - 1).min_wiek = min_wiek;
                std::cout << "Zmieniono!" << std::endl;
                system("pause");
                break;
            }
            case 5: {
                bool ulubione;
                char taknie = 'n';
                std::cout << "Czy przedmiot ma byæ w ulubionych? [t/N]: ";
                std::cin >> taknie;
                std::cin.ignore(256, '\n');
                if (tolower(taknie) == 't') ulubione = true;
                else ulubione = false;
                muzyka.at(choice - 1).ulubione = ulubione;
                std::cout << "Zmieniono!" << std::endl;
                system("pause");
                break;
            }
            case 6: {
                unsigned short czas_trwania;
                std::cout << "Podaj nowy czas trwania albumu muzycznego w minutach: ";
                std::cin >> czas_trwania;
                std::cin.ignore(256, '\n');
                muzyka.at(choice - 1).czas_trwania = czas_trwania;
                std::cout << "Zmieniono!" << std::endl;
                system("pause");
                break;
            }
            case 7: {
                unsigned short utworow;
                std::cout << "Podaj now¹ iloœæ utworów: ";
                std::cin >> utworow;
                std::cin.ignore(256, '\n');
                muzyka.at(choice - 1).utworow = utworow;
                std::cout << "Zmieniono!" << std::endl;
                system("pause");
                break;
            }
            case 8: {
                std::string autor;
                std::cout << "Podaj nowego autora/autorów albumu: ";
                std::getline(std::cin, autor);
                muzyka.at(choice - 1).autor = autor;
                std::cout << "Zmieniono!" << std::endl;
                system("pause");
                break;
            }
            case 9: {
                std::string gatunek;
                std::cout << "Podaj nowy gatunek muzyczny: ";
                std::getline(std::cin, gatunek);
                muzyka.at(choice - 1).gatunek = gatunek;
                std::cout << "Zmieniono!" << std::endl;
                system("pause");
                break;
            }
            }
            break;
        }
        case 2: {
            std::cout << "Powy¿szy wpis zostanie skopiowany. Czy kontynuowaæ? (1 - Tak, Reszta - Nie)" << std::endl;
            std::cout << "Wybór: ";
            unsigned short wybor;
            std::cin >> wybor;
            std::cin.ignore(256, '\n');
            if (wybor == 1) {
                Album_muzyczny nowy(muzyka.at(choice - 1));
                muzyka.push_back(nowy);
                std::cout << "Skopiowano!" << std::endl;
            }
            else std::cout << "Nic nie zosta³o skopiowane." << std::endl;
            system("pause");
            break;
        }
        case 3: {
            std::cout << "Powy¿szy wpis zostanie skopiowany (operator =). Czy kontynuowaæ? (1 - Tak, Reszta - Nie)" << std::endl;
            std::cout << "Wybór: ";
            unsigned short wybor;
            std::cin >> wybor;
            std::cin.ignore(256, '\n');
            if (wybor == 1) {
                Album_muzyczny nowy;
                nowy=muzyka.at(choice - 1);
                muzyka.push_back(nowy);
                std::cout << "Skopiowano!" << std::endl;
            }
            else std::cout << "Nic nie zosta³o skopiowane." << std::endl;
            system("pause");
            break;
        }
        case 4: {
            std::cout << "Powy¿szy wpis zostanie usuniêty. Czy kontynuowaæ? (1 - Tak, Reszta - Nie)" << std::endl;
            std::cout << "Wybór: ";
            unsigned short wybor;
            std::cin >> wybor;
            std::cin.ignore(256, '\n');
            if (wybor == 1) {
                wsk = nullptr;
                muzyka.erase(muzyka.begin() + (choice - 1));
                std::cout << "Usuniêto!" << std::endl;
            }
            else std::cout << "Nic nie zosta³o usuniête." << std::endl;
            system("pause");
            break;
        }
        }
    }
    else {
    system("cls");
    std::cout << "Anulowano edycjê." << std::endl;
    system("pause");
}
}

void szukajKsiazki(std::vector<Ksiazka>& ksiazki) {
    Utwor* wsk;
    unsigned short results = 0;
    unsigned short ksiazek = 0;
    std::cout << "Opcje wyszukiwania ksi¹¿ki: " << std::endl;
    std::cout << std::endl;
    std::cout << "1. Szukaj po tytule." << std::endl;
    std::cout << "2. Szukaj po autorze." << std::endl;
    std::cout << "3. Szukaj po wydawnictwie." << std::endl;
    std::cout << "4. Szukaj po gatunku." << std::endl;
    std::cout << "5. Szukaj po roku wydania." << std::endl;
    std::cout << "6. Szukaj po iloœci stron." << std::endl;
    std::cout << "7. Szukaj po ograniczeniu wiekowym." << std::endl;
    std::cout << "8. Szukaj po ocenie." << std::endl;
    std::cout << std::endl;
    std::cout << "0. Anuluj wyszukiwanie." << std::endl;
    std::cout << std::endl;
    std::cout << "Wybór: ";
    unsigned short choice;
    std::cin >> choice;
    std::cin.ignore(256, '\n');
    system("cls");
    switch (choice) {
        case 1: {
            std::string tytul;
            std::cout << "Podaj tytu³ ksi¹¿ki do znalezienia: ";
            std::getline(std::cin, tytul);
            std::cout << "Wyniki wyszukiwania: " << std::endl;
            for (unsigned int i = 0; i < ksiazki.size(); i++) {
                wsk = &ksiazki.at(i);
                if (ksiazki.at(i).tytul.find(tytul) != std::string::npos) {
                    std::cout << std::endl;
                    wsk->wyswietl();
                    results++;
                }
                if (i + 1 == ksiazki.size()) ksiazek = ksiazki.at(i).zwrocLiczbeKsiazek();
            }
            break;
        }
        case 2: {
            std::string autor;
            std::cout << "Podaj autora, którego ksi¹¿ki chcesz wyszukaæ: ";
            std::getline(std::cin, autor);
            std::cout << "Wyniki wyszukiwania: " << std::endl;
            for (unsigned int i = 0; i < ksiazki.size(); i++) {
                if (ksiazki.at(i).autor.find(autor) != std::string::npos) {
                    wsk = &ksiazki.at(i);
                    std::cout << std::endl;
                    wsk->wyswietl();
                    results++;
                }
                if (i + 1 == ksiazki.size()) ksiazek = ksiazki.at(i).zwrocLiczbeKsiazek();
            }
            break;
        }
        case 3: {
            std::string wydawnictwo;
            std::cout << "Podaj wydawnictwo, od którego ksi¹¿ki chcesz wyszukaæ: ";
            std::getline(std::cin, wydawnictwo);
            std::cout << "Wyniki wyszukiwania: " << std::endl;
            for (unsigned int i = 0; i < ksiazki.size(); i++) {
                if (ksiazki.at(i).wydawnictwo.find(wydawnictwo) != std::string::npos) {
                    wsk = &ksiazki.at(i);
                    std::cout << std::endl;
                    wsk->wyswietl();
                    results++;
                }
                if (i + 1 == ksiazki.size()) ksiazek = ksiazki.at(i).zwrocLiczbeKsiazek();
            }
            break;
        }
        case 4: {
            std::string gatunek;
            std::cout << "Podaj gatunek ksi¹¿ek, których chcesz wyszukaæ: ";
            std::getline(std::cin, gatunek);
            std::cout << "Wyniki wyszukiwania: " << std::endl;
            for (unsigned int i = 0; i < ksiazki.size(); i++) {
                if (ksiazki.at(i).gatunek.find(gatunek) != std::string::npos) {
                    wsk = &ksiazki.at(i);
                    std::cout << std::endl;
                    wsk->wyswietl();
                    results++;
                }
                if (i + 1 == ksiazki.size()) ksiazek = ksiazki.at(i).zwrocLiczbeKsiazek();
            }
            break;
        }
        case 5: {
            std::cout << "W jaki sposób wyszukaæ po roku wydania?" << std::endl;
            std::cout << std::endl;
            std::cout << "1. Wyszukaj ksi¹¿ki wydane w podanym roku" << std::endl;
            std::cout << "2. Wyszukaj ksi¹¿ki wydane w podanym roku b¹dŸ wczeœniej" << std::endl;
            std::cout << "3. Wyszukaj ksi¹¿ki wydane w podanym roku b¹dŸ póŸniej" << std::endl;
            std::cout << "4. Wyszukaj ksi¹¿ki wydane w podanym przedziale lat" << std::endl;
            std::cout << std::endl;
            std::cout << "0. Anuluj" << std::endl;
            std::cout << std::endl;
            std::cout << "Wybór: ";
            unsigned short choice1;
            std::cin >> choice1;
            std::cin.ignore(256, '\n');
            system("cls");
            switch (choice1) {
                case 1: {
                    unsigned short rok_wydania;
                    std::cout << "Podaj rok wydania [wydane w]: ";
                    std::cin >> rok_wydania;
                    std::cin.ignore(256, '\n');
                    std::cout << "Wyniki wyszukiwania: " << std::endl;
                    for (unsigned int i = 0; i < ksiazki.size(); i++) {
                        if (ksiazki.at(i).rok_wydania == rok_wydania) {
                            wsk = &ksiazki.at(i);
                            std::cout << std::endl;
                            wsk->wyswietl();
                            results++;
                        }
                        if (i + 1 == ksiazki.size()) ksiazek = ksiazki.at(i).zwrocLiczbeKsiazek();
                    }
                    break;
                }
                case 2: {
                    unsigned short rok_wydania;
                    std::cout << "Podaj rok wydania [wydane przed i w]: ";
                    std::cin >> rok_wydania;
                    std::cin.ignore(256, '\n');
                    std::cout << "Wyniki wyszukiwania: " << std::endl;
                    for (unsigned int i = 0; i < ksiazki.size(); i++) {
                        if (ksiazki.at(i).rok_wydania <= rok_wydania) {
                            wsk = &ksiazki.at(i);
                            std::cout << std::endl;
                            wsk->wyswietl();
                            results++;
                        }
                        if (i + 1 == ksiazki.size()) ksiazek = ksiazki.at(i).zwrocLiczbeKsiazek();
                    }
                    break;
                }
                case 3: {
                    unsigned short rok_wydania;
                    std::cout << "Podaj rok wydania [wydane w i po]: ";
                    std::cin >> rok_wydania;
                    std::cin.ignore(256, '\n');
                    std::cout << "Wyniki wyszukiwania: " << std::endl;
                    for (unsigned int i = 0; i < ksiazki.size(); i++) {
                        if (ksiazki.at(i).rok_wydania >= rok_wydania) {
                            wsk = &ksiazki.at(i);
                            std::cout << std::endl;
                            wsk->wyswietl();
                            results++;
                        }
                        if (i + 1 == ksiazki.size()) ksiazek = ksiazki.at(i).zwrocLiczbeKsiazek();
                    }
                    break;
                }
                case 4: {
                    unsigned short rok_wydania1, rok_wydania2;
                    std::cout << "Podaj pocz¹tek przedzia³u (domkniêty): ";
                    std::cin >> rok_wydania1;
                    std::cin.ignore(256, '\n');
                    std::cout << "Podaj koniec przedzia³u (domkniêty): ";
                    std::cin >> rok_wydania2;
                    std::cin.ignore(256, '\n');
                    for (unsigned int i = 0; i < ksiazki.size(); i++) {
                        if (ksiazki.at(i).rok_wydania >= rok_wydania1 && ksiazki.at(i).rok_wydania <= rok_wydania2) {
                            wsk = &ksiazki.at(i);
                            std::cout << std::endl;
                            wsk->wyswietl();
                            results++;
                        }
                        if (i + 1 == ksiazki.size()) ksiazek = ksiazki.at(i).zwrocLiczbeKsiazek();
                    }
                    break;
                }
            }
            break;
        }
        case 6: {
            std::cout << "W jaki sposób wyszukaæ po iloœci stron?" << std::endl;
            std::cout << std::endl;
            std::cout << "1. Wyszukaj ksi¹¿ki maj¹ce tyle stron" << std::endl;
            std::cout << "2. Wyszukaj ksi¹¿ki maj¹ce tyle b¹dŸ mniej stron" << std::endl;
            std::cout << "3. Wyszukaj ksi¹¿ki maj¹ce tyle b¹dŸ wiêcej stron" << std::endl;
            std::cout << "4. Wyszukaj ksi¹¿ki maj¹ce iloœæ stron w podanym przedziale" << std::endl;
            std::cout << std::endl;
            std::cout << "0. Anuluj" << std::endl;
            std::cout << std::endl;
            std::cout << "Wybór: ";
            unsigned short choice1;
            std::cin >> choice1;
            std::cin.ignore(256, '\n');
            system("cls");
            switch (choice1) {
            case 1: {
                unsigned short strony;
                std::cout << "Podaj iloœæ stron [dok³adnie ile]: ";
                std::cin >> strony;
                std::cin.ignore(256, '\n');
                std::cout << "Wyniki wyszukiwania: " << std::endl;
                for (unsigned int i = 0; i < ksiazki.size(); i++) {
                    if (ksiazki.at(i).strony == strony) {
                        wsk = &ksiazki.at(i);
                        std::cout << std::endl;
                        wsk->wyswietl();
                        results++;
                    }
                    if (i + 1 == ksiazki.size()) ksiazek = ksiazki.at(i).zwrocLiczbeKsiazek();
                }
                break;
            }
            case 2: {
                unsigned short strony;
                std::cout << "Podaj iloœæ stron [tyle lub mniej]: ";
                std::cin >> strony;
                std::cin.ignore(256, '\n');
                std::cout << "Wyniki wyszukiwania: " << std::endl;
                for (unsigned int i = 0; i < ksiazki.size(); i++) {
                    if (ksiazki.at(i).strony <= strony) {
                        wsk = &ksiazki.at(i);
                        std::cout << std::endl;
                        wsk->wyswietl();
                        results++;
                    }
                    if (i + 1 == ksiazki.size()) ksiazek = ksiazki.at(i).zwrocLiczbeKsiazek();
                }
                break;
            }
            case 3: {
                unsigned short strony;
                std::cout << "Podaj iloœæ stron [tyle lub wiêcej]: ";
                std::cin >> strony;
                std::cin.ignore(256, '\n');
                std::cout << "Wyniki wyszukiwania: " << std::endl;
                for (unsigned int i = 0; i < ksiazki.size(); i++) {
                    if (ksiazki.at(i).strony >= strony) {
                        wsk = &ksiazki.at(i);
                        std::cout << std::endl;
                        wsk->wyswietl();
                        results++;
                    }
                    if (i + 1 == ksiazki.size()) ksiazek = ksiazki.at(i).zwrocLiczbeKsiazek();
                }
                break;
            }
            case 4: {
                unsigned short strony1, strony2;
                std::cout << "Podaj pocz¹tek przedzia³u (domkniêty): ";
                std::cin >> strony1;
                std::cin.ignore(256, '\n');
                std::cout << "Podaj koniec przedzia³u (domkniêty): ";
                std::cin >> strony2;
                std::cin.ignore(256, '\n');
                for (unsigned int i = 0; i < ksiazki.size(); i++) {
                    if (ksiazki.at(i).strony >= strony1 && ksiazki.at(i).strony <= strony2) {
                        wsk = &ksiazki.at(i);
                        std::cout << std::endl;
                        wsk->wyswietl();
                        results++;
                    }
                    if (i + 1 == ksiazki.size()) ksiazek = ksiazki.at(i).zwrocLiczbeKsiazek();
                }
                break;
            }
            }
            break;
        }
        case 7: {
            unsigned short min_wiek = 0;
            std::cout << "Podaj wiek, dla którego znaleŸæ odpowiednie ksi¹¿ki: " << std::endl;
            std::cin >> min_wiek;
            std::cin.ignore(256, '\n');
            for (unsigned int i = 0; i < ksiazki.size(); i++) {
                if (ksiazki.at(i).min_wiek <= min_wiek) {
                    wsk = &ksiazki.at(i);
                    std::cout << std::endl;
                    wsk->wyswietl();
                    results++;
                }
                if (i + 1 == ksiazki.size()) ksiazek = ksiazki.at(i).zwrocLiczbeKsiazek();
            }
            break;
        }
        case 8: {
            std::cout << "Wyszukaæ po jakich ocenach?" << std::endl;
            std::cout << std::endl;
            std::cout << "1. Wyszukaj ksi¹¿ki o dok³adnie takiej ocenie" << std::endl;
            std::cout << "2. Wyszukaj ksi¹¿ki o gorszej lub takiej ocenie" << std::endl;
            std::cout << "3. Wyszukaj ksi¹¿ki o lepszej lub takiej ocenie" << std::endl;
            std::cout << "4. Wyszukaj ksi¹¿ki w podanym przedziale ocen" << std::endl;
            std::cout << "5. Wyszukaj ksi¹¿ki jeszcze nie ocenione" << std::endl;
            std::cout << std::endl;
            std::cout << "0. Anuluj" << std::endl;
            std::cout << std::endl;
            std::cout << "Wybór: ";
            unsigned short choice1;
            std::cin >> choice1;
            std::cin.ignore(256, '\n');
            system("cls");
            switch (choice1) {
            case 1: {
                double ocena;
                std::cout << "Podaj ocenê [dok³adnie tak¹]: ";
                std::cin >> ocena;
                std::cin.ignore(256, '\n');
                std::cout << "Wyniki wyszukiwania: " << std::endl;
                for (unsigned int i = 0; i < ksiazki.size(); i++) {
                    if (ksiazki.at(i).ocena == ocena && ksiazki.at(i).ocena!=0) {
                        wsk = &ksiazki.at(i);
                        std::cout << std::endl;
                        wsk->wyswietl();
                        results++;
                    }
                    if (i + 1 == ksiazki.size()) ksiazek = ksiazki.at(i).zwrocLiczbeKsiazek();
                }
                break;
            }
            case 2: {
                double ocena;
                std::cout << "Podaj ocenê [gorsz¹ lub równ¹]: ";
                std::cin >> ocena;
                std::cin.ignore(256, '\n');
                std::cout << "Wyniki wyszukiwania: " << std::endl;               
                for (unsigned int i = 0; i < ksiazki.size(); i++) {
                    if (ksiazki.at(i).ocena <= ocena && ksiazki.at(i).ocena != 0) {
                        wsk = &ksiazki.at(i);
                        std::cout << std::endl;
                        wsk->wyswietl();
                        results++;
                    }
                    if (i + 1 == ksiazki.size()) ksiazek = ksiazki.at(i).zwrocLiczbeKsiazek();
                }
                break;
            }
            case 3: {
                double ocena;
                std::cout << "Podaj ocenê [lepsz¹ lub równ¹]: ";
                std::cin >> ocena;
                std::cin.ignore(256, '\n');
                std::cout << "Wyniki wyszukiwania: " << std::endl;
                for (unsigned int i = 0; i < ksiazki.size(); i++) {
                    if (ksiazki.at(i).ocena >= ocena && ksiazki.at(i).ocena != 0) {
                        wsk = &ksiazki.at(i);
                        std::cout << std::endl;
                        wsk->wyswietl();
                        results++;
                    }
                    if (i + 1 == ksiazki.size()) ksiazek = ksiazki.at(i).zwrocLiczbeKsiazek();
                }
                break;
            }
            case 4: {
                double ocena1, ocena2;
                std::cout << "Podaj pocz¹tek przedzia³u (domkniêty): ";
                std::cin >> ocena1;
                std::cin.ignore(256, '\n');
                std::cout << "Podaj koniec przedzia³u (domkniêty): ";
                std::cin >> ocena2;
                std::cin.ignore(256, '\n');
                for (unsigned int i = 0; i < ksiazki.size(); i++) {
                    if (ksiazki.at(i).ocena >= ocena1 && ksiazki.at(i).ocena <= ocena2 && ksiazki.at(i).ocena != 0) {
                        wsk = &ksiazki.at(i);
                        std::cout << std::endl;
                        wsk->wyswietl();
                        results++;
                    }
                    if (i + 1 == ksiazki.size()) ksiazek = ksiazki.at(i).zwrocLiczbeKsiazek();
                }
                break;
            }
            case 5: {
                for (unsigned int i = 0; i < ksiazki.size(); i++) {
                    if (ksiazki.at(i).ocena==0) {
                        wsk = &ksiazki.at(i);
                        std::cout << std::endl;
                        wsk->wyswietl();
                        results++;
                    }
                    if (i + 1 == ksiazki.size()) ksiazek = ksiazki.at(i).zwrocLiczbeKsiazek();
                }
                break;
            }
            }
            break;
        }
        break;
    }
    std::cout << "Koniec wyszukiwania - " << results << " wyników z " << ksiazek << std::endl;
    system("pause");
}

void szukajFilmu(std::vector<Film>& filmy) {
    Utwor* wsk;
    unsigned short results = 0;
    unsigned short filmow = 0;
    std::cout << "Opcje wyszukiwania: " << std::endl;
    std::cout << std::endl;
    std::cout << "1. Szukaj po tytule." << std::endl;
    std::cout << "2. Szukaj po re¿yserze." << std::endl;
    std::cout << "3. Szukaj po gatunku." << std::endl;
    std::cout << "4. Szukaj po roku wydania." << std::endl;
    std::cout << "5. Szukaj po czasie trwania." << std::endl;
    std::cout << "6. Szukaj po ograniczeniu wiekowym." << std::endl;
    std::cout << "7. Szukaj po ocenie." << std::endl;
    std::cout << std::endl;
    std::cout << "0. Anuluj wyszukiwanie." << std::endl;
    std::cout << std::endl;
    std::cout << "Wybór: ";
    unsigned short choice;
    std::cin >> choice;
    std::cin.ignore(256, '\n');
    system("cls");
    switch (choice) {
    case 1: {
        std::string tytul;
        std::cout << "Podaj tytu³ filmu do znalezienia: ";
        std::getline(std::cin, tytul);
        std::cout << "Wyniki wyszukiwania: " << std::endl;      
        for (unsigned int i = 0; i < filmy.size(); i++) {
            if (filmy.at(i).tytul.find(tytul) != std::string::npos) {
                wsk = &filmy.at(i);
                std::cout << std::endl;
                wsk->wyswietl();
                results++;
            }
            if (i + 1 == filmy.size())filmow = filmy.at(i).zwrocLiczbeFilmow();
        }
        break;
    }
    case 2: {
        std::string rezyser;
        std::cout << "Podaj re¿ysera, którego filmy chcesz wyszukaæ: ";
        std::getline(std::cin, rezyser);
        std::cout << "Wyniki wyszukiwania: " << std::endl;       
        for (unsigned int i = 0; i < filmy.size(); i++) {
            if (filmy.at(i).rezyser.find(rezyser) != std::string::npos) {
                wsk = &filmy.at(i);
                std::cout << std::endl;
                wsk->wyswietl();
                results++;
            }
            if (i + 1 == filmy.size())filmow = filmy.at(i).zwrocLiczbeFilmow();
        }
        break;
    }
    case 3: {
        std::string gatunek;
        std::cout << "Podaj gatunek filmów, których chcesz wyszukaæ: ";
        std::getline(std::cin, gatunek);
        std::cout << "Wyniki wyszukiwania: " << std::endl;       
        for (unsigned int i = 0; i < filmy.size(); i++) {
            if (filmy.at(i).gatunek.find(gatunek) != std::string::npos) {
                wsk = &filmy.at(i);
                std::cout << std::endl;
                wsk->wyswietl();
                results++;
            }
            if (i + 1 == filmy.size())filmow = filmy.at(i).zwrocLiczbeFilmow();
        }
        break;
    }
    case 4: {
        unsigned short rok_wydania;
        std::cout << "W jaki sposób wyszukaæ po roku wydania?" << std::endl;
        std::cout << std::endl;
        std::cout << "1. Wyszukaj filmy wydane w podanym roku" << std::endl;
        std::cout << "2. Wyszukaj filmy wydane w podanym roku b¹dŸ wczeœniej" << std::endl;
        std::cout << "3. Wyszukaj filmy wydane w podanym roku b¹dŸ póŸniej" << std::endl;
        std::cout << "4. Wyszukaj filmy wydane w podanym przedziale lat" << std::endl;
        std::cout << std::endl;
        std::cout << "0. Anuluj" << std::endl;
        std::cout << std::endl;
        std::cout << "Wybór: ";
        unsigned short choice1;
        std::cin >> choice1;
        std::cin.ignore(256, '\n');
        system("cls");
        switch (choice1) {
        case 1: { 
            std::cout << "Podaj rok wydania [wydane w]: ";
            std::cin >> rok_wydania;
            std::cin.ignore(256, '\n');
            std::cout << "Wyniki wyszukiwania: " << std::endl;           
            for (unsigned int i = 0; i < filmy.size(); i++) {
                if (filmy.at(i).rok_wydania == rok_wydania) {
                    wsk = &filmy.at(i);
                    std::cout << std::endl;
                    wsk->wyswietl();
                    results++;
                }
                if (i + 1 == filmy.size())filmow = filmy.at(i).zwrocLiczbeFilmow();
            }
            break;
        }
        case 2: {
            std::cout << "Podaj rok wydania [wydane przed i w]: ";
            std::cin >> rok_wydania;
            std::cin.ignore(256, '\n');
            std::cout << "Wyniki wyszukiwania: " << std::endl;           
            for (unsigned int i = 0; i < filmy.size(); i++) {
                if (filmy.at(i).rok_wydania <= rok_wydania) {
                    wsk = &filmy.at(i);
                    std::cout << std::endl;
                    wsk->wyswietl();
                    results++;
                }
                if (i + 1 == filmy.size())filmow = filmy.at(i).zwrocLiczbeFilmow();
            }
            break;
        }
        case 3: {
            std::cout << "Podaj rok wydania [wydane w i po]: ";
            std::cin >> rok_wydania;
            std::cin.ignore(256, '\n');
            std::cout << "Wyniki wyszukiwania: " << std::endl;            
            for (unsigned int i = 0; i < filmy.size(); i++) {
                if (filmy.at(i).rok_wydania >= rok_wydania) {
                    wsk = &filmy.at(i);
                    std::cout << std::endl;
                    wsk->wyswietl();
                    results++;
                }
                if (i + 1 == filmy.size())filmow = filmy.at(i).zwrocLiczbeFilmow();
            }
            break;
        }
        case 4: {
            unsigned short rok_wydania1;
            std::cout << "Podaj pocz¹tek przedzia³u (domkniêty): ";
            std::cin >> rok_wydania;
            std::cin.ignore(256, '\n');
            std::cout << "Podaj koniec przedzia³u (domkniêty): ";
            std::cin >> rok_wydania1;
            std::cin.ignore(256, '\n');            
            for (unsigned int i = 0; i < filmy.size(); i++) {
                if (filmy.at(i).rok_wydania >= rok_wydania && filmy.at(i).rok_wydania <= rok_wydania1) {
                    wsk = &filmy.at(i);
                    std::cout << std::endl;
                    wsk->wyswietl();
                    results++;
                }
                if (i + 1 == filmy.size())filmow = filmy.at(i).zwrocLiczbeFilmow();
            }
            break;
        }
        }
        break;
    }
    case 5: {
        unsigned short czas_trwania;
        std::cout << "W jaki sposób wyszukaæ po czasie trwania?" << std::endl;
        std::cout << std::endl;
        std::cout << "1. Wyszukaj filmy trwaj¹ce tyle" << std::endl;
        std::cout << "2. Wyszukaj filmy trwaj¹ce tyle b¹dŸ krócej" << std::endl;
        std::cout << "3. Wyszukaj filmy trwaj¹ce tyle b¹dŸ d³u¿ej" << std::endl;
        std::cout << "4. Wyszukaj filmy, których czas trwania jest w podanym przedziale" << std::endl;
        std::cout << std::endl;
        std::cout << "0. Anuluj" << std::endl;
        std::cout << std::endl;
        std::cout << "Wybór: ";
        unsigned short choice1;
        std::cin >> choice1;
        std::cin.ignore(256, '\n');
        system("cls");
        switch (choice1) {
        case 1: {
            std::cout << "Podaj czas trwania w minutach [dok³adnie ile]: ";
            std::cin >> czas_trwania;
            std::cin.ignore(256, '\n');
            std::cout << "Wyniki wyszukiwania: " << std::endl;          
            for (unsigned int i = 0; i < filmy.size(); i++) {
                if (filmy.at(i).czas_trwania == czas_trwania) {
                    wsk = &filmy.at(i);
                    std::cout << std::endl;
                    wsk->wyswietl();
                    results++;
                }
                if (i + 1 == filmy.size())filmow = filmy.at(i).zwrocLiczbeFilmow();
            }
            break;
        }
        case 2: {
            std::cout << "Podaj czas trwania w minutach [tyle lub mniej]: ";
            std::cin >> czas_trwania;
            std::cin.ignore(256, '\n');
            std::cout << "Wyniki wyszukiwania: " << std::endl;            
            for (unsigned int i = 0; i < filmy.size(); i++) {
                if (filmy.at(i).czas_trwania <= czas_trwania) {
                    wsk = &filmy.at(i);
                    std::cout << std::endl;
                    wsk->wyswietl();
                    results++;
                }
                if (i + 1 == filmy.size())filmow = filmy.at(i).zwrocLiczbeFilmow();
            }
            break;
        }
        case 3: {
            std::cout << "Podaj czas trwania w minutach [tyle lub wiêcej]: ";
            std::cin >> czas_trwania;
            std::cin.ignore(256, '\n');
            std::cout << "Wyniki wyszukiwania: " << std::endl;
            for (unsigned int i = 0; i < filmy.size(); i++) {
                if (filmy.at(i).czas_trwania >= czas_trwania) {
                    wsk = &filmy.at(i);
                    std::cout << std::endl;
                    wsk->wyswietl();
                    results++;
                }
                if (i + 1 == filmy.size())filmow = filmy.at(i).zwrocLiczbeFilmow();
            }
            break;
        }
        case 4: {
            unsigned short czas_trwania1;
            std::cout << "Podaj pocz¹tek przedzia³u (domkniêty): ";
            std::cin >> czas_trwania;
            std::cin.ignore(256, '\n');
            std::cout << "Podaj koniec przedzia³u (domkniêty): ";
            std::cin >> czas_trwania1;
            std::cin.ignore(256, '\n');           
            for (unsigned int i = 0; i < filmy.size(); i++) {
                if (filmy.at(i).czas_trwania >= czas_trwania && filmy.at(i).czas_trwania <= czas_trwania1) {
                    wsk = &filmy.at(i);
                    std::cout << std::endl;
                    wsk->wyswietl();
                    results++;
                }
                if (i + 1 == filmy.size())filmow = filmy.at(i).zwrocLiczbeFilmow();
            }
            break;
        }
        }
        break;
    }
    case 6: {
        unsigned short min_wiek;
        std::cout << "Podaj wiek, dla którego znaleŸæ odpowiednie filmy: " << std::endl;
        std::cin >> min_wiek;
        std::cin.ignore(256, '\n');        
        for (unsigned int i = 0; i < filmy.size(); i++) {
            if (filmy.at(i).min_wiek <= min_wiek) {
                wsk = &filmy.at(i);
                std::cout << std::endl;
                wsk->wyswietl();
                results++;
            }
            if (i + 1 == filmy.size())filmow = filmy.at(i).zwrocLiczbeFilmow();
        }
        break;
    }
    case 7: {
        double ocena;
        std::cout << "Wyszukaæ po jakich ocenach?" << std::endl;
        std::cout << std::endl;
        std::cout << "1. Wyszukaj filmy o dok³adnie takiej ocenie" << std::endl;
        std::cout << "2. Wyszukaj filmy o gorszej lub takiej ocenie" << std::endl;
        std::cout << "3. Wyszukaj filmy o lepszej lub takiej ocenie" << std::endl;
        std::cout << "4. Wyszukaj filmy w podanym przedziale ocen" << std::endl;
        std::cout << "5. Wyszukaj filmy jeszcze nie ocenione" << std::endl;
        std::cout << std::endl;
        std::cout << "0. Anuluj" << std::endl;
        std::cout << std::endl;
        std::cout << "Wybór: ";
        unsigned short choice1;
        std::cin >> choice1;
        std::cin.ignore(256, '\n');
        system("cls");
        switch (choice1) {
        case 1: {
            std::cout << "Podaj ocenê [dok³adnie tak¹]: ";
            std::cin >> ocena;
            std::cin.ignore(256, '\n');
            std::cout << "Wyniki wyszukiwania: " << std::endl;           
            for (unsigned int i = 0; i < filmy.size(); i++) {
                if (filmy.at(i).ocena == ocena && filmy.at(i).ocena != 0) {
                    wsk = &filmy.at(i);
                    std::cout << std::endl;
                    wsk->wyswietl();
                    results++;
                }
                if (i + 1 == filmy.size())filmow = filmy.at(i).zwrocLiczbeFilmow();
            }
            break;
        }
        case 2: {
            std::cout << "Podaj ocenê [gorsz¹ lub równ¹]: ";
            std::cin >> ocena;
            std::cin.ignore(256, '\n');
            std::cout << "Wyniki wyszukiwania: " << std::endl;           
            for (unsigned int i = 0; i < filmy.size(); i++) {
                if (filmy.at(i).ocena <= ocena && filmy.at(i).ocena != 0) {
                    wsk = &filmy.at(i);
                    std::cout << std::endl;
                    wsk->wyswietl();
                    results++;
                }
                if (i + 1 == filmy.size())filmow = filmy.at(i).zwrocLiczbeFilmow();
            }
            break;
        }
        case 3: {
            std::cout << "Podaj ocenê [lepsz¹ lub równ¹]: ";
            std::cin >> ocena;
            std::cin.ignore(256, '\n');
            std::cout << "Wyniki wyszukiwania: " << std::endl;
            for (unsigned int i = 0; i < filmy.size(); i++) {
                if (filmy.at(i).ocena >= ocena && filmy.at(i).ocena != 0) {
                    wsk = &filmy.at(i);
                    std::cout << std::endl;
                    wsk->wyswietl();
                    results++;
                }
                if (i + 1 == filmy.size())filmow = filmy.at(i).zwrocLiczbeFilmow();
            }
            break;
        }
        case 4: {
            double ocena1;
            std::cout << "Podaj pocz¹tek przedzia³u (domkniêty): ";
            std::cin >> ocena;
            std::cin.ignore(256, '\n');
            std::cout << "Podaj koniec przedzia³u (domkniêty): ";
            std::cin >> ocena1;
            std::cin.ignore(256, '\n');
            for (unsigned int i = 0; i < filmy.size(); i++) {
                if (filmy.at(i).ocena >= ocena && filmy.at(i).ocena <= ocena1 && filmy.at(i).ocena != 0) {
                    wsk = &filmy.at(i);
                    std::cout << std::endl;
                    wsk->wyswietl();
                    results++;
                }
                if (i + 1 == filmy.size())filmow = filmy.at(i).zwrocLiczbeFilmow();
            }
            break;
        }
        case 5: {
            for (unsigned int i = 0; i < filmy.size(); i++) {
                if (filmy.at(i).ocena == 0) {
                    wsk = &filmy.at(i);
                    std::cout << std::endl;
                    wsk->wyswietl();
                    results++;
                }
                if (i + 1 == filmy.size())filmow = filmy.at(i).zwrocLiczbeFilmow();
            }
            break;
        }
        }
        break;
    }
    }
    std::cout << "Koniec wyszukiwania - " << results << " wyników z " << filmow << std::endl;
    system("pause");
}

void szukajAlbumuMuzycznego(std::vector<Album_muzyczny>& muzyka) {
    Utwor* wsk;
    unsigned short results = 0;
    unsigned short albumow = 0;
    std::cout << "Opcje wyszukiwania: " << std::endl;
    std::cout << std::endl;
    std::cout << "1. Szukaj po tytule." << std::endl;
    std::cout << "2. Szukaj po autorze." << std::endl;
    std::cout << "3. Szukaj po gatunku." << std::endl;
    std::cout << "4. Szukaj po roku wydania." << std::endl;
    std::cout << "5. Szukaj po czasie trwania." << std::endl;
    std::cout << "6. Szukaj po iloœci utworów." << std::endl;
    std::cout << "7. Szukaj po ograniczeniu wiekowym." << std::endl;
    std::cout << "8. Szukaj po ocenie." << std::endl;
    std::cout << std::endl;
    std::cout << "0. Anuluj wyszukiwanie." << std::endl;
    std::cout << std::endl;
    std::cout << "Wybór: ";
    unsigned short choice;
    std::cin >> choice;
    std::cin.ignore(256, '\n');
    system("cls");
    switch (choice) {
    case 1: {
        std::string tytul;
        std::cout << "Podaj tytu³ albumu muzycznego do znalezienia: ";
        std::getline(std::cin, tytul);
        std::cout << "Wyniki wyszukiwania: " << std::endl;
        for (unsigned int i = 0; i < muzyka.size(); i++) {
            if (muzyka.at(i).tytul.find(tytul) != std::string::npos) {
                wsk = &muzyka.at(i);
                std::cout << std::endl;
                wsk->wyswietl();
                results++;
            }
            if (i + 1 == muzyka.size())albumow = muzyka.at(i).zwrocLiczbeAlbumow();
        }
        break;
    }
    case 2: {
        std::string autor;
        std::cout << "Podaj autora, którego album muzyczny chcesz wyszukaæ: ";
        std::getline(std::cin, autor);
        std::cout << "Wyniki wyszukiwania: " << std::endl;
        for (unsigned int i = 0; i < muzyka.size(); i++) {
            if (muzyka.at(i).autor.find(autor) != std::string::npos) {
                wsk = &muzyka.at(i);
                std::cout << std::endl;
                wsk->wyswietl();
                results++;
            }
            if (i + 1 == muzyka.size())albumow = muzyka.at(i).zwrocLiczbeAlbumow();
        }
        break;
    }
    case 3: {
        std::string gatunek;
        std::cout << "Podaj gatunek muzyczny, którego chcesz wyszukaæ: ";
        std::getline(std::cin, gatunek);
        std::cout << "Wyniki wyszukiwania: " << std::endl;
        for (unsigned int i = 0; i < muzyka.size(); i++) {
            if (muzyka.at(i).gatunek.find(gatunek) != std::string::npos) {
                wsk = &muzyka.at(i);
                std::cout << std::endl;
                wsk->wyswietl();
                results++;
            }
            if (i + 1 == muzyka.size())albumow = muzyka.at(i).zwrocLiczbeAlbumow();
        }
        break;
    }
    case 4: {
        unsigned short rok_wydania;
        std::cout << "W jaki sposób wyszukaæ po roku wydania?" << std::endl;
        std::cout << std::endl;
        std::cout << "1. Wyszukaj albumy wydane w podanym roku" << std::endl;
        std::cout << "2. Wyszukaj albumy wydane w podanym roku b¹dŸ wczeœniej" << std::endl;
        std::cout << "3. Wyszukaj albumy wydane w podanym roku b¹dŸ póŸniej" << std::endl;
        std::cout << "4. Wyszukaj albumy wydane w podanym przedziale lat" << std::endl;
        std::cout << std::endl;
        std::cout << "0. Anuluj" << std::endl;
        std::cout << std::endl;
        std::cout << "Wybór: ";
        unsigned short choice1;
        std::cin >> choice1;
        std::cin.ignore(256, '\n');
        system("cls");
        switch (choice1) {
        case 1: {
            std::cout << "Podaj rok wydania [wydane w]: ";
            std::cin >> rok_wydania;
            std::cin.ignore(256, '\n');
            std::cout << "Wyniki wyszukiwania: " << std::endl;
            for (unsigned int i = 0; i < muzyka.size(); i++) {
                if (muzyka.at(i).rok_wydania == rok_wydania) {
                    wsk = &muzyka.at(i);
                    std::cout << std::endl;
                    wsk->wyswietl();
                    results++;
                }
                if (i + 1 == muzyka.size())albumow = muzyka.at(i).zwrocLiczbeAlbumow();
            }
            break;
        }
        case 2: {
            std::cout << "Podaj rok wydania [wydane przed i w]: ";
            std::cin >> rok_wydania;
            std::cin.ignore(256, '\n');
            std::cout << "Wyniki wyszukiwania: " << std::endl;
            for (unsigned int i = 0; i < muzyka.size(); i++) {
                if (muzyka.at(i).rok_wydania <= rok_wydania) {
                    wsk = &muzyka.at(i);
                    std::cout << std::endl;
                    wsk->wyswietl();
                    results++;
                }
                if (i + 1 == muzyka.size())albumow = muzyka.at(i).zwrocLiczbeAlbumow();
            }
            break;
        }
        case 3: {
            std::cout << "Podaj rok wydania [wydane w i po]: ";
            std::cin >> rok_wydania;
            std::cin.ignore(256, '\n');
            std::cout << "Wyniki wyszukiwania: " << std::endl;
            for (unsigned int i = 0; i < muzyka.size(); i++) {
                if (muzyka.at(i).rok_wydania >= rok_wydania) {
                    wsk = &muzyka.at(i);
                    std::cout << std::endl;
                    wsk->wyswietl();
                    results++;
                }
                if (i + 1 == muzyka.size())albumow = muzyka.at(i).zwrocLiczbeAlbumow();
            }
            break;
        }
        case 4: {
            unsigned short rok_wydania1;
            std::cout << "Podaj pocz¹tek przedzia³u (domkniêty): ";
            std::cin >> rok_wydania;
            std::cin.ignore(256, '\n');
            std::cout << "Podaj koniec przedzia³u (domkniêty): ";
            std::cin >> rok_wydania1;
            std::cin.ignore(256, '\n');
            for (unsigned int i = 0; i < muzyka.size(); i++) {
                if (muzyka.at(i).rok_wydania >= rok_wydania && muzyka.at(i).rok_wydania <= rok_wydania1) {
                    wsk = &muzyka.at(i);
                    std::cout << std::endl;
                    wsk->wyswietl();
                    results++;
                }
                if (i + 1 == muzyka.size())albumow = muzyka.at(i).zwrocLiczbeAlbumow();
            }
            break;
        }
        }
        break;
    }
    case 5: {
        unsigned short czas_trwania;
        std::cout << "W jaki sposób wyszukaæ po czasie trwania?" << std::endl;
        std::cout << std::endl;
        std::cout << "1. Wyszukaj albumy trwaj¹ce dok³adnie tyle" << std::endl;
        std::cout << "2. Wyszukaj albumy trwaj¹ce tyle b¹dŸ krócej" << std::endl;
        std::cout << "3. Wyszukaj albumy trwaj¹ce tyle b¹dŸ d³u¿ej" << std::endl;
        std::cout << "4. Wyszukaj albumy, których czas trwania jest w podanym przedziale" << std::endl;
        std::cout << std::endl;
        std::cout << "0. Anuluj" << std::endl;
        std::cout << std::endl;
        std::cout << "Wybór: ";
        unsigned short choice1;
        std::cin >> choice1;
        std::cin.ignore(256, '\n');
        system("cls");
        switch (choice1) {
        case 1: {
            std::cout << "Podaj czas trwania w minutach [dok³adnie ile]: ";
            std::cin >> czas_trwania;
            std::cin.ignore(256, '\n');
            std::cout << "Wyniki wyszukiwania: " << std::endl;
            for (unsigned int i = 0; i < muzyka.size(); i++) {
                if (muzyka.at(i).czas_trwania == czas_trwania) {
                    wsk = &muzyka.at(i);
                    std::cout << std::endl;
                    wsk->wyswietl();
                    results++;
                }
                if (i + 1 == muzyka.size())albumow = muzyka.at(i).zwrocLiczbeAlbumow();
            }
            break;
        }
        case 2: {
            std::cout << "Podaj czas trwania w minutach [tyle lub mniej]: ";
            std::cin >> czas_trwania;
            std::cin.ignore(256, '\n');
            std::cout << "Wyniki wyszukiwania: " << std::endl;
            for (unsigned int i = 0; i < muzyka.size(); i++) {
                if (muzyka.at(i).czas_trwania <= czas_trwania) {
                    wsk = &muzyka.at(i);
                    std::cout << std::endl;
                    wsk->wyswietl();
                    results++;
                }
                if (i + 1 == muzyka.size())albumow = muzyka.at(i).zwrocLiczbeAlbumow();
            }
            break;
        }
        case 3: {
            std::cout << "Podaj czas trwania w minutach [tyle lub wiêcej]: ";
            std::cin >> czas_trwania;
            std::cin.ignore(256, '\n');
            std::cout << "Wyniki wyszukiwania: " << std::endl;
            for (unsigned int i = 0; i < muzyka.size(); i++) {
                if (muzyka.at(i).czas_trwania >= czas_trwania) {
                    wsk = &muzyka.at(i);
                    std::cout << std::endl;
                    wsk->wyswietl();
                    results++;
                }
                if (i + 1 == muzyka.size())albumow = muzyka.at(i).zwrocLiczbeAlbumow();
            }
            break;
        }
        case 4: {
            unsigned short czas_trwania1;
            std::cout << "Podaj pocz¹tek przedzia³u (domkniêty): ";
            std::cin >> czas_trwania;
            std::cin.ignore(256, '\n');
            std::cout << "Podaj koniec przedzia³u (domkniêty): ";
            std::cin >> czas_trwania1;
            std::cin.ignore(256, '\n');
            for (unsigned int i = 0; i < muzyka.size(); i++) {
                if (muzyka.at(i).czas_trwania >= czas_trwania && muzyka.at(i).czas_trwania <= czas_trwania1) {
                    wsk = &muzyka.at(i);
                    std::cout << std::endl;
                    wsk->wyswietl();
                    results++;
                }
                if (i + 1 == muzyka.size())albumow = muzyka.at(i).zwrocLiczbeAlbumow();
            }
            break;
        }
        }
        break;
    }
    case 6: {
        unsigned short utworow;
        std::cout << "W jaki sposób wyszukaæ po iloœci utworów?" << std::endl;
        std::cout << std::endl;
        std::cout << "1. Wyszukaj albumy, które maj¹ dok³adnie tyle utworów" << std::endl;
        std::cout << "2. Wyszukaj albumy, które maj¹ tyle b¹dŸ mniej utworów" << std::endl;
        std::cout << "3. Wyszukaj albumy, które maj¹ tyle badŸ wiêcej utworów" << std::endl;
        std::cout << "4. Wyszukaj albumy, których iloœæ utworów jest w podanym przedziale" << std::endl;
        std::cout << std::endl;
        std::cout << "0. Anuluj" << std::endl;
        std::cout << std::endl;
        std::cout << "Wybór: ";
        unsigned short choice1;
        std::cin >> choice1;
        std::cin.ignore(256, '\n');
        system("cls");
        switch (choice1) {
        case 1: {           
            std::cout << "Podaj iloœæ utworów [dok³adnie ile]: ";
            std::cin >> utworow;
            std::cin.ignore(256, '\n');
            std::cout << "Wyniki wyszukiwania: " << std::endl;
            for (unsigned int i = 0; i < muzyka.size(); i++) {
                if (muzyka.at(i).utworow == utworow) {
                    wsk = &muzyka.at(i);
                    std::cout << std::endl;
                    wsk->wyswietl();
                    results++;
                }
                if (i + 1 == muzyka.size())albumow = muzyka.at(i).zwrocLiczbeAlbumow();
            }
            break;
        }
        case 2: {
            std::cout << "Podaj iloœæ utworów [tyle lub mniej]: ";
            std::cin >> utworow;
            std::cin.ignore(256, '\n');
            std::cout << "Wyniki wyszukiwania: " << std::endl;
            for (unsigned int i = 0; i < muzyka.size(); i++) {
                if (muzyka.at(i).utworow <= utworow) {
                    wsk = &muzyka.at(i);
                    std::cout << std::endl;
                    wsk->wyswietl();
                    results++;
                }
                if (i + 1 == muzyka.size())albumow = muzyka.at(i).zwrocLiczbeAlbumow();
            }
            break;
        }
        case 3: {
            std::cout << "Podaj iloœæ utworów [tyle lub wiêcej]: ";
            std::cin >> utworow;
            std::cin.ignore(256, '\n');
            std::cout << "Wyniki wyszukiwania: " << std::endl;
            for (unsigned int i = 0; i < muzyka.size(); i++) {
                if (muzyka.at(i).utworow >= utworow) {
                    wsk = &muzyka.at(i);
                    std::cout << std::endl;
                    wsk->wyswietl();
                    results++;
                }
                if (i + 1 == muzyka.size())albumow = muzyka.at(i).zwrocLiczbeAlbumow();
            }
            break;
        }
        case 4: {
            unsigned short utworow1;
            std::cout << "Podaj pocz¹tek przedzia³u (domkniêty): ";
            std::cin >> utworow;
            std::cin.ignore(256, '\n');
            std::cout << "Podaj koniec przedzia³u (domkniêty): ";
            std::cin >> utworow1;
            std::cin.ignore(256, '\n');
            for (unsigned int i = 0; i < muzyka.size(); i++) {
                if (muzyka.at(i).utworow >= utworow && muzyka.at(i).utworow <= utworow1) {
                    wsk = &muzyka.at(i);
                    std::cout << std::endl;
                    wsk->wyswietl();
                    results++;
                }
                if (i + 1 == muzyka.size())albumow = muzyka.at(i).zwrocLiczbeAlbumow();
            }
            break;
        }
        }
        break;
    }
    case 7: {
        unsigned short min_wiek;
        std::cout << "Podaj wiek, dla którego znaleŸæ odpowiednie albumy muzyczne: " << std::endl;
        std::cin >> min_wiek;
        std::cin.ignore(256, '\n');
        for (unsigned int i = 0; i < muzyka.size(); i++) {
            if (muzyka.at(i).min_wiek <= min_wiek) {
                wsk = &muzyka.at(i);
                std::cout << std::endl;
                wsk->wyswietl();
                results++;
            }
            if (i + 1 == muzyka.size())albumow = muzyka.at(i).zwrocLiczbeAlbumow();
        }
        break;
    }
    case 8: {
        double ocena;
        std::cout << "Wyszukaæ po jakich ocenach?" << std::endl;
        std::cout << std::endl;
        std::cout << "1. Wyszukaj albumy o dok³adnie takiej ocenie" << std::endl;
        std::cout << "2. Wyszukaj albumy o gorszej lub takiej samej ocenie" << std::endl;
        std::cout << "3. Wyszukaj albumy o lepszej lub takiej samej ocenie" << std::endl;
        std::cout << "4. Wyszukaj albumy w podanym przedziale ocen" << std::endl;
        std::cout << "5. Wyszukaj albumy jeszcze nie ocenione" << std::endl;
        std::cout << std::endl;
        std::cout << "0. Anuluj" << std::endl;
        std::cout << std::endl;
        std::cout << "Wybór: ";
        unsigned short choice1;
        std::cin >> choice1;
        std::cin.ignore(256, '\n');
        system("cls");
        switch (choice1) {
        case 1: {
            std::cout << "Podaj ocenê [dok³adnie tak¹]: ";
            std::cin >> ocena;
            std::cin.ignore(256, '\n');
            std::cout << "Wyniki wyszukiwania: " << std::endl;
            for (unsigned int i = 0; i < muzyka.size(); i++) {
                if (muzyka.at(i).ocena == ocena && muzyka.at(i).ocena != 0) {
                    wsk = &muzyka.at(i);
                    std::cout << std::endl;
                    wsk->wyswietl();
                    results++;
                }
                if (i + 1 == muzyka.size())albumow = muzyka.at(i).zwrocLiczbeAlbumow();
            }
            break;
        }
        case 2: {
            std::cout << "Podaj ocenê [gorsz¹ lub równ¹]: ";
            std::cin >> ocena;
            std::cin.ignore(256, '\n');
            std::cout << "Wyniki wyszukiwania: " << std::endl;
            for (unsigned int i = 0; i < muzyka.size(); i++) {
                if (muzyka.at(i).ocena <= ocena && muzyka.at(i).ocena != 0) {
                    wsk = &muzyka.at(i);
                    std::cout << std::endl;
                    wsk->wyswietl();
                    results++;
                }
                if (i + 1 == muzyka.size())albumow = muzyka.at(i).zwrocLiczbeAlbumow();
            }
            break;
        }
        case 3: {
            std::cout << "Podaj ocenê [lepsz¹ lub równ¹]: ";
            std::cin >> ocena;
            std::cin.ignore(256, '\n');
            std::cout << "Wyniki wyszukiwania: " << std::endl;
            for (unsigned int i = 0; i < muzyka.size(); i++) {
                if (muzyka.at(i).ocena >= ocena && muzyka.at(i).ocena != 0) {
                    wsk = &muzyka.at(i);
                    std::cout << std::endl;
                    wsk->wyswietl();
                    results++;
                }
                if (i + 1 == muzyka.size())albumow = muzyka.at(i).zwrocLiczbeAlbumow();
            }
            break;
        }
        case 4: {
            double ocena1;
            std::cout << "Podaj pocz¹tek przedzia³u (domkniêty): ";
            std::cin >> ocena;
            std::cin.ignore(256, '\n');
            std::cout << "Podaj koniec przedzia³u (domkniêty): ";
            std::cin >> ocena1;
            std::cin.ignore(256, '\n');
            for (unsigned int i = 0; i < muzyka.size(); i++) {
                if (muzyka.at(i).ocena >= ocena && muzyka.at(i).ocena <= ocena1 && muzyka.at(i).ocena != 0) {
                    wsk = &muzyka.at(i);
                    std::cout << std::endl;
                    wsk->wyswietl();
                    results++;
                }
                if (i + 1 == muzyka.size())albumow = muzyka.at(i).zwrocLiczbeAlbumow();
            }
            break;
        }
        case 5: {           
            for (unsigned int i = 0; i < muzyka.size(); i++) {
                if (muzyka.at(i).ocena == 0) {
                    wsk = &muzyka.at(i);
                    std::cout << std::endl;
                    wsk->wyswietl();
                    results++;
                }
                if (i + 1 == muzyka.size())albumow = muzyka.at(i).zwrocLiczbeAlbumow();
            }
            break;
        }
        }
        break;
    }
    }
    std::cout << "Koniec wyszukiwania - " << results << " wyników z " << albumow << std::endl;
    system("pause");
}

// Ksiazka n(x.tytul, x.rok_wydania, x.ocena, x.min_wiek, x.ulubione, x.strony, x.autor, x.wydawnictwo, x.gatunek) <- uk³ad obiektu typu ksi¹zka
void zapiszKsiazki(const std::vector<Ksiazka>& db, const std::string name) {
    std::fstream plik;
    const std::string filename = name + "_k.csv";
    plik.open(filename, std::ios::out);
    plik << "\"Tytu³\",\"Rok wydania\",\"Ocena\",\"Min. ograniczenie wiekowe\",\"Ulubione\",\"Iloœæ stron\",\"Autor\",\"Wydawnictwo\",\"Gatunek\"" << std::endl;
    for (unsigned int i = 0; i < db.size(); i++) {
        if (db.at(i).tytul != "\0") plik << db.at(i).tytul;
        plik << ',';
        if (db.at(i).rok_wydania != NULL) plik << db.at(i).rok_wydania;
        plik << ',';
        if (db.at(i).ocena != NULL) plik << db.at(i).ocena;
        plik << ',';
        if (db.at(i).min_wiek != NULL)plik << db.at(i).min_wiek;
        plik << ',';
        if (db.at(i).ulubione != NULL)plik << db.at(i).ulubione;
        plik << ',';
        if (db.at(i).strony != NULL)plik << db.at(i).strony;
        plik << ',';
        if (db.at(i).autor != "\0")plik << db.at(i).autor;
        plik << ',';
        if (db.at(i).wydawnictwo != "\0")plik << db.at(i).wydawnictwo;
        plik << ',';
        if (db.at(i).gatunek != "\0")plik << db.at(i).gatunek;
        plik << ',';
    }
    plik.close();
    std::cout << "Zapisano bazê danych do pliku " << filename << std::endl;
}

//Film n(x.tytul, x.rok_wydania, x.ocena, x.min_wiek, x.ulubione, x.czas_trwania, x.rezyser, x.gatunek); <- uk³ad obiektu typu film
void zapiszFilmy(const std::vector<Film>& db, const std::string name) {
    std::fstream plik;
    const std::string filename = name + "_f.csv";
    plik.open(filename, std::ios::out);
    plik << "\"Tytu³\",\"Rok wydania\",\"Ocena\",\"Min. ograniczenie wiekowe\",\"Ulubione\",\"Czas trwania [m]\",\"Re¿yser\",\"Gatunek\"" << std::endl;
    for (unsigned int i = 0; i < db.size(); i++) {
        if (db.at(i).tytul != "\0") plik << db.at(i).tytul;
        plik << ',';
        if (db.at(i).rok_wydania != NULL) plik << db.at(i).rok_wydania;
        plik << ',';
        if (db.at(i).ocena != NULL) plik << db.at(i).ocena;
        plik << ',';
        if (db.at(i).min_wiek != NULL)plik << db.at(i).min_wiek;
        plik << ',';
        if (db.at(i).ulubione != NULL)plik << db.at(i).ulubione;
        plik << ',';
        if (db.at(i).czas_trwania != NULL)plik << db.at(i).czas_trwania;
        plik << ',';
        if (db.at(i).rezyser != "\0")plik << db.at(i).rezyser;
        plik << ',';
        if (db.at(i).gatunek != "\0")plik << db.at(i).gatunek;
        plik << ',';
    }
    plik.close();
    std::cout << "Zapisano bazê danych do pliku " << filename << std::endl;
}

//Album_muzyczny n(x.tytul, x.rok_wydania, x.ocena, x.min_wiek, x.ulubione, x.czas_trwania, x.utworow, x.autor, x.gatunek); <- uk³ad obiektu typu album_muzyczny
void zapiszMuzyke(const std::vector<Album_muzyczny>& db, const std::string name) {
    std::fstream plik;
    const std::string filename = name + "_m.csv";
    plik.open(filename, std::ios::out);
    plik << "\"Tytu³\",\"Rok wydania\",\"Ocena\",\"Min. ograniczenie wiekowe\",\"Ulubione\",\"Czas trwania [m]\",\"Liczba utworów\",\"Autor\",\"Gatunek\"" << std::endl;
    for (unsigned int i = 0; i < db.size(); i++) {
        if (db.at(i).tytul != "\0") plik << db.at(i).tytul;
        plik << ',';
        if (db.at(i).rok_wydania != NULL) plik << db.at(i).rok_wydania;
        plik << ',';
        if (db.at(i).ocena != NULL) plik << db.at(i).ocena;
        plik << ',';
        if (db.at(i).min_wiek != NULL)plik << db.at(i).min_wiek;
        plik << ',';
        if (db.at(i).ulubione != NULL)plik << db.at(i).ulubione;
        plik << ',';
        if (db.at(i).czas_trwania != NULL)plik << db.at(i).czas_trwania;
        plik << ',';
        if (db.at(i).utworow != NULL)plik << db.at(i).utworow;
        plik << ',';
        if (db.at(i).autor != "\0")plik << db.at(i).autor;
        plik << ',';
        if (db.at(i).gatunek != "\0")plik << db.at(i).gatunek;
        plik << ',';
    }
    plik.close();
    std::cout << "Zapisano bazê danych do pliku " << filename << std::endl;
}

// Ksiazka n(x.tytul, x.rok_wydania, x.ocena, x.min_wiek, x.ulubione, x.strony, x.autor, x.wydawnictwo, x.gatunek) <- uk³ad obiektu typu ksi¹zka
void wczytajKsiazki(std::vector<Ksiazka>& db, const std::string name) {

    std::string tytul="\0";
    unsigned short rok_wydania = 0;
    double ocena = 0;
    unsigned short min_wiek = 0;
    bool ulubione = false;
    unsigned short strony = 0;
    std::string autor;
    std::string wydawnictwo;
    std::string gatunek;

    unsigned int linecount = 1;
    std::fstream plik;
    std::string wartosc, rekord;
    std::vector<std::string> przedmiot;
    std::string filename = name + "_k.csv";
    plik.open(filename, std::ios::in);
    while (getline(plik, wartosc)) {
        std::stringstream liniaStream(wartosc);
        while (getline(liniaStream, rekord, ',')) {
            przedmiot.push_back(rekord);
        }
        tytul = przedmiot.at(0);
        rok_wydania = atoi(przedmiot.at(1).c_str());
        ocena = atof(przedmiot.at(2).c_str());
        min_wiek = atoi(przedmiot.at(3).c_str());
        ulubione = atoi(przedmiot.at(4).c_str());
        strony = atoi(przedmiot.at(5).c_str());
        autor = przedmiot.at(6);
        wydawnictwo = przedmiot.at(7);
        gatunek = przedmiot.at(8);

        if (linecount != 1) {
            Ksiazka n(tytul, rok_wydania, ocena, min_wiek, ulubione, strony, autor, wydawnictwo, gatunek);
            db.push_back(n);
        }
        przedmiot.clear();
        linecount++;
    }
    plik.close();
    std::cout << "Wczytano folder z ksi¹zkami z pliku " << filename << std::endl;
}

// Film n(x.tytul, x.rok_wydania, x.ocena, x.min_wiek, x.ulubione, x.czas_trwania, x.rezyser, x.gatunek) <- uk³ad obiektu typu film
void wczytajFilmy(std::vector<Film>& db, const std::string name) {

    std::string tytul = "\0";
    unsigned short rok_wydania = 0;
    double ocena = 0;
    unsigned short min_wiek = 0;
    bool ulubione = false;
    unsigned short czas_trwania = 0;
    std::string rezyser;
    std::string gatunek;

    unsigned int linecount = 1;
    std::fstream plik;
    std::string wartosc, rekord;
    std::vector<std::string> przedmiot;
    std::string filename = name + "_f.csv";
    plik.open(filename, std::ios::in);
    while (getline(plik, wartosc)) {
        std::stringstream liniaStream(wartosc);
        while (getline(liniaStream, rekord, ',')) {
            przedmiot.push_back(rekord);
        }
        tytul = przedmiot.at(0);
        rok_wydania = atoi(przedmiot.at(1).c_str());
        ocena = atof(przedmiot.at(2).c_str());
        min_wiek = atoi(przedmiot.at(3).c_str());
        ulubione = atoi(przedmiot.at(4).c_str());
        czas_trwania = atoi(przedmiot.at(5).c_str());
        rezyser = przedmiot.at(6);
        gatunek = przedmiot.at(7);

        if (linecount != 1) {
            Film n(tytul, rok_wydania, ocena, min_wiek, ulubione, czas_trwania, rezyser, gatunek);
            db.push_back(n);
        }
        przedmiot.clear();
        linecount++;
    }
    plik.close();
    std::cout << "Wczytano folder z ksi¹zkami z pliku " << filename << std::endl;
}

// Album_muzyczny n(x.tytul, x.rok_wydania, x.ocena, x.min_wiek, x.ulubione, x.czas_trwania, x.utworow, x.autor, x.gatunek); <- uk³ad obiektu typu album_muzyczny
void wczytajMuzyke(std::vector<Album_muzyczny>& db, const std::string name) {

    std::string tytul = "\0";
    unsigned short rok_wydania = 0;
    double ocena = 0;
    unsigned short min_wiek = 0;
    bool ulubione = false;
    unsigned short czas_trwania = 0;
    unsigned short utworow = 0;
    std::string autor;
    std::string gatunek;

    unsigned int linecount = 1;
    std::fstream plik;
    std::string wartosc, rekord;
    std::vector<std::string> przedmiot;
    std::string filename = name + "_m.csv";
    plik.open(filename, std::ios::in);
    while (getline(plik, wartosc)) {
        std::stringstream liniaStream(wartosc);
        while (getline(liniaStream, rekord, ',')) {
            przedmiot.push_back(rekord);
        }
        tytul = przedmiot.at(0);
        rok_wydania = atoi(przedmiot.at(1).c_str());
        ocena = atof(przedmiot.at(2).c_str());
        min_wiek = atoi(przedmiot.at(3).c_str());
        ulubione = atoi(przedmiot.at(4).c_str());
        czas_trwania = atoi(przedmiot.at(5).c_str());
        utworow = atoi(przedmiot.at(6).c_str());
        autor = przedmiot.at(7);
        gatunek = przedmiot.at(8);

        if (linecount != 1) {
            Album_muzyczny n(tytul, rok_wydania, ocena, min_wiek, ulubione, czas_trwania, utworow, autor, gatunek);
            db.push_back(n);
        }
        przedmiot.clear();
        linecount++;
    }
    plik.close();
    std::cout << "Wczytano folder z ksi¹zkami z pliku " << filename << std::endl;
}