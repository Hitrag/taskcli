#include "../header/include.h"

int delete(char *id, char *content)
{
    int idI=0;
    int c=0;
    int tmp =0;
    int tmp2=0;
    char *numbers= "0123456789";
    char * cpy1;
    char *printval;
    char * cpy2;
    while(id[c]!='\0')
    {
        for (int i=0; i<10;i++)
        {
            if (id[c]==numbers[i])
            {
                idI*=10;
                idI+=i;
            }
        }
        c++;
    }
    c = getid(idI,0,content);
    if (c==0)
    {
        printf("enter a valid id\n");
        return -1;
    }
    while(content[c]!='{') c--;
    c--;
    while(tmp<c)
    {
        tmp++;
    }
    cpy1 =malloc(sizeof(char)*tmp+1);
    tmp=0;
    while (tmp<c)
    {
        cpy1[tmp]=content[tmp];
        tmp++;
    }
    while (content[c]!='}') c++;
    c++;
    tmp=c;
    while(content[tmp]!='\0') tmp++;
    cpy2 =malloc(sizeof(char)*tmp+1);
    tmp=0;
    while(content[c]!='\0')
    {
        cpy2[tmp]=content[c];
        c++;
        tmp++;
    }
    tmp=0;
    while(cpy1[tmp]!='\0')
    {
        tmp++;
    }
    while(cpy2[tmp2]!='\0')
    {
        tmp++;
        tmp2++;
    }
    printval=malloc(sizeof(char)*tmp+1);
    tmp=0;
    tmp2=0;
    while(cpy1[tmp]!='\0')
    {
        printval[tmp2]=cpy1[tmp];
        tmp2++;
        tmp++;
    }
    tmp=0;
    while(cpy2[tmp]!='\0')
    {
        printval[tmp2]=cpy2[tmp];
        tmp2++;
        tmp++;
    }
    writetasks(printval);
    free(printval);
    free(cpy1);
    free(cpy2);
    return 0;
}