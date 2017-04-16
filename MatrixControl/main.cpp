#include"CLEDMatrix.hpp"

int main(int argc, char **argv) {
	if (argc != 7 && argc != 5 && argc != 3) {
		std::cout << "MatrixControl <FB_Path> <x> <y> <r> <g> <b>" << std::endl;
		std::cout << "MatrixControl <FB_Path> <r> <g> <b>" << std::endl;
		std::cout << "MatrixControl <FB_Path> <IMG_Path>" << std::endl;
		return 0;
	}
	
	try {
		CLEDMatrix ledmatrix;
		ledmatrix.initFB(argv[1]);
		if (argc == 7) {
			ledmatrix.setPixel(std::stoi(argv[2]), std::stoi(argv[3]),
				std::stoi(argv[4]), std::stoi(argv[5]), std::stoi(argv[6]));
		} else if(argc == 3) {
			ledmatrix.displayImage(argv[2]);
		} else {
			ledmatrix.clearMatrix(std::stoi(argv[2]), std::stoi(argv[3]), std::stoi(argv[4]));
		}
	}catch(int e){
		std::cout << "ERROR: " << e << std::endl;
	}

	return 0;
}