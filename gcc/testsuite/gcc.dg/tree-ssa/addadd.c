/* { dg-do compile } */
/* { dg-options "-O -fdump-tree-optimized" } */

int f(unsigned x){
  x += 123;
  int y = x;
  y -= 99;
  return y;
}
unsigned g(int x){
  x += 123;
  unsigned y = x;
  y -= 99;
  return y;
}
int h(int x){
  x += __INT_MAX__;
  x += 1;
  return x;
}
int i(int x){
  x += __INT_MAX__;
  x += __INT_MAX__;
  return x;
}
typedef int S __attribute__((vector_size(16)));
void j(S*x){
  *x += __INT_MAX__;
  *x += __INT_MAX__;
}

/* { dg-final { scan-tree-dump-times " \\+ 24;" 2 "optimized" { xfail *-*-* } } } */
/* { dg-final { scan-tree-dump-times "\\(unsigned int\\)" 2 "optimized" { xfail *-*-* }  } } */
/* { dg-final { scan-tree-dump-not "2147483647" "optimized" { xfail *-*-* }  } } */
