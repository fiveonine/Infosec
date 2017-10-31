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
