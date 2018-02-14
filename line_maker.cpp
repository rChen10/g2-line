#include <iostream>
#include <fstream>
#include "line.cpp" 

int main(){
	screen s(500, 500);
	
	line l1 = line(0, 0, 499, 499);
	l1.draw(s);

	line l2 = line(250, 0, 250, 499);
	l2.draw(s);

	line l3 = line(499, 0, 0, 499);
	l3.draw(s);

	line l4 = line(0, 250, 499, 250);
	l4.draw(s);

	line l;

	for(int i = -50; i < 0; i++){
		l = line(250 + i, 250 + ((i + 50) * -1), 250 + (i + 50), 250 + (i * -1));
		l.set_color( pixel(255, 0, 0) );
		l.draw(s);
	}

	s.render();
}
