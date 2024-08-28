#include<stdio.h>
#include<string.h>

void encrypt(char message[], int shift);
void decrypt(char message[], int key);

int main(){
    char message[200];
    char decision[10];
    int shift, key;
    printf("What do you want to do: Encrypt or Decrypt? ");
    fgets(decision, sizeof(decision), stdin);
    decision[strcspn(decision, "\n")] = '\0'; 

    if(strcmp(decision, "Encrypt") == 0){
        printf("Enter your message: ");
        fgets(message, sizeof(message), stdin);
        printf("Enter the number of shifts you want: ");
        scanf("%d", &shift);
        encrypt(message, shift);
    }
    else if(strcmp(decision, "Decrypt") == 0){
        printf("Enter your message: ");
        fgets(message, sizeof(message), stdin);
        printf("Enter the key: ");
        scanf("%d", &key);
        decrypt(message, key);
    }
   
    return 0;
}

void encrypt(char message[], int shift){
    int i;
    int length = strlen(message);
    for(i = 0; i < length; ++i){
        char ch = message[i];
        if(ch>= 'a' && ch<= 'z'){
            ch = 'a' + (ch - 'a' + shift)%26;
        }
        else if(ch>= 'A' && ch <= 'Z'){
            ch = 'A'+ (ch - 'A' + shift)%26;
        }
        message[i] = ch;
    }
    printf("Encrypted message: %s", message);
}

void decrypt(char message[], int key){
    int i;
    int length = strlen(message);
    for(i = 0; i < length; ++i){
        char ch = message[i];
        if(ch>= 'a' && ch<= 'z'){
            ch = 'a' + (ch - 'a' - key + 26) % 26;
        }
        else if(ch >= 'A' && ch <= 'Z'){
            ch = 'A' + (ch - 'A' - key + 26) % 26;
        }
        message[i] = ch;
    }
    printf("Decrypted message: %s", message);
}

