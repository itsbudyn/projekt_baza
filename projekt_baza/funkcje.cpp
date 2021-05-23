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
    if (choice != 0) {
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
                        wsk->tytul = tytul;
                        std::cout << "Zmieniono!" << std::endl;
                        system("pause");
                        break;
                    }
                    case 2: {
                        unsigned short rok_wydania;
                        std::cout << "Podaj nowy rok wydania: ";
                        std::cin >> rok_wydania;
                        std::cin.ignore(256, '\n');
                        wsk->rok_wydania = rok_wydania;
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
                        wsk->ocena = ocena;
                        std::cout << "Zmieniono!" << std::endl;
                        system("pause");
                        break;
                    }
                    case 4: {
                        unsigned short min_wiek;
                        std::cout << "Podaj nowe ograniczenie wiekowe: ";
                        std::cin >> min_wiek;
                        std::cin.ignore(256, '\n');
                        wsk->min_wiek = min_wiek;
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
                        wsk->ulubione = ulubione;
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
    if (choice != 0) {
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
                wsk->tytul = tytul;
                std::cout << "Zmieniono!" << std::endl;
                system("pause");
                break;
            }
            case 2: {
                unsigned short rok_wydania;
                std::cout << "Podaj nowy rok wydania: ";
                std::cin >> rok_wydania;
                std::cin.ignore(256, '\n');
                wsk->rok_wydania = rok_wydania;
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
                wsk->ocena = ocena;
                std::cout << "Zmieniono!" << std::endl;
                system("pause");
                break;
            }
            case 4: {
                unsigned short min_wiek;
                std::cout << "Podaj nowe ograniczenie wiekowe: ";
                std::cin >> min_wiek;
                std::cin.ignore(256, '\n');
                wsk->min_wiek = min_wiek;
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
                wsk->ulubione = ulubione;
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
    if (choice != 0) {
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
                wsk->tytul = tytul;
                std::cout << "Zmieniono!" << std::endl;
                system("pause");
                break;
            }
            case 2: {
                unsigned short rok_wydania;
                std::cout << "Podaj nowy rok wydania: ";
                std::cin >> rok_wydania;
                std::cin.ignore(256, '\n');
                wsk->rok_wydania = rok_wydania;
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
                wsk->ocena = ocena;
                std::cout << "Zmieniono!" << std::endl;
                system("pause");
                break;
            }
            case 4: {
                unsigned short min_wiek;
                std::cout << "Podaj nowe ograniczenie wiekowe: ";
                std::cin >> min_wiek;
                std::cin.ignore(256, '\n');
                wsk->min_wiek = min_wiek;
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
                wsk->ulubione = ulubione;
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
}