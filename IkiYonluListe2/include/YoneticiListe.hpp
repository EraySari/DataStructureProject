/**
* @file IkiYonluListe2
* @description Cift tarafli bagli liste ile eklenilen verileri ekrana yazdirma, veriler üzerinde gezinme, veri silme ve cift tarafli bagli liste dugumu icerisindeki diger cift tarafli bagli liste verilerini her biri kendi dugumunun altina gelecek sekilde  dikey olarak yazdirmak
* @course 1-C
* @assignment 1.Ödev
* @date 20.11.2022
* @author Eray Sari eray.sari2@ogr.sakarya.edu.tr
*/

#ifndef YoneticiListe_hpp
#define YoneticiListe_hpp
#include "SatirListesi.hpp"

class YoneticiListe
{
public:
  int dugumSayisiYonetici;
  YoneticiListe();
  ~YoneticiListe();
  void yListeEkle(SatirListesi* satirVeri);
  void yListeCikar(SatirListesi* satirVeri);
  void sayfaIsaret(SatirListesi* satirVeri);
  SatirListesi* yoneticiDugumGetir(int dugum);
  void adresYazdir(int nodeSayisi, SatirListesi* gecici);
  void cizgiYazdir(int nodeSayisi);
  void oncekiAdres(int nodeSayisi, SatirListesi* gecici);
  void sonrakiAdres(int nodeSayisi, SatirListesi*& gecici);
  double ortalamaYazdir(int nodeSayisi, SatirListesi* gecici); 
  void dugumSecici(int index,int nodeSayisi,string& wr);
  void yoneticiYazdir(); 
  int dugumSayisi(SatirListesi* liste);

private:
  SatirListesi *listeIlk;
};

#endif
