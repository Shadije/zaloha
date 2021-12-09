#include<stdio.h>
#include<stdlib.h>
//#define NDEBUG    
#include<assert.h>
#define POCET 10
#define RIADKY 10

void testuj (void *hodnota, const char *sprava);
void alokujPamatNoveRiadky (int zaciatok, int koniec, char **pPole);
void vypisVety (size_t pocet, char **pPole);
void uvolniVety (size_t pocet, char **pPole);
int cmp (const void *prva, const void *druha);
int cmpSamohlasky (const void *prva, const void *druha);
int vratPocetSamohlasok (const char *slovo);
//MEMCPI, MEMMOVE, STRPBRK

int main()
{
    FILE *fr; //pointer na subor;
    if((fr=fopen("text.txt", "r"))==NULL){
        puts("Subor sa nepodarilo otvorit.");
        return 1;
    }

    int znak;
    size_t pocetZnakov =0; //long int - neznamienkovz int;
    size_t pocetRealokaciiZnak=1;
    size_t pocetRiadkov=0;
    size_t pocetRealokaciiRiadky=1;


    char **pole; //pole pointerov na jednotlive riadky; t.j. pointer na pointer;

    if((pole=(char**)malloc(RIADKY*sizeof(char*)))==NULL){ //alokacia pola pointerov na char
        puts ("Problem s pamatou!");
        return 1;
    }
    for(int i=0;i<RIADKY;++i){
        if((*(pole+i)=(char*)malloc(POCET*sizeof(char)))==NULL){ //alokacia pointerov na jednotlive riadky;
            puts("Problem s pamatou!");
        }
        *(pole+i)=(char*)malloc(POCET*sizeof(char));
    }


   while((znak=getc(fr))!=EOF){

    if(znak !='\n'){ //ak nie som na konci riadka
         ++pocetZnakov;

        if(pocetZnakov%POCET==0){

            ++pocetRealokaciiZnak;

            if((*(pole+pocetRiadkov)= (char*)realloc(*(pole+pocetRiadkov), POCET*pocetRealokaciiZnak*sizeof(znak)))==NULL){
               puts("Chyba pri praci s pamatou!");
               return 1;
            }
         }

         //mas este k dispozicii volne znaky v riadku
         *(*(pole+pocetRiadkov)+pocetZnakov-1)=znak;

    }
    else{ //ak som na konci riadka
        *(*(pole+pocetRiadkov)+pocetZnakov)='\0'; //zakoncim riadok textu

        ++pocetRiadkov;

        if(pocetRiadkov%RIADKY==0) { //ak som uz minul vsetky riadky musim pridat nove

            ++pocetRealokaciiRiadky;
            if((pole=(char**)realloc(pole, RIADKY*pocetRealokaciiRiadky*sizeof(char*)))==NULL){
                    puts ("Chyba pri praci s pamatou!");
                    return 1;

        }
        pocetZnakov=0;
        pocetRealokaciiZnak=1;
    }



    }


}

    fclose(fr);
    return 0;
}
