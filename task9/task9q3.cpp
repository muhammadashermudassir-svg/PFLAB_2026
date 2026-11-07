#include <stdio.h>
#include <string.h>

int main() {
char crctpass[] = "lab67pass";
char userinput[50];
printf("Enter password: ");
scanf("%s", userinput);
if (strcmp(userinput, crctpass) == 0) { 
printf("Access granted\n");
} else {
 printf("Access denied\n");
}
if (strncmp(userinput, crctpass, 3) == 0) {
printf("First 3 characters match.\n");
}
return 0;
}