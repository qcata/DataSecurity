#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include<conio.h>

#define KEY "DENIS"

void clrscr()
{
    system("@cls||clear");
}

void vigenere_encrypt(char* message){
    int i,j=0;
  
    for(i = 0; i < strlen(message); i++)
    {
    	if (message[i] == '\n' || message[i] == ' ')
      		continue;

    	unsigned char isLowerCase = islower(message[i]);

   		 char toEncode = toupper(message[i]);
   		 message[i] = (((KEY[j] - 'A') + (toEncode - 'A')) % 26) + 'A';
   		
   		 if (isLowerCase)
   		   message[i] = tolower(message[i]);
   		
   		 j++;
   		 if (KEY[j] == '\0')
   		   j=0;
	}
 
    
    printf("Encrypted message: %s\n", message);
}

void vigenere_decrypt(char* message){
	int i,j=0;
	
 	for(i = 0; i < strlen(message); i++)
 	{
 	  if (message[i] == '\n' || message[i] == ' ')
 	    continue;
 	
 	  unsigned char isLowerCase = islower(message[i]);
 	
 	  char toDecode = toupper(message[i]);
 	  if (toDecode < KEY[j])
 	    toDecode += 26;
 	
 	  message[i] = (toDecode - KEY[j]) + 'A';
 	
 	  if (isLowerCase)
 	    message[i] = tolower(message[i]);
 	
 	  j++;
 	  if (KEY[j] == '\0')
 	    j=0;
 	}
    printf("Decrypted message: %s\n", message);
    
}

int main()
{
  char text[1000];
  
  printf("message=");
  fgets(text, sizeof(text), stdin);

  vigenere_encrypt(text);
  vigenere_decrypt(text);

  return 0;
}
