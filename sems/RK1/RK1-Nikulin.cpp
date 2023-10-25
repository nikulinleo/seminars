#include "Shop.hpp"

using std::cout, std::cin, std::endl;

int main(){
	Shop s;
	char comand[100];
	do{
		cout << "Что Вы хотите сделать? Купить/Подытог/Конец: ";
		cin >> comand;
		if(!strcmp(comand, "Купить")) s.buy();
		else if(!strcmp(comand, "Подытог")) cout << s;
		else if(strcmp(comand, "Конец")) cout << "Неизвестный ввод, попробуйте еще раз." << endl;
		else{
			cout << s;
			break;
		}
	}while(strcmp(comand, "Конец"));
	return 0; 
}