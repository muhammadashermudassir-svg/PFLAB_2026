#include <stdio.h>
int isSubsequence(char* a, char* b) {
int i = 0;
int j = 0;
while (a[i] != '\0' && b[j] != '\0') {
if (a[i] == b[j]) {
i++;
}
j++;
}
if (a[i] == '\0') {
return 1;
}
return 0;
}
int main() {
char a1[] = "abc";
char b1[] = "ahbgdc";
    
    if (isSubsequence(a1, b1)) {
        printf("True\n");
    } else {
        printf("False\n");
    }
    
    return 0;
}
