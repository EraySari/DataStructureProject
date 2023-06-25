/**
* @file IkiYonluListe2
* @description Cift tarafli bagli liste ile eklenilen verileri ekrana yazdirma, veriler üzerinde gezinme, veri silme ve cift tarafli bagli liste dugumu icerisindeki diger cift tarafli bagli liste verilerini her biri kendi dugumunun altina gelecek sekilde  dikey olarak yazdirmak
* @course 1-C
* @assignment 1.Ödev
* @date 20.11.2022
* @author Eray Sari eray.sari2@ogr.sakarya.edu.tr
*/

#include "SatirListesi.hpp"
#include<iostream>
SatirListesi::SatirListesi()
{
    ilk = 0;
    listeOnceki = 0;
    listeSonraki = 0;
    sutunSayisi = 0;
    ortalama = 0;
}
SatirListesi::~SatirListesi()
{
  delete ilk;
  delete listeOnceki;
  delete listeSonraki;
}
void SatirListesi::ekle(int veri)
{
  Dugum *yeni = new Dugum(veri);  

  if(ilk == 0)
  {
    ilk = yeni;
    ortalama = ortalamaAl();
  }
  else
  {
    Dugum *gec = ilk;
    while (gec->sonraki != 0)
    {
      gec = gec->sonraki;
    }
    gec->sonraki = yeni;
    yeni->onceki = gec;
    ortalama = ortalamaAl();
  }
  sutunSayisi++;
}
void SatirListesi::cikar()
{
        if(ilk == 0) return;
        if(ilk->sonraki == 0)
        {
            delete ilk;
            ilk = 0;
            return;
        }

        Dugum *gec = ilk;
        while (gec->sonraki != 0)
        {
            gec = gec->sonraki;
        }
        gec->onceki->sonraki = 0;
        delete gec;
}
Dugum *SatirListesi::dugumGetir(int sira)
{
        Dugum *gec = ilk;
        int sayac = 0;
        while (gec != 0)
        {
            if(sayac == sira)
            {
                return gec;
            }
            gec = gec->sonraki;
            sayac++;
        }
        return 0;
}
double SatirListesi::ortalamaAl()
{
  int satirSayisi = 1;
  int toplam = 0;
  Dugum *gec = ilk;
  while (gec != 0)
  {
    toplam += gec->veri;
    gec = gec->sonraki;
    satirSayisi++;
  }
  return toplam / (float)(satirSayisi -1);
}
void SatirListesi::listeYazdir(int dugumSayi,string bosluk)
{
  Dugum *gecici = ilk;
  for(int i = 0; i<dugumSayi;i++)
  {
    cout << bosluk << right << setw(10) << gecici << "    " << endl;
    cout << bosluk << "-----------"<<endl;
    cout << bosluk << "|" << right << setw(9) << gecici->veri << "|" << "    " << endl;
    cout << bosluk << "-----------"<<endl;
    cout << bosluk << "|" << right << setw(9) << gecici->sonraki << "|" << "    " << endl;
    cout << bosluk << "-----------"<<endl;
    cout << bosluk << endl;
    gecici = gecici ->sonraki;
  }

}