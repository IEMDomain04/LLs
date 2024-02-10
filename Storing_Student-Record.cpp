#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <ctype.h>
	
void gotoxy(short x, short y){
	COORD c = {x, y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
	
struct students {
	char name[25];
	int id;
	float gwa;
};
	
int main(){
	struct students record[10];
	int numStud = 0, intStudentCount = 1;
	char response;
		
	do {
	   system("cls");
    int centerX = 45; // Center X position
    int centerY = 4; // Center Y position
	    
	    gotoxy(centerX, centerY); printf("### Storing Student Record ###");
	    gotoxy(centerX - 7, centerY + 2); printf("Student Count: %d", intStudentCount);
	    
	    gotoxy(centerX - 10, centerY + 4); printf("Enter Student Name: ");
	    scanf("%s", &record[numStud].name);
	    
	    gotoxy(centerX - 10, centerY + 5); printf("Enter Student ID: ");
	    scanf("%d", &record[numStud].id);
	    
	    gotoxy(centerX - 10, centerY + 6); printf("Enter Student GWA: ");
	    scanf("%f", &record[numStud].gwa);
	    
	    numStud++;
	    intStudentCount++;
	    
	    gotoxy(centerX - 10, centerY + 8); printf("Record another student? (Y/N): ");
	    scanf(" %c", &response);
	} while (toupper(response) == 'Y' || toupper(response) == 'y');
	
		system("cls");
		int centerX = 45;
		int centerY = 10; 

		gotoxy(centerX, centerY); printf("List of students:");
		gotoxy(centerX, centerY + 1); printf("%-15s%-15s%-15s\n", "Name", "ID Number", "GWA");
	
		for (int i = 0; i < numStud; i++) {
    gotoxy(centerX, centerY + 2 + i); printf("%-15s%-15d%-15.2f\n", record[i].name, record[i].id, record[i].gwa);
}

	
	
	    return 0;
	}
