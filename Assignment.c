#include <stdio.h>

//Function prototype

void encryptionFunction(char *testStatement, int cipherKey);

int main()
{
    char testStatement[1000];
    int cipherKey;
    scanf("%s", testStatement);                                            //Gets message to be tested from the 'input' file
    scanf("%d", &cipherKey);                                               //Gets the key for the cipher from the 'input' file
    encryptionFunction(testStatement, cipherKey);                          //Calling the result of the encryption function
}

//Function definition for encrypting the message

void encryptionFunction(char *testStatement, int cipherKey)
{
    int i;
    for(i = 0; testStatement[i] != '\0'; ++i)                              //Goes through each element of the string and changes its value
    {

        if(testStatement[i] >= 65 && testStatement[i] < 90)                //65 and 90 are ASCII values for 'A' and 'Z'
        {
            testStatement[i] += cipherKey;                                 //Assigninging the individual character to its new value
        }
        else if(testStatement[i] == 90)                                    
        {
            testStatement[i] = (testStatement[i] - 90) + 64 + cipherKey;   //Loops to beginning of alphabet when going past 'Z'
        }
        else if(testStatement[i] >= 97 && testStatement[i] < 122)          //97 and 122 are ASCII values for 'a' and 'z'
        {
            testStatement[i] += cipherKey;                                 //Assigninging the individual character to its new value
        }
        else if(testStatement[i] == 122)                                   
        {
            testStatement[i] = (testStatement[i] - 122) + 96 + cipherKey;  //Loops to beginning of alphabet when going past 'z'
        }
    }
    printf("%s", testStatement);
} 
    
    
    
