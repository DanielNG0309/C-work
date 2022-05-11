// ENCM 335 Fall 2021
// Lab 7 Exercise D

struct One {
  int i;
  char c[4];
};

struct Two {
  struct One a;
  int b;
};

void foo(struct Two *p)
{
  struct One *q;
  int *r;
  q = &(p->a);
  q->c[2] = 'z';
  p->b += 2;
  r = &q->i;
  *r -= 1;

  // point one

  return;
}

int main(void)
{
  struct Two x = { { 99, "uvw" }, 87 };
  foo(&x);
  return 0;
}
