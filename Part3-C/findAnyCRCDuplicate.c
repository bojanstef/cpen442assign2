#include <stdio.h>
#include <string.h>
#include "crc.h"

#define ARRAY_COUNT 10000
#define STRING_SIZE 100

int main(int argc, const char * argv[]) {
    char strs[ARRAY_COUNT][STRING_SIZE];
    crc_t crcs[ARRAY_COUNT];

    for (int i=0; i<ARRAY_COUNT; i++) {
        char str[STRING_SIZE];
        sprintf(str, "%d", i);
        strcpy(strs[i], str);
    }

    for(int i=0; i<ARRAY_COUNT; i++) {
        crc_t crc;
        crc = crc_init();
        crc = crc_update(crc, (unsigned char *)strs[i], strlen(strs[i]));
        crc = crc_finalize(crc);
        crcs[i] = crc;
        printf("%s: 0x%lx\n", strs[i], (unsigned long)crc);
    }

    for(int j=0; j<ARRAY_COUNT; j++) {
        for(int k=0; k<ARRAY_COUNT; k++) {
            if ((crcs[j] == crcs[k]) && (j != k)) {
                printf("Equal: j: %d, k: %d\n", j, k);
                printf("crcs[j]: 0x%hx, crcs[k]: 0x%hx\n\n", crcs[j], crcs[j]);
                return 0; // Comment out to show all duplicates.
            }
        }
    }

    return 0;
}

