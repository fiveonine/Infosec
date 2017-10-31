# Infosec

**Oppgave1:**
1. Lag et C-program som krypterer og dekrypterer med encrypt decrypt-
funksjonen og demonstrer at funksjonen fungerer.

```c
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

```
2. Hvorfor er bruken av rand-funksjonen problematisk?

``Fordi rand() kan ha forskjellig implementering på forskjellige maskiner. Samme nøkkel kan da gi forskjellig svar.``

3. I tillegg er krypteringsmetoden sårbar mot både brute force-angrep og
nøkkelkollisjonsangrep. Forklar hvorfor. Hva måtte vi gjøre om vi ville
“redde” krypteringsmetoden?

``seeden i srand() er begrenset av størrelsen på variabler datamaskinen kan håndtere, for en 64bit maskin blir dette 64bit. I tillegg har ikke srand() nødvendigvis noe beskyttelse mot at forskjellige nøkler kan gi samme resultat, og det kan fort oppstå nøkkelkollisjoner.``

**Oppgåve2:**
1 Bruk framgangsmåten under til å knekke WEP-krypteringa til Wi-Fi-et som
er sett opp i klasserommet.

2. Bruk Wireshark til å samanlikne pakke-capture før og etter dekryptering.

3. På side 389 i læreboka (Introduction to computer security) er det skildra
fire kategoriar åtak mot kryptering. Kva kategori fell åtaket frå oppgåve a)
under?

``Vi benytter oss av IV-collision. Vi samler inn en rekke IV'er og så venter på at aksesspunktet skal gjenta en.``

4. I dei fyrste implementasjonane av WEP var ikkje IV -ane tilfeldige men
sekvensnummer. Ein konsekvens av dette var høgt gjenbruk av IV -ar.
Forklar korleis dette opna for nøkkelkollisjonsåtak mot WEP.

``Økt antall kollisjoner gjør det lettere å revesrere nøkkelstrengen. ``

**Oppgåve3:**
1. Følg framgangsmåten for å kryptere eit bilete med AES-128 og ECB.

2. Krypter det same biletet med den same nøkkelen men med CBC.

3. Samanlikne dei to bileta. Kvifor har dei blitt som dei har blitt?
