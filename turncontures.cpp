#include <iostream>
#define SIZE 8

int matrix[SIZE][SIZE] = {{	1,	2,	3,	4,	5,	6,	7,	8},
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
	for(int k = 0; k < SIZE/2; k++){
		if(k%2==0){
			for(int l = 0; l < ((k==0)? 1:2); ++l){
				for(int i = k; i < SIZE - k; ++i){
					for(int j = i + 1; j < SIZE - k; ++j){
						matrix[i][j] ^= matrix[j][i];
						matrix[j][i] ^= matrix[i][j];
						matrix[i][j] ^= matrix[j][i];
					}
				}

				for(int i = k; i < SIZE - k; ++i){
					for(int j = k; j < SIZE/2; ++j){
						matrix[i][j] ^= matrix[i][SIZE-1-j];
						matrix[i][SIZE-1-j] ^= matrix[i][j];
						matrix[i][j] ^= matrix[i][SIZE-1-j];
					}
				}
			}
		}
		else{
			for(int l = 0; l < 2; ++l){
				for(int i = k; i < SIZE - k; ++i){
					for(int j = k; j < SIZE/2; ++j){
						matrix[i][j] ^= matrix[i][SIZE-1-j];
						matrix[i][SIZE-1-j] ^= matrix[i][j];
						matrix[i][j] ^= matrix[i][SIZE-1-j];
					}
				}
				for(int i = k; i < SIZE - k; ++i){
					for(int j = i + 1; j < SIZE - k; ++j){
						matrix[i][j] ^= matrix[j][i];
						matrix[j][i] ^= matrix[i][j];
						matrix[i][j] ^= matrix[j][i];
					}
				}
			} 
		}
	}
	
	printm();
	return 0;
}