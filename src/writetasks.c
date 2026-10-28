#include "../header/include.h"

char *errochecker(char *content)
{
    int c=0;
    char lastchar='\0';
    char *null=malloc(sizeof(char));
    while(content[c]!='\0')
    {
        if(lastchar==':'&& content[c]==']') return null;
        else if (lastchar==':'&& content[c]==',') 
        {
            content[c]='[';
        }
        lastchar=content[c];
        c++;
    }
    return content;
}

void writetasks(char *content)
{
    FILE *write=fopen("tasks.json", "wb");
    int size=0;
    char *printval=errochecker(content);
    while (printval[size]!='\0') size++;
    fwrite(printval, sizeof(char), size, write);
    fclose(write);
    return ;
}