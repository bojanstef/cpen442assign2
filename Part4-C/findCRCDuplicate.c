#include <stdio.h>
#include "crc.h"

int main(int argc, const char * argv[]) {
    unsigned int endNumber = 999999;
    unsigned int i;
    unsigned int *p;

    for (i = 0; i < endNumber; i++) {
        p = &i;
        crc_t crc = crc_init();
        crc = crc_update(crc, p, sizeof(i));
        crc = crc_finalize(crc);
        printf("%u: 0x%lx\n", i, (unsigned long)crc);
    }

    return 0;
}

