#include <stdio.h> 
#include <string.h> 
int main() 
{ 
    char str[100], state= 'A'; 
    int i; 
    printf("Enter the string of {a,b}: ");    
	 scanf("%s",str);     
	 for(i=0;str[i]!='\0';i++) 
    { 
        switch(state) 
        {             case 'A': 
            if(str[i]=='a')                 state='B';             else if(str[i]=='b')                 state='A';             break;             case 'B': 
            if(str[i]=='a')                 state='A';             else if(str[i]=='b')                 state='B';             break; 
        } 
    }    if(state=='B')  {        
	 printf("%s Accepted.\n",str); 
    }     else {         
	printf("%s Rejected.\n", str); 
    } 
    printf("\nLab NO:4\n");
	printf("Name:Rajip Maharjan\n");
	printf("Roll no:14");
} 

