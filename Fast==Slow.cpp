#include <stdio.h>
int main(){
	/* In the given program to compute the sum of integers 
	from 1 to N, it is necessary to initialize the variable s 
	with 0 because the for loop iterates from i=1 to i=N and 
	accumulates the sum of integers in the s variable.
	
	If s is not initialized to 0 before the for loop, it will 
	contain garbage or uninitialized data, which will give an 
	incorrect result when added to the first number of the sequence.

	By initializing s to 0 before the for loop, we ensure that s 
	starts at 0 and correctly accumulates the sum of integers 
	from 1 to N. */
	
	int N, i, f, s=0;
	
	
	//Prompt user to enter a number
	printf("Enter a number: ");
	scanf("%d", &N);
	
	//Compute for Slow
	for(i = 1; i <= N; i++){
		s += i;
	}
	
	//Compute for fast
	f = (N*(N+1))/2;
	
	//Display Fast and Slow
	printf("\n Slow = %d", s);
	printf("\n Fast = %d", f);
	
	//Compare the Fast and Slow
	if (f == s){
		printf("\n Fast and Slow are Equal.");
	} else {
		printf("\n Fast and Slow are not Equal.");
	}
	return 0;
}
