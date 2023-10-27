#include "Shop.hpp"

using std::cout, std::cin, std::endl;

int main(){
	Shop s;
	char comand[100];
	do{
		cout << "What do you want to do? buy/check/end: ";
		cin >> comand;
		if(!strcmp(comand, "buy")) s.buy(); // если после buy что-то было, оно останется в буфере
		else if(!strcmp(comand, "check")) cout << s;
		else if(strcmp(comand, "end")) cout << "Unknown comand, try again." << endl;
		else{
			cout << s;
		}
	}while(strcmp(comand, "end"));
	return 0; 
}
