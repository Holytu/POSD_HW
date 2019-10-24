.PHONY : clear

all : clear bin/ut_all

bin/ut_all : test/ut_main.cpp test/ut_fs.h src/file.h src/folder.h src/iterator.h src/node.h src/null_iterator.h src/utilities.h
	g++ -std=c++11 test/ut_main.cpp -o bin/ut_all -lgtest -lpthread

clear :
	rm -f bin/*
