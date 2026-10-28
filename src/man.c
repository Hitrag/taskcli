#include "../header/include.h"

int man(char *command)
{
    char *commands[7]= {"help", "add", "update", "delete", "list", "man", "mark"};
    for (int i =0; i<7; i++)
    {
        if(strcompare(command,commands[i])==0)
        {
            switch (i)
            {
                case 0:
                    printf("help prints out basic information about every command       \n      usage: taskcli help\n");
                    return 0;
                case 1:
                    printf("add creates a new task inside the tasks.json file           \n      usage: taskcli add [\"description\"]\n");
                    return 0;
                case 2:
                    printf("update allows changing of the tasks description by its id   \n      usage: taskcli update [id] [\"description\"]\n");
                    return 0;
                case 3:
                    printf("delete allows the deletion of tasks by its id               \n      usage: taskcli delete [id]\n");
                    return 0;
                case 4:
                    printf("lists all tasks under a specific filter or no filter        \n      usage: taskcli list ([filter])      \n      filter: in-progress/done");
                    return 0;
                case 5:
                    printf("man explains what one command does                          \n      usage: taskcli man [command]\n");
                    return 0;
                case 6:
                    printf("mark changes the status of a task from in progrees to done  \n      usage: taskcli mark [id] [status]   \n      status: in-progress/done\n");
                    return 0;
            }
        }
    }
    return 0;
}