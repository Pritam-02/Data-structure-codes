#include<stdio.h>
#include<stdlib.h>
#include <math.h>

int countOne(int n){
	int i;
	int c = 0;
	
	while(n > 0){
		int d = n & 1; // LSB extraction
		if(d == 1){
			c++; // counting number of 1s
		}
		n = n >> 1; // number reduction
	}
	return c;
}

void printBinary(int nos, int n){
	int i;
	for(i=n-1; i>=0; i--){
		printf("%d", (nos>>i)&1);
	}
}
int main(void){
	int n; // n-bit number
	int *ti, *ci, *ai;
	int nos;
	int i; // loop
	
	printf("\nEnter n:\t");
	scanf("%d",&n);
	
	nos = pow(2, n);
	
	ti = (int *)calloc(nos+1, sizeof(int));
	ci = (int *)calloc(nos+1, sizeof(int));
	ai = (int *)calloc(nos+1, sizeof(int));
	
	for(i = 1; i<= nos; i++){
		int x = countOne(i^(i-1));
		ti[i] = x;
	}
	ti[nos] = n;
	
	for(i = 1; i <= nos; i++){
		ci[i] = countOne(i);
	}
	ci[nos] = 0;
	
	for(i = 1; i<= nos; i++){
		ai[i] = ti[i] + ci[i] - ci[i-1];
	}
	
	printf("\n\n\nThe Amortized Cost Calculation Table is:\n");
	printf("=================================\n");
	printf("Steps\tNumber\tInteger\tti\tci\tai\n");
	for(i = 0 ; i <= nos; i++){
		printf("%d\t%d\t", i, i);
	//	printf("%d\t%d\t%d\t%d\t%d\n", i, i, ti[i], ci[i], ai[i]);
		printBinary(i%nos, n);
		printf("\t%d\t%d\t%d\n", ti[i], ci[i], ai[i]);
	}
	
	free(ti);
	free(ci);
	free(ai);
	return 0;
}
