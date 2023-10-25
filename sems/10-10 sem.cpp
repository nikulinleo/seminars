#include <iostream>
#include <cstring>
using namespace std;

int main(){
	char* str = new char[100];

	cin  >> str;
	uint len = strlen(str);

	for(int i = 0; i <= len / 2; ++i){
		str[i] ^= str[len - i];
		str[len - i] ^= str[i];
		str[i] ^= str[len - i];
		
	}

	for(int i = 0; i <= len; ++i){
		cout << str[i];
	}
	cout << endl; 
	
	delete[] str;
	return 0;
}