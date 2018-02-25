#include <assert.h>

struct A {
  ~A() {
    assert(0);
  }
};

extern "C" void test_start(void(*f)());
extern "C" void test_end();

static void bar() {
  test_end();
}

static void foo() {
  A a;
  bar();
}

static void another() {
  foo();
}

extern "C"
void CppTest() {
  test_start(another);
}
