#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int match(int* a, int* b) {
    for (int i = 0; i < 26; i++) {
        if (a[i] != b[i]) {
            return 0;
        }
    }
    return 1;
}
int checkInclusion(char* s1, char* s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);

    if (len1 > len2) {
        return 0;
    }

   
    int freq_s1[26] = { 0 };
    int freq_s2[26] = { 0 };

   
    for (int i = 0; i < len1; i++) {
        freq_s1[s1[i] - 'a']++;
        freq_s2[s2[i] - 'a']++;
    }


    for (int i = len1; i < len2; i++) {
        if (match(freq_s1, freq_s2)) {
            return 1;
        }
        
        freq_s2[s2[i] - 'a']++;
        freq_s2[s2[i - len1] - 'a']--;
    }


    return match(freq_s1, freq_s2);
}


int main()
{
 
}

