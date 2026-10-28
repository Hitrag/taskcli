#include "../header/include.h"

int mark(char *id, char *status, char *content)
{
    /*int idI=0;
    char *numbers= "0123456789";
    bool done =false;
    char *statuses[2]= {"in-progress", "done"};
    bool correct =false;
    bool correctnes=false;
    int c =0;
    char *statuscheck= "\"status\": \"";
    char s='p';

    time_t now = time(NULL);        
    struct tm *t = localtime(&now);
    char *time = malloc(sizeof(char)*11);
    strftime(time,11,"%Y-%m-%d", t);


    for (int i=0; i<2; i++)
    {
        if (strcompare(statuses[i],status))
        {
            correct=true;
            if(i==1) done=false;
            else if(i==0) done=true;
        }
    }
    if(done==true) s='c';
    if (correct==false)
    {
        printf("enter a valid status    \n      in-progress/done");
        return 4;
    }
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
    while (content[c]!='\0')
    {
        for (int i=0; i<11; i++)
        {
            if (content[c+i]=='\0') break;
            if (content[c+i]==statuscheck[i]) 
            {
                correctnes=true;
            }
            else if (content[c+i]!=statuscheck[i])
            {
                correctnes=false;
                break;
            }
        }
        if (correctnes==true)
        {
            c+=11;
            break;
        }
        c++;
    }
    content[c]=s;
    c+=45;
    for (int i=0; i<10; i++)
    {
        content[c+i]=time[i];
    }
    writetasks(content);*/
    return 0;
}