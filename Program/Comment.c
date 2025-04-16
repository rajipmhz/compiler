#include<stdio.h> 
void main() 
{ 
   char comment[30]; 
   int i = 2, a = 0; 
    printf("\nEnter a comment:");    
	gets(comment);    
    if(comment[0] == '/') 
   { 
     if(comment[1] == '/') {
	  printf("\n It is a comment");

	 }     
	  else if(comment[1]=='*') 
         { 
           for(i=2; i<=30; i++) 
            { 
             if(comment[i]== '*' && comment[i+1] == '/') 
                { 
                  printf("\n It is a comment ");   
				    printf("\nLab NO:5\n");
	  				printf("Name:Rajip Maharjan\n");
	  				printf("Roll no:14");               
				    a = 1;                  
					 break; 
                }              
				 else             
				    continue; 
            }             
			if(a == 0)             
			printf("\n It is not a comment"); 
         } 
     else      
	  printf("\n It is not a comment"); 
   } 
   else    
    printf("\n It is not a comment"); 
} 

