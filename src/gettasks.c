#include "../header/include.h"

int gettasks(char **content)
{
    int size =0;
    FILE *task=fopen("tasks.json", "rb");
    *content=malloc(sizeof(char));

    while (fread(*content,sizeof(char),1,task)!=0) size++;

    free(*content);
    *content=malloc(sizeof(char)*size);

    fseek(task,0,SEEK_SET);
    fread(*content, sizeof(char),size,task);

    fclose(task);

    return size;
}