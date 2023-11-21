#include <iostream>
#include <list>
#include <string>

class Book{
	std::string name;
	std::string author;
	uint year;
	bool avaliable;

public:
	Book(std::string _name, std::string _author, uint _year):name(_name), author(_author), year(_year), avaliable(true){};
	Book():name(""), author(""), year(0), avaliable(false){};

	void changestatus(){avaliable = !avaliable;};
	bool getstatus(){return avaliable;};

	friend std::ostream& operator <<(std::ostream&, Book&);
};

std::ostream& operator <<(std::ostream& o, Book& b){
	o << b.name << " by " << b.author << ", written in " << b.year << " - " << (b.avaliable?"":"un") << "avaliable";
	return o;
}

std::ostream& operator <<(std::ostream& o, std::list<Book>& l){}

int main(){
	std::list<Book> lib;
	std::string entry;

	lib.emplace_front("kjsvnd", "kdjdfsd", 1980);

	while(true){
		std::cin >> entry;
		if(entry == "list"){
			for(Book b: lib) std::cout << b << std::endl;
		}
	}


	lib.emplace_front("kjsvnd", "kdjdfsd", 1980);

	for(Book b: lib){
		std::cout << b << std::endl;
	}

}