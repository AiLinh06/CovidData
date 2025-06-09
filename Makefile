assignment4: main.o CovidDB.o DataEntry.o
	g++ -Wall -Werror -pedantic -std=c++11 -o assignment4 main.o CovidDB.o DataEntry.o

main.o: main.cpp CovidDB.h DataEntry.h
	g++ -Wall -Werror -pedantic -std=c++11 -c main.cpp -o main.o

CovidDB.o: CovidDB.cpp CovidDB.h DataEntry.h
	g++ -Wall -Werror -pedantic -std=c++11 -c CovidDB.cpp -o CovidDB.o

DataEntry.o: DataEntry.cpp DataEntry.h
	g++ -Wall -Werror -pedantic -std=c++11 -c DataEntry.cpp -o DataEntry.o
