CXXFLAGS += --std=c++17
GTKFLAGS = `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`

all: mass

mass: main.o mainwin.o animal.o dog.o shelter.o client.o cat.o rabbit.o *.h
	$(CXX) $(CXXFLAGS) main.o mainwin.o animal.o dog.o shelter.o client.o cat.o rabbit.o $(GTKFLAGS) -o mass
main.o: main.cpp *.h
	$(CXX) $(CXXFLAGS) -c main.cpp $(GTKFLAGS) -o main.o
mainwin.o: mainwin.cpp *.h
	$(CXX) $(CXXFLAGS) -c mainwin.cpp $(GTKFLAGS) -o mainwin.o
animal.o: animal.cpp *.h
	$(CXX) $(CXXFLAGS) -c animal.cpp -o animal.o
dog.o: dog.cpp *.h
	$(CXX) $(CXXFLAGS) -c dog.cpp -o dog.o
shelter.o: shelter.cpp *.h
	$(CXX) $(CXXFLAGS) -c shelter.cpp -o shelter.o
client.o: client.cpp *.h
	$(CXX) $(CXXFLAGS) -c client.cpp -o client.o
cat.o: cat.cpp *.h
	$(CXX) $(CXXFLAGS) -c cat.cpp -o cat.o
rabbit.o: rabbit.cpp *.h
	$(CXX) $(CXXFLAGS) -c rabbit.cpp -o rabbit.o 
 

clean:
	rm -f *.o *.gch a.out mass 

