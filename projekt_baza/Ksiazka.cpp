#include "Ksiazka.h"

// w każdym konstruktorze musi być liczbaKsiazek++
// aby składnik statyczny liczbaKsiazek była równa
// rzeczywistej liczbie aktualnie stworzonych
// książek. destruktor ma liczbaKsiazek--, aby
// przy każdym zniszczeniu obiektu typu książka
// składnik statyczny miał wartość rzeczywistej
// liczbie stworzonych książek. 

// sposób analogiczny dla klas film i album_muzyczny

unsigned int Ksiazka::liczbaKsiazek = 0;

void Ksiazka::wyswietl() const{
    std::cout << "Tytuł:\t\t\t" << this->tytul << std::endl;
    std::cout << "Autorzy:\t\t" << this->autor << std::endl;
    std::cout << "Wydawnictwo:\t\t" << this->wydawnictwo << std::endl;
    std::cout << "Gatunek: \t\t" << this->gatunek << std::endl;
    std::cout << "Rok wydania:\t\t" << this->rok_wydania << std::endl;
    std::cout << std::endl;
    std::cout << "Stron:\t\t\t" << this->strony << std::endl;
    std::cout << "Ograniczenia wiekowe:\t" << this->min_wiek << "+" << std::endl;
    std::cout << std::endl;
    std::cout << "Ocena:\t\t\t";
    if (this->ocena != 0) std::cout << this->ocena << " / 5";
    else std::cout << "Nieocenione";
    std::cout << std::endl;
    std::cout << "Ulubione:\t\t";
    if (this->ulubione == true) std::cout << "Tak";
    else std::cout << "Nie";
    std::cout << std::endl;
}

// metoda zwracająca liczbę stron
unsigned short Ksiazka::zwrocStrony() const {
    return strony;
}

// metoda zwracająca wartość składnika statycznego
unsigned int Ksiazka::zwrocLiczbeKsiazek() {
    return liczbaKsiazek;
}

// konstruktor bezargumentowy
Ksiazka::Ksiazka() {
    liczbaKsiazek++;
}

// konstruktor uzupełniający wszystkie zmienne
Ksiazka::Ksiazka(std::string u_tytul, unsigned short u_rok_wydania, double u_ocena, unsigned short u_min_wiek, bool u_ulubione, unsigned short u_strony, std::string u_autor, std::string u_wydawnictwo, std::string u_gatunek) :Utwor(u_tytul, u_rok_wydania, u_ocena, u_min_wiek, u_ulubione) {
    liczbaKsiazek++;
    this->strony = u_strony;
    this->autor = u_autor;
    this->wydawnictwo = u_wydawnictwo;
    this->gatunek = u_gatunek;
}

// konstruktor kopiujący
Ksiazka::Ksiazka(const Ksiazka& x) :Utwor(x.tytul, x.rok_wydania, x.ocena, x.min_wiek, x.ulubione) {
    liczbaKsiazek++;
    this->strony = x.strony;
    this->autor = x.autor;
    this->wydawnictwo = x.wydawnictwo;
    this->gatunek = x.gatunek;
}

// destruktor
Ksiazka::~Ksiazka() {
    liczbaKsiazek--;
}

// przeciążony operator przypisywania
Ksiazka& Ksiazka::operator=(const Ksiazka& x) {
    if (&x == this)return *this; // w przypadku gdy operator wskazuje na samego siebie

    // jeżeli nie - część kopiująca
    tytul = x.tytul;
    rok_wydania = x.rok_wydania;
    ocena = x.ocena;
    min_wiek = x.min_wiek;
    ulubione = x.ulubione;
    strony = x.strony;
    autor = x.autor;
    wydawnictwo = x.wydawnictwo;
    gatunek = x.gatunek;

    return *this;
}