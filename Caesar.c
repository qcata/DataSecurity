#include<stdio.h>
#include<conio.h>
#include <stdlib.h>

void clrscr()
{
    system("@cls||clear");
}

void caesar_encrypt(){
    char message[100], ch;
    int i, key;
    
    printf("Enter a message to encrypt: ");
    gets(message);
    printf("Enter key: ");
    scanf("%d", &key);
    
    for(i = 0; message[i] != '\0'; ++i){
        ch = message[i];
        
        if(ch >= 'a' && ch <= 'z'){
            ch = ch + key;
            
            if(ch > 'z'){
                ch = ch - 'z' + 'a' - 1;
            }
            
            message[i] = ch;
        }
        else if(ch >= 'A' && ch <= 'Z'){
            ch = ch + key;
            
            if(ch > 'Z'){
                ch = ch - 'Z' + 'A' - 1;
            }
            
            message[i] = ch;
        }
    }
    
    printf("Encrypted message: %s", message);
}

void caesar_decrypt(){
    char message[100], ch;
    int i, key;
    
    printf("Enter a message to decrypt: ");
    gets(message);
    printf("Enter key: ");
    scanf("%d", &key);
    
    for(i = 0; message[i] != '\0'; ++i){
        ch = message[i];
        
        if(ch >= 'a' && ch <= 'z'){
            ch = ch - key;
            
            if(ch < 'a'){
                ch = ch + 'z' - 'a' + 1;
            }
            
            message[i] = ch;
        }
        else if(ch >= 'A' && ch <= 'Z'){
            ch = ch - key;
            
            if(ch < 'A'){
                ch = ch + 'Z' - 'A' + 1;
            }
            
            message[i] = ch;
        }
    }
    
    printf("Decrypted message: %s", message);
    
}

int main()
{
    int option;
    printf("--Enter 1 to encrypt\n");
    printf("--Enter 2 to decrypt\n");
    printf("--Enter 0 to exit\n");
    printf("--Enter your option:");
    scanf("%d", &option);
    while(option!= 0){
        if(option == 1) caesar_encrypt();
        if(option == 2) caesar_decrypt();
        clrscr();
        printf("\n--Enter your option:");
        scanf("%d", &option);
        }
    return 0;

}
