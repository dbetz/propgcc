/* { dg-do compile } */
/* { dg-options "-O2 -march=armv6t2" } */

int mac(const short *a, const short *b, int sqr, int *sum)
{
  int i;
  int dotp = *sum;

  for (i = 0; i < 150; i++) {
    dotp += b[i] * a[i];
    sqr += b[i] * b[i];
  }

  *sum = dotp;
  return sqr;
}

/* { dg-final { scan-assembler-times "smlabb" 2 } } */