#include <iostream>
#define SIZE 8

int max(float a, float b){
	a *= a > 0? 1 : -1;
	b *= b > 0? 1 : -1;
	return a > b? a : b;
}

int matrix[8][8] = 	{{	1,	2,	3,	4,	5,	6,	7,	8},
					{	9,	10,	11,	12,	13,	14,	15,	16},
					{	17,	18,	19,	20,	21,	22,	23,	24},
					{	25,	26,	27,	28,	29,	30,	31,	32},
					{	33,	34,	35,	36,	37,	38,	39,	40},
					{	41,	42,	43,	44,	45,	46,	47,	48},
					{	49,	50,	51,	52,	53,	54,	55,	56},
					{	57,	58,	59,	60,	61,	62,	63,	64}};

void printm(){
	for(int i = 0; i < SIZE; ++i){
		for(int j = 0; j < SIZE; ++j){
			std::cout << matrix[i][j] << "\t";
		}
		std::cout << '\n';
	}
}

int main(){

	for(int i = 0; i < SIZE; ++i){
		for(int j = i + 1; j < SIZE; ++j){
			if(max((i - (SIZE-1.0)/2), (j - (SIZE-1.0)/2))%2 == (SIZE-1)/2 % 2){
				matrix[i][j] ^= matrix[j][i];
				matrix[j][i] ^= matrix[i][j];
				matrix[i][j] ^= matrix[j][i];
			}
		}
	}

	for(int i = 0; i < SIZE; ++i){
		for(int j = 0; j < SIZE/2; ++j){
			if(max((i - (SIZE-1.0)/2), (j - (SIZE-1.0)/2))%2 == (SIZE-1)/2 % 2){
				matrix[i][j] ^= matrix[i][SIZE-1-j];
				matrix[i][SIZE-1-j] ^= matrix[i][j];
				matrix[i][j] ^= matrix[i][SIZE-1-j];
			}
		}
	}

	for(int i = 0; i < SIZE; ++i){
		for(int j = 0; j < SIZE/2; ++j){
			if(max((i - (SIZE-1.0)/2), (j - (SIZE-1.0)/2))%2 != (SIZE-1)/2 % 2){
			matrix[i][j] ^= matrix[i][SIZE-1-j];
			matrix[i][SIZE-1-j] ^= matrix[i][j];
			matrix[i][j] ^= matrix[i][SIZE-1-j];
			}
		}
	}

	for(int i = 0; i < SIZE; ++i){
		for(int j = i + 1; j < SIZE; ++j){
			if(max((i - (SIZE-1.0)/2), (j - (SIZE-1.0)/2))%2 != (SIZE-1)/2 % 2){
				matrix[i][j] ^= matrix[j][i];
				matrix[j][i] ^= matrix[i][j];
				matrix[i][j] ^= matrix[j][i];
			}
		}
	}
	
	printm();
	return 0;
}