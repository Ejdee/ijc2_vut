#include "io.h"

int main() {
    FILE *fp = fopen("test_file", "r");
    if(fp == NULL) {
        fprintf(stderr, "Failed to open a file.\n");
        return 1;
    }

    int len = 255;
    char s[len];
    bool warning = false;
 
    for(int i = 0; i < 15; i++) {
        int length = read_word(s, len-1, fp);
        if(length > 254 && !warning) {
            fprintf(stderr, "The word exceeded the limit for length. CUT.\n");
            warning = true;
        } 
        printf("%d\n", length);
        printf("%s\n", s);
    }

    fclose(fp);

    return 0;
}