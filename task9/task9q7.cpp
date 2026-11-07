#include <stdio.h>
int main() {
FILE *file;
char name[50];
int count = 0;
file = fopen("students.txt", "w");
if (file == NULL) {
printf("error opening file\n");
return 1;
}
printf("enter 3 student names\n");
for (int i = 0; i < 3; i++) {
scanf("%s", name);
fprintf(file,"%s\n", name);
}
fclose(file);
file = fopen("students.txt", "r");
if (file == NULL) {
printf("error opening file\n");
return 1;
}
printf("names read from students.txt:\n");
while (fscanf(file, "%s", name) != EOF) {
count++;
printf("%d. %s\n", count, name);
}
printf("total students in file: %d\n", count);
fclose(file);
return 0;
}
