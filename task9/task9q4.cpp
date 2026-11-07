#include <stdio.h>
#include <string.h>
int main() {
char phrase[200];
printf("enter a phrase ");
fgets(phrase, sizeof(phrase), stdin);
phrase[strcspn(phrase, "\n")] = '\0';
char *p = strchr(phrase, 'a');
if (p != NULL) {
printf("first 'a' found at index %d\n", p - phrase);
} else {
printf("letter 'a' not found in the sentence.\n");
}
if (strstr(phrase, "good") != NULL) {
printf("Word 'good' found\n");
} else {
printf("Word 'good' not found\n");
}   
return 0;
}