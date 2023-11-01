#include <iostream>
#include <fstream>

int main(int argc, char* argv[]){
	std::ifstream file;
	if(argc > 1){
		file = std::ifstream(argv[1]);
	}
	else{
		std::cout << "Enter file name: ";
		std::string filename;
		std::cin >> filename;
		file = std::ifstream(filename);
	}

	uint cnt = 0; 
	if(file.is_open()){
		char sym;
		do{
			file >> sym;
			sym = std::tolower(sym);
			switch(sym){
				case 'a':
				case 'e':
				case 'i':
				case 'o':
				case 'u':
					++cnt;
					break;
			}
		}while(!file.eof());

		std::cout << "Quantity of aioeu is " << cnt << std::endl;
		file.close();
	}
	else{
		std::cerr << "Error: no such file";
		return -1;
	}

	return 0;
}