.PHONY : clean

all : clean dirs bin/ut_all

bin/ut_all : test/ut_sort.h src/main.cpp src/triangle.h src/circular_sector.h src/ellipse.h
	g++ -std=c++11 src/main.cpp -o bin/ut_all -lgtest -lpthread

dirs :
	mkdir -p bin
clean :
	rm -f bin/*
