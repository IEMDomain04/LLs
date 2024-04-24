#include <stdio.h>
#include <string.h>

struct BankAccount {
	char AccName[20];
	int AccNumber; 
	float Balance, Deposit, Withdraw;
};

int main(){
	struct BankAccount record;
	
	printf("Enter Account holder name: ");
	scanf("%s", &record.AccName);
	
	printf("\nEnter Account number: ");
	scanf("%d", &record.AccNumber);
	
	printf("\nEnter Account balance: ");
	scanf("%f", &record.Balance);
	
	printf("\nAccount name: %s", record.AccName);
	printf("\nAccount number: %d", record.AccNumber);
	printf("\nAccount balance: %.2f", record.Balance);
	
	printf("\n\nHow much money you want to deposit: ");
	scanf("%f", &record.Deposit);
	
		record.Balance += record.Deposit;
	
	printf("\nAccount name: %s", record.AccName);
	printf("\nAccount number: %d", record.AccNumber);
	printf("\nAccount balance: %.2f", record.Balance);
	
	printf("\n\nHow much money you want to Withdraw: ");
	scanf("%f", &record.Withdraw);
	
		record.Balance -= record.Withdraw;
	
	printf("\n**********Final Result**********");
	printf("\n\tAccount name: %s", record.AccName);
	printf("\n\tAccount number: %d", record.AccNumber);
	printf("\n\tAccount balance: %.2f", record.Balance);
	
	return 0;
}
