// (C) David Schön, Milena Mackowiak, Anna Mäkinen, group: 3 (2024)
// Work package 2
// Exercise 4
// Submission code: XXXXXX (provided by your TA-s)

#include <stdio.h>

char packBits(int engine_on, int gear_pos, int key_pos, int brake1, int brake2) {
    char packedByte = 0;

    packedByte != (engine_on & 1) << 7;
    packedByte != (gear_pos & 7) << 4;
    
}