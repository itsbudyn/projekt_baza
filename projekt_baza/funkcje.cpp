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

    std::cout << "Podaj tytu� ksi��ki: ";
    std::getline(std::cin, tytul);

    std::cout << "Podaj autora ksi��ki: ";
    std::getline(std::cin, autor);

    std::cout << "Podaj wydawnictwo ksi��ki: ";
    std::getline(std::cin, wydawnictwo);

    std::cout << "Podaj rok wydania ksi��ki: ";
    std::cin >> rok_wydania;
    std::cin.ignore(256, '\n');

    std::cout << "Podaj gatunek ksi��ki: ";
    std::getline(std::cin, gatunek);

    std::cout << "Podaj ilo�� stron: ";
    std::cin >> strony;
    std::cin.ignore(256, '\n');

    std::cout << "Podaj minimalne ograniczenie wiekowe: ";
    std::cin >> min_wiek;
    std::cin.ignore(256, '\n');

    std::cout << "Ocena? (0-5)";
    std::cin >> ocena;
    std::cin.ignore(256, '\n');

    std::cout << "Oznaczy� jako ulubione? [t/N]";
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

    std::cout << "Podaj tytu� filmu: ";
    std::getline(std::cin, tytul);

    std::cout << "Podaj re�ysera filmu: ";
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

    std::cout << "Oznaczy� jako ulubione? [t/N]";
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
    bool czy_single; 
    std::string autor; 
    std::string gatunek; 

    std::cout << "Podaj tytu� albumu: ";
    std::getline(std::cin, tytul);

    std::cout << "Podaj autor�w albumu: ";
    std::getline(std::cin, autor);

    std::cout << "Podaj rok wydania albumu: ";
    std::cin >> rok_wydania;
    std::cin.ignore(256, '\n');

    std::cout << "Podaj gatunek muzyczny albumu: ";
    std::getline(std::cin, gatunek);

    std::cout << "Podaj czas trwania albumu [m]: ";
    std::cin >> czas_trwania;
    std::cin.ignore(256, '\n');

    std::cout << "Podaj ilo�� utwor�w w albumie: ";
    std::cin >> utworow;
    std::cin.ignore(256, '\n');
    if (utworow == 1)czy_single = true;
    else czy_single = false;

    std::cout << "Podaj minimalne ograniczenie wiekowe: ";
    std::cin >> min_wiek;
    std::cin.ignore(256, '\n');

    std::cout << "Ocena? (0-5)";
    std::cin >> ocena;
    std::cin.ignore(256, '\n');

    std::cout << "Oznaczy� jako ulubione? [t/N]";
    char wybor;
    std::cin >> wybor;
    std::cin.ignore(256, '\n');
    if (tolower(wybor) == 't') ulubione = true;
    else ulubione = false;

    Album_muzyczny x(tytul, rok_wydania, ocena, min_wiek, ulubione, czas_trwania, utworow, czy_single, autor, gatunek);
    x.wyswietl();
    a.push_back(x);
    system("pause");
}

void edytujKsiazki(std::vector<Ksiazka>& ksiazki) {
    Utwor* wsk;
    unsigned short int choice;
    for (unsigned int i = 0; i < ksiazki.size(); i++) {
        std::cout << std::endl;
        std::cout << "Ksi��ka nr. " << i + 1 << std::endl;
        wsk = &ksiazki.at(i);
        wsk->wyswietl();
    }
    std::cout << std::endl;
    std::cout << "Wybierz przedmiot do edycji (0 aby anulowa�): ";
    std::cin >> choice;
    std::cin.ignore(256, '\n');
    if (choice != 0 && choice<=ksiazki.size()) {
        wsk = &ksiazki.at(choice - 1);
        wsk->wyswietl();
        std::cout << std::endl;
        std::cout << "Co zrobi� z powy�szym przedmiotem?" << std::endl;
        std::cout << "1. Edytuj pole" << std::endl;
        std::cout << "2. Usu� przedmiot" << std::endl;
        std::cout << std::endl;
        std::cout << "0. Nic" << std::endl;
        std::cout << std::endl;
        std::cout << "Wyb�r: ";
        unsigned short int choice1;
        std::cin >> choice1;
        std::cin.ignore(256, '\n');
        switch (choice1) {
            case 1: {
                unsigned short int field;
                std::cout << "Wybierz pole do zmiany: " << std::endl;
                std::cout << "1. Zmie� tytu�: " << std::endl;
                std::cout << "2. Zmie� rok wydania: " << std::endl;
                std::cout << "3. Zmie� ocen�: " << std::endl;
                std::cout << "4. Zmie� ograniczenie wiekowe: " << std::endl;
                std::cout << "5. Dodaj/Usu� z ulubionych: " << std::endl;
                std::cout << "6. Zmie� ilo�� stron: " << std::endl;
                std::cout << "7. Zmie� autora: " << std::endl;
                std::cout << "8. Zmie� wydawnictwo: " << std::endl;
                std::cout << "9. Zmie� gatunek: " << std::endl;
                std::cout << std::endl;
                std::cout << "Inne - Anuluj: " << std::endl;
                std::cout << std::endl;
                std::cout << "Wyb�r: ";
                std::cin >> field;
                std::cin.ignore(256, '\n');
                switch (field) {
                    case 1: {
                        std::string tytul;
                        std::cout << "Podaj nowy tytu�: ";
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
                        std::cout << "Podaj now� ocen� (0 aby usun�� ocen�): ";
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
                        std::cout << "Czy przedmiot ma by� w ulubionych? [t/N]: ";
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
                        std::cout << "Ile stron ma ksi��ka?: ";
                        std::cin >> strony;
                        std::cin.ignore(256, '\n');
                        ksiazki.at(choice - 1).strony = strony;
                        std::cout << "Zmieniono!" << std::endl;
                        system("pause");
                        break;
                    }
                    case 7: {
                        std::string autor;
                        std::cout << "Podaj nowego autora/autor�w ksi��ki: ";
                        std::getline(std::cin, autor);
                        ksiazki.at(choice - 1).autor = autor;
                        std::cout << "Zmieniono!" << std::endl;
                        system("pause");
                        break;
                    }
                    case 8: {
                        std::string wydawnictwo;
                        std::cout << "Podaj nowe wydawnictwo ksi��ki: ";
                        std::getline(std::cin, wydawnictwo);
                        ksiazki.at(choice - 1).wydawnictwo = wydawnictwo;
                        std::cout << "Zmieniono!" << std::endl;
                        system("pause");
                        break;
                    }
                    case 9: {
                        std::string gatunek;
                        std::cout << "Podaj nowy gatunek ksi��ki: ";
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
                std::cout << "Powy�szy wpis zostanie usuni�ty. Czy kontynuowa�? (1 - Tak, Reszta - Nie)" << std::endl;
                std::cout << "Wyb�r: ";
                unsigned short wybor;
                std::cin >> wybor;
                std::cin.ignore(256, '\n');
                if (wybor == 1) {
                    wsk = nullptr;
                    ksiazki.erase(ksiazki.begin() + (choice - 1));
                }
                break;
            }
        }
    }
    else {
    system("cls");
    std::cout << "Anulowano edycj�." << std::endl;
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
    std::cout << "Wybierz przedmiot do edycji (0 aby anulowa�): ";
    std::cin >> choice;
    std::cin.ignore(256, '\n');
    if (choice != 0 && choice <= filmy.size()) {
        wsk = &filmy.at(choice - 1);
        wsk->wyswietl();
        std::cout << std::endl;
        std::cout << "Co zrobi� z powy�szym przedmiotem?" << std::endl;
        std::cout << "1. Edytuj pole" << std::endl;
        std::cout << "2. Usu� przedmiot" << std::endl;
        std::cout << std::endl;
        std::cout << "0. Nic" << std::endl;
        std::cout << std::endl;
        std::cout << "Wyb�r: ";
        unsigned short int choice1;
        std::cin >> choice1;
        std::cin.ignore(256, '\n');
        switch (choice1) {
        case 1: {
            unsigned short int field;
            std::cout << "Wybierz pole do zmiany: " << std::endl;
            std::cout << "1. Zmie� tytu�: " << std::endl;
            std::cout << "2. Zmie� rok wydania: " << std::endl;
            std::cout << "3. Zmie� ocen�: " << std::endl;
            std::cout << "4. Zmie� ograniczenie wiekowe: " << std::endl;
            std::cout << "5. Dodaj/Usu� z ulubionych: " << std::endl;
            std::cout << "6. Zmie� czas trwania: " << std::endl;
            std::cout << "7. Zmie� re�ysera: " << std::endl;
            std::cout << "8. Zmie� gatunek: " << std::endl;
            std::cout << std::endl;
            std::cout << "Inne - Anuluj: " << std::endl;
            std::cout << std::endl;
            std::cout << "Wyb�r: ";
            std::cin >> field;
            std::cin.ignore(256, '\n');
            switch (field) {
            case 1: {
                std::string tytul;
                std::cout << "Podaj nowy tytu�: ";
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
                std::cout << "Podaj now� ocen� (0 aby usun�� ocen�): ";
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
                std::cout << "Czy przedmiot ma by� w ulubionych? [t/N]: ";
                std::cin >> taknie;
                std::cin.ignore(256, '\n');
                if (tolower(taknie) == 't') ulubione = true;
                else ulubione = false;
                filmy.at(choice - 1).ulubione = ulubione;
                std::cout << "Zmieniono!" << std::endl;
                system("pause");
                break;
            } // weed
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
                std::cout << "Podaj nowego re�ysera filmu: ";
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
            std::cout << "Powy�szy wpis zostanie usuni�ty. Czy kontynuowa�? (1 - Tak, Reszta - Nie)" << std::endl;
            std::cout << "Wyb�r: ";
            unsigned short wybor;
            std::cin >> wybor;
            std::cin.ignore(256, '\n');
            if (wybor == 1) {
                wsk = nullptr;
                filmy.erase(filmy.begin() + (choice - 1));
            }
            break;
        }
        }
    }
    else {
    system("cls");
    std::cout << "Anulowano edycj�." << std::endl;
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
    std::cout << "Wybierz przedmiot do edycji (0 aby anulowa�): ";
    std::cin >> choice;
    std::cin.ignore(256, '\n');
    if (choice != 0 && choice <= muzyka.size()) {
        wsk = &muzyka.at(choice - 1);
        wsk->wyswietl();
        std::cout << std::endl;
        std::cout << "Co zrobi� z powy�szym przedmiotem?" << std::endl;
        std::cout << "1. Edytuj pole" << std::endl;
        std::cout << "2. Usu� przedmiot" << std::endl;
        std::cout << std::endl;
        std::cout << "0. Nic" << std::endl;
        std::cout << std::endl;
        std::cout << "Wyb�r: ";
        unsigned short int choice1;
        std::cin >> choice1;
        std::cin.ignore(256, '\n');
        switch (choice1) {
        case 1: {
            unsigned short int field;
            std::cout << "Wybierz pole do zmiany: " << std::endl;
            std::cout << "1. Zmie� tytu�: " << std::endl;
            std::cout << "2. Zmie� rok wydania: " << std::endl;
            std::cout << "3. Zmie� ocen�: " << std::endl;
            std::cout << "4. Zmie� ograniczenie wiekowe: " << std::endl;
            std::cout << "5. Dodaj/Usu� z ulubionych: " << std::endl;
            std::cout << "6. Zmie� czas trwania: " << std::endl;
            std::cout << "7. Zmie� ilo�c utwor�w: " << std::endl;
            std::cout << "8. Zmie� autora/autor�w: " << std::endl;
            std::cout << "9. Zmie� gatunek: " << std::endl;
            std::cout << std::endl;
            std::cout << "Inne - Anuluj: " << std::endl;
            std::cout << std::endl;
            std::cout << "Wyb�r: ";
            std::cin >> field;
            std::cin.ignore(256, '\n');
            switch (field) {
            case 1: {
                std::string tytul;
                std::cout << "Podaj nowy tytu�: ";
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
                std::cout << "Podaj now� ocen� (0 aby usun�� ocen�): ";
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
                std::cout << "Czy przedmiot ma by� w ulubionych? [t/N]: ";
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
                std::cout << "Podaj now� ilo�� utwor�w: ";
                std::cin >> utworow;
                std::cin.ignore(256, '\n');
                muzyka.at(choice - 1).utworow = utworow;
                std::cout << "Zmieniono!" << std::endl;
                system("pause");
                break;
            }
            case 8: {
                std::string autor;
                std::cout << "Podaj nowego autora/autor�w albumu: ";
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
            std::cout << "Powy�szy wpis zostanie usuni�ty. Czy kontynuowa�? (1 - Tak, Reszta - Nie)" << std::endl;
            std::cout << "Wyb�r: ";
            unsigned short wybor;
            std::cin >> wybor;
            std::cin.ignore(256, '\n');
            if (wybor == 1) {
                wsk = nullptr;
                muzyka.erase(muzyka.begin() + (choice - 1));
            }
            break;
        }
        }
    }
    else {
    system("cls");
    std::cout << "Anulowano edycj�." << std::endl;
    system("pause");
}
}

void szukajKsiazki(std::vector<Ksiazka>& ksiazki) {
    Utwor* wsk;
    std::cout << "Opcje wyszukiwania ksi��ki: " << std::endl;
    std::cout << std::endl;
    std::cout << "1. Szukaj po tytule." << std::endl;
    std::cout << "2. Szukaj po autorze." << std::endl;
    std::cout << "3. Szukaj po wydawnictwie." << std::endl;
    std::cout << "4. Szukaj po gatunku." << std::endl;
    std::cout << "5. Szukaj po roku wydania." << std::endl;
    std::cout << "6. Szukaj po ilo�ci stron." << std::endl;
    std::cout << "7. Szukaj po ograniczeniu wiekowym." << std::endl;
    std::cout << "8. Szukaj po ocenie." << std::endl;
    std::cout << std::endl;
    std::cout << "0. Anuluj wyszukiwanie." << std::endl;
    std::cout << std::endl;
    std::cout << "Wyb�r: ";
    unsigned short choice;
    std::cin >> choice;
    std::cin.ignore(256, '\n');
    system("cls");
    switch (choice) {
        case 1: {
            std::string tytul;
            std::cout << "Podaj tytu� ksi��ki do znalezienia: ";
            std::getline(std::cin, tytul);
            std::cout << "Wyniki wyszukiwania: " << std::endl;
            unsigned short results = 0;
            for (unsigned int i = 0; i < ksiazki.size(); i++) {
                if (ksiazki.at(i).tytul.find(tytul) != std::string::npos) {
                    wsk = &ksiazki.at(i);
                    std::cout << std::endl;
                    wsk->wyswietl();
                    results++;
                }
            }
            std::cout << "Koniec wyszukiwania - " << results << " wynik�w" << std::endl;
            system("pause");
            break;
        }
        case 2: {
            std::string autor;
            std::cout << "Podaj autora, kt�rego ksi��ki chcesz wyszuka�: ";
            std::getline(std::cin, autor);
            std::cout << "Wyniki wyszukiwania: " << std::endl;
            unsigned short results = 0;
            for (unsigned int i = 0; i < ksiazki.size(); i++) {
                if (ksiazki.at(i).autor.find(autor) != std::string::npos) {
                    wsk = &ksiazki.at(i);
                    std::cout << std::endl;
                    wsk->wyswietl();
                    results++;
                }
            }
            std::cout << "Koniec wyszukiwania - " << results << " wynik�w"<< std::endl;
            system("pause");
            break;
        }
        case 3: {
            std::string wydawnictwo;
            std::cout << "Podaj wydawnictwo, od kt�rego ksi��ki chcesz wyszuka�: ";
            std::getline(std::cin, wydawnictwo);
            std::cout << "Wyniki wyszukiwania: " << std::endl;
            unsigned short results = 0;
            for (unsigned int i = 0; i < ksiazki.size(); i++) {
                if (ksiazki.at(i).wydawnictwo.find(wydawnictwo) != std::string::npos) {
                    wsk = &ksiazki.at(i);
                    std::cout << std::endl;
                    wsk->wyswietl();
                    results++;
                }
            }
            std::cout << "Koniec wyszukiwania - " << results << " wynik�w" << std::endl;
            system("pause");
            break;
        }
        case 4: {
            std::string gatunek;
            std::cout << "Podaj gatunek ksi��ek, kt�rych chcesz wyszuka�: ";
            std::getline(std::cin, gatunek);
            std::cout << "Wyniki wyszukiwania: " << std::endl;
            unsigned short results = 0;
            for (unsigned int i = 0; i < ksiazki.size(); i++) {
                if (ksiazki.at(i).gatunek.find(gatunek) != std::string::npos) {
                    wsk = &ksiazki.at(i);
                    std::cout << std::endl;
                    wsk->wyswietl();
                    results++;
                }
            }
            std::cout << "Koniec wyszukiwania - " << results << " wynik�w" << std::endl;
            system("pause");
            break;
        }
        case 5: {
            std::cout << "W jaki spos�b wyszuka� po roku wydania?" << std::endl;
            std::cout << std::endl;
            std::cout << "1. Wyszukaj po ksi��kach wydanych w podanym roku" << std::endl;
            std::cout << "2. Wyszukaj ksi��ki starsze i wydane w podanym roku" << std::endl;
            std::cout << "3. Wyszukaj ksi��ki nowsze i wydawne w podanym roku" << std::endl;
            std::cout << "4. Wyszukaj ksi��ki wydane w przedziale podanych lat" << std::endl;
            std::cout << std::endl;
            std::cout << "0. Anuluj" << std::endl;
            std::cout << std::endl;
            std::cout << "Wyb�r: ";
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
                    unsigned short results = 0;
                    for (unsigned int i = 0; i < ksiazki.size(); i++) {
                        if (ksiazki.at(i).rok_wydania == rok_wydania) {
                            wsk = &ksiazki.at(i);
                            std::cout << std::endl;
                            wsk->wyswietl();
                            results++;
                        }
                    }
                    std::cout << "Koniec wyszukiwania - " << results << " wynik�w" << std::endl;
                    system("pause");
                    break;
                }
                case 2: {
                    unsigned short rok_wydania;
                    std::cout << "Podaj rok wydania [wydane przed i w]: ";
                    std::cin >> rok_wydania;
                    std::cin.ignore(256, '\n');
                    std::cout << "Wyniki wyszukiwania: " << std::endl;
                    unsigned short results = 0;
                    for (unsigned int i = 0; i < ksiazki.size(); i++) {
                        if (ksiazki.at(i).rok_wydania <= rok_wydania) {
                            wsk = &ksiazki.at(i);
                            std::cout << std::endl;
                            wsk->wyswietl();
                            results++;
                        }
                    }
                    std::cout << "Koniec wyszukiwania - " << results << " wynik�w" << std::endl;
                    system("pause");
                    break;
                }
                case 3: {
                    unsigned short rok_wydania;
                    std::cout << "Podaj rok wydania [wydane w i po]: ";
                    std::cin >> rok_wydania;
                    std::cin.ignore(256, '\n');
                    std::cout << "Wyniki wyszukiwania: " << std::endl;
                    unsigned short results = 0;
                    for (unsigned int i = 0; i < ksiazki.size(); i++) {
                        if (ksiazki.at(i).rok_wydania >= rok_wydania) {
                            wsk = &ksiazki.at(i);
                            std::cout << std::endl;
                            wsk->wyswietl();
                            results++;
                        }
                    }
                    std::cout << "Koniec wyszukiwania - " << results << " wynik�w" << std::endl;
                    system("pause");
                    break;
                }
                case 4: {
                    unsigned short rok_wydania1, rok_wydania2;
                    std::cout << "Podaj pocz�tek przedzia�u (domkni�ty): ";
                    std::cin >> rok_wydania1;
                    std::cin.ignore(256, '\n');
                    std::cout << "Podaj koniec przedzia�u (domkni�ty): ";
                    std::cin >> rok_wydania2;
                    std::cin.ignore(256, '\n');
                    unsigned short results = 0;
                    for (unsigned int i = 0; i < ksiazki.size(); i++) {
                        if (ksiazki.at(i).rok_wydania >= rok_wydania1 && ksiazki.at(i).rok_wydania <= rok_wydania2) {
                            wsk = &ksiazki.at(i);
                            std::cout << std::endl;
                            wsk->wyswietl();
                            results++;
                        }
                    }
                    std::cout << "Koniec wyszukiwania - " << results << " wynik�w" << std::endl;
                    system("pause");
                    break;
                }
            }
            break;
        }
        case 6: {
            std::cout << "W jaki spos�b wyszuka� po ilo�ci stron?" << std::endl;
            std::cout << std::endl;
            std::cout << "1. Wyszukaj po ksi��kach maj�cych dok�adnie tyle stron" << std::endl;
            std::cout << "2. Wyszukaj ksi��ki maj�ce tyle b�d� mniej stron" << std::endl;
            std::cout << "3. Wyszukaj ksi��ki maj�ce tyle b�d� wi�cej stron" << std::endl;
            std::cout << "4. Wyszukaj ksi��ki maj�ce ilo�� stron w podanym przedziale" << std::endl;
            std::cout << std::endl;
            std::cout << "0. Anuluj" << std::endl;
            std::cout << std::endl;
            std::cout << "Wyb�r: ";
            unsigned short choice1;
            std::cin >> choice1;
            std::cin.ignore(256, '\n');
            system("cls");
            switch (choice1) {
            case 1: {
                unsigned short strony;
                std::cout << "Podaj ilo�� stron [dok�adnie ile]: ";
                std::cin >> strony;
                std::cin.ignore(256, '\n');
                std::cout << "Wyniki wyszukiwania: " << std::endl;
                unsigned short results = 0;
                for (unsigned int i = 0; i < ksiazki.size(); i++) {
                    if (ksiazki.at(i).strony == strony) {
                        wsk = &ksiazki.at(i);
                        std::cout << std::endl;
                        wsk->wyswietl();
                        results++;
                    }
                }
                std::cout << "Koniec wyszukiwania - " << results << " wynik�w" << std::endl;
                system("pause");
                break;
            }
            case 2: {
                unsigned short strony;
                std::cout << "Podaj ilo�� stron [tyle lub mniej]: ";
                std::cin >> strony;
                std::cin.ignore(256, '\n');
                std::cout << "Wyniki wyszukiwania: " << std::endl;
                unsigned short results = 0;
                for (unsigned int i = 0; i < ksiazki.size(); i++) {
                    if (ksiazki.at(i).strony <= strony) {
                        wsk = &ksiazki.at(i);
                        std::cout << std::endl;
                        wsk->wyswietl();
                        results++;
                    }
                }
                std::cout << "Koniec wyszukiwania - " << results << " wynik�w" << std::endl;
                system("pause");
                break;
            }
            case 3: {
                unsigned short strony;
                std::cout << "Podaj ilo�� stron [tyle lub wi�cej]: ";
                std::cin >> strony;
                std::cin.ignore(256, '\n');
                std::cout << "Wyniki wyszukiwania: " << std::endl;
                unsigned short results = 0;
                for (unsigned int i = 0; i < ksiazki.size(); i++) {
                    if (ksiazki.at(i).strony >= strony) {
                        wsk = &ksiazki.at(i);
                        std::cout << std::endl;
                        wsk->wyswietl();
                        results++;
                    }
                }
                std::cout << "Koniec wyszukiwania - " << results << " wynik�w" << std::endl;
                system("pause");
                break;
            }
            case 4: {
                unsigned short strony1, strony2;
                std::cout << "Podaj pocz�tek przedzia�u (domkni�ty): ";
                std::cin >> strony1;
                std::cin.ignore(256, '\n');
                std::cout << "Podaj koniec przedzia�u (domkni�ty): ";
                std::cin >> strony2;
                std::cin.ignore(256, '\n');
                unsigned short results = 0;
                for (unsigned int i = 0; i < ksiazki.size(); i++) {
                    if (ksiazki.at(i).strony >= strony1 && ksiazki.at(i).strony <= strony2) {
                        wsk = &ksiazki.at(i);
                        std::cout << std::endl;
                        wsk->wyswietl();
                        results++;
                    }
                }
                std::cout << "Koniec wyszukiwania - " << results << " wynik�w" << std::endl;
                system("pause");
                break;
            }
            }
            break;
        }
        case 7: {
            unsigned short min_wiek;
            std::cout << "Podaj wiek, dla kt�rego znale�� odpowiednie ksi��ki: " << std::endl;
            std::cin >> min_wiek;
            std::cin.ignore(256, '\n');
            unsigned short results = 0;
            for (unsigned int i = 0; i < ksiazki.size(); i++) {
                if (ksiazki.at(i).min_wiek <= min_wiek) {
                    wsk = &ksiazki.at(i);
                    std::cout << std::endl;
                    wsk->wyswietl();
                    results++;
                }
            }
            std::cout << "Koniec wyszukiwania - " << results << " wynik�w" << std::endl;
            system("pause");
            break;
        }
        case 8: {
            std::cout << "Wyszuka� po jakich ocenach?" << std::endl;
            std::cout << std::endl;
            std::cout << "1. Wyszukaj ksi��ki o dok�adnie takiej ocenie" << std::endl;
            std::cout << "2. Wyszukaj ksi��ki o gorszej lub takiej samej ocenie" << std::endl;
            std::cout << "3. Wyszukaj ksi��ki o lepszej lub takiej samej ocenie" << std::endl;
            std::cout << "4. Wyszukaj ksi��ki w podanym przedziale ocen" << std::endl;
            std::cout << "5. Wyszukaj ksi��ki jeszcze nie ocenione" << std::endl;
            std::cout << std::endl;
            std::cout << "0. Anuluj" << std::endl;
            std::cout << std::endl;
            std::cout << "Wyb�r: ";
            unsigned short choice1;
            std::cin >> choice1;
            std::cin.ignore(256, '\n');
            system("cls");
            switch (choice1) {
            case 1: {
                double ocena;
                std::cout << "Podaj ocen� [dok�adnie tak�]: ";
                std::cin >> ocena;
                std::cin.ignore(256, '\n');
                std::cout << "Wyniki wyszukiwania: " << std::endl;
                unsigned short results = 0;
                for (unsigned int i = 0; i < ksiazki.size(); i++) {
                    if (ksiazki.at(i).ocena == ocena && ksiazki.at(i).ocena!=0) {
                        wsk = &ksiazki.at(i);
                        std::cout << std::endl;
                        wsk->wyswietl();
                        results++;
                    }
                }
                std::cout << "Koniec wyszukiwania - " << results << " wynik�w" << std::endl;
                system("pause");
                break;
            }
            case 2: {
                double ocena;
                std::cout << "Podaj ocen� [gorsz� lub r�wn�]: ";
                std::cin >> ocena;
                std::cin.ignore(256, '\n');
                std::cout << "Wyniki wyszukiwania: " << std::endl;
                unsigned short results = 0;
                for (unsigned int i = 0; i < ksiazki.size(); i++) {
                    if (ksiazki.at(i).ocena <= ocena && ksiazki.at(i).ocena != 0) {
                        wsk = &ksiazki.at(i);
                        std::cout << std::endl;
                        wsk->wyswietl();
                        results++;
                    }
                }
                std::cout << "Koniec wyszukiwania - " << results << " wynik�w" << std::endl;
                system("pause");
                break;
            }
            case 3: {
                double ocena;
                std::cout << "Podaj ocen� [lepsz� lub r�wn�]: ";
                std::cin >> ocena;
                std::cin.ignore(256, '\n');
                std::cout << "Wyniki wyszukiwania: " << std::endl;
                unsigned short results = 0;
                for (unsigned int i = 0; i < ksiazki.size(); i++) {
                    if (ksiazki.at(i).ocena >= ocena && ksiazki.at(i).ocena != 0) {
                        wsk = &ksiazki.at(i);
                        std::cout << std::endl;
                        wsk->wyswietl();
                        results++;
                    }
                }
                std::cout << "Koniec wyszukiwania - " << results << " wynik�w" << std::endl;
                system("pause");
                break;
            }
            case 4: {
                double ocena1, ocena2;
                std::cout << "Podaj pocz�tek przedzia�u (domkni�ty): ";
                std::cin >> ocena1;
                std::cin.ignore(256, '\n');
                std::cout << "Podaj koniec przedzia�u (domkni�ty): ";
                std::cin >> ocena2;
                std::cin.ignore(256, '\n');
                unsigned short results = 0;
                for (unsigned int i = 0; i < ksiazki.size(); i++) {
                    if (ksiazki.at(i).ocena >= ocena1 && ksiazki.at(i).ocena <= ocena2 && ksiazki.at(i).ocena != 0) {
                        wsk = &ksiazki.at(i);
                        std::cout << std::endl;
                        wsk->wyswietl();
                        results++;
                    }
                }
                std::cout << "Koniec wyszukiwania - " << results << " wynik�w" << std::endl;
                system("pause");
                break;
            }
            case 5: {
                unsigned short results = 0;
                for (unsigned int i = 0; i < ksiazki.size(); i++) {
                    if (ksiazki.at(i).ocena==0) {
                        wsk = &ksiazki.at(i);
                        std::cout << std::endl;
                        wsk->wyswietl();
                        results++;
                    }
                }
                std::cout << "Koniec wyszukiwania - " << results << " wynik�w" << std::endl;
                system("pause");
                break;
            }
            }
            break;
        }
    }
}

void szukajFilmu(std::vector<Film>& filmy) {
    Utwor* wsk;
    std::cout << "Opcje wyszukiwania: " << std::endl;
    std::cout << std::endl;
    std::cout << "1. Szukaj po tytule." << std::endl;
    std::cout << "2. Szukaj po re�yserze." << std::endl;
    std::cout << "3. Szukaj po gatunku." << std::endl;
    std::cout << "4. Szukaj po roku wydania." << std::endl;
    std::cout << "5. Szukaj po czasie trwania." << std::endl;
    std::cout << "6. Szukaj po ograniczeniu wiekowym." << std::endl;
    std::cout << "7. Szukaj po ocenie." << std::endl;
    std::cout << std::endl;
    std::cout << "0. Anuluj wyszukiwanie." << std::endl;
    std::cout << std::endl;
    std::cout << "Wyb�r: ";
    unsigned short choice;
    std::cin >> choice;
    std::cin.ignore(256, '\n');
    system("cls");
    switch (choice) {
    case 1: {
        std::string tytul;
        std::cout << "Podaj tytu� filmu do znalezienia: ";
        std::getline(std::cin, tytul);
        std::cout << "Wyniki wyszukiwania: " << std::endl;
        unsigned short results = 0;
        for (unsigned int i = 0; i < filmy.size(); i++) {
            if (filmy.at(i).tytul.find(tytul) != std::string::npos) {
                wsk = &filmy.at(i);
                std::cout << std::endl;
                wsk->wyswietl();
                results++;
            }
        }
        std::cout << "Koniec wyszukiwania - " << results << " wynik�w" << std::endl;
        system("pause");
        break;
    }
    case 2: {
        std::string rezyser;
        std::cout << "Podaj re�ysera, kt�rego filmy chcesz wyszuka�: ";
        std::getline(std::cin, rezyser);
        std::cout << "Wyniki wyszukiwania: " << std::endl;
        unsigned short results = 0;
        for (unsigned int i = 0; i < filmy.size(); i++) {
            if (filmy.at(i).rezyser.find(rezyser) != std::string::npos) {
                wsk = &filmy.at(i);
                std::cout << std::endl;
                wsk->wyswietl();
                results++;
            }
        }
        std::cout << "Koniec wyszukiwania - " << results << " wynik�w" << std::endl;
        system("pause");
        break;
    }
    case 3: {
        std::string gatunek;
        std::cout << "Podaj gatunek film�w, kt�rych chcesz wyszuka�: ";
        std::getline(std::cin, gatunek);
        std::cout << "Wyniki wyszukiwania: " << std::endl;
        unsigned short results = 0;
        for (unsigned int i = 0; i < filmy.size(); i++) {
            if (filmy.at(i).gatunek.find(gatunek) != std::string::npos) {
                wsk = &filmy.at(i);
                std::cout << std::endl;
                wsk->wyswietl();
                results++;
            }
        }
        std::cout << "Koniec wyszukiwania - " << results << " wynik�w" << std::endl;
        system("pause");
        break;
    }
    case 4: {
        std::cout << "W jaki spos�b wyszuka� po roku wydania?" << std::endl;
        std::cout << std::endl;
        std::cout << "1. Wyszukaj po filmach wydanych w podanym roku" << std::endl;
        std::cout << "2. Wyszukaj filmy starsze i wydane w podanym roku" << std::endl;
        std::cout << "3. Wyszukaj filmy nowsze i wydawne w podanym roku" << std::endl;
        std::cout << "4. Wyszukaj filmy wydane w przedziale podanych lat" << std::endl;
        std::cout << std::endl;
        std::cout << "0. Anuluj" << std::endl;
        std::cout << std::endl;
        std::cout << "Wyb�r: ";
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
            unsigned short results = 0;
            for (unsigned int i = 0; i < filmy.size(); i++) {
                if (filmy.at(i).rok_wydania == rok_wydania) {
                    wsk = &filmy.at(i);
                    std::cout << std::endl;
                    wsk->wyswietl();
                    results++;
                }
            }
            std::cout << "Koniec wyszukiwania - " << results << " wynik�w" << std::endl;
            system("pause");
            break;
        }
        case 2: {
            unsigned short rok_wydania;
            std::cout << "Podaj rok wydania [wydane przed i w]: ";
            std::cin >> rok_wydania;
            std::cin.ignore(256, '\n');
            std::cout << "Wyniki wyszukiwania: " << std::endl;
            unsigned short results = 0;
            for (unsigned int i = 0; i < filmy.size(); i++) {
                if (filmy.at(i).rok_wydania <= rok_wydania) {
                    wsk = &filmy.at(i);
                    std::cout << std::endl;
                    wsk->wyswietl();
                    results++;
                }
            }
            std::cout << "Koniec wyszukiwania - " << results << " wynik�w" << std::endl;
            system("pause");
            break;
        }
        case 3: {
            unsigned short rok_wydania;
            std::cout << "Podaj rok wydania [wydane w i po]: ";
            std::cin >> rok_wydania;
            std::cin.ignore(256, '\n');
            std::cout << "Wyniki wyszukiwania: " << std::endl;
            unsigned short results = 0;
            for (unsigned int i = 0; i < filmy.size(); i++) {
                if (filmy.at(i).rok_wydania >= rok_wydania) {
                    wsk = &filmy.at(i);
                    std::cout << std::endl;
                    wsk->wyswietl();
                    results++;
                }
            }
            std::cout << "Koniec wyszukiwania - " << results << " wynik�w" << std::endl;
            system("pause");
            break;
        }
        case 4: {
            unsigned short rok_wydania1, rok_wydania2;
            std::cout << "Podaj pocz�tek przedzia�u (domkni�ty): ";
            std::cin >> rok_wydania1;
            std::cin.ignore(256, '\n');
            std::cout << "Podaj koniec przedzia�u (domkni�ty): ";
            std::cin >> rok_wydania2;
            std::cin.ignore(256, '\n');
            unsigned short results = 0;
            for (unsigned int i = 0; i < filmy.size(); i++) {
                if (filmy.at(i).rok_wydania >= rok_wydania1 && filmy.at(i).rok_wydania <= rok_wydania2) {
                    wsk = &filmy.at(i);
                    std::cout << std::endl;
                    wsk->wyswietl();
                    results++;
                }
            }
            std::cout << "Koniec wyszukiwania - " << results << " wynik�w" << std::endl;
            system("pause");
            break;
        }
        }
        break;
    }
    case 5: {
        std::cout << "W jaki spos�b wyszuka� po czasie trwania?" << std::endl;
        std::cout << std::endl;
        std::cout << "1. Wyszukaj filmy trwaj�cyce dok�adnie tyle" << std::endl;
        std::cout << "2. Wyszukaj filmy trwaj�ce tyle b�d� kr�cej" << std::endl;
        std::cout << "3. Wyszukaj filmy trwaj�ce tyle b�d� d�u�ej" << std::endl;
        std::cout << "4. Wyszukaj filmy, kt�rych czas trwania jest w podanym przedziale" << std::endl;
        std::cout << std::endl;
        std::cout << "0. Anuluj" << std::endl;
        std::cout << std::endl;
        std::cout << "Wyb�r: ";
        unsigned short choice1;
        std::cin >> choice1;
        std::cin.ignore(256, '\n');
        system("cls");
        switch (choice1) {
        case 1: {
            unsigned short czas_trwania;
            std::cout << "Podaj czas trwania w minutach [dok�adnie ile]: ";
            std::cin >> czas_trwania;
            std::cin.ignore(256, '\n');
            std::cout << "Wyniki wyszukiwania: " << std::endl;
            unsigned short results = 0;
            for (unsigned int i = 0; i < filmy.size(); i++) {
                if (filmy.at(i).czas_trwania == czas_trwania) {
                    wsk = &filmy.at(i);
                    std::cout << std::endl;
                    wsk->wyswietl();
                    results++;
                }
            }
            std::cout << "Koniec wyszukiwania - " << results << " wynik�w" << std::endl;
            system("pause");
            break;
        }
        case 2: {
            unsigned short czas_trwania;
            std::cout << "Podaj czas trwania w minutach [tyle lub mniej]: ";
            std::cin >> czas_trwania;
            std::cin.ignore(256, '\n');
            std::cout << "Wyniki wyszukiwania: " << std::endl;
            unsigned short results = 0;
            for (unsigned int i = 0; i < filmy.size(); i++) {
                if (filmy.at(i).czas_trwania <= czas_trwania) {
                    wsk = &filmy.at(i);
                    std::cout << std::endl;
                    wsk->wyswietl();
                    results++;
                }
            }
            std::cout << "Koniec wyszukiwania - " << results << " wynik�w" << std::endl;
            system("pause");
            break;
        }
        case 3: {
            unsigned short czas_trwania;
            std::cout << "Podaj czas trwania w minutach [tyle lub wi�cej]: ";
            std::cin >> czas_trwania;
            std::cin.ignore(256, '\n');
            std::cout << "Wyniki wyszukiwania: " << std::endl;
            unsigned short results = 0;
            for (unsigned int i = 0; i < filmy.size(); i++) {
                if (filmy.at(i).czas_trwania >= czas_trwania) {
                    wsk = &filmy.at(i);
                    std::cout << std::endl;
                    wsk->wyswietl();
                    results++;
                }
            }
            std::cout << "Koniec wyszukiwania - " << results << " wynik�w" << std::endl;
            system("pause");
            break;
        }
        case 4: {
            unsigned short czas_trwania1, czas_trwania2;
            std::cout << "Podaj pocz�tek przedzia�u (domkni�ty): ";
            std::cin >> czas_trwania1;
            std::cin.ignore(256, '\n');
            std::cout << "Podaj koniec przedzia�u (domkni�ty): ";
            std::cin >> czas_trwania2;
            std::cin.ignore(256, '\n');
            unsigned short results = 0;
            for (unsigned int i = 0; i < filmy.size(); i++) {
                if (filmy.at(i).czas_trwania >= czas_trwania1 && filmy.at(i).czas_trwania <= czas_trwania2) {
                    wsk = &filmy.at(i);
                    std::cout << std::endl;
                    wsk->wyswietl();
                    results++;
                }
            }
            std::cout << "Koniec wyszukiwania - " << results << " wynik�w" << std::endl;
            system("pause");
            break;
        }
        }
        break;
    }
    case 6: {
        unsigned short min_wiek;
        std::cout << "Podaj wiek, dla kt�rego znale�� odpowiednie filmy: " << std::endl;
        std::cin >> min_wiek;
        std::cin.ignore(256, '\n');
        unsigned short results = 0;
        for (unsigned int i = 0; i < filmy.size(); i++) {
            if (filmy.at(i).min_wiek <= min_wiek) {
                wsk = &filmy.at(i);
                std::cout << std::endl;
                wsk->wyswietl();
                results++;
            }
        }
        std::cout << "Koniec wyszukiwania - " << results << " wynik�w" << std::endl;
        system("pause");
        break;
    }
    case 7: {
        std::cout << "Wyszuka� po jakich ocenach?" << std::endl;
        std::cout << std::endl;
        std::cout << "1. Wyszukaj filmy o dok�adnie takiej ocenie" << std::endl;
        std::cout << "2. Wyszukaj filmy o gorszej lub takiej samej ocenie" << std::endl;
        std::cout << "3. Wyszukaj filmy o lepszej lub takiej samej ocenie" << std::endl;
        std::cout << "4. Wyszukaj filmy w podanym przedziale ocen" << std::endl;
        std::cout << "5. Wyszukaj filmy jeszcze nie ocenione" << std::endl;
        std::cout << std::endl;
        std::cout << "0. Anuluj" << std::endl;
        std::cout << std::endl;
        std::cout << "Wyb�r: ";
        unsigned short choice1;
        std::cin >> choice1;
        std::cin.ignore(256, '\n');
        system("cls");
        switch (choice1) {
        case 1: {
            double ocena;
            std::cout << "Podaj ocen� [dok�adnie tak�]: ";
            std::cin >> ocena;
            std::cin.ignore(256, '\n');
            std::cout << "Wyniki wyszukiwania: " << std::endl;
            unsigned short results = 0;
            for (unsigned int i = 0; i < filmy.size(); i++) {
                if (filmy.at(i).ocena == ocena && filmy.at(i).ocena != 0) {
                    wsk = &filmy.at(i);
                    std::cout << std::endl;
                    wsk->wyswietl();
                    results++;
                }
            }
            std::cout << "Koniec wyszukiwania - " << results << " wynik�w" << std::endl;
            system("pause");
            break;
        }
        case 2: {
            double ocena;
            std::cout << "Podaj ocen� [gorsz� lub r�wn�]: ";
            std::cin >> ocena;
            std::cin.ignore(256, '\n');
            std::cout << "Wyniki wyszukiwania: " << std::endl;
            unsigned short results = 0;
            for (unsigned int i = 0; i < filmy.size(); i++) {
                if (filmy.at(i).ocena <= ocena && filmy.at(i).ocena != 0) {
                    wsk = &filmy.at(i);
                    std::cout << std::endl;
                    wsk->wyswietl();
                    results++;
                }
            }
            std::cout << "Koniec wyszukiwania - " << results << " wynik�w" << std::endl;
            system("pause");
            break;
        }
        case 3: {
            double ocena;
            std::cout << "Podaj ocen� [lepsz� lub r�wn�]: ";
            std::cin >> ocena;
            std::cin.ignore(256, '\n');
            std::cout << "Wyniki wyszukiwania: " << std::endl;
            unsigned short results = 0;
            for (unsigned int i = 0; i < filmy.size(); i++) {
                if (filmy.at(i).ocena >= ocena && filmy.at(i).ocena != 0) {
                    wsk = &filmy.at(i);
                    std::cout << std::endl;
                    wsk->wyswietl();
                    results++;
                }
            }
            std::cout << "Koniec wyszukiwania - " << results << " wynik�w" << std::endl;
            system("pause");
            break;
        }
        case 4: {
            double ocena1, ocena2;
            std::cout << "Podaj pocz�tek przedzia�u (domkni�ty): ";
            std::cin >> ocena1;
            std::cin.ignore(256, '\n');
            std::cout << "Podaj koniec przedzia�u (domkni�ty): ";
            std::cin >> ocena2;
            std::cin.ignore(256, '\n');
            unsigned short results = 0;
            for (unsigned int i = 0; i < filmy.size(); i++) {
                if (filmy.at(i).ocena >= ocena1 && filmy.at(i).ocena <= ocena2 && filmy.at(i).ocena != 0) {
                    wsk = &filmy.at(i);
                    std::cout << std::endl;
                    wsk->wyswietl();
                    results++;
                }
            }
            std::cout << "Koniec wyszukiwania - " << results << " wynik�w" << std::endl;
            system("pause");
            break;
        }
        case 5: {
            unsigned short results = 0;
            for (unsigned int i = 0; i < filmy.size(); i++) {
                if (filmy.at(i).ocena == 0) {
                    wsk = &filmy.at(i);
                    std::cout << std::endl;
                    wsk->wyswietl();
                    results++;
                }
            }
            std::cout << "Koniec wyszukiwania - " << results << " wynik�w" << std::endl;
            system("pause");
            break;
        }
        }
        break;
    }
    }
}

void szukajAlbumuMuzycznego(std::vector<Album_muzyczny>& muzyka) {
    Utwor* wsk;
    std::cout << "Opcje wyszukiwania: " << std::endl;
    std::cout << std::endl;
    std::cout << "1. Szukaj po tytule." << std::endl;
    std::cout << "2. Szukaj po autorze." << std::endl;
    std::cout << "3. Szukaj po gatunku." << std::endl;
    std::cout << "4. Szukaj po roku wydania." << std::endl;
    std::cout << "5. Szukaj po czasie trwania." << std::endl;
    std::cout << "6. Szukaj po ilo�ci utwor�w." << std::endl;
    std::cout << "7. Szukaj po ograniczeniu wiekowym." << std::endl;
    std::cout << "8. Szukaj po ocenie." << std::endl;
    std::cout << std::endl;
    std::cout << "0. Anuluj wyszukiwanie." << std::endl;
    std::cout << std::endl;
    std::cout << "Wyb�r: ";
    unsigned short choice;
    std::cin >> choice;
    std::cin.ignore(256, '\n');
    system("cls");
    switch (choice) {
    case 1: {
        std::string tytul;
        std::cout << "Podaj tytu� albumu muzycznego do znalezienia: ";
        std::getline(std::cin, tytul);
        std::cout << "Wyniki wyszukiwania: " << std::endl;
        unsigned short results = 0;
        for (unsigned int i = 0; i < muzyka.size(); i++) {
            if (muzyka.at(i).tytul.find(tytul) != std::string::npos) {
                wsk = &muzyka.at(i);
                std::cout << std::endl;
                wsk->wyswietl();
                results++;
            }
        }
        std::cout << "Koniec wyszukiwania - " << results << " wynik�w" << std::endl;
        system("pause");
        break;
    }
    case 2: {
        std::string autor;
        std::cout << "Podaj autora, kt�rego album muzyczny chcesz wyszuka�: ";
        std::getline(std::cin, autor);
        std::cout << "Wyniki wyszukiwania: " << std::endl;
        unsigned short results = 0;
        for (unsigned int i = 0; i < muzyka.size(); i++) {
            if (muzyka.at(i).autor.find(autor) != std::string::npos) {
                wsk = &muzyka.at(i);
                std::cout << std::endl;
                wsk->wyswietl();
                results++;
            }
        }
        std::cout << "Koniec wyszukiwania - " << results << " wynik�w" << std::endl;
        system("pause");
        break;
    }
    case 3: {
        std::string gatunek;
        std::cout << "Podaj gatunek muzyczny, kt�rego chcesz wyszuka�: ";
        std::getline(std::cin, gatunek);
        std::cout << "Wyniki wyszukiwania: " << std::endl;
        unsigned short results = 0;
        for (unsigned int i = 0; i < muzyka.size(); i++) {
            if (muzyka.at(i).gatunek.find(gatunek) != std::string::npos) {
                wsk = &muzyka.at(i);
                std::cout << std::endl;
                wsk->wyswietl();
                results++;
            }
        }
        std::cout << "Koniec wyszukiwania - " << results << " wynik�w" << std::endl;
        system("pause");
        break;
    }
    case 4: {
        std::cout << "W jaki spos�b wyszuka� po roku wydania?" << std::endl;
        std::cout << std::endl;
        std::cout << "1. Wyszukaj po albumach wydanych w podanym roku" << std::endl;
        std::cout << "2. Wyszukaj albumy starsze i wydane w podanym roku" << std::endl;
        std::cout << "3. Wyszukaj albumy nowsze i wydawne w podanym roku" << std::endl;
        std::cout << "4. Wyszukaj albumy wydane w przedziale podanych lat" << std::endl;
        std::cout << std::endl;
        std::cout << "0. Anuluj" << std::endl;
        std::cout << std::endl;
        std::cout << "Wyb�r: ";
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
            unsigned short results = 0;
            for (unsigned int i = 0; i < muzyka.size(); i++) {
                if (muzyka.at(i).rok_wydania == rok_wydania) {
                    wsk = &muzyka.at(i);
                    std::cout << std::endl;
                    wsk->wyswietl();
                    results++;
                }
            }
            std::cout << "Koniec wyszukiwania - " << results << " wynik�w" << std::endl;
            system("pause");
            break;
        }
        case 2: {
            unsigned short rok_wydania;
            std::cout << "Podaj rok wydania [wydane przed i w]: ";
            std::cin >> rok_wydania;
            std::cin.ignore(256, '\n');
            std::cout << "Wyniki wyszukiwania: " << std::endl;
            unsigned short results = 0;
            for (unsigned int i = 0; i < muzyka.size(); i++) {
                if (muzyka.at(i).rok_wydania <= rok_wydania) {
                    wsk = &muzyka.at(i);
                    std::cout << std::endl;
                    wsk->wyswietl();
                    results++;
                }
            }
            std::cout << "Koniec wyszukiwania - " << results << " wynik�w" << std::endl;
            system("pause");
            break;
        }
        case 3: {
            unsigned short rok_wydania;
            std::cout << "Podaj rok wydania [wydane w i po]: ";
            std::cin >> rok_wydania;
            std::cin.ignore(256, '\n');
            std::cout << "Wyniki wyszukiwania: " << std::endl;
            unsigned short results = 0;
            for (unsigned int i = 0; i < muzyka.size(); i++) {
                if (muzyka.at(i).rok_wydania >= rok_wydania) {
                    wsk = &muzyka.at(i);
                    std::cout << std::endl;
                    wsk->wyswietl();
                    results++;
                }
            }
            std::cout << "Koniec wyszukiwania - " << results << " wynik�w" << std::endl;
            system("pause");
            break;
        }
        case 4: {
            unsigned short rok_wydania1, rok_wydania2;
            std::cout << "Podaj pocz�tek przedzia�u (domkni�ty): ";
            std::cin >> rok_wydania1;
            std::cin.ignore(256, '\n');
            std::cout << "Podaj koniec przedzia�u (domkni�ty): ";
            std::cin >> rok_wydania2;
            std::cin.ignore(256, '\n');
            unsigned short results = 0;
            for (unsigned int i = 0; i < muzyka.size(); i++) {
                if (muzyka.at(i).rok_wydania >= rok_wydania1 && muzyka.at(i).rok_wydania <= rok_wydania2) {
                    wsk = &muzyka.at(i);
                    std::cout << std::endl;
                    wsk->wyswietl();
                    results++;
                }
            }
            std::cout << "Koniec wyszukiwania - " << results << " wynik�w" << std::endl;
            system("pause");
            break;
        }
        }
        break;
    }
    case 5: {
        std::cout << "W jaki spos�b wyszuka� po czasie trwania?" << std::endl;
        std::cout << std::endl;
        std::cout << "1. Wyszukaj albumy trwaj�cyce dok�adnie tyle" << std::endl;
        std::cout << "2. Wyszukaj albumy trwaj�ce tyle b�d� kr�cej" << std::endl;
        std::cout << "3. Wyszukaj albumy trwaj�ce tyle b�d� d�u�ej" << std::endl;
        std::cout << "4. Wyszukaj albumy, kt�rych czas trwania jest w podanym przedziale" << std::endl;
        std::cout << std::endl;
        std::cout << "0. Anuluj" << std::endl;
        std::cout << std::endl;
        std::cout << "Wyb�r: ";
        unsigned short choice1;
        std::cin >> choice1;
        std::cin.ignore(256, '\n');
        system("cls");
        switch (choice1) {
        case 1: {
            unsigned short czas_trwania;
            std::cout << "Podaj czas trwania w minutach [dok�adnie ile]: ";
            std::cin >> czas_trwania;
            std::cin.ignore(256, '\n');
            std::cout << "Wyniki wyszukiwania: " << std::endl;
            unsigned short results = 0;
            for (unsigned int i = 0; i < muzyka.size(); i++) {
                if (muzyka.at(i).czas_trwania == czas_trwania) {
                    wsk = &muzyka.at(i);
                    std::cout << std::endl;
                    wsk->wyswietl();
                    results++;
                }
            }
            std::cout << "Koniec wyszukiwania - " << results << " wynik�w" << std::endl;
            system("pause");
            break;
        }
        case 2: {
            unsigned short czas_trwania;
            std::cout << "Podaj czas trwania w minutach [tyle lub mniej]: ";
            std::cin >> czas_trwania;
            std::cin.ignore(256, '\n');
            std::cout << "Wyniki wyszukiwania: " << std::endl;
            unsigned short results = 0;
            for (unsigned int i = 0; i < muzyka.size(); i++) {
                if (muzyka.at(i).czas_trwania <= czas_trwania) {
                    wsk = &muzyka.at(i);
                    std::cout << std::endl;
                    wsk->wyswietl();
                    results++;
                }
            }
            std::cout << "Koniec wyszukiwania - " << results << " wynik�w" << std::endl;
            system("pause");
            break;
        }
        case 3: {
            unsigned short czas_trwania;
            std::cout << "Podaj czas trwania w minutach [tyle lub wi�cej]: ";
            std::cin >> czas_trwania;
            std::cin.ignore(256, '\n');
            std::cout << "Wyniki wyszukiwania: " << std::endl;
            unsigned short results = 0;
            for (unsigned int i = 0; i < muzyka.size(); i++) {
                if (muzyka.at(i).czas_trwania >= czas_trwania) {
                    wsk = &muzyka.at(i);
                    std::cout << std::endl;
                    wsk->wyswietl();
                    results++;
                }
            }
            std::cout << "Koniec wyszukiwania - " << results << " wynik�w" << std::endl;
            system("pause");
            break;
        }
        case 4: {
            unsigned short czas_trwania1, czas_trwania2;
            std::cout << "Podaj pocz�tek przedzia�u (domkni�ty): ";
            std::cin >> czas_trwania1;
            std::cin.ignore(256, '\n');
            std::cout << "Podaj koniec przedzia�u (domkni�ty): ";
            std::cin >> czas_trwania2;
            std::cin.ignore(256, '\n');
            unsigned short results = 0;
            for (unsigned int i = 0; i < muzyka.size(); i++) {
                if (muzyka.at(i).czas_trwania >= czas_trwania1 && muzyka.at(i).czas_trwania <= czas_trwania2) {
                    wsk = &muzyka.at(i);
                    std::cout << std::endl;
                    wsk->wyswietl();
                    results++;
                }
            }
            std::cout << "Koniec wyszukiwania - " << results << " wynik�w" << std::endl;
            system("pause");
            break;
        }
        }
        break;
    }
    case 6: {
        std::cout << "W jaki spos�b wyszuka� po ilo�ci utwor�w?" << std::endl;
        std::cout << std::endl;
        std::cout << "1. Wyszukaj albumy, kt�re maj� dok�adnie tyle utwor�w" << std::endl;
        std::cout << "2. Wyszukaj albumy, kt�re maj� tyle b�d� mniej utwor�w" << std::endl;
        std::cout << "3. Wyszukaj albumy, kt�re maj� tyle bad� wi�cej utwor�w" << std::endl;
        std::cout << "4. Wyszukaj albumy, kt�rych ilo�� utwor�w jest w podanym przedziale" << std::endl;
        std::cout << std::endl;
        std::cout << "0. Anuluj" << std::endl;
        std::cout << std::endl;
        std::cout << "Wyb�r: ";
        unsigned short choice1;
        std::cin >> choice1;
        std::cin.ignore(256, '\n');
        system("cls");
        switch (choice1) {
        case 1: {
            unsigned short utworow;
            std::cout << "Podaj ilo�� utwor�w [dok�adnie ile]: ";
            std::cin >> utworow;
            std::cin.ignore(256, '\n');
            std::cout << "Wyniki wyszukiwania: " << std::endl;
            unsigned short results = 0;
            for (unsigned int i = 0; i < muzyka.size(); i++) {
                if (muzyka.at(i).utworow == utworow) {
                    wsk = &muzyka.at(i);
                    std::cout << std::endl;
                    wsk->wyswietl();
                    results++;
                }
            }
            std::cout << "Koniec wyszukiwania - " << results << " wynik�w" << std::endl;
            system("pause");
            break;
        }
        case 2: {
            unsigned short utworow;
            std::cout << "Podaj ilo�� utwor�w [tyle lub mniej]: ";
            std::cin >> utworow;
            std::cin.ignore(256, '\n');
            std::cout << "Wyniki wyszukiwania: " << std::endl;
            unsigned short results = 0;
            for (unsigned int i = 0; i < muzyka.size(); i++) {
                if (muzyka.at(i).utworow <= utworow) {
                    wsk = &muzyka.at(i);
                    std::cout << std::endl;
                    wsk->wyswietl();
                    results++;
                }
            }
            std::cout << "Koniec wyszukiwania - " << results << " wynik�w" << std::endl;
            system("pause");
            break;
        }
        case 3: {
            unsigned short utworow;
            std::cout << "Podaj ilo�� utwor�w [tyle lub wi�cej]: ";
            std::cin >> utworow;
            std::cin.ignore(256, '\n');
            std::cout << "Wyniki wyszukiwania: " << std::endl;
            unsigned short results = 0;
            for (unsigned int i = 0; i < muzyka.size(); i++) {
                if (muzyka.at(i).utworow >= utworow) {
                    wsk = &muzyka.at(i);
                    std::cout << std::endl;
                    wsk->wyswietl();
                    results++;
                }
            }
            std::cout << "Koniec wyszukiwania - " << results << " wynik�w" << std::endl;
            system("pause");
            break;
        }
        case 4: {
            unsigned short utworow1, utworow2;
            std::cout << "Podaj pocz�tek przedzia�u (domkni�ty): ";
            std::cin >> utworow1;
            std::cin.ignore(256, '\n');
            std::cout << "Podaj koniec przedzia�u (domkni�ty): ";
            std::cin >> utworow2;
            std::cin.ignore(256, '\n');
            unsigned short results = 0;
            for (unsigned int i = 0; i < muzyka.size(); i++) {
                if (muzyka.at(i).utworow >= utworow1 && muzyka.at(i).utworow <= utworow2) {
                    wsk = &muzyka.at(i);
                    std::cout << std::endl;
                    wsk->wyswietl();
                    results++;
                }
            }
            std::cout << "Koniec wyszukiwania - " << results << " wynik�w" << std::endl;
            system("pause");
            break;
        }
        }
        break;
    }
    case 7: {
        unsigned short min_wiek;
        std::cout << "Podaj wiek, dla kt�rego znale�� odpowiednie albumy muzyczne: " << std::endl;
        std::cin >> min_wiek;
        std::cin.ignore(256, '\n');
        unsigned short results = 0;
        for (unsigned int i = 0; i < muzyka.size(); i++) {
            if (muzyka.at(i).min_wiek <= min_wiek) {
                wsk = &muzyka.at(i);
                std::cout << std::endl;
                wsk->wyswietl();
                results++;
            }
        }
        std::cout << "Koniec wyszukiwania - " << results << " wynik�w" << std::endl;
        system("pause");
        break;
    }
    case 8: {
        std::cout << "Wyszuka� po jakich ocenach?" << std::endl;
        std::cout << std::endl;
        std::cout << "1. Wyszukaj albumy o dok�adnie takiej ocenie" << std::endl;
        std::cout << "2. Wyszukaj albumy o gorszej lub takiej samej ocenie" << std::endl;
        std::cout << "3. Wyszukaj albumy o lepszej lub takiej samej ocenie" << std::endl;
        std::cout << "4. Wyszukaj albumy w podanym przedziale ocen" << std::endl;
        std::cout << "5. Wyszukaj albumy jeszcze nie ocenione" << std::endl;
        std::cout << std::endl;
        std::cout << "0. Anuluj" << std::endl;
        std::cout << std::endl;
        std::cout << "Wyb�r: ";
        unsigned short choice1;
        std::cin >> choice1;
        std::cin.ignore(256, '\n');
        system("cls");
        switch (choice1) {
        case 1: {
            double ocena;
            std::cout << "Podaj ocen� [dok�adnie tak�]: ";
            std::cin >> ocena;
            std::cin.ignore(256, '\n');
            std::cout << "Wyniki wyszukiwania: " << std::endl;
            unsigned short results = 0;
            for (unsigned int i = 0; i < muzyka.size(); i++) {
                if (muzyka.at(i).ocena == ocena && muzyka.at(i).ocena != 0) {
                    wsk = &muzyka.at(i);
                    std::cout << std::endl;
                    wsk->wyswietl();
                    results++;
                }
            }
            std::cout << "Koniec wyszukiwania - " << results << " wynik�w" << std::endl;
            system("pause");
            break;
        }
        case 2: {
            double ocena;
            std::cout << "Podaj ocen� [gorsz� lub r�wn�]: ";
            std::cin >> ocena;
            std::cin.ignore(256, '\n');
            std::cout << "Wyniki wyszukiwania: " << std::endl;
            unsigned short results = 0;
            for (unsigned int i = 0; i < muzyka.size(); i++) {
                if (muzyka.at(i).ocena <= ocena && muzyka.at(i).ocena != 0) {
                    wsk = &muzyka.at(i);
                    std::cout << std::endl;
                    wsk->wyswietl();
                    results++;
                }
            }
            std::cout << "Koniec wyszukiwania - " << results << " wynik�w" << std::endl;
            system("pause");
            break;
        }
        case 3: {
            double ocena;
            std::cout << "Podaj ocen� [lepsz� lub r�wn�]: ";
            std::cin >> ocena;
            std::cin.ignore(256, '\n');
            std::cout << "Wyniki wyszukiwania: " << std::endl;
            unsigned short results = 0;
            for (unsigned int i = 0; i < muzyka.size(); i++) {
                if (muzyka.at(i).ocena >= ocena && muzyka.at(i).ocena != 0) {
                    wsk = &muzyka.at(i);
                    std::cout << std::endl;
                    wsk->wyswietl();
                    results++;
                }
            }
            std::cout << "Koniec wyszukiwania - " << results << " wynik�w" << std::endl;
            system("pause");
            break;
        }
        case 4: {
            double ocena1, ocena2;
            std::cout << "Podaj pocz�tek przedzia�u (domkni�ty): ";
            std::cin >> ocena1;
            std::cin.ignore(256, '\n');
            std::cout << "Podaj koniec przedzia�u (domkni�ty): ";
            std::cin >> ocena2;
            std::cin.ignore(256, '\n');
            unsigned short results = 0;
            for (unsigned int i = 0; i < muzyka.size(); i++) {
                if (muzyka.at(i).ocena >= ocena1 && muzyka.at(i).ocena <= ocena2 && muzyka.at(i).ocena != 0) {
                    wsk = &muzyka.at(i);
                    std::cout << std::endl;
                    wsk->wyswietl();
                    results++;
                }
            }
            std::cout << "Koniec wyszukiwania - " << results << " wynik�w" << std::endl;
            system("pause");
            break;
        }
        case 5: {
            unsigned short results = 0;
            for (unsigned int i = 0; i < muzyka.size(); i++) {
                if (muzyka.at(i).ocena == 0) {
                    wsk = &muzyka.at(i);
                    std::cout << std::endl;
                    wsk->wyswietl();
                    results++;
                }
            }
            std::cout << "Koniec wyszukiwania - " << results << " wynik�w" << std::endl;
            system("pause");
            break;
        }
        }
        break;
    }
    }
}