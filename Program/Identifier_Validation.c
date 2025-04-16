#include<stdio.h>
//#include<conio.h>
#include<ctype.h>
void main()
{
char identifier[20];
int flag, i = 1;
//clrscr();
printf("\n Enter an identifier :");
gets(identifier);
if(isalpha(identifier[0]))
 flag = 1;
else
 printf("\n It is not valid identifier");
while(identifier[i] != '\0')
 {
 if(!isdigit(identifier[i])&&!isalpha(identifier[i]))
 {
 flag = 0;
 break;
 }
 i++;
 }
 if(flag == 1)
 printf("\n It is a valid identifier");

printf("\nLab NO:8\n");
printf("Name:Rajip Maharjan\n");
printf("Roll no:14");
 //getch();
}

