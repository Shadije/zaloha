 //#include <iostream>cin, cout - objektxx ktore vznikli na zaklade triedy v iostream;  musime si ich zo std priedstoru zobrat = std::cin/ std::cout; istream - vstup, ostream-vystup;
#include "kruh.h"
#include<fstream> //na pracu so suborom;

 using std::cout; //importovanie cout do globalneho priestoru kde je aj main 1.
 using std::cin;
 using std::endl;
 using std::ifstream; //sluzi n vstup do suboru;
 using std::ofstream; //sluzi na vystup do suboru;

 //using namespace std;

 int main()
 {
    //citanie zo suboru
    ifstream fin; //vytvoreny objekt pre citanie zo suboru;
    fin.open ("citaj.txt"); //inicializujeme objekt konkretnym suborom;
    //alternativa: ifstream fin("citaj.txt"); otorenie suboru  pomocou konstruktora;
    ofstream fout;
    fout.open("zapis.txt");

     try{
        if(!fin.is_open())  //ak sa nepodarilo otvorit s !; otestovanie otvorenia subooru bez;
        {
            throw Kruh ::streamError("Nepodarilo sa otvorit subor na citanie!");
        }
         if(!fout.is_open())
         {
             throw Kruh ::streamError("Nepodarilo sa otvorit subor na zapis!");
         }
        Kruh K(0); //objekt do ktoreho budeme citat jednotlive kruhy
        while(fin>>K)//otestujeme, ci sa citanie podarilo; kym je citanie uspesne
        {
            cout<<K; //vypiseme precitany kruh na obrazovku;
            fout<<K; //zapiseme kruh do suboru ;
        }

        fin.close(); //uzatvorime stream;
        fout.close();
     }
     catch (const Kruh::streamError &ex){ //zachytenie vynimky;
         ex.getMsg();
         return 1;
     }





     Kruh k1(10);
     Kruh k2(5);


     Kruh Spocitane=k1+k2;
     cout<<Spocitane.getPolomer()<<endl;
   //  cout<<(k1<k2);
     std::cout<<(k1+k2).getPolomer()<<endl;

   //  Kruh Spocitane=k1+3;
  //   cout<<Spocitane.getPolomer()<<endl;
     std::cout<<(k1+3).getPolomer()<<endl;

   //  Kruh Odcitane=k1-k2;
    // cout<<Odcitane.getPolomer()<<endl;
     std::cout<<(k1-k2).getPolomer()<<endl;

     //Kruh Odcitane=k1-3;
    // cout<<Odcitane.getPolomer()<<endl;
     std::cout<<(k1-3).getPolomer()<<endl;

    // Kruh Nasobenie=k1*k2;
   //  cout<<Nasobenie.getPolomer()<<endl;
     std::cout<<(k1*k2).getPolomer()<<endl;

   //  Kruh Nasobenie=k1*3;
    // cout<<Nasobenie.getPolomer()<<endl;
     std::cout<<(k1*3).getPolomer()<<endl;

     ++k1;
     //++++k1; //skaredy zapis
     k2++;
     std::cout<<(10+k2).getPolomer()<<endl; //nedokaze pocitat cislo + kruh ale len kruh + cislo;

     //kruh*cislo, kruh +cislo, kruh-cislo,  kruh-kruh; nezaporne cislo;
    std::cout<<k1; //ak chceme pracovat so vstupom a vystupom treba iostream- vytvori sa niekolko objektov: triedy istream(objekt cin>>), ostream(cout<<), ifstream,

    //cout<<i<<j<<k; //vracia odkaz na sam seba vytlaci i, vrati odkaz na sam seba, j, vrati odkaz,... je dolezite aby vracal sam seba;


    //odteraz mozeme namiesto std::cout<<(k1-3).getPolomer()<<endl; pisat iba std::cout<<(k1-3)
    std::cin>>k2;

    const int kolko=50;
    Kruh kruhy[kolko];
    Kruh::generujPoleKruhov(kruhy, kolko);
    Kruh::vypisPoleKruhov(kruhy, kolko);

    int pocet;
    cout<<"Zadajte pocet prvkov pola:";
    cin>>pocet;

    Kruh *dynamickePole = new Kruh[pocet]; //alokacia pamate na hromade operatorom new(da sa pretazit);

    try
    {
        dynamickePole = new Kruh [pocet];
    }
    catch (std::bad_alloc &ex)
    {
        std:: cout<<"Chyba pridelenia pamate";
        return 1;
    }
    if (dynamickePole==NULL){
        cout<<"Nepodarilo sa alokovat pamat."
        exit (2);
    }
    cout<<"Povodne pole:"<<endl;
    Kruh ::generujPoleKruhov(dynamickePole, pocet);
    Kruh::vypisPoleKruhov(dynamickePole, pocet);

    cout <<"Utriedene pole:"<<endl;
    Kruh::utriedPoleKruhov(dynamickePole, pocet);
    Kruh::vypisPoleKruhov(dynamickePole, pocet);

    delete [] dynamickePole; //uvolnenie pamate;
    dynamickePole = 0;



     return 0;
}
