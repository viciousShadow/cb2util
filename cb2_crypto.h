/*
 * Cryptographic functions for CodeBreaker PS2
 *
 * Copyright (C) 2006-2011 Mathias Lafeldt <misfire@debugon.org>
 * All rights reserved.
 *
 * This file is part of cb2util, the CodeBreaker PS2 File Utility.
 *
 * cb2util is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * cb2util is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#ifndef _CB2_CRYPTO_H_
#define _CB2_CRYPTO_H_

#include <stddef.h>
#include <stdint.h>

/* CB V1 code encryption */
#ifdef CODE_ENCRYPTION
void cb1_encrypt_code(uint32_t *addr, uint32_t *val);
#endif
void cb1_decrypt_code(uint32_t *addr, uint32_t *val);

/* CB V7 code encryption */
void cb7_beefcode(int init, uint32_t val);
#ifdef CODE_ENCRYPTION
void cb7_encrypt_code(uint32_t *addr, uint32_t *val);
#endif
void cb7_decrypt_code(uint32_t *addr, uint32_t *val);

/* All versions */
void cb_reset(void);
void cb_set_common_v7(void);
#ifdef CODE_ENCRYPTION
void cb_encrypt_code(uint32_t *addr, uint32_t *val);
#endif
void cb_decrypt_code(uint32_t *addr, uint32_t *val);
void cb_decrypt_code2(uint32_t *addr, uint32_t *val);

/* CB file functions */
int cb_verify_signature(const uint8_t *sig, const uint8_t *buf, size_t buflen);
void cb_crypt_data(uint8_t *buf, size_t buflen);

#endif /* _CB2_CRYPTO_H_ */
