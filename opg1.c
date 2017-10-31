#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void encrypt_decrypt(unsigned int key,
                     unsigned char plain[],
                     unsigned char cipher[]) {

    /* Use the key as seed for the random function */
    srand(key);

    /* Get length of plaintext */
    int len = strlen(plain);

    /* For each byte in the plaintext */
    int i;
    for (i = 0; i < len; i++) {

        unsigned char pad = (unsigned char) rand();

        /* Encrypt a byte by XORing it with the pad */
        cipher[i] = plain[i] ^ pad;
    }
}


 void main() {
   uint k1 = 13;
   uint k2 = 13;
   char m1[] = "test123";
   char M[strlen(m1)];
   char m2[strlen(m1)];
   printf("Orginal melding:%s\n", m1);

   encrypt_decrypt(k1,m1,M);
   printf("kryptert:%s\n", M);

   encrypt_decrypt(k2,M,m2);
   printf("dekryptert: %s\n", m2);
 }
