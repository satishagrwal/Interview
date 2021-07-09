#include <stdio.h>
#include <string.h>

void isAnagram(char* pFirstStr, char* pSecondStr)
{
    int iFirst[26] = {0};
    int iSecond[26] = {0};
    int iCount = 0;
    
    while(pFirstStr[iCount] != '\0')
    {
        iFirst[pFirstStr[iCount] - 'a']++;
        iCount++;
    }
    
    iCount = 0;
    
    while(pSecondStr[iCount] != '\0')
    {
        iSecond[pSecondStr[iCount] - 'a']++;
        iCount++;
    }
    
    for (int a= 0; a < 26 ; a++)
    {
        if(iFirst[a] != iSecond[a])
        {
          printf("Not an anagram...!!!\n");
          return;
        }
    }
    printf("An anagram...!!!\n");
}

int main()
{
     char cFirstStr[] = "satish";
     char cSecondStr[] = "hssait";
     
     isAnagram(cFirstStr, cSecondStr);   
     return 0;
}
