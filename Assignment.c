#include <stdio.h>
#include <string.h>

//Function prototypes

void rotationEncrypt(char *rotMessage, int rotKey);                
void rotationDecrypt(char *rotMessage, int rotKey);
void substituionEncrypt(char *subMessage, char *subKey);
void substitutionDecrypt(char *subMessage, char *subKey);

FILE *InputEncrypt;
FILE *InputDecrypt;


int main()
{
    int Choice, i;
    
    int rotKey;
   
                  
    char subKey[26];                                       //Initialising the array for the input of the key
    char rotMessage[1000] = {0};                                                  //Elements set to zero to avoid a false rotMessage due to random data
    char subMessage[1000] = {0};
    
    printf("Please select an option: \n");
    printf("To encrypt by rotation, press 1.\nTo decrypt by rotation, press 2.\nTo encrypt by substituion, press 3.\nTo decrypt by substitution, press 4.");
    scanf("%d", &Choice);

   
    
    switch(Choice) 
    {
        case 1:     printf("Please enter the cipher key:\n");
                    scanf("%d", &rotKey);
                    InputEncrypt = fopen("InputEncrypt.txt", "r");                //Opening the text file to read
                    i = 0;
                    while(!feof(InputEncrypt))
                    {                                   
                        fscanf(InputEncrypt, "%c", &rotMessage[i]);               //Loop through the input data file to form a string of characters, stored in rotMessage
                        i++;
                    }
                    rotationEncrypt(rotMessage, rotKey);
                    break;

        case 2:     printf("Please enter the cipher key:\n");
                    scanf("%d", &rotKey);
                    InputDecrypt = fopen("InputDecrypt.txt", "r");
                    i = 0;
                    while(!feof(InputDecrypt))
                    {
                        fscanf(InputDecrypt, "%c", &rotMessage[i]);
                        i++;
                    }
                    rotationDecrypt(rotMessage, rotKey); 
                    break;
        
        case 3:     printf("Please enter the arrangement of the 26 character's of the key");
                    scanf("%s", subKey);                                                         //Input stored in subKey array
                    InputEncrypt = fopen("InputEncrypt.txt", "r");                //Opening the text file to read
                    i = 0;
                    while(!feof(InputEncrypt))
                    {                                   
                        fscanf(InputEncrypt, "%c", &subMessage[i]);               //Loop through the input data file to form a string of characters, stored in subMessage
                        i++;
                    }
                    substitutionEncrypt(subMessage, subKey);
                    break;
        default:    printf("Unknown option %c\nPlease enter 1, 2, 3 or 4.\n", Choice);
    }
}

//Function definition for encrypting the message

void rotationEncrypt(char *rotMessage, int rotKey)
{
    int i;
    char newCharacter;
    for(i = 0; rotMessage[i] != 0; i++)                                           //Goes through each element of the string and changes its value
    {
        char tempCharacter;
        tempCharacter = rotMessage[i];
        if(tempCharacter >= 65 && tempCharacter <= 90)
        {
            newCharacter = (char)((tempCharacter - 65 + rotKey) % 26 + 65);
            rotMessage[i] = newCharacter;
        }
        else if(tempCharacter >= 97 && tempCharacter <= 122)
        {
            tempCharacter -= 32; 
            newCharacter = (char)((tempCharacter - 65 + rotKey) % 26 + 65);
            rotMessage[i] = newCharacter;
        }
    }   
    printf("The encrypted message is: %s\n", rotMessage);
 }  
    

//Function Definition for decrypting the message

void rotationDecrypt(char *rotMessage, int rotKey)
{
    int i;
    char newCharacter;
    for(i = 0; rotMessage[i] != 0; i++)                                              //Goes through each element of the string and changes its value
    {
        char tempCharacter;
        tempCharacter = rotMessage[i];
        if(tempCharacter >= 65 && tempCharacter <= 90)
        {
            newCharacter = (char)((tempCharacter - 65 + 26 - rotKey) % 26 + 65);
            rotMessage[i] = newCharacter;
        }
        else if(tempCharacter >= 97 && tempCharacter <= 122)
        {
            tempCharacter -= 32;                                                            //Converting lower case to upper case
            newCharacter = (char)((tempCharacter - 65 + 26 - rotKey) % 26 + 65);
            rotMessage[i] = newCharacter;
        }
    }   
    printf("The decrypted message is: %s\n", rotMessage);
 }  
    
    
    
void substituionEncrypt(char *subMessage, char *subKey)
{
    char *alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";         //Alphabet declared as a constant string
    int i,j;
    for(i = 0; subMessage[i] != '\0'; i++)
    {
        for(j = 0; j < 26; j++)
        {
            if(alphabet[j] == subMessage[i])
            {
                subMessage[i] = subKey[j];
                break;                                     //Break is used to exit nested for loop when condition is met
            }
        }
    }
    printf("The encrypted message is: %s", subMessage);    //Printing the ciphered message
}