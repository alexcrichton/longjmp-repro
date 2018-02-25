#include <assert.h>
#include <setjmp.h>

static jmp_buf ENV;

extern void test_middle();

void test_start() {
  if (setjmp(ENV) != 0)
    return;
  test_middle();
  assert(0);
}

void test_end() {
  longjmp(ENV, 1);
  assert(0);
}
