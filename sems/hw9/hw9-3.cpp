#include <iostream>
#include <fstream>
#include <cstring>

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

	if(file.is_open()){
		uint cnt = 0;
		float avgage;
		float avgsal;
		char line[9999];
		while(true){
			file.getline(line, 9999);
			float currentsal, currentage;
			char* position = strchr(line, ',');
			if(position != nullptr && sscanf(position + 1, "%f, %f", &currentage, &currentsal) == 2){
				avgage = (avgage * (cnt++) + currentage) / cnt;
				avgsal = (avgsal * (cnt-1) + currentsal) / cnt;
			}
			else if(strlen(line) > 0){
				std::cerr << "Error while reading csv file." << std::endl;
				return -2;
			}
			if(file.eof()) break; 
		} 

		file.close();
		std::cout << "Average age is " << avgage << std::endl;
		std::cout << "Average salary is " << avgsal << std::endl;
	}
	else{
		std::cerr << "Error: no such file" << std::endl;
		return -1;
	}
}