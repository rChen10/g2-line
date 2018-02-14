all: line_maker.cpp line
	g++ line_maker.cpp
	./a.out
pixel: pixel.cpp
	g++ pixel.cpp -c

line: pixel line.cpp
	g++ line.cpp -c

