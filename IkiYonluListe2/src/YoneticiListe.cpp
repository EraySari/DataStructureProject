/**
* @file IkiYonluListe2
* @description Cift tarafli bagli liste ile eklenilen verileri ekrana yazdirma, veriler üzerinde gezinme, veri silme ve cift tarafli bagli liste dugumu icerisindeki diger cift tarafli bagli liste verilerini her biri kendi dugumunun altina gelecek sekilde  dikey olarak yazdirmak
* @course 1-C
* @assignment 1.Ödev
* @date 20.11.2022
* @author Eray Sari eray.sari2@ogr.sakarya.edu.tr
*/

#include "YoneticiListe.hpp"

YoneticiListe::YoneticiListe()
{
  listeIlk = 0;
  dugumSayisiYonetici = 0;
}
YoneticiListe::~YoneticiListe()
{
  delete listeIlk;
}
void YoneticiListe::yListeEkle(SatirListesi *satirVeri)
{
  if(listeIlk == 0)
  {
    listeIlk = satirVeri;
    return;
  }
  else
  {
    SatirListesi *geciciListe = listeIlk;

      //eger ilk ortalamadan kucukse
      if(satirVeri->ortalama <= listeIlk->ortalama)
      {
        satirVeri->listeSonraki  = listeIlk;
        listeIlk->listeOnceki = satirVeri;      
        satirVeri->listeOnceki = 0;
        listeIlk = satirVeri;
        dugumSayisiYonetici++;
        return;
      }
      //degilse kucuk olani bulana kadar gecici listeyi ileri goturuyoruz
      while(geciciListe->listeSonraki != 0 && geciciListe->ortalama < satirVeri->ortalama)
        geciciListe = geciciListe->listeSonraki;

      if(satirVeri->ortalama <= geciciListe->ortalama)
      {
        geciciListe->listeOnceki->listeSonraki = satirVeri;
        satirVeri->listeOnceki = geciciListe->listeOnceki;
        geciciListe->listeOnceki = satirVeri;
        satirVeri->listeSonraki = geciciListe;
      }
      else
      {
        geciciListe->listeSonraki = satirVeri;
        satirVeri->listeOnceki = geciciListe;
      }
  }
  dugumSayisiYonetici++;
}
void YoneticiListe::yListeCikar(SatirListesi* yoneticiDugum)
{
  if(yoneticiDugum->listeOnceki == 0 && yoneticiDugum->listeSonraki == 0)
  {
    listeIlk = 0;
  } 
  else if(yoneticiDugum->listeOnceki == 0 && yoneticiDugum->listeSonraki != 0)
  {
    yoneticiDugum->listeSonraki->listeOnceki = 0;
  }
  else if(yoneticiDugum->listeOnceki != 0 && yoneticiDugum->listeSonraki != 0)
  {
    yoneticiDugum->listeSonraki->listeOnceki = yoneticiDugum->listeOnceki;
    yoneticiDugum->listeOnceki->listeSonraki = yoneticiDugum->listeSonraki;
  }
  else
  {
    yoneticiDugum->listeOnceki->listeSonraki = 0;  
  }
  return;
}
void YoneticiListe::sayfaIsaret(SatirListesi* satirVeri)
{
        if(satirVeri->listeOnceki == 0)
        {
          cout << left << setw(110) << "ilk";
          cout << "-->";
        }
        else if(satirVeri == 0)
        {
          cout << left << setw(110) << "<--";
          cout << "son";
        }
        else
        {
          cout << left << setw(110) << "<--";
          cout << "-->";
        }
        cout << endl;
}
SatirListesi* YoneticiListe::yoneticiDugumGetir(int dugum)
{
  SatirListesi *gecici = listeIlk;
  int sayac = 0;
  while (gecici != 0)
  {
    if(dugum == sayac){
      return gecici;
    }
    gecici = gecici->listeSonraki;
    sayac++;
  }
  return 0;
}
void YoneticiListe::adresYazdir(int nodeSayisi, SatirListesi* geciciListe)
{
  for(int i = 0; i<nodeSayisi; i++)
  {
    cout << " " << left << setw(9) <<  geciciListe << "     ";
    geciciListe = geciciListe->listeSonraki;
  }
  cout << endl;
}
void YoneticiListe::cizgiYazdir(int nodeSayisi)
{
  for(int i = 0; i<nodeSayisi; i++)
        {
          cout << "-----------" << "    ";

        }
        cout << endl;
}
void YoneticiListe::oncekiAdres(int nodeSayisi, SatirListesi* geciciListe)
{
  for(int i = 0; i<nodeSayisi; i++)
  {
    cout << "|" << left << setw(9) << geciciListe->listeOnceki << "|" << "    ";
    geciciListe = geciciListe->listeSonraki;

  }
}
void YoneticiListe::sonrakiAdres(int nodeSayisi, SatirListesi*& geciciListe)
{
  for(int i = 0; i<nodeSayisi; i++)
  {
    cout << "|" << left << setw(9) << geciciListe->listeSonraki << "|" << "    ";
    geciciListe = geciciListe->listeSonraki;
  }
}
double YoneticiListe::ortalamaYazdir(int nodeSayisi, SatirListesi* geciciListe)
{
  
  for(int i = 0; i<nodeSayisi; i++)
        {
          cout << "|" << right << setw(9) << geciciListe->ortalama << "|" << "    ";
          geciciListe = geciciListe->listeSonraki;
        }
}
int YoneticiListe::dugumSayisi(SatirListesi* geciciListe)
{
  int nodeSayisi = 0;
  for(int i = 0; i<8; i++)
        {
          if(geciciListe->listeSonraki == 0)
          {
            nodeSayisi++;

            break;
          }
                
          nodeSayisi++;
          geciciListe = geciciListe->listeSonraki;
        }
        return nodeSayisi;
}
void YoneticiListe::dugumSecici(int index,int nodeSayisi,string& wr)
{
        for(int i = 0; i<index*15;i++)
        {
          if(index*15 < nodeSayisi*15)
            wr += " ";
          else
            index--;
        }
        cout << wr <<"^^^^^^^^^^^"<<endl;
}
void YoneticiListe::yoneticiYazdir()
{
  SatirListesi* geciciListe = listeIlk;
  SatirListesi* geciciYedek = listeIlk;
  SatirListesi* dugumSec = listeIlk;
  SatirListesi* yazdirilacak = listeIlk;
  SatirListesi* eskiGecici;
  

  int nodeSayisi = 0;
  int index = 0;
  int indexTutucu = 0;
  int toplamNodeSayisi = 0;
  string wr="";   
  char ch;
  while (true)
      {
        //system("cls");
        eskiGecici = geciciListe;
        geciciListe = geciciYedek;        
        //Node sayisini belirleme
        nodeSayisi = 0;
        nodeSayisi = dugumSayisi(geciciListe);
        geciciListe = geciciYedek;
        cout << geciciListe << endl;


        //<--, --> yazdrima
        sayfaIsaret(geciciListe);

        //kendi adresini yazdirma
        adresYazdir(nodeSayisi, geciciListe);
        cizgiYazdir(nodeSayisi);

        //onceki adresini yazdrima
        oncekiAdres(nodeSayisi, geciciListe);
        cout << endl;
        cizgiYazdir(nodeSayisi);

        //Ortalama yazdirma
        ortalamaYazdir(nodeSayisi, geciciListe);
        cout << endl;
        cizgiYazdir(nodeSayisi);

        //Sonraki yazdirma
        sonrakiAdres(nodeSayisi, geciciListe);
        cout << endl;
        cizgiYazdir(nodeSayisi);

        //Liste dugumlerini yazdirma
        dugumSecici(index,nodeSayisi,wr);
        yoneticiDugumGetir(indexTutucu)->listeYazdir(yoneticiDugumGetir(indexTutucu)->sutunSayisi,wr);
        cout << endl;

        //SECIM BOLUMU
        cin >> ch;
        if (ch == 'z' && index != 0)
        {
          
          index--;
          indexTutucu--;

          yazdirilacak = yazdirilacak->listeOnceki;
          geciciListe = eskiGecici;
          cout<<"yazdirilacak z " << yazdirilacak << endl;
        }         
        else if (ch == 'c' && index < nodeSayisi-1)   
        {          
          geciciListe = eskiGecici;
          yazdirilacak = eskiGecici;
          if(yazdirilacak->listeSonraki != 0)
          {
          index++;
          indexTutucu++;
          for(int i = 0; i<index; i++)
          {
            yazdirilacak = yazdirilacak->listeSonraki;
          }         
          }  
        } 
        else if(ch == 'a')
        {
          if (geciciYedek->listeOnceki != 0)
          {
            SatirListesi* eskiYedek = eskiGecici;
            for(int i = 0; i<8; i++)
            {
              eskiYedek = eskiYedek->listeOnceki;
            }
            index = 0;
            geciciYedek = eskiYedek;
            toplamNodeSayisi -= nodeSayisi;
            indexTutucu = toplamNodeSayisi;
          }
        }
        else if(ch == 'd')
        {       
          if(geciciListe != 0)
          {
            toplamNodeSayisi += nodeSayisi;
            geciciYedek = geciciListe;
            yazdirilacak = geciciListe;
            index = 0;
            indexTutucu += (toplamNodeSayisi-indexTutucu);
          }
        } 
        else if(ch == 'p')
        {
          cout << "dugum adresss " << yoneticiDugumGetir(indexTutucu) <<endl;
        }
        else
        {
          geciciListe = eskiGecici;
        }
        wr = "";      
      }
}