#include <stdio.h>
#include <string.h>

int main() {
char name[100];
char copy[100];
fgets(name,sizeof(name),stdin);
name[strcspn(name,"\n")] = '\0';
printf("length is %d\n", (int)strlen(name));
strcpy(copy, name);
printf("copied name \n %s\n", copy);
printf("sizeof(name) array is %d bytes\n", (int)sizeof(name));
printf("strlen(name) value is %d\n", (int)strlen(name));

}