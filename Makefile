CC=g++
CFLAGS=-I.

maingtk: maingtk.cpp 
	$(CC) `pkg-config --cflags gtk+-3.0` -o maingtk maingtk.cpp `pkg-config --libs gtk+-3.0`

gladegtk: gladegtk.cpp 
	$(CC) `pkg-config --cflags gtk+-3.0` -o gladegtk gladegtk.cpp `pkg-config --libs gtk+-3.0`

