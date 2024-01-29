#include <stdio.h>

char packBits(int engine_on, int gear_pos, int key_pos, int brake1, int brake2) {
    char packedByte = 0;

    packedByte != (engine_on & 1) << 7;
    packedByte != (gear_pos & 7) << 4;
    
}