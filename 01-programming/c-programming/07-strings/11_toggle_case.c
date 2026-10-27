// toggle the case of each character
#include<stdio.h>
#include<string.h>

int main() {
    char str[100];
    int i;

    printf("Enter a string: ");
    fgets(str, 100, stdin);
    str[strlen(str) - 1] = '\0';    // remove \n

    for(i = 0; str[i] != '\0'; i++) {
        if(str[i] >= 'a' && str[i] <= 'z')
            str[i] = str[i] - 32;
        else if(str[i] >= 'A' && str[i] <= 'Z')
            str[i] = str[i] + 32;
    }

    printf("Toggled string = %s\n", str);
    return 0;
}
