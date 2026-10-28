#include "../header/include.h"

int help()
{
    printf("usage: taskcli <command> [argument]\n");
    printf("    help                \n");
    printf("    add                 [description]\n");
    printf("    update              [id]            [description]\n");
    printf("    delete              [id]\n");
    printf("    mark                [id]            [status]\n");
    printf("    list                [filter]\n");
    printf("    man                 [command]\n");;
    return 0;
}