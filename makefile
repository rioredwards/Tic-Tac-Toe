# Project Makefile
#

all:		*.h *.cpp
		g++ -o main -std=c++11 -Wall -g *.cpp
