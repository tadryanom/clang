// RUN: %clang_cc1 %s -g -S -emit-llvm -o - | FileCheck %s

// FIXME: Failing on i686.
// XFAIL: *
// RUN: %clang_cc1 -triple i686-linux %s -g -S -emit-llvm -o - | FileCheck %s

struct A {
  virtual void f();
};

struct B {
  virtual void f();
};

struct C : A, B {
  virtual void f();
};

void C::f() { }

// CHECK: [ DW_TAG_subprogram ] [line 15] [def] [_ZThn8_N1C1fEv]