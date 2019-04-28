#include <stdio.h>

//Function prototypes

void rotationEncrypt(char *rotMessage, int rotKey);                
void rotationDecrypt(char *rotMessage, int rotKey);
void substitutionEncrypt(char *subMessage, char *subKey);
void substitutionDecryptK(char *subMessage, char *subKey);
void substitutionDecrypt(char *subMessage);

FILE *Message;



//-------------------------------- Main Function -----------------------------------------------------------------------------------------//


int main()
{
    int Choice, Input, i;                                           //'i' is for the while loop in the switch case statements
    
    int rotKey;
    char subKey[26];                                         //Initialising the array for the input of the key
    
    char rotMessage[1000] = {0};                                                  //Elements set to zero to avoid a false Message due to random data
    char subMessage[1000] = {0};
    
    printf("Please select an option: \n");
    printf("To encrypt by rotation, press 1.\nTo decrypt by rotation, press 2.\nTo encrypt by substitution, press 3.\nTo decrypt by substitution, press 4.\n");
    scanf("%d", &Choice);

   //User menu for selecting the encryption and decryption preferences
    
    switch(Choice) 
    {
        case 1:     printf("Please enter the cipher key:\n");
                    scanf("%d", &rotKey);
                    Message = fopen("Message.txt", "r");                //Opening the text file to read
                    i = 0;
                    while(!feof(Message))
                    {                                   
                        fscanf(Message, "%c", &rotMessage[i]);               //Loop through the input data file to form a string of characters, stored in rotMessage
                        i++;
                    }
                    rotationEncrypt(rotMessage, rotKey);
                    break;

        case 2:     printf("If you have the key, press 1.\nIf you don't have the key, press 2.\n");
                    scanf("%d", &Input);
                    switch(Input)
                    {
                        case 1: printf("Please enter the cipher key:\n");
                                scanf("%d", &rotKey);
                                Message = fopen("Message.txt", "r");
                                i = 0;
                                while(!feof(Message))
                                {
                                    fscanf(Message, "%c", &rotMessage[i]);
                                    i++;
                                }
                                rotationDecrypt(rotMessage, rotKey); 
                                break;

                        case 2: printf("All possible decryptions will now be displayed:\n\n");
                                Message = fopen("InputDecrypt.txt", "r");
                                i = 0;
                                while(!feof(Message))
                                {
                                    fscanf(Message, "%c", &rotMessage[i]);
                                    i++;
                                }
                                for(rotKey = 0; rotKey < 26; rotKey++)
                                {
                                    rotationDecrypt(rotMessage, rotKey);
                                }
                                break;
                    }
                    break;
        
        case 3:     printf("Please enter the arrangement of the 26 character's of the encryption key: ");
                    scanf("%s", subKey);                                                         //Input stored in subKey array
                    Message = fopen("Message.txt", "r");                //Opening the text file to read
                    i = 0;
                    while(!feof(Message))
                    {                                   
                        fscanf(Message, "%c", &subMessage[i]);               //Loop through the input data file to form a string of characters, stored in subMessage
                        i++;
                    }
                    substitutionEncrypt(subMessage, subKey);
                    break;
                    
        case 4:     printf("If you have the key, press 1.\nIf you don't have the key, press 2.\n");
                    scanf("%d", &Input);
                    switch(Input)
                    {
                        case 1:     printf("Plese enter the arrangement of the 26 character's of the decryption key: ");
                                    scanf("%s", subKey);
                                    Message = fopen("Message.txt", "r");
                                    i = 0;
                                    while(!feof(Message))
                                    {
                                        fscanf(Message, "%c", &subMessage[i]);
                                        i++;
                                    }
                                    substitutionDecryptK(subMessage, subKey);
                                    break; 
                        
                        case 2:     Message = fopen("Message.txt", "r");
                                    i = 0;
                                    while(!feof(Message))
                                    {
                                        fscanf(Message, "%c", &subMessage[i]);
                                        i++;
                                    }
                                    printf("%s", subMessage);
                                    substitutionDecrypt(subMessage);
                                    break; 
                    }
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
    
    
    
void substitutionEncrypt(char *subMessage, char *subKey)
{
    char *alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";         //Alphabet declared as a constant string
    int i,j;
    for(i = 0; subMessage[i] != '\0'; i++)
    {
        for(j = 0; j < 26; j++)
        {
            if(alphabet[j] == subMessage[i])               //Makes sure index of message and the alphabet are lined up
            {
                subMessage[i] = subKey[j];
                break;                                     //Break is used to exit nested for loop when condition is met
            }
        }
    }
    printf("The encrypted message is: %s\n", subMessage);    //Printing the ciphered message
}



void substitutionDecryptK(char *subMessage, char *subKey)
{
    char *alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";         //Alphabet declared as a constant string
    int i,j;

    for(i = 0; subMessage[i] != '\0'; i++)
    {
       for(j = 0; j < 26; j++)
       {
           if(subMessage[i] == subKey[j])
           {
               subMessage[i] = alphabet[j];
               break;
           }
       }
    }
    printf("The decrypted message is: %s\n", subMessage);   
}

/*Decryption function without the key. It firstly works out the letters that appear the most in the encrypted text.
It then prompts the user to input the order of most present letters, which are stored in an array.
It then works its way through the encrypted text (subMessage) and assigns the most used letter to E then T and so on.*/


void substitutionDecrypt(char *subMessage)
{
    int i, j, k, l, x;

    int count[26] = {0}; 
    char input[26] = {0};
 
    //Calculate frequency of each letter
    for(i = 0; subMessage[i] != '\0'; i++) 
    {
        x = subMessage[i] - 65;
        count[x]++;
    }

    for (j = 0; j < 26; j++)
        printf("%c occurs %d times in the string.\n", j + 65, count[j]);
    
    printf("Enter the letters in order of highest frequency to lowest frequency: ");
    
    for(k = 0; k <= 10; k++)
        scanf("%c", &input[k-1]);

   
    for(l = 0; subMessage[l] != '\0'; l++)
    {
        if(subMessage[l] == input[0])
            subMessage[l] = 'E';
        else if(subMessage[l] == input[1])
            subMessage[l] = 'T';
        else if(subMessage[l] == input[2])
            subMessage[l] = 'A';
        else if(subMessage[l] == input[3])
            subMessage[l] = 'O';
        else if(subMessage[l] == input[4])
            subMessage[l] = 'I';
        else if(subMessage[l] == input[5])
            subMessage[l] = 'N';
        else if(subMessage[l] == input[6])
            subMessage[l] = 'S';
        else if(subMessage[l] == input[7])
            subMessage[l] = 'H';
        else if(subMessage[l] == input[8])
            subMessage[l] = 'R';
        else if(subMessage[l] == input[9])
            subMessage[l] = 'D';
    }
    printf("The decrypted message is %s", subMessage);
}

