#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using std::string;
using std::cout;
using std::cin;

template <typename T1, typename T2>
class Pair {
public:
    Pair() {}
    Pair(const T1& first, const T2& second) : first(first), second(second) {}

    void displayPair() const {
        std::cout << first << ": " << second << std::endl;
    }

    void savePairToFile(std::ofstream& outFile) const {
        outFile << first << " " << second << " ";
    }

private:
    T1 first;
    T2 second;
};

class Product{
protected:
	string name;
	double price;
	uint quantity;

public:
	Product(string _name, double _price, uint _quantity): name(_name), price(_price), quantity(_quantity){};

	const string getName(){return name;};
	const double getPrice(){return price;};
	const uint getQuantity(){return quantity;};

	virtual std::ostream& displayinfo(std::ostream& o){
		o << this->name << " - " << this->price << " * " << this->quantity;
		return o;
	};
	virtual std::ostream& printinfo(std::ostream& o)=0;
};

class Electronics: public Product{
public:
	Electronics(string _name, double _price, uint _quantity):Product(_name, _price, _quantity){};

	virtual std::ostream& displayinfo(std::ostream& o){
		this->Product::displayinfo(o) << " " << 0;
		return o;
	}

	virtual std::ostream& printinfo(std::ostream& o){
		this->Product::displayinfo(o) << " Тип: Электроника";
		return o;
	}
};

class Clother: public Product{
public:
	Clother(string _name, double _price, uint _quantity):Product(_name, _price, _quantity){};


	virtual std::ostream& displayinfo(std::ostream& o){
		this->Product::displayinfo(o) << " " << 1;
		return o;
	}

	virtual std::ostream& printinfo(std::ostream& o){
		this->Product::displayinfo(o) << " Тип: Одежда";
		return o;
	}
};

class Other: public Product{
public:
	Other(string _name, double _price, uint _quantity):Product(_name, _price, _quantity){};


	virtual std::ostream& displayinfo(std::ostream& o){
		this->Product::displayinfo(o) << " " << 2;
		return o;
	}

	virtual std::ostream& printinfo(std::ostream& o){
		this->Product::displayinfo(o) << " Тип: Другое";
		return o;
	}
};

int main() {
    setlocale(LC_ALL, "Russian");

    std::vector<Product*> products;

    int choice;
    string filename;

    do {
        cout << "Меню:" << std::endl;
        cout << "1. Добавить продукт" << std::endl;
        cout << "2. Изменить данные продукта" << std::endl;
        cout << "3. Удалить продукт" << std::endl;
        cout << "4. Найти продукт" << std::endl;
        cout << "5. Сохранить в файл" << std::endl;
        cout << "6. Загрузить из файла" << std::endl;
        cout << "7. Сортировать по цене" << std::endl;
        cout << "8. Сортировать по имени" << std::endl;
		cout << "9. Вывести список продуктов" << std::endl;
		cout << "10. Выход" << std::endl;
        cout << "Введите ваш выбор: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string Name;
				double Price;
				uint Quantity, type;

                std::cout << "Введите данные продукта:" << std::endl;
                std::cout << "Имя: ";
                std::cin >> Name;
                std::cout << "Цена: ";
                std::cin >> Price;
                std::cout << "Количество: ";
                std::cin >> Quantity;
				cout << "Тип: 0 - Электроника, 1 - Одежда, 2 - Другое";
				cin >> type;

				Product* temp;

				switch(type){
					case 0:{
						temp = new Electronics(Name, Price, Quantity);
						break;
					}
					case 1:{
						temp = new Clother(Name, Price, Quantity);
						break;
					}
					default:{
						temp = new Other(Name, Price, Quantity);
						break;
					}
				}

                products.push_back(temp);

                break;
            }
            
			case 2: {
                string Name;
				double Price;

                cout << "Введите данные продукта для изменения:" << std::endl;
                cout << "Название: ";
                cin >> Name;
                cout << "Цена: ";
                cin >> Price;

                auto it = std::find_if(products.begin(), products.end(), [Name, Price](Product* p) {
                    double price = p->getPrice() - Price;
					price *= price>0 ? 1 : -1;
					return p->getName() == Name, price < 0.01;
                });

                if (it != products.end()) {
					cout << "Продукт найден: ";
					((*it)->printinfo(cout)) << std::endl;
					string Name;
					double Price;
					uint Quantity, type;

					std::cout << "Введите новые данные продукта:" << std::endl;
					std::cout << "Цена: ";
					std::cin >> Price;
					std::cout << "Количество: ";
					std::cin >> Quantity;
					cout << "Тип: 0 - Электроника, 1 - Одежда, 2 - Другое";
					cin >> type;

					Product* temp;

					switch(type){
						case 0:{
							temp = new Electronics((*it)->getName(), Price, Quantity);
							break;
						}
						case 1:{
							temp = new Clother((*it)->getName(), Price, Quantity);
							break;
						}
						default:{
							temp = new Other((*it)->getName(), Price, Quantity);
							break;
						}
					}
					delete *it;
                	*it = temp;

                } else {
                    std::cout << "Продукт не найден." << std::endl;
                }

                break;
            }
			
			case 3: {
                string Name;
				double Price;

                cout << "Введите данные продукта для удаления:" << std::endl;
                cout << "Название: ";
                cin >> Name;
                cout << "Цена: ";
                cin >> Price;

                auto it = std::find_if(products.begin(), products.end(), [Name, Price](Product* p) {
                    double price = p->getPrice() - Price;
					price *= price>0 ? 1 : -1;
					return p->getName() == Name, price < 0.01;
                });

                if (it != products.end()) {
					cout << "Продукт найден: ";
					((*it)->printinfo(cout)) << std::endl;
					
					delete *it;
					products.erase(it);
                } 
				else {
                    std::cout << "Продукт не найден." << std::endl;
                }
                break;
            }
            
			case 4: {
				string Name;
				double Price;

                cout << "Введите данные продукта для поиска:" << std::endl;
                cout << "Название: ";
                cin >> Name;
                cout << "Цена: ";
                cin >> Price;

                auto it = std::find_if(products.begin(), products.end(), [Name, Price](Product* p) {
                    double price = p->getPrice() - Price;
					price *= price>0 ? 1 : -1;
					return p->getName() == Name, price < 0.01;
                });

                if (it != products.end()) {
					cout << "Продукт найден: ";
					((*it)->printinfo(cout)) << std::endl;
                } 
				else {
                    std::cout << "Продукт не найден." << std::endl;
                }
                break;

			}
			
			case 5:{				
				cout << "Введите имя файла: ";
				cin >> filename;
				std::ofstream file(filename, std::ofstream::out);
				if(file.is_open()){
					for (auto* product : products) {
						(product->displayinfo(file)) << std::endl;
					}
					file.close();
				}
				else{
					cout << "Файл не создан!" << std::endl;
				}
				break;
			}

			case 6:{
				cout << "Введите имя файла: ";
				cin >> filename;
				std::ifstream file(filename, std::ifstream::in);
				if(file.is_open()){
					while(!file.eof()){
						string Name, trash;
						double Price;
						uint Quantity, type;

						file >> Name >> trash >> Price >> trash >> Quantity >> type;
						if(file.eof()) break;
						Product* temp;
						switch(type){
							case 0:{
								temp = new Electronics(Name, Price, Quantity);
								break;
							}
							case 1:{
								temp = new Clother(Name, Price, Quantity);
								break;
							}
							default:{
								temp = new Other(Name, Price, Quantity);
								break;
							}
						}

						products.push_back(temp);
					}
					file.close();
				}
				else{
					cout << "Файл не найден!" << std::endl;
				}
				break;
			}

			case 7:{
				std::sort(products.begin(), products.end(), [](Product* a, Product* b){return a->getPrice() > b->getPrice();});
				break;
			}

			case 8:{
				std::sort(products.begin(), products.end(), [](Product* a, Product* b){return (a->getName()).compare(b->getName()) < 0;});
				break;
			}

			case 9: {
				cout << "Список продуктов:" << std::endl;

				for (auto* product : products) {
					(product->printinfo(cout)) << std::endl;
				}

				cout << "________________________" << std::endl;

				break;
			}

			case 10:{
				std::cout << "Выход." << std::endl;
                break;
			}
            
			default:
                std::cout << "Неверный выбор." << std::endl;
        }
    } while (choice != 10);

    for (const auto* product : products) {
        delete product;
    }

    return 0;
}