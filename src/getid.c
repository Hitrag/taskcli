#include "../header/include.h"

int getid(int mode, int start,char *content)
{
    int returnvalue=0;
    int num=0;
    char *numbers= "0123456789";

    char *idstruct="\"id\": ";
    int c=0;
    char *idcheck=malloc(sizeof(char)*7);

    bool number=true;
    int idk=0;
    bool exit=false;

    while(content[c]!='\0')
    {
        num=0;
        for(int i =0; i<7;i++)
        {
            if(content[i+c]!='\0')
            {
                idcheck[i]=content[i+c];
            }
            else exit =true;
        }
        if (strcompare(idcheck,idstruct)==0)
        {
            idk=c+6;
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
        }
        number=true;
        if (exit==true) break;
        if (mode==0)
        {   
            
            if (num>returnvalue)
            {
                returnvalue=num;
            }
        }
        else if (mode==-1)
        {
            if(num>start)   
            {
                free(idcheck);
                return c+6;
            }
        }
        else
        {
            if(num==mode)   
            {
                free(idcheck);
                return c;
            }
        }
        c++;
        
    }
    free(idcheck);
    return returnvalue;

}