/* Lab Program 14
   Count the vowels, consonants and words in a sentence read using fgets.
   gcc lab14_count_vowels_consonants_words.c -o lab14  */

#include<stdio.h>

int main() {
    char str[200];
    int i, vowels = 0, cons = 0, words = 1;
    char ch;

    printf("Enter a sentence : ");
    fgets(str, 200, stdin);

    for(i = 0; str[i] != '\0'; i++) {
        ch = str[i];
        if(ch >= 'A' && ch <= 'Z')
            ch = ch + 32;
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
            vowels++;
        else if(ch >= 'a' && ch <= 'z')
            cons++;
        else if(ch == ' ')
            words++;
    }

    printf("Vowels = %d\n", vowels);
    printf("Consonants = %d\n", cons);
    printf("Words = %d\n", words);
    return 0;
}
