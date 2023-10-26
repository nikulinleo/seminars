#include <iostream>
#include <string.h>

class Product{
	float price;
	int quantity;
	char name[100];
public:
	Product(char* _name, float _price, int _q);
	float getPrice(int a = 1){return price * a;};
	friend std::ostream& operator <<(std::ostream&, Product&);
	friend int cmp(const void*, const void*);
	friend class Shop;
};

std::ostream& operator <<(std::ostream&, Product&);
int cmp(const void*, const void*);

class Shop{
	Product** items;
	int len;
	int quantity;
	float sum;
public:
	Shop(): items(nullptr), len(0),	quantity(0), sum(0.0){};

	void buy();

	~Shop(){
		for(int i = 0; i < len; ++i){
			delete items[i];
		}
		delete items;
	}

	friend std::ostream& operator <<(std::ostream&, Shop&);

};

std::ostream& operator <<(std::ostream&, Shop&);

