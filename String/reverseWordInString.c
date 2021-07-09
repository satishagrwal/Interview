#include<stdio.h>
void revString(char *pBegin, char *pEnd)
{
    char temp;
    while (pBegin < pEnd)
    {
        temp = *pBegin;
        *pBegin++ = *pEnd;
        *pEnd-- = temp;
    }
}

void reverseWordInString(char *pString)
{
    // store the beginning address of word
    char *word_begin = NULL;
  
    // word_boundary is for word boundary
    char *word_boundary = pString; /* */
    
  //Loop to reverse the character of words
    while( *word_boundary )
    {
        //This condition is to make sure that
        //the string start with valid character
        if (( word_begin == NULL ) && (*word_boundary != ' ') )
        {
            word_begin = word_boundary;
        }
        if(word_begin && ((*(word_boundary+1) == ' ') || (*(word_boundary+1) == '\0')))
        {
            revString(word_begin, word_boundary);
            word_begin = NULL;
        }
        word_boundary++;
    }
    // reverse the whole string
    revString(pString, word_boundary-1);
}

int main()
{
    //source string
    char src[] = "How are you";
  
    //Reverse the word of the string
    reverseWordInString(src);
  
  //print the resultant string
    printf("Resultant string = %s", src);
  
  return 0;
}
