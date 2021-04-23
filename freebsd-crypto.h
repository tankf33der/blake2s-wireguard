/* SPDX-License-Identifier: MIT
 *
 * Copyright (C) 2015-2021 Jason A. Donenfeld <Jason@zx2c4.com>. All Rights Reserved.
 */

#ifndef _WG_CRYPTO
#define _WG_CRYPTO

#include <sys/types.h>
#include <stdint.h>
#include <inttypes.h>

// #include <sys/mbuf.h>

enum blake2s_lengths {
	BLAKE2S_BLOCK_SIZE = 64,
	BLAKE2S_HASH_SIZE = 32,
	BLAKE2S_KEY_SIZE = 32
};

struct blake2s_state {
	uint32_t h[8];
	uint32_t t[2];
	uint32_t f[2];
	uint8_t buf[BLAKE2S_BLOCK_SIZE];
	unsigned int buflen;
	unsigned int outlen;
};

void freebsd_blake2s_init(struct blake2s_state *state, const size_t outlen);

void freebsd_blake2s_init_key(struct blake2s_state *state, const size_t outlen,
		      const uint8_t *key, const size_t keylen);

void freebsd_blake2s_update(struct blake2s_state *state, const uint8_t *in, size_t inlen);

void freebsd_blake2s_final(struct blake2s_state *state, uint8_t *out);

void freebsd_blake2s(uint8_t *out, const uint8_t *in, const uint8_t *key,
	     const size_t outlen, const size_t inlen, const size_t keylen);

#endif
