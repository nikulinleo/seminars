#include "Shop.hpp"

Product::Product(char* _name, float _price, int _q): price(_price), quantity(_q){
    for(int i = 0; _name[i] != '\0'; ++i) name[i] = _name[i];
};

int cmp(const void* a, const void* b){
	Product* aa = *(Product**) a;
	Product* bb = *(Product**) b;
	return strcmp(aa -> name, bb -> name);
};

std::ostream& operator <<(std::ostream& o, Product& p){
	return (o << p.name << " - " << p.quantity << " pcs., by " << p.price << " RUB per piece");
};

void Shop::buy(){
    char _name[100];
    for(int i = 0; i < 100; _name[i++] = '\0');
    std::cin >> std::noskipws;
    std::cin.getline(_name, 99); // считаем остаток буфера, если после buy ничего не было, останется \n
    while (std::iswspace(_name[0])) for(int i = 0; i < 99; _name[i-1] = _name[++i]); // убираем пробельные символы из начала строки
    if(strlen(_name) == 0){
        std::cout << "Enter the product name: "; // если после пробельных символов ничего не было, то выведем приглашение
        std::cin.getline(_name, 99); // считаем название
    }


    float _price;
    int _quantity;

    std::cout << "Enter price and quantity: ";
    std::cin >> std::skipws >> _price >> _quantity;
    while(std::cin.fail() || _price < 0 || _quantity <= 0){
        if(std::cin.fail()) std::cerr << "Unable to read nubers, try again: ";
        else std::cerr << "Incorrect values, try again: ";
        std::cin.clear();
        std::cin.ignore(9999, '\n');
        std::cin >> std::skipws >> _price >> _quantity;
    }

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

std::ostream& operator <<(std::ostream& o, Shop& s){
	qsort((void*) s.items, s.len, sizeof(Product*), cmp);
	o << "Overall bought:" << std::endl;
	for (int i = 0; i < s.len; ++i){
		o << *(s.items[i]) << std::endl;
	}
	o << "Sum: " << s.sum << " RUB" << std::endl;

	o << "Avg price: " << s.sum / s.quantity << " RUB per piece" << std::endl;

	return o;
}