// Copyright lowRISC contributors.
// Licensed under the Apache License, Version 2.0, see LICENSE for details.
// SPDX-License-Identifier: Apache-2.0

#include <stdio.h>

#include "hmac.h"
#include "sha.h"
#include "sha256.h"
#include "svdpi.h"

typedef unsigned long long ull_t;

extern void SHA_hash_dpi(const svOpenArrayHandle msg, ull_t len,
                         unsigned int hash[8]) {
  unsigned char *arr;
  unsigned int *arr_ptr;
  ull_t i;

  arr = (unsigned char *)malloc(len * sizeof(unsigned char));
  arr_ptr = (unsigned int *)svGetArrayPtr(msg);

  for (i = 0; i < len; i++) {
    arr[i] = arr_ptr[i];
  }

  // compute SHA hash
  SHA_hash(arr, len, hash);

  free(arr);
}

extern void SHA256_hash_dpi(const svOpenArrayHandle msg, ull_t len,
                            unsigned int hash[8]) {
  unsigned char *arr;
  unsigned int *arr_ptr;
  ull_t i;

  arr = (unsigned char *)malloc(len * sizeof(unsigned char));
  arr_ptr = (unsigned int *)svGetArrayPtr(msg);

  for (i = 0; i < len; i++) {
    arr[i] = arr_ptr[i];
  }

  // compute SHA256 hash
  SHA256_hash(arr, len, hash);

  free(arr);
}

extern void HMAC_SHA_dpi(const svOpenArrayHandle key, ull_t key_len,
                         const svOpenArrayHandle msg, ull_t msg_len,
                         unsigned int hmac[8]) {
  unsigned char *msg_arr;
  unsigned int *msg_arr_ptr;
  unsigned char *key_arr;
  unsigned int *key_arr_ptr;
  ull_t i;

  msg_arr = (unsigned char *)malloc(msg_len * sizeof(unsigned char));
  msg_arr_ptr = (unsigned int *)svGetArrayPtr(msg);

  key_arr = (unsigned char *)malloc(key_len * sizeof(unsigned char));
  key_arr_ptr = (unsigned int *)svGetArrayPtr(key);

  for (i = 0; i < msg_len; i++) {
    msg_arr[i] = msg_arr_ptr[i];
  }

  for (i = 0; i < key_len; i++) {
    key_arr[i] = key_arr_ptr[i];
  }

  // compute SHA hash
  HMAC_SHA(key_arr, key_len, msg_arr, msg_len, hmac);

  free(msg_arr);
  free(key_arr);
}

extern void HMAC_SHA256_dpi(const svOpenArrayHandle key, ull_t key_len,
                            const svOpenArrayHandle msg, ull_t msg_len,
                            unsigned int hmac[8]) {
  unsigned char *msg_arr;
  unsigned int *msg_arr_ptr;
  unsigned char *key_arr;
  unsigned int *key_arr_ptr;
  ull_t i;

  msg_arr = (unsigned char *)malloc(msg_len * sizeof(unsigned char));
  msg_arr_ptr = (unsigned int *)svGetArrayPtr(msg);

  key_arr = (unsigned char *)malloc(key_len * sizeof(unsigned char));
  key_arr_ptr = (unsigned int *)svGetArrayPtr(key);

  for (i = 0; i < msg_len; i++) {
    msg_arr[i] = msg_arr_ptr[i];
  }

  for (i = 0; i < key_len; i++) {
    key_arr[i] = key_arr_ptr[i];
  }

  // compute SHA256 hash
  HMAC_SHA256(key_arr, key_len, msg_arr, msg_len, hmac);

  free(msg_arr);
  free(key_arr);
}