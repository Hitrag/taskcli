#include "../header/include.h"

int strcompare(char *str1, char *str2)
{
    int c=0;
    int correctnes=0;
    while (str1[c]!='\0' && str2[c]!='\0')
    {
        if (str1[c]==str2[c])
        {
            correctnes++;
        }
        c++;
    }
    if (correctnes==c)
    {
        return 0;
    }
    return 1;

}