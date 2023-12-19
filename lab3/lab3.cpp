#include <iostream>
#include <cstring> 
#include <fstream>
#include <stdio.h>
#include <list>

class Book{
	std::string name;
	std::string author;
	int year;
	
public:
	Book(): name(""), author(""), year(0){};
	Book(const Book& b): name(b.name), author(b.author), year(b.year){};
	Book(char* _name, char* _author, int _year): name(_name), author(_author), year(_year){};

	bool operator< (Book&);
	static bool cmpAuthor(Book&, Book&);
	bool eqau(char*);
	bool eqnm(char*);
	bool eqyr(int);

	friend std::fstream& operator<< (std::fstream&, Book&);
	friend std::ostream& operator<< (std::ostream&, Book&);
	friend std::istream& operator>> (std::istream&, Book&);
};

bool Book::operator<(Book& b){
	return this->year < b.year;
}

bool Book::cmpAuthor(Book& a, Book& b){
	return a.author < b.author;
}

bool Book::eqau(char* a){
	std::string author(a);
	return author == this->author;
}

bool Book::eqnm(char* a){
	std::string name(a);
	return name == this->name;
}

bool Book::eqyr(int a){
	int year(a);
	return a == this->year;
}

std::fstream& operator<<(std::fstream& o, Book& b){
	o << std::endl << b.name << ", " << b.author << ", " << b.year;
	return o;
};

std::ostream& operator<<(std::ostream& o, Book& b){
	o << b.name << " " << b.author << " " << b.year;
	return o;
};

std::istream& operator>> (std::istream& i, Book& b){
	char name[100];
	i.getline(name, 999, ',');
	if(strlen(name) == 0){
		std::cerr << "Error while parsing name." << std::endl;
		i.setstate(std::ios::failbit);
		return i;
	}
	char author[100];
	i.getline(author, 999, ',');
	if(strlen(name) == 0){
		std::cerr << "Error while parsing author." << std::endl;
		i.setstate(std::ios::failbit);
		return i;
	}
	int year;
	i >> year;
	i.ignore(999, '\n');
	b = Book(name, author, year);
	return i;
};

int main(int argc, char* argv[]){

	std::fstream file;
	if(argc > 1){
		file.open(argv[1], std::ios::in | std::ios::app);
	}
	else{
		std::cout << "Enter file name: ";
		std::string filename;
		std::cin >> filename;
		file.open(filename, std::ios::in | std::ios::app);
	}

	if(file.is_open()){

		std::list<Book> lib;

		while(!file.eof()){
			Book temp;
			if(file >> temp){
				lib.emplace_back(temp);
			}	
			else break;
		}
		file.clear();

		char comand[100];
		do{
			std::cout << "What do you want to do? add/sort/list/search: ";
			std::cin >> comand;
			std::cin.get();
			if(!strcmp(comand, "add")){
				Book temp;
				std::cout << "Enter name, author, year: ";
				if(std::cin >> temp){
					file << temp;
					lib.emplace_back(temp);
				}
				else{
					std::cerr << "Invalid arguments" << std::endl;
					return -2;
				}
			}
			else if(!strcmp(comand, "sort")){
				std::cout << "Do you want to sort by year or by author? ";
				std::cin >> comand;
				if(!strcmp(comand, "year")){
					lib.sort();
				}
				else if(!strcmp(comand, "author")){
					lib.sort(Book::cmpAuthor);
				}
				else{
					std::cerr << "Unknown argument" << std::endl;
					return -3;
				}
			}
			else if(!strcmp(comand, "list")){
				for(Book& b : lib){
					std::cout << b << std::endl;
				}
			}
			else if(!strcmp(comand, "search")){
				std::cout << "Do you want to search by author, name, year or yearbefore? ";
				std::cin >> comand;
				if(!strcmp(comand, "author")){
					bool f(true);
					std::cin.getline(comand, 999);
					for(Book& b : lib){
						if(b.eqau(comand)){
							std::cout << b << std::endl;
							f = false;
							break;
						}
					}
					if(f) std::cout << "Nothing found." << std::endl;
				}
				else if(!strcmp(comand, "name")){
					bool f(true);
					std::cin.getline(comand, 999);
					for(Book& b : lib){
						if(b.eqnm(comand)){
							std::cout << b << std::endl;
							f = false;
							break;
						}
					}
					if(f) std::cout << "Nothing found." << std::endl;
				}
				else if(!strcmp(comand, "year")){
					bool f(true);
					int a;
					std::cin >> a;
					for(Book& b : lib){
						if(b.eqyr(a)){
							std::cout << b << std::endl;
							f = false;
							break;
						}
					}
					if(f) std::cout << "Nothing found." << std::endl;
				}
				else if(!strcmp(comand, "yearbefore")){
					bool f(true);
					int a;
					std::cin >> a;
					Book c("", "", a);
					for(Book& b : lib){
						if(b < c){
							std::cout << b << std::endl;
							f = false;
						}
					}
					if(f) std::cout << "Nothing found." << std::endl;
				}
				else{
					std::cerr << "Unknown argument" << std::endl;
					return -3;
				}
			}
			else if(!strcmp(comand, "count")){
				std::cout << lib.size() << std::endl;
			} 
			else{
				break;
			}
		}while(strcmp(comand, "end"));
		file.close();
	}
	else{
		std::cerr << "Error: no such file" << std::endl;
		return -1;
	}
	return 0;
}