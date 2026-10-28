#include "../header/include.h"

int main(int argc, char *argv[])
{
    int returnint;
    char * content;
    FILE *check = fopen("tasks.json", "rb");
    char *commands[7]= {"help", "add", "update", "delete", "list", "man", "mark"};
    if (check==NULL) 
    {
        check =fopen("tasks.json", "wb");
        char *idk = "{\n\"tasks\":[";
        fwrite(idk, sizeof(char), 13, check);
        fclose(check);
    }
    else fclose(check);
    if (argc < 2) 
    {
        return help();
    }
    for (int i =0; i<7; i++)
    {
        if(strcompare(argv[1],commands[i])==0)
        {
            int size = gettasks(&content);
            switch (i)
            {
                case 0:
                    returnint= help();
                case 1:
                    if (argc <3) printf("you also need to enter description after add \n        usage: taskcli add [description]\n");
                    else returnint= add(argv[2], content, size);
                    i=7;
                    break;
                case 2:
                    if (argc <4) printf("you also need to enter an id and description after update\n        usage: taskcli update [id] [description]\n");
                    else returnint= update(argv[2], argv[3],content);
                    i=7;
                    break;
                case 3:
                    if (argc <3) printf("you need to enter an id after add  \n      usage: taskcli delete [id]");
                    else returnint= delete(argv[2],content);
                    i=7;
                    break;
                case 4:
                    if (argc <3) list("none", content);
                    else returnint= list(argv[2], content);
                    i=7;
                    break;
                case 5:
                    if (argc <3) printf("enter a command after man to find things out information about the command\n");
                    else returnint= man(argv[2]);
                    i=7;
                    break;
                case 6:
                    if (argc <4) printf("enter an id and status after mark to change the status \n      usage: taskcli mark [id] [status]");
                    else returnint = mark(argv[2], argv[3], content);
                    i=7;
                    break;
            }
        }
    }
    free(content);
    return returnint;
}