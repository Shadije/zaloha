//
// Created by map on 9. 11. 2021.
//

#include "trojuholnik.h"
#include<cmath>

using std::cout;
using std::cin;
using std::endl;

Bod::Bod() {
    x=0;
    y=0;
}

Bod::Bod(float a) {
    this->x =a;
    this->y =a;
}

Bod::Bod(float a, float b) {
    this->x=a;
    this->y=b;
}

std::ostream &operator<<(std::ostream &os, const Bod &mojBod) {
    os<<"Suradnice bodu su ["std::setprecision(4)<<mojBod.x<<";"<<mojBod.y<<"]"<<endl;
    return os;
}

std::istream &operator>>(std::istream &is, Bod &mojBod) {
    is>>mojBod.x>>mojBod.y;
    return is;
}

Bod Bod ::operator+( const Bod &other) const {
    return Bod(other.x+x, other.y+y);
}

Bod Bod ::operator*(const int cislo) const {
    return Bod(x*cislo, y*cislo);
}
Bod Bod :: operator *(int cislo, const Bod &other){
    return other*cislo;
}

Bod Bod:: operator /(int cislo){
    return Bod (x/cislo, y/cislo);
}

Bod Bod:: operator -(const Bod &other){
    return Bod(x-other.x, y-other.y);
}

bool Bod operator <(const Bod &other)
{
  return *this<other;
}

bool Bod operator>(const Bod &other)
{
  return *this>other;
}

float Bod:: getDistance (const Bod &other=Bod (0,0)) const{
    Bod novy;
    novy.x = x-other.x;
    novy.y = y-other.y;
    float prvy = sqrt ((novy.x*novy.x)+(novy.y*novy.y));
    return prvy;
}

Bod Bod:: getCenter (const Bod &other) const{
    return ((*this)+other)/2.f;
}

Bod Bod::operator^(constBod &other)const{
  return this->getCenter(other);
}

Bod::operator float() const {
    return this->getDistance(Bod(0,0));
}

void Bod::generujPoleBodov(Bod *pole, const int pocet) {
    srand (time(NULL));
    Bod *poleBodov;
  try{
    pole = new Bod[pocet];
    for (int i=0;i<pocet;++i) {
        (pole + i)->x = 1 + std::rand() % 99;
        (pole + i)->y = 1 + std::rand() % 99;
    }
  }
  catch (const std::bad_alloc &ex)
  {
    std::cout <<"Chybna alokacia pamate.";
    return NULL;
  }
  return pole;
}

void Bod::vypisPoleBodov(const Bod *pole, const int pocet) {
  for(int i=0;i<pocet;++i){
    cout<<*(pole+i)<<" ";
  }
}

int Bod::cmp(const void *prvy, const void *druhy) {
    Bod *A=(Bod*)prvy;
    Bod *B=(Bod*)druhy;
    
    return ((float)(*A)<(float)(*B))?1:((float)(*A)>(float)(*B))?-1:0;
}


  
