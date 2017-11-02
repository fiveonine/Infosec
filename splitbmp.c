
#include<stdio.h>
#include<stdlib.h>


int main(int argc, char *argv[]) {

  if (argc < 2) {
    printf("USAGE: splitbmp FILE");
    exit(1);
  }

  FILE *infile = fopen(argv[1], "r");
  if (infile == 0) {
    fprintf(stderr, "Could not open file %s\n", argv[1]);
    exit(2);
    
  }

  FILE *headfile = fopen("HEAD", "w");
  FILE *bodyfile = fopen("BODY", "w");

  if (headfile == 0 || bodyfile == 0) {
    fprintf(stderr, "Could not write file\n");
    exit(2);
  }

  int i = 0;
  int c = fgetc(infile);
  while (c != EOF && i < 0x8A) {
    fputc(c, headfile);
    c = fgetc(infile);
    i++;
  }

  while (c != EOF) {
    fputc(c, bodyfile);
    c = fgetc(infile);
  }

  fclose(infile);
  fclose(headfile);
  fclose(bodyfile);

  printf("Done.");

  exit(0);

}
