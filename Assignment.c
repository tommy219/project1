#include <stdio.h>

//Function prototypes

void rotationEncrypt(char *rotMessage, int cipherKey);                

void rotationDecrypt(char *rotMessage, int cipherKey);

void substituionEncrypt(char *subMessage, int cipherKey);

void substitutionDecrypt(char *subMessage, int cipherKey);

int main()
{
    char rotMessage[1000];
    int cipherKey;
    
    printf("Please select an option: \n");
    printf("To encrypt by rotation, press A.\n");
    printf("To decrypt by rotation, press B.\n");

    switch(input) {
        case ’A’: rotationEncrypt(rotMessage, cipherKey); break;
        case ’B’: rotationDecrypt(rotMessage, cipherKey); break;
        default: printf("Unknown option %c\nPlease enter A or B\n", input);
    }
    
    
    
    
    scanf("%s", rotMessage);                                            //Gets message to be tested from the 'input' file
    scanf("%d", &cipherKey);                                               //Gets the key for the cipher from the 'input' file
    
}

//Function definition for encrypting the message

void rotationEncrypt(char *rotMessage, int cipherKey)
{
    int i;
    for(i = 0; rotMessage[i] != 0; ++i)                              //Goes through each element of the string and changes its value
    {

        if(rotMessage[i] >= 65 && rotMessage[i] < 90)                //65 and 90 are ASCII values for 'A' and 'Z'
        {
           rotMessage[i] += cipherKey;                                 //Assigninging the individual character to its new value
        }
        else if(rotMessage[i] == 90)                                    
        {
            rotMessage[i] = (rotMessage[i] - 90) + 64 + cipherKey;   //Loops to beginning of alphabet when going past 'Z'
        }
        else if(rotMessage[i] >= 97 && rotMessage[i] < 122)          //97 and 122 are ASCII values for 'a' and 'z'
        {
            rotMessage[i] -= 32;
            rotMessage[i] += cipherKey;                                 //Assigninging the individual character to its new value
        }
        else if(rotMessage[i] == 122)                                   
        {
            rotMessage[i] = (rotMessage[i] - 122) + 64 + cipherKey;  //Loops to beginning of alphabet when going past 'z'
        }
    }
    printf("The encrypted message is: %s\n\n", rotMessage);
}   
    
    



//Function Definition for decrypting the message



void rotationDecrypt(char *rotMessage, int cipherKey)
{
    int i;
    for(i = 0; rotMessage[i] != '\0'; ++i)                              //Goes through each element of the string and changes its value
    {

        if(rotMessage[i] >= 65 && rotMessage[i] < 90)                //65 and 90 are ASCII values for 'A' and 'Z'
        {
            rotMessage[i] -= cipherKey;                                 //Assigninging the individual character to its new value, which is correct letter
        }
        else if(rotMessage[i] == 90)                                    
        {
            rotMessage[i] = (rotMessage[i] - 90) + 64 - cipherKey;   //Loops to beginning of alphabet when going past 'Z'
        }
        else if(rotMessage[i] >= 97 && rotMessage[i] < 122)          //97 and 122 are ASCII values for 'a' and 'z'
        {
            rotMessage[i] -= cipherKey;                                 //Assigninging the individual character to its new value, which is correct letter
        }
        else if(rotMessage[i] == 122)                                   
        {
            rotMessage[i] = (rotMessage[i] - 122) + 96 - cipherKey;  //Loops to beginning of alphabet when going past 'z'
        }
    }
    printf("The decrypted message is: %s", rotMessage);
}   
   
    
    
