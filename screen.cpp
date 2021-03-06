#include <iostream>
#include <fstream>
#include <vector>
#include "pixel.cpp"

class point{
	public:
		std::vector<int> v;

	point(){
		v = std::vector<int>(3, 0);
	}

	point(int x){
		v = std::vector<int>(3, 0);
		v[0] = x;
	}

	point(int x, int y){
		v = std::vector<int>(3, 0);
		v[0] = x;
		v[1] = y;
	}

	point(int x, int y, int z){
		v = std::vector<int>(3, 0);
		v[0] = x;
		v[1] = y;
		v[2] = z;
	}

	int operator[](int i){
		return v[i];
	}

	void add(int pos, int i){
		v[pos] += i;
	}
};

class screen{
	public:
		std::vector<pixel> colors;
		pixel ***grid;
		int h, w;

		screen(){
			grid = 0;
		}

		screen(int x, int y){
			w = x;
			h = y;

			colors.push_back( pixel(255, 255, 255) );
			//colors.push_back( pixel(0, 0, 0) );

			grid = new pixel**[y];
			for (int i = 0; i < h; i++){
				grid[i] = new pixel*[x];
				for(int j = 0; j < w; j++){
					grid[i][j] = &colors[0];
				}
			}

		}

		void render(){
			std::ofstream f;
			f.open("output.ppm");
			f << "P3\n";
			f << w << " " << h << "\n";
			f << "255\n";

			for(int i = 0; i < h; i++){
				for(int j = 0; j < w; j++){
					f << *(grid[i][j]);
					if (j != (w-1))
						f << " ";
				}
				if (i != (h-1))
					f << "\n";
			}

			f.close();
		}

		void plot(point& p, pixel& col){
			pixel& c = insert_color(col);

			grid[p[1]][p[0]] = &c;
		}

		pixel& insert_color(pixel& col){
			for (int i = 0; i < colors.size(); i++){
				if( colors[i] == col ){
					//delete &col;
					return colors[i];
				}
			}

			colors.push_back(col);
			return col;
		}
};
