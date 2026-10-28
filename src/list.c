#include "../header/include.h"

struct task
{
    int id;
    char *name;
    bool done;
};

int list(char *filter, char *content)
{
    int c=0;
    int mode=0;
    bool number=true;
    int amount=0;
    int num=0;
    int tmp=0;
    char *numbers= "0123456789";
    char *filtes[3]= {"done", "in-progress", "none"};
    while (content[c]!='\0')
    {
        if (content[c]=='}') amount ++;
        c++;
    }
    if (amount <2) 
    {
        printf("No tasks were created\n");
        return 0;
    }
    amount--;
    struct task tasks[amount];
    int idk;
    c=0;
    for(int i=0; i<amount;i++)
    {
        c=getid(-1,num,content);
        num=0;
        idk=c;
        number=true;
        while (number==true)
        {
            for (int i =0; i<10;i++)
            {
                if(content[idk]==numbers[i])
                {
                    num*=10;
                    num+=i;
                    number=true;
                    break;
                }
                else
                {
                    number=false;
                }
            }
            idk++;
        }
        tasks[i].id=num;
        c+=19;
        idk=c;
        while(content[idk]!='\"')
        {
            idk++;
        }
        tasks[i].name=malloc(sizeof(char)*(idk-c)+1);
        tmp=0;
        while(c<idk)
        {
            tasks[i].name[tmp]=content[c];
            tmp++;
            c++;
        }
        c+=14;
        if(content[c]=='p')
        {
            tasks[i].done=false;
        }
        else if(content[c]=='c')
        {
            tasks[i].done=true;
        }
    }
    if(strcompare(filter, "none")==0) mode=0;
    else if(strcompare(filter, "in-progress")==0) mode=1;
    else if(strcompare(filter, "done")==0) mode=2;
    printf(" id\t| description\t\t\t\t\t| status\n");
    for(int i=0; i<amount; i++)
    {
        number=true;
        if(mode==1) 
        {
            if (tasks[i].done==true) number=false;
        }
        else if(mode==2)
        {
            if (tasks[i].done==false) number=false;
        }
        if(number==true)
        {
            printf(" %i\t|",tasks[i].id);
            c=0;
            while(tasks[i].name[c]!='\0')c++;
            c=(c+1)/8;
            printf(" %s",tasks[i].name);
            for (int i=0; i<6-c;i++) printf("\t");
            printf("|");
            if(tasks[i].done==true) printf(" done\n");
            else if(tasks[i].done==false) printf(" in-progress\n");
        }
    }
    return 0;
}