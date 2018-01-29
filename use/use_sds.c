#include <stdio.h>
#include <stdlib.h>
#include "../sds.h"


int main(int argc, char *argv[])
{
  FILE *fp;
  char buf[1024];
  sds line = NULL;

  if (argc != 2) {
    printf("argv fail");
    exit(1);
  }

  if ((fp = fopen(argv[1], "r")) == NULL) {
    printf("Fatal error can't open config file");
  }

  while (fgets(buf, 1024, fp) != NULL) {
    line = sdsnew(buf);
    printf("sds: %s", line);
  }

  printf("file name:%s", argv[1]);
}
