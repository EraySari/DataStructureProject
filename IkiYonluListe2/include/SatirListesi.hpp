/**
* @file IkiYonluListe2
* @description Cift tarafli bagli liste ile eklenilen verileri ekrana yazdirma, veriler üzerinde gezinme, veri silme ve cift tarafli bagli liste dugumu icerisindeki diger cift tarafli bagli liste verilerini her biri kendi dugumunun altina gelecek sekilde  dikey olarak yazdirmak
* @course 1-C
* @assignment 1.Ödev
* @date 20.11.2022
* @author Eray Sari eray.sari2@ogr.sakarya.edu.tr
*/

#ifndef SatirListesi_hpp
#define SatirListesi_hpp
#include<exception>
#include "Dugum.hpp"
#include<iostream>
#include <iomanip>
using namespace std;
class SatirListesi
{
public:    
    SatirListesi();
    ~SatirListesi();    
    SatirListesi *listeSonraki;
    SatirListesi *listeOnceki;
    int sutunSayisi;
    double ortalama;
    void ekle(int veri);
    void cikar();
    void listeYazdir(int dugumSayi,string bosluk);
    double ortalamaAl();
    Dugum *dugumGetir(int sira);
private:
    Dugum *ilk;
};
#endif
