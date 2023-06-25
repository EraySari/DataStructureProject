all:derle bagla calistir
derle:
	g++ -c -I "./include" ./src/main.cpp -o ./lib/main.o
	g++ -c -I "./include" ./src/YoneticiListe.cpp -o ./lib/YoneticiListe.o
	g++ -c -I "./include" ./src/SatirListesi.cpp -o ./lib/SatirListesi.o
	g++ -c -I "./include" ./src/Dugum.cpp -o ./lib/Dugum.o

bagla:
	g++ ./lib/YoneticiListe.o ./lib/SatirListesi.o ./lib/Dugum.o ./lib/main.o -o ./bin/program
calistir:
	./bin/program