#include <iostream>
#include <stdio.h>
#include <string.h>

using std::cout, std::cin, std::endl;

class Product{
	float price;
	int quantity;
	char name[100];
public:
	Product(char* _name, float _price, int _q): price(_price), quantity(_q) {for(int i = 0; _name[i] != '\0'; ++i) name[i] = _name[i];};
	float getPrice(int a = 1){return price * a;};
	friend std::ostream& operator <<(std::ostream&, Product&);
	friend int cmp(const void*, const void*);
	friend class Shop;
};

std::ostream& operator <<(std::ostream& o, Product& p){
	return (o << p.name << " - " << p.quantity << " шт. по цене " << p.price << " рублей за штуку");
}

int cmp(const void* a, const void* b){
	Product* aa = *(Product**) a;
	Product* bb = *(Product**) b;
	return strcmp(aa -> name, bb -> name);
} 


class Shop{
	Product** items;
	int len;
	int quantity;
	float sum;
public:
	Shop(){
		items = nullptr;
		len = 0;
		quantity = 0;
		sum = 0;
	}

	void buy(){
		cout << "Введите название продукта: ";

		char _name[100];
		char sym;
		int i = 0;
		do{
			cin >> sym;
			if(i == 0) cin >> std::noskipws;
			if(sym != '\n' && sym != '\0' && i < 99){
				_name[i] = sym;
			} 
			else{
				_name[i] = '\0';
			}
			i++;
		}while(i < 100 && sym != '\n' && sym != '\0');
		

		float _price;
		int _quantity;

		cout << "Введите цену продукта и количество: ";
 		cin >> std::skipws >> _price >> _quantity;

		Product* p = new Product(_name, _price, _quantity); 
		Product** temp = new Product*[len+1];
		for(int i = 0; i < len; ++i){
			temp[i] = items[i];
		}
		delete items;
		items = temp;
		items[len] = p;
		len++;
		quantity += _quantity;
		sum += p->getPrice(_quantity);
	}

	~Shop(){
		for(int i = 0; i < len; ++i){
			delete items[i];
		}
		delete items;
	}

	friend std::ostream& operator <<(std::ostream&, Shop&);

};

std::ostream& operator <<(std::ostream& o, Shop& s){
	qsort((void*) s.items, s.len, sizeof(Product*), cmp);
	cout << "Итого куплено:" << endl;
	for (int i = 0; i < s.len; ++i){
		o << *(s.items[i]) << endl;
	}
	cout << "Сумма покупок: " << s.sum << " рублей" << endl;

	cout << "Средняя цена: " << s.sum / s.quantity << " рублей за штуку" << endl;

	return o;
}


int main(){
	Shop s;
	char comand[100];
	do{
		cout << "Что Вы хотите сделать? Купить/Итог/Конец: ";
		cin >> comand;
		if(!strcmp(comand, "Купить")) s.buy();
		else if(!strcmp(comand, "Итог")) cout << s;
		else break;
	}while(strcmp(comand, "Конец"));
	return 0; 
}