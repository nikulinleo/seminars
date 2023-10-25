#include <iostream>
using namespace std;

int cmp(const void* a, const void* b){
	return *((char*) a) - *((char*) b);
};

int main(){
	char a[] = "hellololo";
	qsort((void**) a, 7, sizeof(char), cmp);

	cout << a << endl;
	return 0;
}