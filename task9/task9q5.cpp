#include <stdio.h>
#include <string.h>
int main() {
char cities[5][50];
int largestindex = 0;
int maxlen = 0;
printf("eter 5 city names\n");
for (int i = 0; i < 5; i++) {
if (fgets(cities[i], sizeof(cities[i]), stdin) != NULL) {
cities[i][strcspn(cities[i], "\n")] = '\0';
}
}
for (int i = 0; i < 5; i++) {
printf("%s\n", cities[i]);
int current = strlen(cities[i]);
if (current> maxlen) {
maxlen = current;
largestindex = i;
}
}
printf("lngest city name is %s\n", cities[largestindex]);
printf("length is%d", maxlen);
return 0;
}