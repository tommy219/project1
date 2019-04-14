#include <stdio.h>

//Function prototypes

void rotationEncrypt(char *rotMessage, int cipherKey);                
void rotationDecrypt(char *rotMessage, int cipherKey);
void substituionEncrypt(char *subMessage, int cipherKey);
void substitutionDecrypt(char *subMessage, int cipherKey);

FILE *InputEncrypt;
FILE *InputDecrypt;


int main()
{
    int Choice = 1;
    int cipherKey;
    
    printf("Please select an option: \n");
    printf("To encrypt by rotation, press 1.\nTo decrypt by rotation, press 2.\n");
    scanf("%d", &Choice);
    printf("Please enter the cipher key:\n");
    scanf("%d", &cipherKey);
   
    int i;
    char rotMessage[1000] = {0};                                                  //Elements set to zero to avoid a false rotMessage due to random data
    switch(Choice) {
        case 1:     InputEncrypt = fopen("InputEncrypt.txt", "r");                //Opening the text file to read
                    i = 0;
                    while(!feof(InputEncrypt)){                                   
                        fscanf(InputEncrypt, "%c", &rotMessage[i]);                 //Loop through the input data file to form a string of characters, stored in rotMessage
                        i++;
                    }
                    rotationEncrypt(rotMessage, cipherKey);
                    break;

        case 2:     InputDecrypt = fopen("InputDecrypt.txt", "r");
                    i = 0;
                    while(!feof(InputDecrypt)){
                        fscanf(InputDecrypt, "%c", &rotMessage[i]);
                        i++;
                    }
                    rotationDecrypt(rotMessage, cipherKey); 
                    break;

        default:    printf("Unknown option %c\nPlease enter A or B\n", Choice);
    }
}

//Function definition for encrypting the message

void rotationEncrypt(char *rotMessage, int cipherKey)
{
    int i;
    char newCharacter;
    for(i = 0; rotMessage[i] != 0; i++)                                //Goes through each element of the string and changes its value
    {
        char tempCharacter;
        tempCharacter = rotMessage[i];
        if(tempCharacter >= 65 && tempCharacter <= 90)
        {
            newCharacter = (char)((tempCharacter - 65 + cipherKey) % 26 + 65);
            rotMessage[i] = newCharacter;
        }
        else if(tempCharacter >= 97 && tempCharacter <= 122)
        {
            tempCharacter -= 32; 
            newCharacter = (char)((tempCharacter - 65 + cipherKey) % 26 + 65);
            rotMessage[i] = newCharacter;
        }
    }   
    printf("The encrypted message is: %s\n", rotMessage);
 }  
    

//Function Definition for decrypting the message

void rotationDecrypt(char *rotMessage, int cipherKey)
{
    int i;
    char newCharacter;
    for(i = 0; rotMessage[i] != 0; i++)                                //Goes through each element of the string and changes its value
    {
        char tempCharacter;
        tempCharacter = rotMessage[i];
        if(tempCharacter >= 65 && tempCharacter <= 90)
        {
            newCharacter = (char)((tempCharacter - 65 + 26 - cipherKey) % 26 + 65);
            rotMessage[i] = newCharacter;
        }
        else if(tempCharacter >= 97 && tempCharacter <= 122)
        {
            tempCharacter -= 32; 
            newCharacter = (char)((tempCharacter - 65 + 26 - cipherKey) % 26 + 65);
            rotMessage[i] = newCharacter;
        }
    }   
    printf("The decrypted message is: %s\n", rotMessage);
 }  
    