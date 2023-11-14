#include <iostream>
#include <fstream>

int main(int argc, char* argv[]){
	std::ifstream* files;
	std::ofstream output;

	if(argc > 1){
		files = new std::ifstream[argc - 1];
		for(int i = 0; i < argc - 1; ++i){
			files[i] = std::ifstream(argv[1 + i]);
		}
	}
	else{
		files = new std::ifstream[2];
		std::cout << "Enter first file name: ";
		std::string filename;
		std::cin >> filename;
		files[0] = std::ifstream(filename);
		std::cout << "Enter second file name: ";
		std::cin >> filename;
		files[1] = std::ifstream(filename);
		argc = 3;
	}

	output = std::ofstream("merged_files.txt");

	for(int i = 0; i < argc - 1; ++i){
		if (files[i].is_open()){
			char sym;
			while(true){
				files[i] >> std::noskipws >> sym;
				if(!files[i].eof()) output << sym;
				else break;
			}
			output << std::endl;
			files[i].close();
		}
		else{
			std::cerr << "Unable to open file.";
		}
	}
	
	output.close();
	delete[] files; 

	std::cout << "Merge finished" << std::endl;
	return 1;
}