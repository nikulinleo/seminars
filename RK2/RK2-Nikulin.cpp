#include <iostream>
#include <string>
#include <vector>

using std::string;

class MInstrument{
protected:
	string name, material;

public:
	MInstrument(const string N, const string M): name(N), material(M){};
	virtual ~MInstrument(){std::cerr << "MI destroyed" << std::endl;};

	friend void changename(MInstrument*, string newname);
	friend void changematerial(MInstrument*, string newmaterial);

	virtual operator string() const = 0;
};

void changename(MInstrument* t, string newname){t -> name = newname;};
void changematerial(MInstrument* t, string newmaterial){t -> material = newmaterial;};

class SInstrument: public MInstrument{
protected:
	uint strings;
public:
	SInstrument(const string N, const string M, uint S): MInstrument(N, M), strings(S){};
	virtual ~SInstrument(){std::cerr << "SI destroyed" << std::endl;};
	virtual operator string() const{
		return(name + ", made of " + material + " and has " + std::to_string(strings) + " strings");
	}
};

class BInstrument: public MInstrument{
protected:
	string brasstype;
public:
	BInstrument(const string N, const string M, const string BT): MInstrument(N, M), brasstype(BT){};
	virtual ~BInstrument(){std::cerr << "BI destroyed" << std::endl;};
	virtual operator string() const{
		return(name + ", made of " + brasstype + " " + material);
	}
};

int main(){
	std::vector< MInstrument *> orchestra;
	orchestra.push_back(new BInstrument("horn", "brass", "yellow"));
	orchestra.push_back(new BInstrument("antihorn", "brass", "green"));
	orchestra.push_back(new BInstrument("anothert horn", "brass", "black"));
	orchestra.push_back(new BInstrument("something impossible", "brass", "old"));
	orchestra.push_back(new SInstrument("guitar", "wood", 6));
	orchestra.push_back(new SInstrument("guitar", "not wood", 7));
	orchestra.push_back(new SInstrument("yamaha guitar", "wood", 12));
	orchestra.push_back(new SInstrument("balalaika", "something", 6));
	orchestra.push_back(new SInstrument("guitar", "wood", 6));
	orchestra.push_back(new SInstrument("guitar", "wood", 6));

	std::cout << "This great orchestra has such instruments as:\n";
	for(MInstrument* temp : orchestra){
		std::cout << (string) *temp  << std::endl;
	}

	std::cout << "Now test changing functions:" << std::endl;

	std::cout << (string) orchestra[0][0] << std::endl;
	changename(orchestra[0], "sdkjvvs");
	std::cout << (string) orchestra[0][0] << std::endl;

	std::cout << (string) orchestra[6][0] << std::endl;
	changename(orchestra[6], "sdkjvvs");
	std::cout << (string) orchestra[6][0] << std::endl;

	for(MInstrument* temp : orchestra){
		delete temp;
	}	
	return 0; 
}
