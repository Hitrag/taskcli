#include "../header/include.h"

int update(char *id,char *description,char *content)
{
    int idI=0;
    char *numbers= "0123456789";
    int c=0;
    char descheck[]= "\"description\": \"";
    bool correct=true;
    int tmp;
    char * printval;
    int tmp2;
    int size=0;
    char * copy1;
    char * copy2;

    time_t now = time(NULL);        
    struct tm *t = localtime(&now);
    char *time = malloc(sizeof(char)*11);
    strftime(time,11,"%Y-%m-%d", t);

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
        return 3;
    }

    while (content[c]!='\0')
    {
        for (int i=0; i<17; i++)
        {
            if(content[c+i]!='\0') break;
            if(content[c+i]==descheck[i])
            {
                correct=true;
            }
            else
            {
                correct=false;
                break;
            }
        }
        if(correct==true)
        {
            c+=21;
            while(content[c]!='\"') c++; 
            c+=4;
            copy1 = malloc(c+1);
            tmp=0;
            while (tmp <c)
            {
                copy1[tmp]= content[tmp];
                tmp++;
            }
            while(content[c]!='\"') c++;
            tmp=c;
            size=0;
            while(content[tmp]!='\0') 
            {
                tmp++;
                size++;
            }
            copy2=malloc(sizeof(char)*size);
            tmp=c;
            tmp2=0;
            while (content[tmp]!='\0')
            {
                copy2[tmp2]= content[tmp];
                tmp++;
                tmp2++;
            }
            tmp=0;
            size=0;
            while(copy1[tmp]!='\0') {size++ ; tmp++;}
            tmp=0;
            while(copy2[tmp]!='\0') {size++ ; tmp++;}
            tmp=0;
            while(description[tmp]!='\0') {size++ ; tmp++;}
            size++;
            printval=malloc(sizeof(char)*size);
            tmp=0;
            tmp2=0;
            while(copy1[tmp]!='\0')
            {
                printval[tmp2]=copy1[tmp];
                tmp++;
                tmp2++;
            }
            tmp=0;
            while(description[tmp]!='\0')
            {
                printval[tmp2]=description[tmp];
                tmp++;
                tmp2++;
            }
            tmp=0;
            while(copy2[tmp]!='\0')
            {
                printval[tmp2]=copy2[tmp];
                if(tmp==59)
                {
                    for(int i =0; i<10; i++)
                    {
                        printval[tmp2+i]=time[i];
                    }
                    tmp2+=9;
                    tmp+=9;
                }
                tmp++;
                tmp2++;
            }
            printval[tmp2]='\0';
            break;
        }
    }
    writetasks(printval);
    free(copy1);
    free(copy2);
    free(printval);

    return 0;
}