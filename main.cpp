#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <memory>
using namespace std;


class teksty_kultury
{
private:
    string nazwa;
    string autor;
    int dlugosc;
    int rok_wydania;
public:
    void stworz()
    {
        cout<<"Podaj nazwe tekstu kultury: "<<endl;
        cin.ignore();
        getline(cin,nazwa);
        cout<<"Podaj autora: "<<endl;
        cin.ignore();
        getline(cin,autor);
        cout<<"Podaj dlugosc (strony / minuty / sekundy): "<<endl;
        cin>>dlugosc;
        cout<<"Podaj rok wydania: "<<endl;
        cin>>rok_wydania;
    }

    void pokaz()
    {
        cout<<endl;
        cout<<"Nazwa: "<<nazwa<<endl;
        cout<<"Autor: "<<autor<<endl;
        cout<<"Dlugosc: "<<dlugosc<<endl;
        cout<<"Rok wydania: "<<rok_wydania<<endl;

    }

    void zmien(int wybor)
    {
        if(wybor==1)
        {
            cout<<"Podaj nowa nazwe: ";
            cin.ignore();
            getline(cin, nazwa);
        }
        if(wybor==2)
        {
            cout<<"Podaj nowego autora: ";
            cin.ignore();
            getline(cin,autor);
        }
        if(wybor==3)
        {
           cout<<"Podaj nowa dlugosc (strony/minuty/sekundy): ";
           cin>>dlugosc;
        }
        if(wybor==4)
        {
           cout<<"Podaj nowy rok wydania: ";
           cin>>rok_wydania;
        }
    }

    void file_out(fstream & file)
    {
        file<<"Nazwa tekstu kultury: "<<nazwa<<endl;
        file<<"Autor: "<<autor<<endl;
        file<<"Dlugosc (strony/minuty/sekundy): "<<dlugosc<<endl;
        file<<"Rok wydania: "<<rok_wydania<<endl;
    }

    friend class lista;
};

class ksiazka: public teksty_kultury
{
//private:
    string rodzaj_okladki;
public:
     void stworz()
    {
        teksty_kultury::stworz();
        cout<<"Wpisz rodzaj okladki: "<<endl;
        cin.ignore();
        getline(cin,rodzaj_okladki);
    }

    void pokaz()
    {
        cout<<endl;
        teksty_kultury::pokaz();
        cout<<"Rodzaj okladki: "<<rodzaj_okladki<<endl;
    }

    void zmien(int wybor)
    {

        teksty_kultury::zmien(wybor);
        if(wybor==5)
        {
            cout<<"Wpisz nowy rodzaj okladki: ";
            cin.ignore();
            getline(cin, rodzaj_okladki);
        }

    }

    void file_out(fstream & file)
    {
        teksty_kultury::file_out(file);
        file<<"Rodzaj okladki: "<<rodzaj_okladki<<endl;
    }
};

class przygodowa: public ksiazka
{
public:
    void stworz()
    {
        ksiazka::stworz();
    }
    void pokaz()
    {
        ksiazka::pokaz();
    }
    void zmien(int wybor)
    {
        cout<<"Twoj obiekt:"<<endl;
        pokaz();
        cout<<endl;
        cout<<"Mozliwe opcje:"<<endl;
        cout<<"1. Nazwa"<<endl;
        cout<<"2. Autor"<<endl;
        cout<<"3. Dlugosc"<<endl;
        cout<<"4. Rok wydania"<<endl;
        cout<<"5. Rodzaj okladki"<<endl;
        cout<<"Wybierz numer, ktory chcesz modyfikowac: "<<endl;
        int ktory;
        cin>>ktory;
        if(ktory<5)
            teksty_kultury::zmien(ktory);
        if(ktory==5)
            ksiazka::zmien(ktory);

    }

    void file_out(fstream & file)
    {
        file<<"Obiekty klasy PRZYGODOWA: "<<endl;
        ksiazka::file_out(file);
    }
};

class romans : public ksiazka
{
    string czy_erotyk;
public:
    void stworz()
    {
        ksiazka::stworz();
        cout<<"Czy jest to erotyk?(Tak/Nie) ";
        cin.ignore();
        getline(cin,czy_erotyk);
    }

    void pokaz()
    {
        ksiazka::pokaz();
        cout<<"Czy erotyk?  "<<czy_erotyk<<endl;

    }

    void zmien(int wybor)
    {
        cout<<"Twoj obiekt:"<<endl;
        pokaz();
        cout<<endl;
        cout<<"Mozliwe opcje:"<<endl;
        cout<<"1. Nazwa"<<endl;
        cout<<"2. Autor"<<endl;
        cout<<"3. Dlugosc"<<endl;
        cout<<"4. Rok wydania"<<endl;
        cout<<"5. Rodzaj okladki"<<endl;
        cout<<"6. Czy erotyk?"<<endl;
        cout<<"Wybierz numer, ktory chcesz modyfikowac: "<<endl;
        int ktory;
        cin>>ktory;
        if(ktory<5)
            teksty_kultury::zmien(ktory);
        if(ktory==5)
            ksiazka::zmien(ktory);
        if(ktory==6)
        {
            cout<<"Czy erotyk? (Tak/Nie)";
            cin.ignore();
            getline(cin,czy_erotyk);
        }
    }

    void file_out(fstream & file)
    {
        file<<"Obiekty klasy ROMANS: "<<endl;
        ksiazka::file_out(file);
        file<<"Czy erotyk? "<<czy_erotyk<<endl;
    }

};

class film : public teksty_kultury
{
    string rodzaj;
public:
    void stworz()
    {
        teksty_kultury::stworz();
        cout<<"Podaj jaki to rodzaj filmu: ";
        cin.ignore();
        getline(cin, rodzaj);
    }

    void pokaz()
    {
        teksty_kultury::pokaz();
        cout<<"Rodzaj filmu: "<<rodzaj<<endl;
    }

    void zmien(int wybor)
    {
        teksty_kultury::zmien(wybor);
        if(wybor==5)
        {
            cout<<"Wpisz nowy rodzaj filmu: ";
            cin.ignore();
            getline(cin,rodzaj);
        }
    }
    void file_out(fstream & file)
    {
        teksty_kultury::file_out(file);
        file<<"Rodzaj: "<<rodzaj<<endl;
    }
};

class dla_doroslych : public film
{
    int ocena_filmu;
public:
    void stworz()
    {
        film::stworz();
        cout<<"Podaj ocene filmu (od 1 do 10): ";
        cin>>ocena_filmu;
    }

    void pokaz()
    {
        film::pokaz();
        cout<<"Ocena filmu (od 1 do 10): "<<ocena_filmu<<endl;
    }

    void zmien(int wybor)
    {
        cout<<"Twoj obiekt:"<<endl;
        pokaz();
        cout<<endl;
        cout<<"Mozliwe opcje:"<<endl;
        cout<<"1. Nazwa"<<endl;
        cout<<"2. Autor"<<endl;
        cout<<"3. Dlugosc"<<endl;
        cout<<"4. Rok wydania"<<endl;
        cout<<"5. Rodzaj "<<endl;
        cout<<"6. Ocena filmu "<<endl;
        cout<<"Wybierz numer, ktory chcesz modyfikowac: "<<endl;
        int ktory;
        cin>>ktory;
        if(ktory<5)
            teksty_kultury::zmien(ktory);
        if(ktory==5)
            film::zmien(ktory);
        if(ktory==6)
        {
            cout<<"Podaj nowa ocene filmu (od 1 do 10): ";
            cin>>ocena_filmu;
        }
    }

    void file_out(fstream & file)
    {
        file<<"Obiekty klasy DLA DOROSLYCH: "<<endl;
        film::file_out(file);
        file<<"Ocena filmu (od 1 do 10): "<<ocena_filmu<<endl;
    }

};

class muzyka : public teksty_kultury
{
public:
    void stworz()
    {
        teksty_kultury::stworz();
    }

    void pokaz()
    {
        teksty_kultury::pokaz();
    }

    void zmien(int wybor)
    {
        teksty_kultury::zmien(wybor);
    }

    void file_out(fstream & file)
    {
        teksty_kultury::file_out(file);
    }
};

class zagraniczna : public muzyka
{
    string kraj;
public:
    void stworz()
    {
        muzyka::stworz();
        cout<<"Podaj kraj: ";
        cin.ignore();
        getline(cin,kraj);
    }

    void pokaz()
    {
        muzyka::pokaz();
        cout<<"Kraj: "<<kraj<<endl;
    }

    void zmien(int wybor)
    {
        cout<<"Twoj obiekt:"<<endl;
        pokaz();
        cout<<endl;
        cout<<"Mozliwe opcje:"<<endl;
        cout<<"1. Nazwa"<<endl;
        cout<<"2. Autor"<<endl;
        cout<<"3. Dlugosc"<<endl;
        cout<<"4. Rok wydania"<<endl;
        cout<<"5. Kraj"<<endl;
        cout<<"Wybierz numer, ktory chcesz modyfikowac: "<<endl;
        int ktory;
        cin>>ktory;
        if(ktory<5)
            teksty_kultury::zmien(ktory);
        if(ktory==5)
        {
            cout<<"Podaj nowy kraj: ";
            cin.ignore();
            getline(cin,kraj);
        }
    }

    void file_out(fstream & file)
    {
        file<<"Obiekty klasy ZAGRANICZNA:"<<endl;
        muzyka::file_out(file);
        file<<"Kraj: "<<kraj<<endl;
    }

};

class klasyczna : public muzyka
{
public:
    void stworz()
    {
        muzyka::stworz();
    }

    void pokaz()
    {
        muzyka::pokaz();
    }

    void zmien(int wybor)
    {
        cout<<"Twoj obiekt:"<<endl;
        pokaz();
        cout<<endl;
        cout<<"Mozliwe opcje:"<<endl;
        cout<<"1. Nazwa"<<endl;
        cout<<"2. Autor"<<endl;
        cout<<"3. Dlugosc"<<endl;
        cout<<"4. Rok wydania"<<endl;
        cout<<"Wybierz numer, ktory chcesz modyfikowac: "<<endl;
        int ktory;
        cin>>ktory;
        if(ktory<5)
            teksty_kultury::zmien(ktory);
    }

    void file_out(fstream & file)
    {
        file<<"Obiekty klasy KLASYCZNA:"<<endl;
        muzyka::file_out(file);
    }

};

class polska : public muzyka
{
public:
    void stworz()
    {
        muzyka::stworz();
    }

    void pokaz()
    {
        muzyka::pokaz();
    }

    void zmien(int wybor)
    {
        cout<<"Twoj obiekt:"<<endl;
        pokaz();
        cout<<endl;
        cout<<"Mozliwe opcje:"<<endl;
        cout<<"1. Nazwa"<<endl;
        cout<<"2. Autor"<<endl;
        cout<<"3. Dlugosc"<<endl;
        cout<<"4. Rok wydania"<<endl;
        cout<<"Wybierz numer, ktory chcesz modyfikowac: "<<endl;
        int ktory;
        cin>>ktory;
        if(ktory<5)
            teksty_kultury::zmien(ktory);
    }

    void file_out(fstream & file)
    {
        file<<"Obiekty klasy POLSKA: "<<endl;
        muzyka::file_out(file);
    }
};


class lista{

public:
    vector<przygodowa>przygodowa_lista;
    vector<romans>romans_lista;
    vector<dla_doroslych>dla_doroslych_lista;
    vector<zagraniczna>zagraniczna_lista;
    vector<klasyczna>klasyczna_lista;
    vector<polska>polska_lista;

    void DIR(int *wskaznik)
    {
        if(*wskaznik==1)
        {
            cout<<"KSIAZKA -> PRZYGODOWA:"<<endl;
            for(int i=0; i<przygodowa_lista.size(); i++)
                cout<<" "<<przygodowa_lista[i].nazwa<<endl;

            cout<<"KSIAZKA -> ROMANS"<<endl;
            for(int i=0; i<romans_lista.size(); i++)
                cout<<" "<<romans_lista[i].nazwa<<endl;

            cout<<"FILM -> DLA DOROSLYCH"<<endl;
            for(int i=0; i<dla_doroslych_lista.size();i++)
                cout<<" "<<dla_doroslych_lista[i].nazwa<<endl;

            cout<<"MUZYKA -> ZAGRANICZNA"<<endl;
            for(int i=0; i<zagraniczna_lista.size();i++)
                cout<<" "<<zagraniczna_lista[i].nazwa<<endl;

            cout<<"MUZYKA -> KLASYCZNA"<<endl;
            for(int i=0; i<klasyczna_lista.size(); i++)
                cout<<" "<<klasyczna_lista[i].nazwa<<endl;

            cout<<"MUZYKA -> POLSKA" <<endl;
            for(int i=0; i<polska_lista.size(); i++)
                cout<<" "<<polska_lista[i].nazwa<<endl;
        }
        if(*wskaznik==2)
        {
            cout<<"KSIAZKA -> PRZYGODOWA:"<<endl;
            for(int i=0; i<przygodowa_lista.size(); i++)
                cout<<" "<<przygodowa_lista[i].nazwa<<endl;

            cout<<"KSIAZKA -> ROMANS"<<endl;
            for(int i=0; i<romans_lista.size(); i++)
                cout<<" "<<romans_lista[i].nazwa<<endl;
        }
        if(*wskaznik==3)
        {
            cout<<"KSIAZKA -> PRZYGODOWA:"<<endl;
            for(int i=0; i<przygodowa_lista.size(); i++)
                cout<<" "<<przygodowa_lista[i].nazwa<<endl;
        }
        if(*wskaznik==4)
        {
            cout<<"KSIAZKA -> ROMANS"<<endl;
            for(int i=0; i<romans_lista.size(); i++)
                cout<<" "<<romans_lista[i].nazwa<<endl;
        }
        if(*wskaznik==5)
        {
            cout<<"FILM -> DLA DOROSLYCH"<<endl;
            for(int i=0; i<dla_doroslych_lista.size();i++)
                cout<<" "<<dla_doroslych_lista[i].nazwa<<endl;
        }
        if(*wskaznik==6)
        {
            cout<<"FILM -> DLA DOROSLYCH"<<endl;
            for(int i=0; i<dla_doroslych_lista.size();i++)
                cout<<" "<<dla_doroslych_lista[i].nazwa<<endl;
        }
        if(*wskaznik==7)
        {
            cout<<"MUZYKA -> ZAGRANICZNA"<<endl;
            for(int i=0; i<zagraniczna_lista.size();i++)
                cout<<" "<<zagraniczna_lista[i].nazwa<<endl;

            cout<<"MUZYKA -> KLASYCZNA"<<endl;
            for(int i=0; i<klasyczna_lista.size(); i++)
                cout<<" "<<klasyczna_lista[i].nazwa<<endl;

            cout<<"MUZYKA -> POLSKA" <<endl;
            for(int i=0; i<polska_lista.size(); i++)
                cout<<" "<<polska_lista[i].nazwa<<endl;
        }
        if(*wskaznik==8)
        {
            cout<<"MUZYKA -> ZAGRANICZNA"<<endl;
            for(int i=0; i<zagraniczna_lista.size();i++)
                cout<<" "<<zagraniczna_lista[i].nazwa<<endl;
        }
        if(*wskaznik==9)
        {
            cout<<"MUZYKA -> KLASYCZNA"<<endl;
            for(int i=0; i<klasyczna_lista.size(); i++)
                cout<<" "<<klasyczna_lista[i].nazwa<<endl;
        }
        if(*wskaznik==10)
        {
            cout<<"MUZYKA -> POLSKA" <<endl;
            for(int i=0; i<polska_lista.size(); i++)
                cout<<" "<<polska_lista[i].nazwa<<endl;
        }
    }

    void SHOW(int *wskaznik)
    {
        int lisc;
        if(*wskaznik==1)
        {
            cout<<"Wybierz z ktorego liscia (klasy) chcesz wyswietlic informacje o obiekcie (po numerze):"<<endl;
            cout<<"1. Ksiazka -> Przygodowa"<<endl;
            cout<<"2. Ksiazka -> Romans"<<endl;
            cout<<"3. Film -> Dla doroslych"<<endl;
            cout<<"4. Muzyka -> Zagraniczna"<<endl;
            cout<<"5. Muzyka -> Klasyczna"<<endl;
            cout<<"6. Muzyka -> Polska"<<endl;
            cout<<"Wybor: "<<endl;
            cin>>lisc;
            if(lisc==1)
            {
                *wskaznik = 3;
                cout<<"Wybierz numer obiektu, ktorego chcesz wyswietlic informacje"<<endl;
                int obiekt;
                cin>>obiekt;
                for(int i=0; i<przygodowa_lista.size(); i++)
                {
                    if(i+1 == obiekt)
                    {
                        przygodowa_lista[i].pokaz();
                    }
                }
                *wskaznik = 1;
            }
            if(lisc==2)
            {
                *wskaznik = 4;
                cout<<"Wybierz numer obiektu, ktorego chcesz wyswietlic informacje"<<endl;
                int obiekt;
                cin>>obiekt;
                for(int i=0; i<romans_lista.size(); i++)
                {
                    if(i+1 == obiekt)
                    {
                        romans_lista[i].pokaz();
                    }
                }
                *wskaznik = 1;
            }
            if(lisc==3)
            {
                *wskaznik = 6;
                cout<<"Wybierz numer obiektu, ktorego chcesz wyswietlic informacje"<<endl;
                int obiekt;
                cin>>obiekt;
                for(int i=0; i<dla_doroslych_lista.size(); i++)
                {
                    if(i+1 == obiekt)
                    {
                        dla_doroslych_lista[i].pokaz();
                    }
                }
                *wskaznik = 1;
            }
            if(lisc==4)
            {
                *wskaznik = 8;
                cout<<"Wybierz numer obiektu, ktorego chcesz wyswietlic informacje"<<endl;
                int obiekt;
                cin>>obiekt;
                for(int i=0; i<zagraniczna_lista.size(); i++)
                {
                    if(i+1 == obiekt)
                    {
                        zagraniczna_lista[i].pokaz();
                    }
                }
                *wskaznik = 1;
            }
            if(lisc==5)
            {
                *wskaznik = 9;
                cout<<"Wybierz numer obiektu, ktorego chcesz wyswietlic informacje"<<endl;
                int obiekt;
                cin>>obiekt;
                for(int i=0; i<klasyczna_lista.size(); i++)
                {
                    if(i+1 == obiekt)
                    {
                        klasyczna_lista[i].pokaz();
                    }
                }
                *wskaznik = 1;
            }
            if(lisc==6)
            {
                *wskaznik = 10;
                cout<<"Wybierz numer obiektu, ktorego chcesz wyswietlic informacje"<<endl;
                int obiekt;
                cin>>obiekt;
                for(int i=0; i<polska_lista.size(); i++)
                {
                    if(i+1 == obiekt)
                    {
                        polska_lista[i].pokaz();
                    }
                }
                *wskaznik = 1;
            }
        }

        if(*wskaznik==2)
        {
            cout<<"Wybierz z ktorego liscia (klasy) chcesz wyswietlic informacje o obiekcie (po numerze):"<<endl;
            cout<<"1. Ksiazka -> Przygodowa"<<endl;
            cout<<"2. Ksiazka -> Romans"<<endl;
            cout<<"Wybor: "<<endl;
            cin>>lisc;
            if(lisc==1)
            {
                *wskaznik = 3;
                cout<<"Wybierz numer obiektu, ktorego chcesz wyswietlic informacje"<<endl;
                int obiekt;
                cin>>obiekt;
                for(int i=0; i<przygodowa_lista.size(); i++)
                {
                    if(i+1 == obiekt)
                    {
                        przygodowa_lista[i].pokaz();
                    }
                }
                *wskaznik = 2;
            }
            if(lisc==2)
            {
                *wskaznik = 4;
                cout<<"Wybierz numer obiektu, ktorego chcesz wyswietlic informacje"<<endl;
                int obiekt;
                cin>>obiekt;
                for(int i=0; i<romans_lista.size(); i++)
                {
                    if(i+1 == obiekt)
                    {
                        romans_lista[i].pokaz();
                    }
                }
                *wskaznik = 2;
            }
        }

        if(*wskaznik==3)
        {
            cout<<"Wybierz numer obiektu, ktorego chcesz wyswietlic informacje"<<endl;
                int obiekt;
                cin>>obiekt;
                for(int i=0; i<przygodowa_lista.size(); i++)
                {
                    if(i+1 == obiekt)
                    {
                        przygodowa_lista[i].pokaz();
                    }
                }
        }

        if(*wskaznik==4)
        {
            cout<<"Wybierz numer obiektu, ktorego chcesz wyswietlic informacje"<<endl;
                int obiekt;
                cin>>obiekt;
                for(int i=0; i<romans_lista.size(); i++)
                {
                    if(i+1 == obiekt)
                    {
                        romans_lista[i].pokaz();
                    }
                }
        }

        if(*wskaznik==5)
        {
            *wskaznik = 6;
            cout<<"Wybierz numer obiektu, ktorego chcesz wyswietlic informacje"<<endl;
                int obiekt;
                cin>>obiekt;
                for(int i=0; i<dla_doroslych_lista.size(); i++)
                {
                    if(i+1 == obiekt)
                    {
                        dla_doroslych_lista[i].pokaz();
                    }
                }
            *wskaznik = 5;
        }

        if(*wskaznik==6)
        {
            cout<<"Wybierz numer obiektu, ktorego chcesz wyswietlic informacje"<<endl;
                int obiekt;
                cin>>obiekt;
                for(int i=0; i<dla_doroslych_lista.size(); i++)
                {
                    if(i+1 == obiekt)
                    {
                        dla_doroslych_lista[i].pokaz();
                    }
                }
        }

        if(*wskaznik==7)
        {
            cout<<"Wybierz z ktorego liscia (klasy) chcesz wyswietlic informacje o obiekcie (po numerze):"<<endl;
            cout<<"1. Muzyka -> Zagraniczna"<<endl;
            cout<<"2. Muzyka -> Klasyczna"<<endl;
            cout<<"3. Muzyka -> Polska"<<endl;
            cout<<"Wybor: "<<endl;
            cin>>lisc;
            if(lisc==1)
            {
                *wskaznik = 8;
                cout<<"Wybierz numer obiektu, ktorego chcesz wyswietlic informacje"<<endl;
                int obiekt;
                cin>>obiekt;
                for(int i=0; i<zagraniczna_lista.size(); i++)
                {
                    if(i+1 == obiekt)
                    {
                        zagraniczna_lista[i].pokaz();
                    }
                }
                *wskaznik = 7;
            }
            if(lisc==2)
            {
                *wskaznik = 9;
                cout<<"Wybierz numer obiektu, ktorego chcesz wyswietlic informacje"<<endl;
                int obiekt;
                cin>>obiekt;
                for(int i=0; i<klasyczna_lista.size(); i++)
                {
                    if(i+1 == obiekt)
                    {
                        klasyczna_lista[i].pokaz();
                    }
                }
                *wskaznik =7;
            }
            if(lisc==3)
            {
                *wskaznik = 10;
                cout<<"Wybierz numer obiektu, ktorego chcesz wyswietlic informacje"<<endl;
                int obiekt;
                cin>>obiekt;
                for(int i=0; i<polska_lista.size(); i++)
                {
                    if(i+1 == obiekt)
                    {
                        polska_lista[i].pokaz();
                    }
                }
                *wskaznik = 7;
            }
        }

        if(*wskaznik==8)
        {
            cout<<"Wybierz numer obiektu, ktorego chcesz wyswietlic informacje"<<endl;
                int obiekt;
                cin>>obiekt;
                for(int i=0; i<zagraniczna_lista.size(); i++)
                {
                    if(i+1 == obiekt)
                    {
                        zagraniczna_lista[i].pokaz();
                    }
                }
        }

        if(*wskaznik==9)
        {
            cout<<"Wybierz numer obiektu, ktorego chcesz wyswietlic informacje"<<endl;
                int obiekt;
                cin>>obiekt;
                for(int i=0; i<klasyczna_lista.size(); i++)
                {
                    if(i+1 == obiekt)
                    {
                        klasyczna_lista[i].pokaz();
                    }
                }
        }

        if(*wskaznik==10)
        {
            cout<<"Wybierz numer obiektu, ktorego chcesz wyswietlic informacje"<<endl;
                int obiekt;
                cin>>obiekt;
                for(int i=0; i<polska_lista.size(); i++)
                {
                    if(i+1 == obiekt)
                    {
                        polska_lista[i].pokaz();
                    }
                }
        }
    }

    void MO(int *wskaznik)
    {
        if(*wskaznik==3)
        {
            przygodowa nowyobiekt;
            nowyobiekt.stworz();
            przygodowa_lista.push_back(nowyobiekt);
        }

        else if(*wskaznik==4)
        {
            romans nowyobiekt;
            nowyobiekt.stworz();
            romans_lista.push_back(nowyobiekt);
        }

        else if(*wskaznik==6)
        {
            dla_doroslych nowyobiekt;
            nowyobiekt.stworz();
            dla_doroslych_lista.push_back(nowyobiekt);
        }

        else if(*wskaznik==8)
        {
            zagraniczna nowyobiekt;
            nowyobiekt.stworz();
            zagraniczna_lista.push_back(nowyobiekt);
        }

        else if(*wskaznik==9)
        {
            klasyczna nowyobiekt;
            nowyobiekt.stworz();
            klasyczna_lista.push_back(nowyobiekt);
        }

        else if(*wskaznik==10)
        {
            polska nowyobiekt;
            nowyobiekt.stworz();
            polska_lista.push_back(nowyobiekt);
        }

        else
        {
            cout<<"Nie ma liscia o takim numerze. Wroc prosze do menu CD i wybierz lisc.";
            return;
        }

    }


    void DO(int *wskaznik)    // USUWANIE OBIEKTOW Z LISCI
    {
        int obiekt;
        if(*wskaznik==3)
        {
            if(przygodowa_lista.empty())
            {
                cout<<"Lisc nie zawiera elementow"<<endl;
                return;
            }
            cout<<"Wybierz numer obiektu, ktory chcesz usunac"<<endl;
            cin>>obiekt;
            przygodowa_lista.erase(przygodowa_lista.begin() + (obiekt-1));
            return;
        }

        else if(*wskaznik==4)
        {
            if(romans_lista.empty())
            {
                cout<<"Lisc nie zawiera elementow"<<endl;
                return;
            }
            cout<<"Wybierz numer obiektu, ktory chcesz usunac"<<endl;
            cin>>obiekt;
            romans_lista.erase(romans_lista.begin() + (obiekt-1));
            return;
        }

        else if(*wskaznik==6)
        {
            if(dla_doroslych_lista.empty())
            {
                cout<<"Lisc nie zawiera elementow"<<endl;
                return;
            }
            cout<<"Wybierz numer obiektu, ktory chcesz usunac"<<endl;
            cin>>obiekt;
            dla_doroslych_lista.erase(dla_doroslych_lista.begin() + (obiekt-1));
            return;
        }

        else if(*wskaznik==8)
        {
            if(zagraniczna_lista.empty())
            {
                cout<<"Lisc nie zawiera elementow"<<endl;
                return;
            }
            cout<<"Wybierz numer obiektu, ktory chcesz usunac"<<endl;
            cin>>obiekt;
            zagraniczna_lista.erase(zagraniczna_lista.begin() + (obiekt-1));
            return;
        }

        else if(*wskaznik==9)
        {
            if(klasyczna_lista.empty())
            {
                cout<<"Lisc nie zawiera elementow"<<endl;
                return;
            }
            cout<<"Wybierz numer obiektu, ktory chcesz usunac"<<endl;
            cin>>obiekt;
            klasyczna_lista.erase(klasyczna_lista.begin() + (obiekt-1));
            return;
        }

        else if(*wskaznik==10)
        {
            if(polska_lista.empty())
            {
                cout<<"Lisc nie zawiera elementow"<<endl;
                return;
            }
            cout<<"Wybierz numer obiektu, ktory chcesz usunac"<<endl;
            cin>>obiekt;
            polska_lista.erase(polska_lista.begin() + (obiekt-1));
            return;
        }

        else
        {
            cout<<"Nie ma liscia o takim numerze. Wroc prosze do menu CD i wybierz lisc.";
            return;
        }
    }

    void MDO(int *wskaznik)
    {
        int obiekt;
        if(*wskaznik==3)
        {
            if(przygodowa_lista.empty())
            {   cout<<"Lisc nie zawiera obiektow."<<endl;
                return;
            }
            else
            {
                cout<<"Wybierz numer obiektu, ktory chcesz modyfikowac."<<endl;
                cin>>obiekt;
                for(int i=0; i<przygodowa_lista.size(); i++)
                {
                    if(i+1 == obiekt)
                    {
                        przygodowa_lista[i].zmien(obiekt);
                        return;
                    }
                }
            }
        }

        else if(*wskaznik==4)
        {
             if(romans_lista.empty())
            {   cout<<"Lisc nie zawiera obiektow."<<endl;
                return;
            }
            else
            {
                cout<<"Wybierz numer obiektu, ktory chcesz modyfikowac."<<endl;
                cin>>obiekt;
                for(int i=0; i<romans_lista.size(); i++)
                {
                    if(i+1 == obiekt)
                    {
                        romans_lista[i].zmien(obiekt);
                        return;
                    }
                }
            }
        }

        else if(*wskaznik==6)
        {
             if(dla_doroslych_lista.empty())
            {   cout<<"Lisc nie zawiera obiektow."<<endl;
                return;
            }
            else
            {
                cout<<"Wybierz numer obiektu, ktory chcesz modyfikowac."<<endl;
                cin>>obiekt;
                for(int i=0; i<dla_doroslych_lista.size(); i++)
                {
                    if(i+1 == obiekt)
                    {
                        dla_doroslych_lista[i].zmien(obiekt);
                        return;
                    }
                }
            }
        }

        else if(*wskaznik==8)
        {
             if(zagraniczna_lista.empty())
            {   cout<<"Lisc nie zawiera obiektow."<<endl;
                return;
            }
            else
            {
                cout<<"Wybierz numer obiektu, ktory chcesz modyfikowac."<<endl;
                cin>>obiekt;
                for(int i=0; i<zagraniczna_lista.size(); i++)
                {
                    if(i+1 == obiekt)
                    {
                        zagraniczna_lista[i].zmien(obiekt);
                        return;
                    }
                }
            }
        }

        else if(*wskaznik==9)
        {
             if(klasyczna_lista.empty())
            {   cout<<"Lisc nie zawiera obiektow."<<endl;
                return;
            }
            else
            {
                cout<<"Wybierz numer obiektu, ktory chcesz modyfikowac."<<endl;
                cin>>obiekt;
                for(int i=0; i<klasyczna_lista.size(); i++)
                {
                    if(i+1 == obiekt)
                    {
                        klasyczna_lista[i].zmien(obiekt);
                        return;
                    }
                }
            }
        }

        else if(*wskaznik==10)
        {
             if(polska_lista.empty())
            {   cout<<"Lisc nie zawiera obiektow."<<endl;
                return;
            }
            else
            {
                cout<<"Wybierz numer obiektu, ktory chcesz modyfikowac."<<endl;
                cin>>obiekt;
                for(int i=0; i<polska_lista.size(); i++)
                {
                    if(i+1 == obiekt)
                    {
                        polska_lista[i].zmien(obiekt);
                        return;
                    }
                }
            }
        }

        else
        {
            cout<<"Nie ma liscia o takim numerze. Wroc prosze do menu CD i wybierz lisc.";
            return;
        }
    }


    void SAVE()
    {
        fstream file;
        file.open("Teksty.txt",ios::out);
        if( file.good()==false)
        {
            cout<<"Taki plik nie istnieje!"<<endl;
            return;
        }

        for(int i=0; i<przygodowa_lista.size(); i++)
        {
            przygodowa_lista[i].file_out(file);
        }

        file<<endl;
        for(int i=0; i<romans_lista.size(); i++)
        {
            romans_lista[i].file_out(file);
        }

        file<<endl;
        for(int i=0; i<dla_doroslych_lista.size(); i++)
        {
            dla_doroslych_lista[i].file_out(file);
        }

        file<<endl;
        for(int i=0; i<zagraniczna_lista.size(); i++)
        {
            zagraniczna_lista[i].file_out(file);
        }

        file<<endl;
        for(int i=0; i<klasyczna_lista.size(); i++)
        {
            klasyczna_lista[i].file_out(file);
        }

        file<<endl;
        for(int i=0; i<polska_lista.size(); i++)
        {
            polska_lista[i].file_out(file);
        }

        file.close();
        cout<<"PLIK ZAPISANY!"<<endl;
    }


    void READ()     // NIE DZIALA!
    {
      /*  ifstream file("Teksty.txt");

        int s = 0;
        string line;
        if(line == "Obiekty klasy PRZYGODOWA:")
        {
        while(getline(file,line))
            // przygodowa_lista.push_back(line);

        for(int i=0; i<przygodowa_lista.size(); i++)
            s++;
        }
        file.close; */
    }
};

void TREE()
{
    string hierarchia;
    fstream file;
    file.open("hierarchia.txt", ios::in);
    if( file.good()==false)
    {
        cout<<"Taki plik nie istnieje!"<<endl;
        return;
    }
    while(!file.eof())
    {
        getline(file, hierarchia);
        cout << hierarchia << endl;
    }
    file.close();
    return;
}

void CD(int *wskaznik)
{
    cout<<"Wybierz na ktorej klasie chcesz operowac (po numerze}:"<<endl;
    cout<<"1. Teksty kultury"<<endl;
    cout<<"2. Tkeksty kultury -> Ksiazka"<<endl;
    cout<<"3. Ksiazka -> Przygodowa"<<endl;
    cout<<"4. Ksiazka -> Romans"<<endl;
    cout<<"5. Teksty kultury -> Film"<<endl;
    cout<<"6. Film -> Dla doroslych"<<endl;
    cout<<"7. Teksty kultury -> Muzyka"<<endl;
    cout<<"8. Muzyka -> Zagraniczna"<<endl;
    cout<<"9. Muzyka -> Klasyczna"<<endl;
    cout<<"10. Muzyka -> Polska"<<endl;
    cout<<"Wybor: "<<endl;
    int wybor;
    cin>>wybor;
    *wskaznik = wybor;
}


int main()
{
    int *wskaznik;
    lista Teksty;
    while(1)
    {
        cout<<"_________________________________________________________"<<endl;
        cout<<"MENU"<<endl;
        cout<<"1. CD - Zmiana wezla"<<endl;
        cout<<"2. MO - Utworzenie nowego biektu"<<endl;
        cout<<"3. DO - Usuwanie obiektu"<<endl;
        cout<<"4. MDO - Modyfikacja obiektu"<<endl;
        cout<<"5. DIR - Wyswietlanie nazw obiektow"<<endl;
        cout<<"6. SHOW - Wyswietlanie szczegolowych info o obiekcie"<<endl;
        cout<<"7. SAVE - Zapis do pliku"<<endl;
        cout<<"8. READ - Zapis z pliku (NIE DZIALA!)"<<endl;
        cout<<"9. TREE - Wyswietlanie calej struktury"<<endl;
        cout<<"10. Zamknij program"<<endl;
        cout<<"Wybierz numer odpowiadajcy operacji, jaka chcesz wykonac"<<endl;
        cout<<"Twoj Wybor: ";
        int menu;
        cin>>menu;
        cout<<"_________________________________________________________"<<endl;

        if(menu<1 || menu>>10)
        {
            cout<<"Wybierz numer od 1 do 10"<<endl;
            continue;
        }

        switch(menu)
        {
        case 1:
            {
                cout<<endl;
                CD(wskaznik);
                cout<<endl;
                break;
            }

        case 2:
            {
                cout<<endl;
                Teksty.MO(wskaznik);
                cout<<"OBIEKT ZOSTAL DODANY!"<<endl;
                cout<<endl;
                break;
            }

        case 3:
            {
                cout<<endl;
                Teksty.DO(wskaznik);
                cout<<"OBIEKT ZOSTAL USUNIETY!"<<endl;
                cout<<endl;
                break;
            }

        case 4:
            {
                cout<<endl;
                Teksty.MDO(wskaznik);
                cout<<"OBIEKT ZOSTAL ZMODYFIKOWANY!"<<endl;
                cout<<endl;
                break;
            }

        case 5:
            {
                cout<<endl;
                Teksty.DIR(wskaznik);
                cout<<endl;
                break;
            }

        case 6:
            {
                cout<<endl;
                Teksty.SHOW(wskaznik);
                cout<<endl;
                break;
            }

        case 7:
            {
                cout<<endl;
                Teksty.SAVE();
                cout<<endl;
                break;
            }

        case 8:
            {
                cout<<endl;
               // Teksty.READ();
               cout<<"ODCZYT Z PLIKU NIE DZIALA!"<<endl;
               cout<<endl;
               break;
            }

        case 9:
            {
                cout<<endl;
                TREE();
                cout<<endl;
                break;
            }

        }
    }
}
