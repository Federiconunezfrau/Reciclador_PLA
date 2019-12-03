#include "utils.h"
#include <string.h>

char* itoa(int value, char* result, int base) {
   // check that the base if valid
   if (base < 2 || base > 36) { *result = '\0'; return result; }

   char* ptr = result, *ptr1 = result, tmp_char;
   int tmp_value;

   do {
      tmp_value = value;
      value /= base;
      *ptr++ = "zyxwvutsrqponmlkjihgfedcba9876543210123456789abcdefghijklmnopqrstuvwxyz" [35 + (tmp_value - value * base)];
   } while ( value );

   // Apply negative sign
   if (tmp_value < 0) *ptr++ = '-';
   *ptr-- = '\0';
   while(ptr1 < ptr) {
      tmp_char = *ptr;
      *ptr--= *ptr1;
      *ptr1++ = tmp_char;
   }
   return result;
}

void appendchar(char * dest, char src) {
	int i;
	i = strlen(dest);
	dest[i++] = src;
	dest[i] = '\0';
}

void clearstring(char * str) {
	int i;
	for (i = strlen(str)-1; i >= 0; i--) {
		str[i] = '\0';
	}
}

int atoi(char* str)
{
    int res = 0; // Initialize result

    // Iterate through all characters of input string and
    // update result
    for (int i = 0; str[i] != '\0'; ++i)
        res = res * 10 + str[i] - '0';

    // return result.
    return res;
}

void myStrCpy(char * dest, char * src) {
	int i;

	for (i=0;i<strlen(src);i++) {
		if (src[i] == '\n') {}
		else {
			dest[i] = src[i];
		}
	}
}

