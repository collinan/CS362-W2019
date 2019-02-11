#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>


//int* kingdomCards(int k1, int k2, int k3, int k4, int k5, int k6, int k7, int k8, int k9, int k10) 

int main(){
	
	int expectedvalue[]={1,2,3,4,5,6,7,8,9,10};
	int i;
	int *temp;
	temp= kingdomCards(1,2,3,4,5,6,7,8,9,10);
	
	for(i=0;i<10;i++){
	if(temp[i]==expectedvalue[i]){
		printf( "TEST PASSED: Values matched");
			printf("Expected value: %d   updateCoins function return total: %d\n",expectedvalue[i],temp[i]);
	}else{
		printf( "TEST Failed: Values do not matched");
		printf("Expected value: %d   updateCoins function return total: %d\n",expectedvalue[i],temp[i]);
	}
	}	
	
	
	return 0;
}