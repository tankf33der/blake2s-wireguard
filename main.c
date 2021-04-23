#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>

#include "blake2-ref.h"
#include "freebsd-crypto.h"

int main(void) {
	uint8_t d[64], out1[33], out2[33];
	int result = 0;
	for(size_t i = 0; i < 64; i++) d[i] = i;
	
	for(size_t o = 1; o <= 32; o++)
		for(size_t k = 0; k <= 32; k++)
			for(size_t m = 0; m < 64; m++) {
				blake2s(out1, o, d, m, d, k);
				freebsd_blake2s(out2, d, d, o, m, k);
				result |= memcmp(out1, out2, o);	
			}
	return result;
}
