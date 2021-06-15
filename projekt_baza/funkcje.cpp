#include "funkcje.h"

void dodaj_ksiazke(std::vector<Ksiazka>& k) {
    // spis treści konstruktora: (tytul, rok_wydania, ocena, min_wiek, ulubione, strony, autor, wydawnictwo, gatunek);
    std::string tytul;
    unsigned short rok_wydania;
    double ocena;
    unsigned short min_wiek;
    bool ulubione;
    unsigned short strony;
    std::string autor;
    std::string wydawnictwo;
    std::string gatunek;

    std::cout << "Podaj tytuł książki: ";
    std::getline(std::cin, tytul);

    std::cout << "Podaj autora książki: ";
    std::getline(std::cin, autor);

    std::cout << "Podaj wydawnictwo książki: ";
    std::getline(std::cin, wydawnictwo);

    std::cout << "Podaj rok wydania książki: ";
    std::cin >> rok_wydania;
    std::cin.ignore(256, '\n');

    std::cout << "Podaj gatunek książki: ";
    std::getline(std::cin, gatunek);

    std::cout << "Podaj ilość stron: ";
    std::cin >> strony;
    std::cin.ignore(256, '\n');

    std::cout << "Podaj minimalne ograniczenie wiekowe: ";
    std::cin >> min_wiek;
    std::cin.ignore(256, '\n');

    std::cout << "Ocena? (0-5): ";
    std::cin >> ocena;
    std::cin.ignore(256, '\n');

    std::cout << "Oznaczyć jako ulubione? [t/N]: ";
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
    // spis treści konstruktora: (tytul, rok_wydania, ocena, min_wiek, ulubione, czas_trwania, rezyser, gatunek);
    std::string tytul;
    unsigned short rok_wydania;
    double ocena;
    unsigned short min_wiek;
    bool ulubione;
    unsigned short czas_trwania;
    std::string rezyser;
    std::string gatunek;

    std::cout << "Podaj tytuł filmu: ";
    std::getline(std::cin, tytul);

    std::cout << "Podaj reżysera filmu: ";
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

    std::cout << "Ocena? (0-5): ";
    std::cin >> ocena;
    std::cin.ignore(256, '\n');

    std::cout << "Oznaczyć jako ulubione? [t/N]: ";
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
    // spis treści konstruktora: (tytul, rok_wydania, ocena, min_wiek, ulubione, czas_trwania, utworow, autor, gatunek);
    std::string tytul; 
    unsigned short rok_wydania; 
    double ocena; 
    unsigned short min_wiek; 
    bool ulubione; 
    unsigned short czas_trwania; 
    unsigned short utworow; 
    std::string autor; 
    std::string gatunek; 

    std::cout << "Podaj tytuł albumu: ";
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

    std::cout << "Podaj ilość utworów w albumie: ";
    std::cin >> utworow;
    std::cin.ignore(256, '\n');

    std::cout << "Podaj minimalne ograniczenie wiekowe: ";
    std::cin >> min_wiek;
    std::cin.ignore(256, '\n');

    std::cout << "Ocena? (0-5): ";
    std::cin >> ocena;
    std::cin.ignore(256, '\n');

    std::cout << "Oznaczyć jako ulubione? [t/N]: ";
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
    // spis treści konstruktora: (tytul, rok_wydania, ocena, min_wiek, ulubione, strony, autor, wydawnictwo, gatunek);
    Utwor* wsk;
    unsigned short int choice;
    for (unsigned int i = 0; i < ksiazki.size(); i++) {
        std::cout << std::endl;
        std::cout << "Książka nr. " << i + 1 << std::endl;
        wsk = &ksiazki.at(i);
        wsk->wyswietl();
    }
    std::cout << std::endl;
    std::cout << "Wybierz przedmiot do edycji (0 aby anulować): ";
    std::cin >> choice;
    std::cin.ignore(256, '\n');
    system("cls");
    if (choice != 0 && choice<=ksiazki.size()) {
        wsk = &ksiazki.at(choice - 1);
        wsk->wyswietl();
        std::cout << std::endl;
        std::cout << "Co zrobić z powyższym przedmiotem?" << std::endl;
        std::cout << "1. Edytuj pole" << std::endl;
        std::cout << "2. Utwórz kopię przedmiotu " << std::endl;
        std::cout << "3. Utwórz kopię przedmiotu (operator =)" << std::endl;
        std::cout << "4. Usuń przedmiot" << std::endl;
        std::cout << std::endl;
        std::cout << "0. Nic" << std::endl;
        std::cout << std::endl;
        std::cout << "Wybór: ";
        unsigned short int choice1;
        std::cin >> choice1;
        std::cin.ignore(256, '\n');
        switch (choice1) {
            case 1: { // edycja pola
                unsigned short int field;
                std::cout << "Wybierz pole do zmiany: " << std::endl;
                std::cout << "1. Zmień tytuł: " << std::endl;
                std::cout << "2. Zmień rok wydania: " << std::endl;
                std::cout << "3. Zmień ocenę: " << std::endl;
                std::cout << "4. Zmień ograniczenie wiekowe: " << std::endl;
                std::cout << "5. Dodaj/Usuń z ulubionych: " << std::endl;
                std::cout << "6. Zmień ilość stron: " << std::endl;
                std::cout << "7. Zmień autora: " << std::endl;
                std::cout << "8. Zmień wydawnictwo: " << std::endl;
                std::cout << "9. Zmień gatunek: " << std::endl;
                std::cout << std::endl;
                std::cout << "Inne - Anuluj: " << std::endl;
                std::cout << std::endl;
                std::cout << "Wybór: ";
                std::cin >> field;
                std::cin.ignore(256, '\n');
                switch (field) {
                    case 1: { // tytul
                        std::string tytul;
                        std::cout << "Podaj nowy tytuł: ";
                        std::getline(std::cin, tytul);
                        ksiazki.at(choice - 1).tytul = tytul;
                        std::cout << "Zmieniono!" << std::endl;
                        system("pause");
                        break;
                    }
                    case 2: { // rok wydania
                        unsigned short rok_wydania;
                        std::cout << "Podaj nowy rok wydania: ";
                        std::cin >> rok_wydania;
                        std::cin.ignore(256, '\n');
                        ksiazki.at(choice - 1).rok_wydania = rok_wydania;
                        std::cout << "Zmieniono!" << std::endl;
                        system("pause");
                        break;
                    }
                    case 3: { // ocena
                        double ocena;
                        std::cout << "Podaj nową ocenę (0 aby usunąć ocenę): ";
                        std::cin >> ocena;
                        std::cin.ignore(256, '\n');
                        if (ocena > 5) ocena = 5;
                        else if (ocena < 0) ocena = 1;
                        ksiazki.at(choice - 1).ocena = ocena;
                        std::cout << "Zmieniono!" << std::endl;
                        system("pause");
                        break;
                    }
                    case 4: { // ograniczenie wiekowe
                        unsigned short min_wiek;
                        std::cout << "Podaj nowe ograniczenie wiekowe: ";
                        std::cin >> min_wiek;
                        std::cin.ignore(256, '\n');
                        ksiazki.at(choice - 1).min_wiek = min_wiek;
                        std::cout << "Zmieniono!" << std::endl;
                        system("pause");
                        break;
                    }
                    case 5: { // ulubione
                        bool ulubione;
                        char taknie='n';
                        std::cout << "Czy przedmiot ma być w ulubionych? [t/N]: ";
                        std::cin >> taknie;
                        std::cin.ignore(256, '\n');
                        if (tolower(taknie) == 't') ulubione = true;
                        else ulubione = false;
                        ksiazki.at(choice - 1).ulubione = ulubione;
                        std::cout << "Zmieniono!" << std::endl;
                        system("pause");
                        break;
                    }
                    case 6: { // stron
                        unsigned short strony;
                        std::cout << "Ile stron ma książka?: ";
                        std::cin >> strony;
                        std::cin.ignore(256, '\n');
                        ksiazki.at(choice - 1).strony = strony;
                        std::cout << "Zmieniono!" << std::endl;
                        system("pause");
                        break;
                    }
                    case 7: { // autor
                        std::string autor;
                        std::cout << "Podaj nowego autora/autorów książki: ";
                        std::getline(std::cin, autor);
                        ksiazki.at(choice - 1).autor = autor;
                        std::cout << "Zmieniono!" << std::endl;
                        system("pause");
                        break;
                    }
                    case 8: { // wydawnictwo
                        std::string wydawnictwo;
                        std::cout << "Podaj nowe wydawnictwo książki: ";
                        std::getline(std::cin, wydawnictwo);
                        ksiazki.at(choice - 1).wydawnictwo = wydawnictwo;
                        std::cout << "Zmieniono!" << std::endl;
                        system("pause");
                        break;
                    }
                    case 9: { // gatunek
                        std::string gatunek;
                        std::cout << "Podaj nowy gatunek książki: ";
                        std::getline(std::cin, gatunek);
                        ksiazki.at(choice - 1).gatunek = gatunek;
                        std::cout << "Zmieniono!" << std::endl;
                        system("pause");
                        break;
                    }
                }
                break;
            }
            case 2: { // kopiowanie przy użyciu konstruktora kopiującego
                std::cout << "Powyższy wpis zostanie skopiowany. Czy kontynuować? (1 - Tak, Reszta - Nie)" << std::endl;
                std::cout << "Wybór: ";
                unsigned short wybor;
                std::cin >> wybor;
                std::cin.ignore(256, '\n');
                if (wybor == 1) {
                    Ksiazka nowa(ksiazki.at(choice - 1)); // tworzenie klasy i użycie konstruktora kopiującego
                    ksiazki.push_back(nowa);
                    std::cout << "Skopiowano!" << std::endl; 
                }
                else std::cout << "Nic nie zostało skopiowane." << std::endl;
                system("pause");
                break;
            }
            case 3: { // kopiowanie przy użyciu operatora =
                std::cout << "Powyższy wpis zostanie skopiowany (operator =). Czy kontynuować? (1 - Tak, Reszta - Nie)" << std::endl;
                std::cout << "Wybór: ";
                unsigned short wybor;
                std::cin >> wybor;
                std::cin.ignore(256, '\n');
                if (wybor == 1) {
                    Ksiazka nowa; // tworzenie pustej klasy
                    nowa = ksiazki.at(choice - 1); // przeciążony operator
                    ksiazki.push_back(nowa);
                    std::cout << "Skopiowano!" << std::endl;
                }
                else std::cout << "Nic nie zostało skopiowane." << std::endl;
                system("pause");
                break;
            }
            case 4: { // usuwanie
                std::cout << "Powyższy wpis zostanie usunięty. Czy kontynuować? (1 - Tak, Reszta - Nie)" << std::endl;
                std::cout << "Wybór: ";
                unsigned short wybor;
                std::cin >> wybor;
                std::cin.ignore(256, '\n');
                if (wybor == 1) {
                    wsk = nullptr;
                    ksiazki.erase(ksiazki.begin() + (choice - 1));
                    std::cout << "Usunięto!" << std::endl;
                }
                else std::cout << "Nic nie zostało usunięte." << std::endl;
                system("pause");
                break;
            }
        }
    }
    else {
    system("cls");
    std::cout << "Anulowano edycję." << std::endl;
    system("pause");
}
}

void edytujFilmy(std::vector<Film>& filmy) {
    // spis treści konstruktora: (tytul, rok_wydania, ocena, min_wiek, ulubione, czas_trwania, rezyser, gatunek);
    Utwor* wsk;
    unsigned short int choice;
    for (unsigned int i = 0; i < filmy.size(); i++) {
        std::cout << std::endl;
        std::cout << "Film nr. " << i + 1 << std::endl;
        wsk = &filmy.at(i);
        wsk->wyswietl();
    }
    std::cout << std::endl;
    std::cout << "Wybierz przedmiot do edycji (0 aby anulować): ";
    std::cin >> choice;
    std::cin.ignore(256, '\n');
    system("cls");
    if (choice != 0 && choice <= filmy.size()) {
        wsk = &filmy.at(choice - 1);
        wsk->wyswietl();
        std::cout << std::endl;
        std::cout << "Co zrobić z powyższym przedmiotem?" << std::endl;
        std::cout << "1. Edytuj pole" << std::endl;
        std::cout << "2. Utwórz kopię przedmiotu " << std::endl;
        std::cout << "3. Utwórz kopię przedmiotu (operator =)" << std::endl;
        std::cout << "4. Usuń przedmiot" << std::endl;
        std::cout << std::endl;
        std::cout << "0. Nic" << std::endl;
        std::cout << std::endl;
        std::cout << "Wybór: ";
        unsigned short int choice1;
        std::cin >> choice1;
        std::cin.ignore(256, '\n');
        switch (choice1) {
        case 1: { // edycja
            unsigned short int field;
            std::cout << "Wybierz pole do zmiany: " << std::endl;
            std::cout << "1. Zmień tytuł: " << std::endl;
            std::cout << "2. Zmień rok wydania: " << std::endl;
            std::cout << "3. Zmień ocenę: " << std::endl;
            std::cout << "4. Zmień ograniczenie wiekowe: " << std::endl;
            std::cout << "5. Dodaj/Usuń z ulubionych: " << std::endl;
            std::cout << "6. Zmień czas trwania: " << std::endl;
            std::cout << "7. Zmień reżysera: " << std::endl;
            std::cout << "8. Zmień gatunek: " << std::endl;
            std::cout << std::endl;
            std::cout << "Inne - Anuluj: " << std::endl;
            std::cout << std::endl;
            std::cout << "Wybór: ";
            std::cin >> field;
            std::cin.ignore(256, '\n');
            switch (field) {
            case 1: { // tytul
                std::string tytul;
                std::cout << "Podaj nowy tytuł: ";
                std::getline(std::cin, tytul);
                filmy.at(choice - 1).tytul = tytul;
                std::cout << "Zmieniono!" << std::endl;
                system("pause");
                break;
            }
            case 2: { // rok wydania
                unsigned short rok_wydania;
                std::cout << "Podaj nowy rok wydania: ";
                std::cin >> rok_wydania;
                std::cin.ignore(256, '\n');
                filmy.at(choice - 1).rok_wydania = rok_wydania;
                std::cout << "Zmieniono!" << std::endl;
                system("pause");
                break;
            }
            case 3: { // ocena
                double ocena;
                std::cout << "Podaj nową ocenę (0 aby usunąć ocenę): ";
                std::cin >> ocena;
                std::cin.ignore(256, '\n');
                if (ocena > 5) ocena = 5;
                else if (ocena < 0) ocena = 1;
                filmy.at(choice - 1).ocena = ocena;
                std::cout << "Zmieniono!" << std::endl;
                system("pause");
                break;
            }
            case 4: { // ograniczenie wiekowe
                unsigned short min_wiek;
                std::cout << "Podaj nowe ograniczenie wiekowe: ";
                std::cin >> min_wiek;
                std::cin.ignore(256, '\n');
                filmy.at(choice - 1).min_wiek = min_wiek;
                std::cout << "Zmieniono!" << std::endl;
                system("pause");
                break;
            }
            case 5: { // ulubione
                bool ulubione;
                char taknie='n';
                std::cout << "Czy przedmiot ma być w ulubionych? [t/N]: ";
                std::cin >> taknie;
                std::cin.ignore(256, '\n');
                if (tolower(taknie) == 't') ulubione = true;
                else ulubione = false;
                filmy.at(choice - 1).ulubione = ulubione;
                std::cout << "Zmieniono!" << std::endl;
                system("pause");
                break;
            } 
            case 6: { // czas_trwania
                unsigned short czas_trwania;
                std::cout << "Podaj nowy czas trwania filmu w minutach: ";
                std::cin >> czas_trwania;
                std::cin.ignore(256, '\n');
                filmy.at(choice - 1).czas_trwania = czas_trwania;
                std::cout << "Zmieniono!" << std::endl;
                system("pause");
                break;
            }
            case 7: { // rezyser
                std::string rezyser;
                std::cout << "Podaj nowego reżysera filmu: ";
                std::getline(std::cin, rezyser);
                filmy.at(choice - 1).rezyser = rezyser;
                std::cout << "Zmieniono!" << std::endl;
                system("pause");
                break;
            }
            case 8: { // gatunek
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
        case 2: { // kopiowanie przy użyciu konstruktora kopiującego
            std::cout << "Powyższy wpis zostanie skopiowany. Czy kontynuować? (1 - Tak, Reszta - Nie)" << std::endl;
            std::cout << "Wybór: ";
            unsigned short wybor;
            std::cin >> wybor;
            std::cin.ignore(256, '\n');
            if (wybor == 1) {
                Film nowy(filmy.at(choice - 1)); // tworzenie klasy i użycie konstruktora kopiującego
                filmy.push_back(nowy);
                std::cout << "Skopiowano!" << std::endl;
            }
            else std::cout << "Nic nie zostało skopiowane." << std::endl;
            system("pause");
            break;
        }
        case 3: { // kopiowanie przy użyciu przeciążonego operatora przypisywania
            std::cout << "Powyższy wpis zostanie skopiowany (operator =). Czy kontynuować? (1 - Tak, Reszta - Nie)" << std::endl;
            std::cout << "Wybór: ";
            unsigned short wybor;
            std::cin >> wybor;
            std::cin.ignore(256, '\n');
            if (wybor == 1) {
                Film nowy; // tworzenie pustej klasy
                nowy = filmy.at(choice - 1); // operator
                filmy.push_back(nowy);
                std::cout << "Skopiowano!" << std::endl;
            }
            else std::cout << "Nic nie zostało skopiowane." << std::endl;
            system("pause");
            break;
        }
        case 4: { // usuwanie
            std::cout << "Powyższy wpis zostanie usunięty. Czy kontynuować? (1 - Tak, Reszta - Nie)" << std::endl;
            std::cout << "Wybór: ";
            unsigned short wybor;
            std::cin >> wybor;
            std::cin.ignore(256, '\n');
            if (wybor == 1) {
                wsk = nullptr;
                filmy.erase(filmy.begin() + (choice - 1));
                std::cout << "Usunięto!" << std::endl;
            }
            else std::cout << "Nic nie zostało usunięte." << std::endl;
            system("pause");
            break;
        }
        }
    }
    else {
    system("cls");
    std::cout << "Anulowano edycję." << std::endl;
    system("pause");
}
}

void edytujAlbumMuzyczny(std::vector<Album_muzyczny>& muzyka) {
    // spis treści konstruktora: (tytul, rok_wydania, ocena, min_wiek, ulubione, czas_trwania, utworow, autor, gatunek);
    Utwor* wsk;
    unsigned short int choice;
    for (unsigned int i = 0; i < muzyka.size(); i++) {
        std::cout << std::endl;
        std::cout << "Album muzyczny nr. " << i + 1 << std::endl;
        wsk = &muzyka.at(i);
        wsk->wyswietl();
    }
    std::cout << std::endl;
    std::cout << "Wybierz przedmiot do edycji (0 aby anulować): ";
    std::cin >> choice;
    std::cin.ignore(256, '\n');
    system("cls");
    if (choice != 0 && choice <= muzyka.size()) {
        wsk = &muzyka.at(choice - 1);
        wsk->wyswietl();
        std::cout << std::endl;
        std::cout << "Co zrobić z powyższym przedmiotem?" << std::endl;
        std::cout << "1. Edytuj pole" << std::endl;
        std::cout << "2. Utwórz kopię przedmiotu " << std::endl;
        std::cout << "3. Utwórz kopię przedmiotu (operator =)" << std::endl;
        std::cout << "4. Usuń przedmiot" << std::endl;
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
            std::cout << "1. Zmień tytuł: " << std::endl;
            std::cout << "2. Zmień rok wydania: " << std::endl;
            std::cout << "3. Zmień ocenę: " << std::endl;
            std::cout << "4. Zmień ograniczenie wiekowe: " << std::endl;
            std::cout << "5. Dodaj/Usuń z ulubionych: " << std::endl;
            std::cout << "6. Zmień czas trwania: " << std::endl;
            std::cout << "7. Zmień ilośc utworów: " << std::endl;
            std::cout << "8. Zmień autora/autorów: " << std::endl;
            std::cout << "9. Zmień gatunek: " << std::endl;
            std::cout << std::endl;
            std::cout << "Inne - Anuluj: " << std::endl;
            std::cout << std::endl;
            std::cout << "Wybór: ";
            std::cin >> field;
            std::cin.ignore(256, '\n');
            switch (field) {
            case 1: { // tytul
                std::string tytul;
                std::cout << "Podaj nowy tytuł: ";
                std::getline(std::cin, tytul);
                muzyka.at(choice - 1).tytul = tytul;
                std::cout << "Zmieniono!" << std::endl;
                system("pause");
                break;
            }
            case 2: { // rok wydania
                unsigned short rok_wydania;
                std::cout << "Podaj nowy rok wydania: ";
                std::cin >> rok_wydania;
                std::cin.ignore(256, '\n');
                muzyka.at(choice - 1).rok_wydania = rok_wydania;
                std::cout << "Zmieniono!" << std::endl;
                system("pause");
                break;
            }
            case 3: { // ocena
                double ocena;
                std::cout << "Podaj nową ocenę (0 aby usunąć ocenę): ";
                std::cin >> ocena;
                std::cin.ignore(256, '\n');
                if (ocena > 5) ocena = 5;
                else if (ocena < 0) ocena = 1;
                muzyka.at(choice - 1).ocena = ocena;
                std::cout << "Zmieniono!" << std::endl;
                system("pause");
                break;
            }
            case 4: { // ograniczenie wiekowe
                unsigned short min_wiek;
                std::cout << "Podaj nowe ograniczenie wiekowe: ";
                std::cin >> min_wiek;
                std::cin.ignore(256, '\n');
                muzyka.at(choice - 1).min_wiek = min_wiek;
                std::cout << "Zmieniono!" << std::endl;
                system("pause");
                break;
            }
            case 5: { // ulubione
                bool ulubione;
                char taknie = 'n';
                std::cout << "Czy przedmiot ma być w ulubionych? [t/N]: ";
                std::cin >> taknie;
                std::cin.ignore(256, '\n');
                if (tolower(taknie) == 't') ulubione = true;
                else ulubione = false;
                muzyka.at(choice - 1).ulubione = ulubione;
                std::cout << "Zmieniono!" << std::endl;
                system("pause");
                break;
            }
            case 6: { // czas trwania
                unsigned short czas_trwania;
                std::cout << "Podaj nowy czas trwania albumu muzycznego w minutach: ";
                std::cin >> czas_trwania;
                std::cin.ignore(256, '\n');
                muzyka.at(choice - 1).czas_trwania = czas_trwania;
                std::cout << "Zmieniono!" << std::endl;
                system("pause");
                break;
            }
            case 7: { // liczba utworów
                unsigned short utworow;
                std::cout << "Podaj nową ilość utworów: ";
                std::cin >> utworow;
                std::cin.ignore(256, '\n');
                muzyka.at(choice - 1).utworow = utworow;
                std::cout << "Zmieniono!" << std::endl;
                system("pause");
                break;
            }
            case 8: { // autor
                std::string autor;
                std::cout << "Podaj nowego autora/autorów albumu: ";
                std::getline(std::cin, autor);
                muzyka.at(choice - 1).autor = autor;
                std::cout << "Zmieniono!" << std::endl;
                system("pause");
                break;
            }
            case 9: { // gatunek
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
        case 2: { // kopiowanie za pomocą konstruktora kopiującego
            std::cout << "Powyższy wpis zostanie skopiowany. Czy kontynuować? (1 - Tak, Reszta - Nie)" << std::endl;
            std::cout << "Wybór: ";
            unsigned short wybor;
            std::cin >> wybor;
            std::cin.ignore(256, '\n');
            if (wybor == 1) {
                Album_muzyczny nowy(muzyka.at(choice - 1)); // tworzenie klasy i użycie konstruktora kopiującego
                muzyka.push_back(nowy);
                std::cout << "Skopiowano!" << std::endl;
            }
            else std::cout << "Nic nie zostało skopiowane." << std::endl;
            system("pause");
            break;
        }
        case 3: { // kopiowanie za pomocą przeciążonego operatora przypisywania =
            std::cout << "Powyższy wpis zostanie skopiowany (operator =). Czy kontynuować? (1 - Tak, Reszta - Nie)" << std::endl;
            std::cout << "Wybór: ";
            unsigned short wybor;
            std::cin >> wybor;
            std::cin.ignore(256, '\n');
            if (wybor == 1) {
                Album_muzyczny nowy; // tworzenie pustej klasy
                nowy=muzyka.at(choice - 1); // operator
                muzyka.push_back(nowy);
                std::cout << "Skopiowano!" << std::endl;
            }
            else std::cout << "Nic nie zostało skopiowane." << std::endl;
            system("pause");
            break;
        }
        case 4: {
            std::cout << "Powyższy wpis zostanie usunięty. Czy kontynuować? (1 - Tak, Reszta - Nie)" << std::endl;
            std::cout << "Wybór: ";
            unsigned short wybor;
            std::cin >> wybor;
            std::cin.ignore(256, '\n');
            if (wybor == 1) {
                wsk = nullptr;
                muzyka.erase(muzyka.begin() + (choice - 1));
                std::cout << "Usunięto!" << std::endl;
            }
            else std::cout << "Nic nie zostało usunięte." << std::endl;
            system("pause");
            break;
        }
        }
    }
    else {
    system("cls");
    std::cout << "Anulowano edycję." << std::endl;
    system("pause");
}
}

void szukajKsiazki(std::vector<Ksiazka>& ksiazki) {
    // spis treści konstruktora: (tytul, rok_wydania, ocena, min_wiek, ulubione, strony, autor, wydawnictwo, gatunek);
    Utwor* wsk;
    unsigned short results = 0;
    unsigned short ksiazek = Ksiazka::zwrocLiczbeKsiazek();
    std::cout << "Opcje wyszukiwania książki: " << std::endl;
    std::cout << std::endl;
    std::cout << "1. Szukaj po tytule." << std::endl;
    std::cout << "2. Szukaj po autorze." << std::endl;
    std::cout << "3. Szukaj po wydawnictwie." << std::endl;
    std::cout << "4. Szukaj po gatunku." << std::endl;
    std::cout << "5. Szukaj po roku wydania." << std::endl;
    std::cout << "6. Szukaj po ilości stron." << std::endl;
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
        case 1: { // tytul
            std::string tytul;
            std::cout << "Podaj tytuł książki do znalezienia: ";
            std::getline(std::cin, tytul);
            std::cout << "Wyniki wyszukiwania: " << std::endl;
            for (unsigned int i = 0; i < ksiazki.size(); i++) {
                wsk = &ksiazki.at(i);
                if (ksiazki.at(i).tytul.find(tytul) != std::string::npos) {
                    std::cout << std::endl;
                    wsk->wyswietl();
                    results++;
                }
            }
            break;
        }
        case 2: { // autor
            std::string autor;
            std::cout << "Podaj autora, którego książki chcesz wyszukać: ";
            std::getline(std::cin, autor);
            std::cout << "Wyniki wyszukiwania: " << std::endl;
            for (unsigned int i = 0; i < ksiazki.size(); i++) {
                if (ksiazki.at(i).autor.find(autor) != std::string::npos) {
                    wsk = &ksiazki.at(i);
                    std::cout << std::endl;
                    wsk->wyswietl();
                    results++;
                }
            }
            break;
        }
        case 3: { // wydawnictwo
            std::string wydawnictwo;
            std::cout << "Podaj wydawnictwo, od którego książki chcesz wyszukać: ";
            std::getline(std::cin, wydawnictwo);
            std::cout << "Wyniki wyszukiwania: " << std::endl;
            for (unsigned int i = 0; i < ksiazki.size(); i++) {
                if (ksiazki.at(i).wydawnictwo.find(wydawnictwo) != std::string::npos) {
                    wsk = &ksiazki.at(i);
                    std::cout << std::endl;
                    wsk->wyswietl();
                    results++;
                }
            }
            break;
        }
        case 4: { // gatunek
            std::string gatunek;
            std::cout << "Podaj gatunek książek, których chcesz wyszukać: ";
            std::getline(std::cin, gatunek);
            std::cout << "Wyniki wyszukiwania: " << std::endl;
            for (unsigned int i = 0; i < ksiazki.size(); i++) {
                if (ksiazki.at(i).gatunek.find(gatunek) != std::string::npos) {
                    wsk = &ksiazki.at(i);
                    std::cout << std::endl;
                    wsk->wyswietl();
                    results++;
                }
            }
            break;
        }
        case 5: { // rok wydania
            std::cout << "W jaki sposób wyszukać po roku wydania?" << std::endl;
            std::cout << std::endl;
            std::cout << "1. Wyszukaj książki wydane w podanym roku" << std::endl;
            std::cout << "2. Wyszukaj książki wydane w podanym roku bądź wcześniej" << std::endl;
            std::cout << "3. Wyszukaj książki wydane w podanym roku bądź później" << std::endl;
            std::cout << "4. Wyszukaj książki wydane w podanym przedziale lat" << std::endl;
            std::cout << std::endl;
            std::cout << "0. Anuluj" << std::endl;
            std::cout << std::endl;
            std::cout << "Wybór: ";
            unsigned short choice1;
            std::cin >> choice1;
            std::cin.ignore(256, '\n');
            system("cls");
            switch (choice1) {
                case 1: { // ==
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
                    }
                    break;
                }
                case 2: { // <=
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
                    }
                    break;
                }
                case 3: { // >=
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
                    }
                    break;
                }
                case 4: { // [x,y]
                    unsigned short rok_wydania1, rok_wydania2;
                    std::cout << "Podaj początek przedziału (domknięty): ";
                    std::cin >> rok_wydania1;
                    std::cin.ignore(256, '\n');
                    std::cout << "Podaj koniec przedziału (domknięty): ";
                    std::cin >> rok_wydania2;
                    std::cin.ignore(256, '\n');
                    for (unsigned int i = 0; i < ksiazki.size(); i++) {
                        if (ksiazki.at(i).rok_wydania >= rok_wydania1 && ksiazki.at(i).rok_wydania <= rok_wydania2) {
                            wsk = &ksiazki.at(i);
                            std::cout << std::endl;
                            wsk->wyswietl();
                            results++;
                        }
                    }
                    break;
                }
            }
            break;
        }
        case 6: { // strony
            std::cout << "W jaki sposób wyszukać po ilości stron?" << std::endl;
            std::cout << std::endl;
            std::cout << "1. Wyszukaj książki mające tyle stron" << std::endl;
            std::cout << "2. Wyszukaj książki mające tyle bądź mniej stron" << std::endl;
            std::cout << "3. Wyszukaj książki mające tyle bądź więcej stron" << std::endl;
            std::cout << "4. Wyszukaj książki mające ilość stron w podanym przedziale" << std::endl;
            std::cout << std::endl;
            std::cout << "0. Anuluj" << std::endl;
            std::cout << std::endl;
            std::cout << "Wybór: ";
            unsigned short choice1;
            std::cin >> choice1;
            std::cin.ignore(256, '\n');
            system("cls");
            switch (choice1) {
            case 1: { // ==
                unsigned short strony;
                std::cout << "Podaj ilość stron [dokładnie ile]: ";
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
                }
                break;
            }
            case 2: { // <=
                unsigned short strony;
                std::cout << "Podaj ilość stron [tyle lub mniej]: ";
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
                }
                break;
            }
            case 3: { // >=
                unsigned short strony;
                std::cout << "Podaj ilość stron [tyle lub więcej]: ";
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
                }
                break;
            }
            case 4: { // [x,y]
                unsigned short strony1, strony2;
                std::cout << "Podaj początek przedziału (domknięty): ";
                std::cin >> strony1;
                std::cin.ignore(256, '\n');
                std::cout << "Podaj koniec przedziału (domknięty): ";
                std::cin >> strony2;
                std::cin.ignore(256, '\n');
                for (unsigned int i = 0; i < ksiazki.size(); i++) {
                    if (ksiazki.at(i).strony >= strony1 && ksiazki.at(i).strony <= strony2) {
                        wsk = &ksiazki.at(i);
                        std::cout << std::endl;
                        wsk->wyswietl();
                        results++;
                    }
                }
                break;
            }
            }
            break;
        }
        case 7: { // ograniczenie wiekowe
            unsigned short min_wiek = 0;
            std::cout << "Podaj wiek, dla którego znaleźć odpowiednie książki: " << std::endl;
            std::cin >> min_wiek;
            std::cin.ignore(256, '\n');
            for (unsigned int i = 0; i < ksiazki.size(); i++) {
                if (ksiazki.at(i).min_wiek <= min_wiek) {
                    wsk = &ksiazki.at(i);
                    std::cout << std::endl;
                    wsk->wyswietl();
                    results++;
                }
            }
            break;
        }
        case 8: { // oceny
            std::cout << "Wyszukać po jakich ocenach?" << std::endl;
            std::cout << std::endl;
            std::cout << "1. Wyszukaj książki o dokładnie takiej ocenie" << std::endl;
            std::cout << "2. Wyszukaj książki o gorszej lub takiej ocenie" << std::endl;
            std::cout << "3. Wyszukaj książki o lepszej lub takiej ocenie" << std::endl;
            std::cout << "4. Wyszukaj książki w podanym przedziale ocen" << std::endl;
            std::cout << "5. Wyszukaj książki jeszcze nie ocenione" << std::endl;
            std::cout << std::endl;
            std::cout << "0. Anuluj" << std::endl;
            std::cout << std::endl;
            std::cout << "Wybór: ";
            unsigned short choice1;
            std::cin >> choice1;
            std::cin.ignore(256, '\n');
            system("cls");
            switch (choice1) {
            case 1: { // ==
                double ocena;
                std::cout << "Podaj ocenę [dokładnie taką]: ";
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
                }
                break;
            }
            case 2: { // <=
                double ocena;
                std::cout << "Podaj ocenę [gorszą lub równą]: ";
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
                }
                break;
            }
            case 3: { // >=
                double ocena;
                std::cout << "Podaj ocenę [lepszą lub równą]: ";
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
                }
                break;
            }
            case 4: { // [x,y]
                double ocena1, ocena2;
                std::cout << "Podaj początek przedziału (domknięty): ";
                std::cin >> ocena1;
                std::cin.ignore(256, '\n');
                std::cout << "Podaj koniec przedziału (domknięty): ";
                std::cin >> ocena2;
                std::cin.ignore(256, '\n');
                for (unsigned int i = 0; i < ksiazki.size(); i++) {
                    if (ksiazki.at(i).ocena >= ocena1 && ksiazki.at(i).ocena <= ocena2 && ksiazki.at(i).ocena != 0) {
                        wsk = &ksiazki.at(i);
                        std::cout << std::endl;
                        wsk->wyswietl();
                        results++;
                    }
                }
                break;
            }
            case 5: { // 0
                for (unsigned int i = 0; i < ksiazki.size(); i++) {
                    if (ksiazki.at(i).ocena==0) {
                        wsk = &ksiazki.at(i);
                        std::cout << std::endl;
                        wsk->wyswietl();
                        results++;
                    }
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
    // spis treści konstruktora: (tytul, rok_wydania, ocena, min_wiek, ulubione, czas_trwania, rezyser, gatunek);
    Utwor* wsk;
    unsigned short results = 0;
    unsigned short filmow = Film::zwrocLiczbeFilmow();
    std::cout << "Opcje wyszukiwania: " << std::endl;
    std::cout << std::endl;
    std::cout << "1. Szukaj po tytule." << std::endl;
    std::cout << "2. Szukaj po reżyserze." << std::endl;
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
    case 1: { // tytul
        std::string tytul;
        std::cout << "Podaj tytuł filmu do znalezienia: ";
        std::getline(std::cin, tytul);
        std::cout << "Wyniki wyszukiwania: " << std::endl;      
        for (unsigned int i = 0; i < filmy.size(); i++) {
            if (filmy.at(i).tytul.find(tytul) != std::string::npos) {
                wsk = &filmy.at(i);
                std::cout << std::endl;
                wsk->wyswietl();
                results++;
            }
        }
        break;
    }
    case 2: { // rezyser
        std::string rezyser;
        std::cout << "Podaj reżysera, którego filmy chcesz wyszukać: ";
        std::getline(std::cin, rezyser);
        std::cout << "Wyniki wyszukiwania: " << std::endl;       
        for (unsigned int i = 0; i < filmy.size(); i++) {
            if (filmy.at(i).rezyser.find(rezyser) != std::string::npos) {
                wsk = &filmy.at(i);
                std::cout << std::endl;
                wsk->wyswietl();
                results++;
            }
        }
        break;
    }
    case 3: { // gatunek
        std::string gatunek;
        std::cout << "Podaj gatunek filmów, których chcesz wyszukać: ";
        std::getline(std::cin, gatunek);
        std::cout << "Wyniki wyszukiwania: " << std::endl;       
        for (unsigned int i = 0; i < filmy.size(); i++) {
            if (filmy.at(i).gatunek.find(gatunek) != std::string::npos) {
                wsk = &filmy.at(i);
                std::cout << std::endl;
                wsk->wyswietl();
                results++;
            }
        }
        break;
    }
    case 4: { // rok wydania
        unsigned short rok_wydania;
        std::cout << "W jaki sposób wyszukać po roku wydania?" << std::endl;
        std::cout << std::endl;
        std::cout << "1. Wyszukaj filmy wydane w podanym roku" << std::endl;
        std::cout << "2. Wyszukaj filmy wydane w podanym roku bądź wcześniej" << std::endl;
        std::cout << "3. Wyszukaj filmy wydane w podanym roku bądź później" << std::endl;
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
        case 1: { // ==
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
            }
            break;
        }
        case 2: { // <=
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
            }
            break;
        }
        case 3: { // >=
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
            }
            break;
        }
        case 4: { // [x,y]
            unsigned short rok_wydania1;
            std::cout << "Podaj początek przedziału (domknięty): ";
            std::cin >> rok_wydania;
            std::cin.ignore(256, '\n');
            std::cout << "Podaj koniec przedziału (domknięty): ";
            std::cin >> rok_wydania1;
            std::cin.ignore(256, '\n');            
            for (unsigned int i = 0; i < filmy.size(); i++) {
                if (filmy.at(i).rok_wydania >= rok_wydania && filmy.at(i).rok_wydania <= rok_wydania1) {
                    wsk = &filmy.at(i);
                    std::cout << std::endl;
                    wsk->wyswietl();
                    results++;
                }
            }
            break;
        }
        }
        break;
    }
    case 5: { // czas_trwania
        unsigned short czas_trwania;
        std::cout << "W jaki sposób wyszukać po czasie trwania?" << std::endl;
        std::cout << std::endl;
        std::cout << "1. Wyszukaj filmy trwające tyle" << std::endl;
        std::cout << "2. Wyszukaj filmy trwające tyle bądź krócej" << std::endl;
        std::cout << "3. Wyszukaj filmy trwające tyle bądź dłużej" << std::endl;
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
        case 1: { // ==
            std::cout << "Podaj czas trwania w minutach [dokładnie ile]: ";
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
            }
            break;
        }
        case 2: { // <=
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
            }
            break;
        }
        case 3: { // >=
            std::cout << "Podaj czas trwania w minutach [tyle lub więcej]: ";
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
            }
            break;
        }
        case 4: { // [x,y]
            unsigned short czas_trwania1;
            std::cout << "Podaj początek przedziału (domknięty): ";
            std::cin >> czas_trwania;
            std::cin.ignore(256, '\n');
            std::cout << "Podaj koniec przedziału (domknięty): ";
            std::cin >> czas_trwania1;
            std::cin.ignore(256, '\n');           
            for (unsigned int i = 0; i < filmy.size(); i++) {
                if (filmy.at(i).czas_trwania >= czas_trwania && filmy.at(i).czas_trwania <= czas_trwania1) {
                    wsk = &filmy.at(i);
                    std::cout << std::endl;
                    wsk->wyswietl();
                    results++;
                }
            }
            break;
        }
        }
        break;
    }
    case 6: { // ograniczenie wiekowe
        unsigned short min_wiek;
        std::cout << "Podaj wiek, dla którego znaleźć odpowiednie filmy: " << std::endl;
        std::cin >> min_wiek;
        std::cin.ignore(256, '\n');        
        for (unsigned int i = 0; i < filmy.size(); i++) {
            if (filmy.at(i).min_wiek <= min_wiek) {
                wsk = &filmy.at(i);
                std::cout << std::endl;
                wsk->wyswietl();
                results++;
            }
        }
        break;
    }
    case 7: { // ocena
        double ocena;
        std::cout << "Wyszukać po jakich ocenach?" << std::endl;
        std::cout << std::endl;
        std::cout << "1. Wyszukaj filmy o dokładnie takiej ocenie" << std::endl;
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
        case 1: { // ==
            std::cout << "Podaj ocenę [dokładnie taką]: ";
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
            }
            break;
        }
        case 2: { // <=
            std::cout << "Podaj ocenę [gorszą lub równą]: ";
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
            }
            break;
        }
        case 3: { // >=
            std::cout << "Podaj ocenę [lepszą lub równą]: ";
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
            }
            break;
        }
        case 4: { // [x,y]
            double ocena1;
            std::cout << "Podaj początek przedziału (domknięty): ";
            std::cin >> ocena;
            std::cin.ignore(256, '\n');
            std::cout << "Podaj koniec przedziału (domknięty): ";
            std::cin >> ocena1;
            std::cin.ignore(256, '\n');
            for (unsigned int i = 0; i < filmy.size(); i++) {
                if (filmy.at(i).ocena >= ocena && filmy.at(i).ocena <= ocena1 && filmy.at(i).ocena != 0) {
                    wsk = &filmy.at(i);
                    std::cout << std::endl;
                    wsk->wyswietl();
                    results++;
                }
            }
            break;
        }
        case 5: { // 0
            for (unsigned int i = 0; i < filmy.size(); i++) {
                if (filmy.at(i).ocena == 0) {
                    wsk = &filmy.at(i);
                    std::cout << std::endl;
                    wsk->wyswietl();
                    results++;
                }
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
    // spis treści konstruktora: (tytul, rok_wydania, ocena, min_wiek, ulubione, czas_trwania, utworow, autor, gatunek);
    Utwor* wsk;
    unsigned short results = 0;
    unsigned short albumow = Album_muzyczny::zwrocLiczbeAlbumow();
    std::cout << "Opcje wyszukiwania: " << std::endl;
    std::cout << std::endl;
    std::cout << "1. Szukaj po tytule." << std::endl;
    std::cout << "2. Szukaj po autorze." << std::endl;
    std::cout << "3. Szukaj po gatunku." << std::endl;
    std::cout << "4. Szukaj po roku wydania." << std::endl;
    std::cout << "5. Szukaj po czasie trwania." << std::endl;
    std::cout << "6. Szukaj po ilości utworów." << std::endl;
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
    case 1: { // tytul
        std::string tytul;
        std::cout << "Podaj tytuł albumu muzycznego do znalezienia: ";
        std::getline(std::cin, tytul);
        std::cout << "Wyniki wyszukiwania: " << std::endl;
        for (unsigned int i = 0; i < muzyka.size(); i++) {
            if (muzyka.at(i).tytul.find(tytul) != std::string::npos) {
                wsk = &muzyka.at(i);
                std::cout << std::endl;
                wsk->wyswietl();
                results++;
            }
        }
        break;
    }
    case 2: { // autor
        std::string autor;
        std::cout << "Podaj autora, którego album muzyczny chcesz wyszukać: ";
        std::getline(std::cin, autor);
        std::cout << "Wyniki wyszukiwania: " << std::endl;
        for (unsigned int i = 0; i < muzyka.size(); i++) {
            if (muzyka.at(i).autor.find(autor) != std::string::npos) {
                wsk = &muzyka.at(i);
                std::cout << std::endl;
                wsk->wyswietl();
                results++;
            }
        }
        break;
    }
    case 3: { // gatunek
        std::string gatunek;
        std::cout << "Podaj gatunek muzyczny, którego chcesz wyszukać: ";
        std::getline(std::cin, gatunek);
        std::cout << "Wyniki wyszukiwania: " << std::endl;
        for (unsigned int i = 0; i < muzyka.size(); i++) {
            if (muzyka.at(i).gatunek.find(gatunek) != std::string::npos) {
                wsk = &muzyka.at(i);
                std::cout << std::endl;
                wsk->wyswietl();
                results++;
            }
        }
        break;
    }
    case 4: { // rok wydania
        unsigned short rok_wydania;
        std::cout << "W jaki sposób wyszukać po roku wydania?" << std::endl;
        std::cout << std::endl;
        std::cout << "1. Wyszukaj albumy wydane w podanym roku" << std::endl;
        std::cout << "2. Wyszukaj albumy wydane w podanym roku bądź wcześniej" << std::endl;
        std::cout << "3. Wyszukaj albumy wydane w podanym roku bądź później" << std::endl;
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
        case 1: { // ==
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
            }
            break;
        }
        case 2: { // >=
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
            }
            break;
        }
        case 3: { // <=
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
            }
            break;
        }
        case 4: { // [x,y]
            unsigned short rok_wydania1;
            std::cout << "Podaj początek przedziału (domknięty): ";
            std::cin >> rok_wydania;
            std::cin.ignore(256, '\n');
            std::cout << "Podaj koniec przedziału (domknięty): ";
            std::cin >> rok_wydania1;
            std::cin.ignore(256, '\n');
            for (unsigned int i = 0; i < muzyka.size(); i++) {
                if (muzyka.at(i).rok_wydania >= rok_wydania && muzyka.at(i).rok_wydania <= rok_wydania1) {
                    wsk = &muzyka.at(i);
                    std::cout << std::endl;
                    wsk->wyswietl();
                    results++;
                }
            }
            break;
        }
        }
        break;
    }
    case 5: { // czas trwania
        unsigned short czas_trwania;
        std::cout << "W jaki sposób wyszukać po czasie trwania?" << std::endl;
        std::cout << std::endl;
        std::cout << "1. Wyszukaj albumy trwające dokładnie tyle" << std::endl;
        std::cout << "2. Wyszukaj albumy trwające tyle bądź krócej" << std::endl;
        std::cout << "3. Wyszukaj albumy trwające tyle bądź dłużej" << std::endl;
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
        case 1: { // ==
            std::cout << "Podaj czas trwania w minutach [dokładnie ile]: ";
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
            }
            break;
        }
        case 2: { // <=
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
            }
            break;
        }
        case 3: { // >=
            std::cout << "Podaj czas trwania w minutach [tyle lub więcej]: ";
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
            }
            break;
        }
        case 4: { // [x,y]
            unsigned short czas_trwania1;
            std::cout << "Podaj początek przedziału (domknięty): ";
            std::cin >> czas_trwania;
            std::cin.ignore(256, '\n');
            std::cout << "Podaj koniec przedziału (domknięty): ";
            std::cin >> czas_trwania1;
            std::cin.ignore(256, '\n');
            for (unsigned int i = 0; i < muzyka.size(); i++) {
                if (muzyka.at(i).czas_trwania >= czas_trwania && muzyka.at(i).czas_trwania <= czas_trwania1) {
                    wsk = &muzyka.at(i);
                    std::cout << std::endl;
                    wsk->wyswietl();
                    results++;
                }
            }
            break;
        }
        }
        break;
    }
    case 6: { // utworow
        unsigned short utworow;
        std::cout << "W jaki sposób wyszukać po ilości utworów?" << std::endl;
        std::cout << std::endl;
        std::cout << "1. Wyszukaj albumy, które mają dokładnie tyle utworów" << std::endl;
        std::cout << "2. Wyszukaj albumy, które mają tyle bądź mniej utworów" << std::endl;
        std::cout << "3. Wyszukaj albumy, które mają tyle badź więcej utworów" << std::endl;
        std::cout << "4. Wyszukaj albumy, których ilość utworów jest w podanym przedziale" << std::endl;
        std::cout << std::endl;
        std::cout << "0. Anuluj" << std::endl;
        std::cout << std::endl;
        std::cout << "Wybór: ";
        unsigned short choice1;
        std::cin >> choice1;
        std::cin.ignore(256, '\n');
        system("cls");
        switch (choice1) {
        case 1: { // ==
            std::cout << "Podaj ilość utworów [dokładnie ile]: ";
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
            }
            break;
        }
        case 2: { // <=
            std::cout << "Podaj ilość utworów [tyle lub mniej]: ";
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
            }
            break;
        }
        case 3: { // >=
            std::cout << "Podaj ilość utworów [tyle lub więcej]: ";
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
            }
            break;
        }
        case 4: { // [x,y]
            unsigned short utworow1;
            std::cout << "Podaj początek przedziału (domknięty): ";
            std::cin >> utworow;
            std::cin.ignore(256, '\n');
            std::cout << "Podaj koniec przedziału (domknięty): ";
            std::cin >> utworow1;
            std::cin.ignore(256, '\n');
            for (unsigned int i = 0; i < muzyka.size(); i++) {
                if (muzyka.at(i).utworow >= utworow && muzyka.at(i).utworow <= utworow1) {
                    wsk = &muzyka.at(i);
                    std::cout << std::endl;
                    wsk->wyswietl();
                    results++;
                }
            }
            break;
        }
        }
        break;
    }
    case 7: { // ograniczenie wiekowe
        unsigned short min_wiek;
        std::cout << "Podaj wiek, dla którego znaleźć odpowiednie albumy muzyczne: " << std::endl;
        std::cin >> min_wiek;
        std::cin.ignore(256, '\n');
        for (unsigned int i = 0; i < muzyka.size(); i++) {
            if (muzyka.at(i).min_wiek <= min_wiek) {
                wsk = &muzyka.at(i);
                std::cout << std::endl;
                wsk->wyswietl();
                results++;
            }
        }
        break;
    }
    case 8: { // ocena
        double ocena;
        std::cout << "Wyszukać po jakich ocenach?" << std::endl;
        std::cout << std::endl;
        std::cout << "1. Wyszukaj albumy o dokładnie takiej ocenie" << std::endl;
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
        case 1: { // ==
            std::cout << "Podaj ocenę [dokładnie taką]: ";
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
            }
            break;
        }
        case 2: { // <=
            std::cout << "Podaj ocenę [gorszą lub równą]: ";
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
            }
            break;
        }
        case 3: { // >=
            std::cout << "Podaj ocenę [lepszą lub równą]: ";
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
            }
            break;
        }
        case 4: { // [x,y]
            double ocena1;
            std::cout << "Podaj początek przedziału (domknięty): ";
            std::cin >> ocena;
            std::cin.ignore(256, '\n');
            std::cout << "Podaj koniec przedziału (domknięty): ";
            std::cin >> ocena1;
            std::cin.ignore(256, '\n');
            for (unsigned int i = 0; i < muzyka.size(); i++) {
                if (muzyka.at(i).ocena >= ocena && muzyka.at(i).ocena <= ocena1 && muzyka.at(i).ocena != 0) {
                    wsk = &muzyka.at(i);
                    std::cout << std::endl;
                    wsk->wyswietl();
                    results++;
                }
            }
            break;
        }
        case 5: { // 0
            for (unsigned int i = 0; i < muzyka.size(); i++) {
                if (muzyka.at(i).ocena == 0) {
                    wsk = &muzyka.at(i);
                    std::cout << std::endl;
                    wsk->wyswietl();
                    results++;
                }
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

// Ksiazka n(x.tytul, x.rok_wydania, x.ocena, x.min_wiek, x.ulubione, x.strony, x.autor, x.wydawnictwo, x.gatunek) <- układ obiektu typu ksiązka
void zapiszKsiazki(const std::vector<Ksiazka>& db, const std::string name) {
    std::fstream plik;
    const std::string filename = name + "_k.csv";
    plik.open(filename, std::ios::out);
    plik << "\"Tytuł\",\"Rok wydania\",\"Ocena\",\"Min. ograniczenie wiekowe\",\"Ulubione\",\"Ilość stron\",\"Autor\",\"Wydawnictwo\",\"Gatunek\"" << std::endl; // wiersz tytułowy
    for (unsigned int i = 0; i < db.size(); i++) { // pętla for - zbieranie linijka po linijce
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
        plik << ',' << std::endl;
    }
    plik.close();
    std::cout << "Zapisano bazę danych do pliku " << filename << std::endl;
}

//Film n(x.tytul, x.rok_wydania, x.ocena, x.min_wiek, x.ulubione, x.czas_trwania, x.rezyser, x.gatunek); <- układ obiektu typu film
void zapiszFilmy(const std::vector<Film>& db, const std::string name) {
    std::fstream plik;
    const std::string filename = name + "_f.csv";
    plik.open(filename, std::ios::out);
    plik << "\"Tytuł\",\"Rok wydania\",\"Ocena\",\"Min. ograniczenie wiekowe\",\"Ulubione\",\"Czas trwania [m]\",\"Reżyser\",\"Gatunek\"" << std::endl;
    for (unsigned int i = 0; i < db.size(); i++) { // pętla for - zbieranie linijka po linijce
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
        plik << ',' << std::endl;
    }
    plik.close();
    std::cout << "Zapisano bazę danych do pliku " << filename << std::endl;
}

//Album_muzyczny n(x.tytul, x.rok_wydania, x.ocena, x.min_wiek, x.ulubione, x.czas_trwania, x.utworow, x.autor, x.gatunek); <- układ obiektu typu album_muzyczny
void zapiszMuzyke(const std::vector<Album_muzyczny>& db, const std::string name) {
    std::fstream plik;
    const std::string filename = name + "_m.csv";
    plik.open(filename, std::ios::out);
    plik << "\"Tytuł\",\"Rok wydania\",\"Ocena\",\"Min. ograniczenie wiekowe\",\"Ulubione\",\"Czas trwania [m]\",\"Liczba utworów\",\"Autor\",\"Gatunek\"" << std::endl;
    for (unsigned int i = 0; i < db.size(); i++) { // pętla for - zbieranie linijka po linijce
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
        plik << ',' << std::endl;
    }
    plik.close();
    std::cout << "Zapisano bazę danych do pliku " << filename << std::endl;
}

// Ksiazka n(x.tytul, x.rok_wydania, x.ocena, x.min_wiek, x.ulubione, x.strony, x.autor, x.wydawnictwo, x.gatunek) <- układ obiektu typu ksiązka
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
    std::cout << "Wczytano folder z ksiązkami z pliku " << filename << std::endl;
}

// Film n(x.tytul, x.rok_wydania, x.ocena, x.min_wiek, x.ulubione, x.czas_trwania, x.rezyser, x.gatunek) <- układ obiektu typu film
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
    std::cout << "Wczytano folder z ksiązkami z pliku " << filename << std::endl;
}

// Album_muzyczny n(x.tytul, x.rok_wydania, x.ocena, x.min_wiek, x.ulubione, x.czas_trwania, x.utworow, x.autor, x.gatunek); <- układ obiektu typu album_muzyczny
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
    std::cout << "Wczytano folder z ksiązkami z pliku " << filename << std::endl;
}

double findmin(const std::vector<double>& k) {
    if (k.size() == 0) return 0;
    double min = k.at(0);
    for (auto i : k) {
        if (i < min) min = i;
    }
    return min;
}

double findmax(const std::vector<double>& k) {
    if (k.size() == 0) return 0;
    double max = k.at(0);
    for (auto i : k) {
        if (i > max) max = i;
    }
    return max;
}

double findavg(const std::vector<double>& k) {
    if (k.size() == 0) return 0;
    double avg = 0;
    double n = 0;
    for (auto i : k) {
        n += i;
    }
    if (k.size() > 0) avg = n / k.size();
    return avg;
}

double findsum(const std::vector<double>& k) {
    if (k.size() == 0) return 0;
    double sum = 0;
    for (auto i : k) {
        sum += i;
    }
    return sum;
}

void statsMenu(const std::vector<Ksiazka>& k, const std::vector<Film>& f, const std::vector<Album_muzyczny>& m) {
    // Ksiazka  (tytul, rok_wydania, ocena, min_wiek, ulubione, strony, autor, wydawnictwo, gatunek);
    // Film     (tytul, rok_wydania, ocena, min_wiek, ulubione, czas_trwania, rezyser, gatunek);
    // Muzyka   (tytul, rok_wydania, ocena, min_wiek, ulubione, czas_trwania, utworow, autor, gatunek);

    std::cout << "Zaawansowane statystyki: " << std::endl;
    std::cout << "Przedmiotów:\t" << Utwor::zwrocLiczbeUtworow() << std::endl;
    std::cout << "Książek:\t" << Ksiazka::zwrocLiczbeKsiazek() << std::endl;
    std::cout << "Filmów:\t\t" << Film::zwrocLiczbeFilmow() << std::endl;
    std::cout << "Albumów muz.:\t" << Album_muzyczny::zwrocLiczbeAlbumow() << std::endl << std::endl;

    std::vector<double> oceny_k;
    std::vector<double> oceny_f;
    std::vector<double> oceny_m;

    std::vector<double> minwiek_k;
    std::vector<double> minwiek_f;
    std::vector<double> minwiek_m;

    std::vector<double> strony;

    std::vector<double> czas_trwania_f;

    std::vector<double> czas_trwania_m;

    std::vector<double> utworow;

    if (Ksiazka::zwrocLiczbeKsiazek()) {
        for (unsigned int i = 0; i < k.size(); i++) {
            oceny_k.push_back(k.at(i).zwrocOcene());
            minwiek_k.push_back(k.at(i).zwrocMinWiek());
            strony.push_back(k.at(i).zwrocStrony());
        }
    }

    if (Film::zwrocLiczbeFilmow()) {
        for (unsigned int i = 0; i < f.size(); i++) {
            oceny_f.push_back(f.at(i).zwrocOcene());
            minwiek_f.push_back(f.at(i).zwrocMinWiek());
            czas_trwania_f.push_back(f.at(i).zwrocCzasTrwania());
        }
    }

    if (Album_muzyczny::zwrocLiczbeAlbumow()) {
        for (unsigned int i = 0; i < m.size(); i++) {
            oceny_m.push_back(m.at(i).zwrocOcene());
            minwiek_m.push_back(m.at(i).zwrocMinWiek());
            czas_trwania_m.push_back(m.at(i).zwrocCzasTrwania());
            utworow.push_back(m.at(i).zwrocLiczbeUtworow());
        }
    }

    std::vector<double> oceny;
    oceny.insert(oceny.end(), oceny_k.begin(), oceny_k.end());
    oceny.insert(oceny.end(), oceny_f.begin(), oceny_f.end());
    oceny.insert(oceny.end(), oceny_m.begin(), oceny_m.end());

    std::vector<double> minwiek;
    minwiek.insert(minwiek.end(), minwiek_k.begin(), minwiek_k.end());
    minwiek.insert(minwiek.end(), minwiek_f.begin(), minwiek_f.end());
    minwiek.insert(minwiek.end(), minwiek_m.begin(), minwiek_m.end());

    std::cout << "OCENY:\t\t" << "SUMA\t" << "MAX\t" << "AVG\t" << "MIN\t" << std::endl;
    std::cout << "OGÓLNE:\t\t" << findsum(oceny) << "\t" << findmax(oceny) << "\t" << findavg(oceny) << "\t" << findmin(oceny) << std::endl;
    std::cout << "KSIĄŻKI:\t" << findsum(oceny_k) << "\t" << findmax(oceny_k) << "\t" << findavg(oceny_k) << "\t" << findmin(oceny_k) << std::endl;
    std::cout << "FILMY:\t\t" << findsum(oceny_f) << "\t" << findmax(oceny_f) << "\t" << findavg(oceny_f) << "\t" << findmin(oceny_f) << std::endl;
    std::cout << "ALBUMY:\t\t" << findsum(oceny_m) << "\t" << findmax(oceny_m) << "\t" << findavg(oceny_m) << "\t" << findmin(oceny_m) << std::endl;

    std::cout << std::endl;

    std::cout << "MIN. WIEK:\t" << "SUMA\t" << "MAX\t" << "AVG\t" << "MIN\t" << std::endl;
    std::cout << "OGÓLNE:\t\t" << findsum(minwiek) << "\t" << findmax(minwiek) << "\t" << findavg(minwiek) << "\t" << findmin(minwiek) << std::endl;
    std::cout << "KSIĄŻKI:\t" << findsum(minwiek_k) << "\t" << findmax(minwiek_k) << "\t" << findavg(minwiek_k) << "\t" << findmin(minwiek_k) << std::endl;
    std::cout << "FILMY:\t\t" << findsum(minwiek_f) << "\t" << findmax(minwiek_f) << "\t" << findavg(minwiek_f) << "\t" << findmin(minwiek_f) << std::endl;
    std::cout << "ALBUMY:\t\t" << findsum(minwiek_m) << "\t" << findmax(minwiek_m) << "\t" << findavg(minwiek_m) << "\t" << findmin(minwiek_m) << std::endl;

    std::cout << std::endl;

    std::cout << "KSIĄŻKI - LICZBA STRON:" << std::endl;
    std::cout << "SUMA\t" << "MAX\t" << "AVG\t" << "MIN\t" << std::endl;
    std::cout << findsum(strony) << "\t" << findmax(strony) << "\t" << findavg(strony) << "\t" << findmin(strony) << std::endl;

    std::cout << std::endl;

    std::cout << "FILMY - CZAS TRWANIA [M]:" << std::endl;
    std::cout << "SUMA\t" << "MAX\t" << "AVG\t" << "MIN\t" << std::endl;
    std::cout << findsum(czas_trwania_f) << "\t" << findmax(czas_trwania_f) << "\t" << findavg(czas_trwania_f) << "\t" << findmin(czas_trwania_f) << std::endl;

    std::cout << std::endl;

    std::cout << "MUZYKA - CZAS TRWANIA [M]:" << std::endl;
    std::cout << "SUMA\t" << "MAX\t" << "AVG\t" << "MIN\t" << std::endl;
    std::cout << findsum(czas_trwania_m) << "\t" << findmax(czas_trwania_m) << "\t" << findavg(czas_trwania_m) << "\t" << findmin(czas_trwania_m) << std::endl;

    std::cout << std::endl;

    std::cout << "MUZYKA - LICZBA UTWORÓW:" << std::endl;
    std::cout << "SUMA\t" << "MAX\t" << "AVG\t" << "MIN\t" << std::endl;
    std::cout << findsum(utworow) << "\t" << findmax(utworow) << "\t" << findavg(utworow) << "\t" << findmin(utworow) << std::endl;

    system("pause");

}