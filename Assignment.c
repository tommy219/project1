#include <stdio.h>

//char encryptionFunction(char *wordTest);

int main()
{
    char testStatement[1000], character;
    int i, cipherKey = 1;
    scanf("%s", testStatement);
    
    
    for(i = 0; testStatement[i] != '\0'; ++i)
    {
        character = testStatement[i];
        if(character >= 65 && character < 90)  //65 and 90 are ASCII values for 'A' and 'Z'
        {
            character += cipherKey;      //Character now becomes the encrypted letter
            printf("%c", character);
        }
       
        else if(character == 90)         //Loops to beginning of alphabet when going past 'Z'
        {
            character = (character - 90) + 64 + cipherKey;
            printf("%c", character);
        }
        
        else if(character >= 97 && character < 122)  //97 and 122 are ASCII values for 'a' and 'z'
        {
            character += cipherKey;      //Character now becomes the encrypted letter
            printf("%c", character);
        }
       
        else if(character == 122)         //Loops to beginning of alphabet when going past 'z'
        {
            character = (character - 122) + 96 + cipherKey;
            printf("%c", character);
        }
    }
    
}
