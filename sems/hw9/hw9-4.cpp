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
		uint cnt(0), maxcnt(0);
		char* longestword = nullptr;
		char* word = nullptr;
		char sym;
		while(true){
			file >> std::noskipws >> sym;
			if(file.eof()) break; 
			if(!isalnum(sym)){
				if(cnt > maxcnt){
					maxcnt = cnt;
					delete[] longestword;
					char* temp = new char[cnt];
					for(uint i = 0; i < cnt; ++i) temp[i] = word[i];
					longestword = temp;
				}
				delete[] word;
				word = nullptr;
				cnt = 0;
			}
			else{
				char* temp = new char[cnt + 1];
				for(uint i = 0; i < cnt; ++i) temp[i] = word[i];
				temp[cnt++] = sym; 
				delete[] word;
				word = temp;
			}
		}

		std::cout << "Longest word is \"" << longestword << "\"" << std::endl;
		std::cout << "It's length is " << maxcnt << std::endl;

		delete[] longestword;
	}
	else{
		std::cerr << "Error: no such file" << std::endl;
		return -1;
	}
}