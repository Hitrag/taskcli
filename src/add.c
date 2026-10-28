#include "../header/include.h"



int add(char *description, char*content, int size)
{

    int c=0;
    int eC=12;


        //Gets the id value 
    int id=getid(0,0,content)+1;
    int nDigits = floor(log10(abs(id))) + 2;

        //gets the time 
    time_t now = time(NULL);        
    struct tm *t = localtime(&now);
    char *time = malloc(sizeof(char)*11);
    strftime(time,11,"%Y-%m-%d", t);

    char* merge=malloc(sizeof(char)*(size+92+22+nDigits));
    while (content[c]!='\0')
    {
        if (content[c]==']')
        {
            eC=c;
        }
        c++;
    }
    char *contentcpy=malloc(sizeof(char)*(eC));
    for (int i=0; i<eC; i++) contentcpy[i]=content[i];
    
    if(eC<=20)  sprintf(merge, "{\n\"tasks\":[{\n\"id\": %i,\n\"description\": \"%s\",\n\"status\": \"p\",\n\"CreatedAt\": \"%s\",\n\"updatedAt\": \"%s\"\n}]}",id,description,time,time);
    else        sprintf(merge, "%s,{\n\"id\": %i,\n\"description\": \"%s\",\n\"status\": \"p\",\n\"CreatedAt\": \"%s\",\n\"updatedAt\": \"%s\"\n}]}",contentcpy,id,description,time,time);
    

    writetasks(merge);

    free(time);
    free(merge);
    return 0;
}