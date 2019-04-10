#include <stdio.h>

//Function prototypes

void rotationEncrypt(char *rotMessage, int cipherKey);                
void rotationDecrypt(char *rotMessage, int cipherKey);
void substituionEncrypt(char *subMessage, int cipherKey);
void substitutionDecrypt(char *subMessage, int cipherKey);
FILE *InputEncryptR;
FILE *InputDecryptR;




int main()
{
    int Choice = 1;
    printf("Please select an option: \n");
    printf("To encrypt by rotation, press 1.\nTo decrypt by rotation, press 2.\n");
    scanf("%d", &Choice);
   
    int i;
    char rotMessage[1000] = {0};                                                  //Elements set to zero to avoid a false rotMessage due to random data
    int cipherKey = 3;
    switch(Choice) {
        case 1:     InputEncryptR = fopen("InputEncryptR.txt", "r");                //Opening the text file to read
                    i = 0;
                    while(!feof(InputEncryptR)){                                   
                        fscanf(InputEncryptR, "%c", &rotMessage[i]);                 //Loop through the input data file to form a string of characters, stored in rotMessage
                        i++;
                    }
                    rotationEncrypt(rotMessage, cipherKey);
                    break;

        case 2:     InputDecryptR = fopen("InputDecryptR.txt", "r");
                    i = 0;
                    while(!feof(InputDecryptR)){
                        fscanf(InputDecryptR, "%c", &rotMessage[i]);
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
    for(i = 0; rotMessage[i] != 0; i++)                              //Goes through each element of the string and changes its value
    {
        char tempCharacter;
        tempCharacter = rotMessage[i];
        if(tempCharacter >= 65 && tempCharacter <= 90)                //65 and 90 are ASCII values for 'A' and 'Z'
        {
            tempCharacter += cipherKey;                                 //Assigninging the individual character to its new value
            if(tempCharacter > 90)                                    
                tempCharacter = tempCharacter - 26;   //Loops to beginning of alphabet when going past 'Z'
            rotMessage[i] = tempCharacter;
        }
        else if(tempCharacter >= 97 && rotMessage[i] <= 122)          //97 and 122 are ASCII values for 'a' and 'z'
        {
            tempCharacter -= 32;
            tempCharacter += cipherKey;                                 //Assigninging the individual character to its new value
            if(tempCharacter > 122)                                    
                tempCharacter = tempCharacter - 26;   //Loops to beginning of alphabet when going past 'Z'
            rotMessage[i] = tempCharacter;
        }
    }   
    printf("The encrypted message is: %s\n", rotMessage);
 }  
    



//Function Definition for decrypting the message



void rotationDecrypt(char *rotMessage, int cipherKey)

{
    int i;
    for(i = 0; rotMessage[i] != 0; i++)                              //Goes through each element of the string and changes its value
    {
        char tempCharacter;
        tempCharacter = rotMessage[i];
        if(tempCharacter >= 65 && tempCharacter <= 90)                //65 and 90 are ASCII values for 'A' and 'Z'
        {
            tempCharacter -= cipherKey;                                 //Assigninging the individual character to its new value
            if(tempCharacter < 90)                                    
                tempCharacter = tempCharacter + 26;   //Loops to beginning of alphabet when going past 'Z'
            rotMessage[i] = tempCharacter;
        }
        else if(tempCharacter >= 97 && rotMessage[i] <= 122)          //97 and 122 are ASCII values for 'a' and 'z'
        {
            tempCharacter -= 32;
            tempCharacter -= cipherKey;                                 //Assigninging the individual character to its new value
            if(tempCharacter > 122)                                    
                tempCharacter = tempCharacter + 26;   //Loops to beginning of alphabet when going past 'Z'
            rotMessage[i] = tempCharacter;
        }
    }   
    printf("The decrypted message is: %s\n", rotMessage);
 }  
    