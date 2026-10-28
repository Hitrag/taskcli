#pragma once
int help();
int strcompare(char *str1, char *str2);
int man(char *command);
int add(char *description, char *content, int size);
int gettasks(char **content);
void writetasks(char *content);
int getid(int mode, int start,char *countent);
int update(char *id,char *description,char *content);
int delete(char *id, char * content);
int mark(char *id, char *status, char *content);
int list(char *filter, char *content);