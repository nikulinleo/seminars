#include <iostream>
#include <fstream>
#include <cstring>

class Student{
private:
	char name[999];
	uint age, score;
	
public:
	Student(): age(0), score(0){for(int i = 0; i < 999; name[i++] = '\0');};

	Student& operator = (Student&);
	int operator > (Student&);
	friend std::ifstream& operator >>(std::ifstream&, Student&);
	friend std::ostream& operator << (std::ostream&, Student&);
};

Student& Student::operator=(Student& other){
	this->age = other.age;
	this->score = other.score;
	for(int i = 0; i < strlen(other.name) + 1; ++i){
		this -> name[i] = other.name[i];
	}
	return *this;
}

int Student::operator>(Student& other){
	if(this -> score > other.score) return 1;
	else return -1;
}

std::ifstream& operator >>(std::ifstream& i, Student& s){
	i.getline(s.name, 999);
	if(strlen(s.name) <= 0){
		if(!i.eof()){
			std::cerr << "Error while reading csv file." << std::endl;
			i.setstate(std::ios::failbit);
		}
		return i;
	}
	strtok(s.name, ",\0");
	char* ptr = strtok(NULL, ",\0");
	if(ptr == nullptr || sscanf(ptr, "%d", &s.age) != 1){
		std::cerr << "Error while reading csv file." << std::endl;
		i.setstate(std::ios::failbit);
		return i;
	}
	ptr = strtok(NULL, ",\0");
	if(ptr == nullptr || sscanf(ptr, "%d", &s.score) != 1){
		std::cerr << "Error while reading csv file." << std::endl;
		i.setstate(std::ios::failbit);
		return i;
	}
	return i;
}

std::ostream& operator << (std::ostream& o, Student& stud){
	for(int i = 0; i < strlen(stud.name); ++i) o << stud.name[i];
	o << " at age " << stud.age << " y.o.";
	return o;
}

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
		Student best;
		while(!file.eof()){
			Student temp;
			if(file >> temp){
				if((temp > best) > 0) best = temp;
			}	
			else break;
		}

		std::cout << "Best student is " << best << std::endl;
	}
	else{
		std::cerr << "Error: no such file" << std::endl;
		return -1;
	}
}