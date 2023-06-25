/**
* @file IkiYonluListe2
* @description Cift tarafli bagli liste ile eklenilen verileri ekrana yazdirma, veriler üzerinde gezinme, veri silme ve cift tarafli bagli liste dugumu icerisindeki diger cift tarafli bagli liste verilerini her biri kendi dugumunun altina gelecek sekilde  dikey olarak yazdirmak
* @course 1-C
* @assignment 1.Ödev
* @date 20.11.2022
* @author Eray Sari eray.sari2@ogr.sakarya.edu.tr
*/

#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>
#include "SatirListesi.hpp"
#include "YoneticiListe.hpp"
#include <sstream>
using namespace std;


int main()
{
  
  YoneticiListe *yonetici = new YoneticiListe();
  fstream myFile;
  myFile.open("veriler.txt", ios::in);
  int satirSayac = 0;

  if(myFile.is_open())
  {
    
    string veri;
    while(getline(myFile,veri))
    {
      satirSayac++;
    }
    myFile.close();
  }
  SatirListesi* *liste = new SatirListesi*[satirSayac];
  
  myFile.open("veriler.txt", ios::in);
  if(myFile.is_open())
  {
    string veri;
    int ortalama = 0;
    satirSayac = 0;
    while (getline(myFile,veri))
    {
      if (veri.empty()) 
        continue;

      istringstream iss(veri);
      int sum = 0, next = 0;
      liste[satirSayac] = new SatirListesi(); //her satir icin yeni bir nesne olusturuluyor
      
      while (iss >> next)
      {
        sum += next;
        
        liste[satirSayac]->ekle(next); //olusturulan nesneye satirdaki sayilar ataniyor
      }
      yonetici->yListeEkle(liste[satirSayac]); // nesne yoneticiye ataniyor
      satirSayac++; 
   }
      myFile.close();
      //cout << liste;
      
      //cout << *liste;
      
      //cout << yonetici->yazdir();
  }
  //cout << *yonetici;
  yonetici->yoneticiYazdir();
}
