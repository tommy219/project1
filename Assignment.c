#include <stdio.h>

//Declaring the function prototypes which represent the encryption and decryption by both rotation and substitution.

void rotationEncrypt(char *rotMessage, int rotKey);                
void rotationDecrypt(char *rotMessage, int rotKey);
void substitutionEncrypt(char *subMessage, char *subKey);
void substitutionDecryptK(char *subMessage, char *subKey);   //This decryption for when the key is known
void substitutionDecrypt(char *subMessage);                  //This decryption is for when key is unkown

FILE *Message;                                               //Pointing to the file 'Message.txt'



//-------------------------------- Main Function -----------------------------------------------------------------------------------------//

//This is where the user interface is established and the appropriate functions are called, depending on input.

int main()
{
    int Choice, Input, i;                                           //'i' is for the while loop in the switch case statements
    
    int rotKey;                                                     //The key for rotation cipher
    char subKey[26];                                                //Initialising the array for the input of the key
    
    char rotMessage[1000000] = {0};                                 //Elements set to zero to avoid a false Message due to random data
    char subMessage[1000000] = {0};
    
    //User menu for selecting the encryption and decryption preferences
   
    printf("Please select an option: \n");                            
    printf("To encrypt by rotation, press 1.\nTo decrypt by rotation, press 2.\nTo encrypt by substitution, press 3.\nTo decrypt by substitution, press 4.\n");
    scanf("%d", &Choice);

  
    
    switch(Choice) 
    {
        case 1:     printf("Please enter the cipher key:\n");
                    scanf("%d", &rotKey);                               //Storing the integer input in rotKey
                    Message = fopen("Message.txt", "r");                //Opening the 'Message.txt' file to read
                    i = 0;                                              //Initialising i = 0 for the while loop
                    while(!feof(Message))                               //Condition remains true until the loop has reached the end of the file
                    {                                   
                        fscanf(Message, "%c", &rotMessage[i]);               //Loop through the input data file to form a string of characters, stored in rotMessage
                        i++;
                    }
                    rotationEncrypt(rotMessage, rotKey);                //Calling the encryption function with the message and the key as the arguments
                    break;

        case 2:     printf("If you have the key, press 1.\nIf you don't have the key, press 2.\n");
                    scanf("%d", &Input);
                    
                    //Nested switch case statement for when the key is either known or unkown
                    
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
                                rotationDecrypt(rotMessage, rotKey);         //Calling the decryption function with the message and the key as the arguments
                                break;

                        case 2: printf("All possible decryptions will now be displayed:\n\n");
                                Message = fopen("InputDecrypt.txt", "r");
                                i = 0;
                                while(!feof(Message))
                                {
                                    fscanf(Message, "%c", &rotMessage[i]);
                                    i++;
                                }
                                for(rotKey = 0; rotKey < 26; rotKey++)         //The for loop goes through each one of the 26 possible keys for encryption by rotation
                                {
                                    rotationDecrypt(rotMessage, rotKey);       //The 'decrypted' message is displayed each time the function is called
                                }
                                break;
                    }
                    break;
        
        case 3:     printf("Please enter the arrangement of the 26 character's of the encryption key: ");
                    scanf("%s", subKey);                                      //Input stored as an array of characters, forming the substituion cipher key
                    Message = fopen("Message.txt", "r");                
                    i = 0;
                    while(!feof(Message))
                    {                                   
                        fscanf(Message, "%c", &subMessage[i]);               //Loop through the input data file to form a string of characters, stored in subMessage
                        i++;                                                  //Increment i to store next character from the message file in 'subMessage'
                    }
                    substitutionEncrypt(subMessage, subKey);                //Calling the encryption function with the message and the key as the arguments
                    break;
                    
        case 4:     printf("If you have the key, press 1.\nIf you don't have the key, press 2.\n");
                    scanf("%d", &Input);
                    switch(Input)
                    {
                        case 1:     printf("Plese enter the arrangement of the 26 character's of the decryption key: ");
                                    scanf("%s", subKey);                                    //The enetered string of ordered characters forms the substituion decryption key. Stored in the subKey array
                                    Message = fopen("Message.txt", "r");
                                    i = 0;
                                    while(!feof(Message))
                                    {
                                        fscanf(Message, "%c", &subMessage[i]);
                                        i++;
                                    }
                                    substitutionDecryptK(subMessage, subKey);  //Calling the decryption function with the message and the key as the arguments
                                    break; 
                        
                        case 2:     Message = fopen("Message.txt", "r");
                                    i = 0;
                                    while(!feof(Message))
                                    {
                                        fscanf(Message, "%c", &subMessage[i]);
                                        i++;
                                    }
                                    substitutionDecrypt(subMessage);          //Calling the decryption function with only the message as the argument
                                    break; 
                    }
                    break;
                    
        default:    printf("Unknown option %c\nPlease enter 1, 2, 3 or 4.\n", Choice);    //Default for when the user input does not match one of the case statements
    }
}

/*FUNCTION DEFINITIONS.
This is where the bulk of the code lies. 
All the algorithms for encryption and decryption are located within their respective functions.
Note that each function is of type void, as no value is returned.
Note that variables are declared locally within the functions, allowing for repeated use without
interference.*/


//Function Definition for encrypting the message by rotation

void rotationEncrypt(char *rotMessage, int rotKey)                    //*rotMessage is a pointer to the stored array, of the Message
{
    int i;
    char newCharacter;
    for(i = 0; rotMessage[i] != 0; i++)                                           //Loops through each element of the string and changes its value
    {
        char tempCharacter;                                     //Temporary character initialised 
        tempCharacter = rotMessage[i];                          //Storing the respective character of the message for later use
        if(tempCharacter >= 65 && tempCharacter <= 90)          //65 and 90 are the ASCII values for A and Z respectively. So testing if letter is uppercase
        {
            newCharacter = (char)((tempCharacter - 65 + rotKey) % 26 + 65);    //The actual algorithm for forming a new character, based on its previous value and the rotation key
            rotMessage[i] = newCharacter;                               //Assigning the specific character to the new character based on the previous line of calculation.
        }
        else if(tempCharacter >= 97 && tempCharacter <= 122)    //97 and 122 are the ASCII values for a and z respectively. So testing if letter is lowercase
        {
            tempCharacter -= 32;                               //Subtracting 32 from the lowercase ASCII value, gives the uppercase equivalent
            newCharacter = (char)((tempCharacter - 65 + rotKey) % 26 + 65);
            rotMessage[i] = newCharacter;
        }
    }   
    printf("The encrypted message is: %s\n", rotMessage);              //When the function is called, the entire encrypted message is printed to the screen.
 }   
    

//Function Definition for decrypting the message by rotation

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
            newCharacter = (char)((tempCharacter - 65 + 26 - rotKey) % 26 + 65);     //The addition of 26 and subtraction of the rotation key returns the specific character to what is was prior to encryption
            rotMessage[i] = newCharacter;
        }
        else if(tempCharacter >= 97 && tempCharacter <= 122)
        {
            tempCharacter -= 32;                                                            //Converting lower case to upper case
            newCharacter = (char)((tempCharacter - 65 + 26 - rotKey) % 26 + 65);
            rotMessage[i] = newCharacter;
        }
    }   
    printf("The decrypted message is: %s\n", rotMessage);                               //When the function is called, the entire decrypted message is printed to the screen.
}  
    

//Function Definition for encrypting the message by substitution   
    
void substitutionEncrypt(char *subMessage, char *subKey)        //The arguments are pointers to the stored array of both the Message and the cipher key
{
    char *alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";         //Alphabet declared as a constant string for later reference
    int i, j;                                              //Initialising the for loop variables
    for(i = 0; subMessage[i] != '\0'; i++)                 //Looping through the entire stored message until it reaches the final NULL character
    {
        for(j = 0; j < 26; j++)                            //Loops through each character of the alphabet string
        {
            if(alphabet[j] == subMessage[i])               //Makes sure index of message and the alphabet are lined up
            {
                subMessage[i] = subKey[j];                 //Assigning the specific character in the message to the coressponding character from the cipher key
                break;                                     //Break is used to exit nested for loop when condition is met
            }
        }
    }
    printf("The encrypted message is: %s\n", subMessage);    //When the function is called, the entire encrypted message is printed to the screen.
}  


//Function Definition for decrypting the message by substitution

void substitutionDecryptK(char *subMessage, char *subKey)
{
    char *alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";         
    int i,j;
    for(i = 0; subMessage[i] != '\0'; i++)
    {
       for(j = 0; j < 26; j++)
       {
           if(subMessage[i] == subKey[j])                   //Testing when the characters of the message are equal to the characters of the cipher key array
           {
               subMessage[i] = alphabet[j];                 //When condition is met, the character is assigned to the corresponding character from the alphabet array, returning it to its previous 'value'
               break;
           }
       }
    }
    printf("The decrypted message is: %s\n", subMessage);   //When the function is called, the entire decrypted message is printed to the screen.
}


/*Decryption function without the key. It firstly works out the letters that appear the most in the encrypted text.
It then prompts the user to input the order of most present letters, which are stored in an array.
It then works its way through the encrypted text (subMessage) and assigns the most used letter to E then T and so on.*/

void substitutionDecrypt(char *subMessage)
{
    int i, j, k, l, x;                                         //Initilising variables used in the for loops

    //Count array for storing the value of how many times each letter appears. Input array is the ordered appearance of letters after analysis
    //Each element is initially assigned as zero to eliminate unwanted data
    int count[26] = {0}; 
    char input[26] = {0};
 
    //Calculate frequency of each letter
    for(i = 0; subMessage[i] != '\0'; i++)      //Looping through each character in message until NULL character is reached
    {
        x = subMessage[i] - 65;                 //Creating the index of the array. Each identical value of x is stored at the same index.
        count[x]++;                             //The value of the element is incremented based on the calculated index, x.
    }

    //Loops through the established count array to print off the frequencies of each character
    
    for (j = 0; j < 26; j++)
        printf("%c occurs %d times in the string.\n", j + 65, count[j]);    //'j + 65' transforms the position value to the ASCII letter equivalent. 'count[j]' is the integer value of frequency.
    
    //Prompting the user input 
    printf("Enter the first 10 letters in order of highest frequency to lowest frequency: ");
    
    for(k = 0; k <= 10; k++)
        scanf("%c", &input[k-1]);               //Storing each entered character in the input array

    /*The following for loop moves through each element of the Message. Each time the character of the encrypted text matches
    that of the input array, the respective letter is substituted and stored as the new character value at that position.*/
    for(l = 0; subMessage[l] != '\0'; l++)
    {
        if(subMessage[l] == input[0])         //'input[0]' corresponds to the highest frequency letter based on user input
            subMessage[l] = 'E';              //This character is assigned to an 'E' based on the statistical properties of English text.
        
        /*The following 'else if' statements change the second most frequent letter to a 'T', the third most frequent
        letter to an 'A', and so on.*/
        
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
    printf("The decrypted message is %s", subMessage);   //Printing the entire 'decrypted' message to the screen
}

