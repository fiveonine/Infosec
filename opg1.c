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

        /* Obtain a random byte to use as pad */
        unsigned char pad = (unsigned char) rand();

        /* Encrypt a byte by XORing it with the pad */
        cipher[i] = plain[i] ^ pad;
    }
}


 void main() {
   uint k1 = 12;
   uint k2 = 12;
   char m1 = 'a';
   char M;
   char m2;
   printf("Orginal melding:%c\n", m1);
   encrypt_decrypt(k1,&m1,&M);
   printf("kryptert:%c\n", M);
   encrypt_decrypt(k2,&M,&m2);
   printf("dekryptert: %c\n", m2);
 }
