
#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[]) {

  if (argc < 3) {
    printf("USAGE; mergebmp HEADFILE BODYFILE");
    exit(1);
  }

  FILE *headfile = fopen(argv[1], "r");
  if (headfile == 0) {
    fprintf(stderr, "Could not open file %s\n", argv[1]);
    exit(2);
  }

  FILE *bodyfile = fopen(argv[2], "r");
  if (headfile == 0) {
    fprintf(stderr, "Could not open file %s\n", argv[2]);
    exit(2);
  }

  FILE *outfile = fopen("MERGE.bmp", "w");
  if (outfile == 0) {
    fprintf(stderr, "Could not write file\n");
    exit(2);
  }

  int c = fgetc(headfile);
  while (c != EOF) {
    fputc(c, outfile);
    c = fgetc(headfile);
  }

  c = fgetc(bodyfile);
  while (c != EOF) {
    fputc(c, outfile);
    c = fgetc(bodyfile);
  }

  fclose(headfile);
  fclose(bodyfile);
  fclose(outfile);

  printf("Done.");
  exit(0);




}
