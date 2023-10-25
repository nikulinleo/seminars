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
	return (o << p.name << " - " << p.quantity << " шт. по цене " << p.price << " рублей за штуку");
};

void Shop::buy(){
    char _name[100];
    char sym;
    int i = 0;
    do{
        if (i = 0){
            sym = std::cin.peek();
            if(sym == EOF) std::cout << "Введите название продукта: ";
            else sym = std::cin.get();
        }
        else std::cin >> std::noskipws >> sym;
        
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

    std::cout << "Введите цену продукта и количество: ";
    std::cin >> std::skipws >> _price >> _quantity;
    while(std::cin.fail() || _price < 0 || _quantity <= 0){
        if(std::cin.fail()) std::cerr << "Не удалось считать числа, попробуйте еще раз: ";
        else std::cerr << "Некорректные числа, попробуйте еще раз: ";
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
	o << "Итого куплено:" << std::endl;
	for (int i = 0; i < s.len; ++i){
		o << *(s.items[i]) << std::endl;
	}
	o << "Сумма покупок: " << s.sum << " рублей" << std::endl;

	o << "Средняя цена: " << s.sum / s.quantity << " рублей за штуку" << std::endl;

	return o;
}