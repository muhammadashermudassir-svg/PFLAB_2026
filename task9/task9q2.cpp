#include <stdio.h>
#include <string.h>

int main() {
char first[100];
char last[100];
char fullname[100];
printf("enter first name");
scanf("%s",first);
printf("enter last name");
scanf("%s",last);
strcpy(fullname,first);
strcat(fullname, " ");
strcat(fullname,last);
 printf("full name is %s\n", fullname);
 return 0;
}



