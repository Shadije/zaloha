//
// Created by map on 27. 9. 2021.
//

#ifndef KRUH_H_INCLUDED
#define KRUH_H_INCLUDED
#include <iostream>
class Kruh {
    //dopisat classes;
    class chyba//konstruktor rnadradenej rodicovskej casti
    {
    protected: //chraneny clen, potomkovia maju k nemu pristup ako k verejnemu, ostatne triedy ako k privatnemu;
        const char *msg;
        int kodChyby;
    public:
        Chyba(const char *sprava):msg(sprava){};
        virtual void getMsg()const {std::cout<<msg<<std::endl;}; //virtual = v triede potomkov ju budeme prepisovat;
        int vratKodChyby(){return kodChyby;};
    };


public:class streamError:public chyba
    {
    public:
        streamError(const char *sprava):chyba(sprava){};
    };

    // vlozime triedy sluziace na vytvorenie vynimiek;
    class noNumber:public Chyba //trieda je verejne odvodena od triedy Chyba // konstruktor rodicovskej casti ???
    {
    private:
        const char *mojaMsg;
    public:
        noNumber(const char *sprava, const char *mojaSprava):Chyba (sprava) {mojaMsg =mojaSprava;};
        const char *getMojaMsg(){return mojaMsg;};
        void getMsg()const {std::cout<<msg<<mojaMsg<<std::endl;};
    };

    class chybaNula:public Chyba //trieda je verejne odvodena od triedy Chyba
    {
    public:
        chybaNula(const char *sprava):Chyba (sprava) {}
    };

    class chybaZaporne:public Chyba //trieda je verejne odvodena od triedy Chyba
    {
    public:
        chybaZaporne(const char *sprava):Chyba (sprava) {}
    };


private:
    int polomer;
    int pocitadlo;
public:
    Kruh(); //destruktor - nici pamat tilda = ~Kruh();
    //DU stablesort priradenie poradia ; upravit konstruktor aby automaticka cisloval kruhy aby ich nechal v spravnom poradi

    explicit Kruh(int r); //zakaze priradit kruhu cislo k2=25 nefunguje; (konverziu cisla na kruh)

    Kruh getPolomer() const;

    Kruh operator+(const Kruh &other) const; //k1+k2 = k1.operator+(k2); pripocita ku kruhu cislo
    friend Kruh operator +(int cislo, const Kruh &other);  //pripocita k cislu kruh- priatelska k tej predoslej;

    bool operator<(const Kruh &other) const;

    Kruh operator*( int cislo) const;
    friend Kruh operator *(int cislo, const Kruh &other); //priatelska funkcia ktora vynasobi cislo kruhom

    Kruh operator-( int cislo) const;

    Kruh operator-(const Kruh &other) const;

    Kruh operator+( int cislo) const;

    Kruh operator*(const Kruh &other) const;

    const Kruh& operator ++(); //menim samotny kruh, nemoze byt konstantna a ked pouzijem odkaz ako navratovu hodnotu budem vracat samotnu hodnotu - vracanie odkazom
    //vracat odkaz len s const aby sa s nim nedalo manipulovat; pouzivat ho viackrat;

    const Kruh operator ++(int nepouzijem);
    //parameter sa nepouzije ale znamena ze sa pretazuje postfix;

    const Kruh& operator += (int cislo) ;
    const Kruh& operator -= (int cislo) ;

    const Kruh& operator --();
    Kruh operator --(int nepouzijem);

    friend std::ostream &operator<<(std::ostream &os, const Kruh &mojKruh); //pretazenie operatora na vystup ;
    friend std::istream &operator>>(std::istream &is, Kruh &mojKruh); //pretazenie operatora na vstup;


    static void generujPoleKruhov(Kruh *pole, int pocet);
    static void vypisPoleKruhov(const Kruh *pole, int pocet);

    static Kruh getMaxKruh (const Kruh*pole, int pocet);
    static void utriedPoleKruhov (Kruh *pole, int pocet); //pole budem triedit nemoze byt const , ziaadna static neni const na konci;
    static int cmp (const void *a, const void *b); //komparacna funkcia (pointer na void), musi byt schopna triedit akykolvek typ pointrerov;
    static int cmpStable (const void *a, const void*b);
    static int getInt(bool nula=true, bool zaporne= true);
    static int generujSuborKruhov (const char *nazov, int kolko);
    static Kruh *precitajSuborKruhov (const char *nazov, int kolko);
};
#endif // KRUH_H_INCLUDED
