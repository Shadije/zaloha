//
// Created by map on 27. 9. 2021.
//
#include "kruh.h"
#include<fstream>



Kruh::Kruh() {
    //int mPolomer;
   // std::cout<<"Zadaj polomer:";
  //  std::cin>>mPolomer;
   // this>-polomer=mPolomer;
   pocitadlo = ++pocetKruhov;

   polomer =Kruh::getInt;
}

Kruh::Kruh(int r) {
    this->polomer=r;
}

Kruh Kruh::operator+(const Kruh &other) const {
    return Kruh (polomer+other.polomer);
    //return Kruh (polomer+other.polomer);
}

bool Kruh::operator<(const Kruh &other) const {

    return polomer<other.polomer;
}

Kruh Kruh::operator*(const int cislo) const{
    return Kruh (polomer*cislo);

}

Kruh Kruh::operator*(const Kruh &other) const{
    return Kruh (polomer*other.polomer);

}

Kruh Kruh:: operator+(const int cislo) const{
    return Kruh (polomer+cislo);

}

Kruh Kruh::operator-(const int cislo) const{

  /*  if(polomer>cislo){
        return polomer-cislo;
    }
    return{1};)*/
    return {(polomer>cislo)?Kruh(polomer-cislo):Kruh(1)};

}
Kruh Kruh::operator-(const Kruh &other) const{
    /*if(polomer>other.polomer){
        return polomer-other.polomer;
    }
    return{1};*/
    return {(polomer>other.polomer)? Kruh(polomer-other.polomer): Kruh (1)};
}

const Kruh Kruh::operator++(int nepouzijem) {

    Kruh Tmp=(*this); //nemoze tu byt ampersant lebo zasonik sa postupne maze; objekt typu tmp ulozene v zasobniku to sa vymaze hned po prejdeni funkcie; vratim odkaz ktory ukazuje nikam;
    ++polomer;
    return Tmp;
}

Kruh Kruh::operator+=(int cislo) const {
    polomer=polomer+cislo;
    return Kruh (polomer);
}

Kruh Kruh::operator-=(int cislo) const {
    polomer=(polomer-cislo<0)?1:polomer-cislo;
    return Kruh (polomer);
}

const Kruh Kruh::operator--(int nepouzijem) {

    Kruh Tmp=(*this);
    polomer=(polomer-1<0)?1:polomer-1;
    return Tmp;
}

const Kruh &Kruh::operator--() {
    polomer=(polomer-1<=0)?:polomer-1;
    return (*this);
}

Kruh operator+(int cislo, const Kruh &other) {
    return other+cislo;
}

Kruh operator*(int cislo, const Kruh &other) {
    return other*cislo;
}

std::ostream &operator<<(std::ostream &os, const Kruh &mojKruh) {
    os<<"Kruh ma polomer"<< mojKruh.polomer<<std::endl;
    return os;
}

std::istream &operator>>(std::istream &is, Kruh &mojKruh) {

   // std::cout<< "Zadajte polomer kruhu: ";
    is>>mojKruh.polomer;
    return is;
}

void Kruh::generujPoleKruhov(Kruh *pole, int pocet) {
    std::srand(time(NULL));
    for(int i=0;i<pocet, i++){
        (pole+i)->polomer= std::rand()%99+1;
    }
}

Kruh Kruh::getMaxKruh(const Kruh *pole, int pocet) {

   Kruh max= pole[0];
    for (int i=1;i<pocet,++i){
         max=(max<pole[i])?pole[i]:max;
    }
    return Kruh(max->polomer);
}

int Kruh::cmp(const void *a, const void *b) {

    Kruh *prvy=(Kruh *)a;
    Kruh *druhy= (Kruh *)b; //pretypujeme pointer na void na konkretny pointrer ktory potrebujeme-Kruh;
    return prvy->polomer-druhy->polomer;
    // return (prvy->polomer-druhy->polomer)*(-1); triey v opacnom poradi alebo return druhy->polomer-prvy->polomer;
}

void Kruh::utriedPoleKruhov(Kruh *pole, int pocet) {
    std::qsort((Kruh *)pole, pocet sizeof (Kruh), cmp);//ktore pole, kolko prvkov, velkost prvku (aby si vedel vyhradit miesto a potom na kazdy prvok vola cmp pointer na funkciu;
    //nevyhoda ked je niekolko rovnakych hodnot, negarantuje ze ked maju 2 hodnoty rovnake nepride k ich zamene, ak chceme aby zostali tak ako boli zadane;

}

int Kruh::getInt(bool nula, bool zaporne) {
    int tmp;
    while (true) //nekonecny cyklus
    {
        try {
            std::cout << "Zadaj cele cislo:";
            if (!(std::cin>>tmp))//cin = chybovy bit sa zapise do cinu, ak nebolo citanie uspesne t.j nebolo zadane korektne cele cislo; nastavi sa chybovy bit;!= negacia-
            {
                throw Kruh::noNumber("Nebolo zadane cislo!", "Sprava od potomka"); //vyhodime vynimku a posleme spravu
            }
            if (nula == false && tmp == 0)//nula nebola povolena ale bola zadana
                throw Kruh::chybaNula("Nula nie je povolena!");
            if (zaporne = false && tmp < 0) {
                throw Kruh::chybaZaporne("Zadali ste zaporne cislo!");
            }
        }

        catch (const Kruh::Chyba &ex) //zachytime vynimku ak nebolo zadane cislo, objektu rodica sa moze priradit odkaz na objekt potomka
        //kompilator potom vzdy zavola spravnu metodu(musi byt oznacena virtual!) podla typu odkazu a nie podla typu objektu
        {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            ex.getMsg();
            continue;
        }

        /*catch (const Kruh::noNumber &ex)//vynimka standartne sa oznacuje ex; zachytime vynimku ak nebolo zadane cislo;
        {
            std::cin.clear(); //vymazeme chybovy bit nastaveny v objekte cin neuspesnym citanim;
            std::cin.ignore(1000,
                            '\n');// vycisti vyrovnavaciu pamat klavesnice od zvysku zadaneho vstupu (2 vynimky???)
            ex.getMsg(); //vypiseme spravu
            continue; //aby pokracoval
        }
        catch (const Kruh::chybaNula &ex) {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            ex.getMsg();
            continue;
        }
        catch (const Kruh::chybaZaporne &ex) {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            ex.getMsg();
            continue;
        }
    }*/
        return tmp;

    }


}

int Kruh::generujSuborKruhov(const char *nazov, int kolko) {
    srand(time(NULL));
    std::ofstream fout;
    fout.open(nazov);

    try {
        if(!fout.is_open())
        {
            throw Kruh ::streamError("Nepodarilo sa otvorit subor na zapis!");
        }
    }
    catch (const Kruh::streamError &ex){ //zachytenie vynimky;
        ex.getMsg();
        return 1;
    }

    for (int i=0;i<kolko;++i){
        fout<<1+rand()%20<<" ";
    }
    fout.close();
}

Kruh *Kruh::precitajSuborKruhov(const char *nazov, int kolko) {
    std::ifstream fin;
    fin.open(nazov);
    Kruh *pole;
    try {
        pole = new Kruh[kolko];
    }
    catch (std::bad_alloc &ex){
        std::cout<<"Nepodarilo sa alokovat pamat!";
    }
    int i=-1;

    try {
        if (!fin.is_open())  //ak sa nepodarilo otvorit s !; otestovanie otvorenia subooru bez;
        {
            throw Kruh::streamError("Nepodarilo sa otvorit subor na citanie!");
        }
        while (fin>>i){
            ++i;
            (pole+1)->polomer =i;
        }
    }
    catch (const Kruh::streamError &ex){ //zachytenie vynimky;
        ex.getMsg();
        return ;//pointer na nulu ;
    }

    fin.close();
}


void Kruh::vypisPoleKruhov(Kruh *pole, int pocet) {

    for (int i=0;i<pocet;++i){
        std::cout<<*(pole+i);
    }

}

const Kruh &Kruh::operator++() const {
    ++polomer;
    return (*this); //zvacsi polomer na mne a vrat mna;
}
