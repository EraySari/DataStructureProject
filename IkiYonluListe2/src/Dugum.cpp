/**
* @file IkiYonluListe2
* @description Cift tarafli bagli liste ile eklenilen verileri ekrana yazdirma, veriler üzerinde gezinme, veri silme ve cift tarafli bagli liste dugumu icerisindeki diger cift tarafli bagli liste verilerini her biri kendi dugumunun altina gelecek sekilde  dikey olarak yazdirmak
* @course 1-C
* @assignment 1.Ödev
* @date 20.11.2022
* @author Eray Sari eray.sari2@ogr.sakarya.edu.tr
*/

#include "Dugum.hpp"

Dugum::Dugum(int veri)
{
        this->veri = veri;
        sonraki = onceki = 0;
}