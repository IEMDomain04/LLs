#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <ctype.h>

//Gotoxy Function
void gotoxy(short x, short y)
{
    COORD c = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

//Struct Function
struct students 
{
    char strName[25];
    int intId;
    float fGwa;
};

int main()
{
    struct students record[10];
    int intNumberStudent = 0, intStudentCount = 0, intCenterX = 45, intCenterY = 4, intCenterY2 = 10;
    char chrResponse = ' ', chrRating[15];
    float fGwa = 0.00f;

    //Do-While loop for program iteration.
    do 
	{
        system("cls");

        //Input data
        gotoxy(intCenterX, intCenterY); printf("### Storing Student Record ###");
        gotoxy(intCenterX - 7, intCenterY + 2); printf("Student Count: %d", intStudentCount);

        gotoxy(intCenterX - 10, intCenterY + 4); printf("Enter Student Name: ");
        scanf("%24s", record[intNumberStudent].strName);

        gotoxy(intCenterX - 10, intCenterY + 5); printf("Enter Student ID: ");
        scanf("%d", &record[intNumberStudent].intId);

        gotoxy(intCenterX - 10, intCenterY + 6); printf("Enter Student GWA: ");
        scanf("%f", &record[intNumberStudent].fGwa);

        intNumberStudent++;
        intStudentCount++;

        //Prompt the user to type record.
        gotoxy(intCenterX - 10, intCenterY + 8); printf("Record another student? (Y/N): ");
        scanf(" %c", &chrResponse);
    } while (toupper(chrResponse) == 'Y');

    system("cls");

    //Displaying the inputted datas.
    gotoxy(intCenterX - 15, intCenterY2); printf("List of students:");
    gotoxy(intCenterX - 15, intCenterY2 + 1); printf("%-25s%-15s%-15s%-15s\n", "NAME", "ID NUMBER", "GWA", "RATING");

    for (int intCounter = 0; intCounter < intStudentCount; intCounter++) 
	{
        
	fGwa = record[intCounter].fGwa;

    //Grade basis
        if (fGwa >= 90)
            strcpy(chrRating, "Outstanding!");
        else if (fGwa >= 80 && fGwa <= 89)
            strcpy(chrRating, "Great!");
        else if (fGwa >= 75 && fGwa <= 79)
            strcpy(chrRating, "Study!!!");
        else
            strcpy(chrRating, "Failed!");

        gotoxy(intCenterX - 15, intCenterY2 + 2 + intCounter);
        printf("%-25s%-15d%-15.2f%-15s\n", record[intCounter].strName, record[intCounter].intId, record[intCounter].fGwa, chrRating);
    }

    return 0;
}
