#Makefile for P04 
CXXFLAGS += --std=c++17

all:trains

debug: CXXFLAGS+= -g
debug: trains

rebuild: clean trains

trains: main.o stock.o coach.o locomotive.o train.o *.h
	$(CXX) $(CXXFLAGS) -o trains main.o stock.o coach.o locomotive.o train.o

main.o: main.cpp *.h
	$(CXX) $(CXXFLAGS) -c main.cpp
stock.o: stock.cpp *.h
	$(CXX) $(CXXFLAGS) -c stock.cpp
coach.o: coach.cpp *.h
	$(CXX) $(CXXFLAGS) -c coach.cpp
locomotive.o: locomotive.cpp *.h
	$(CXX) $(CXXFLAGS) -c locomotive.cpp
train.o: train.cpp *.h
	$(CXX) $(CXXFLAGS) -c train.cpp

clean:
	rm -f *.0 *.gch *~ trains
