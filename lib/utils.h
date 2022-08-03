#ifndef SEM3_OOP_CPP_UTILS_H
#define SEM3_OOP_CPP_UTILS_H

#include <iostream>

// #define DEBUG

#ifdef DEBUG
#define D(x...) x
#else
#define D(x...)
#endif  // DEBUG

#define TEST(name, tests...) \
  int main() {               \
    char testname[] = name;  \
    int failed = 0;          \
    tests;                   \
    if (failed) {            \
      return 1;              \
    } else {                 \
      return 0;              \
    }                        \
  }

#define UNIT(name, expr...)                                                            \
  {                                                                                    \
    char unitname[] = name;                                                            \
    int unitfailed = 0;                                                                \
    expr;                                                                              \
    if (unitfailed) {                                                                  \
      std::cout << "\033[31m[FAILED] " << testname << ": " << unitname << "\033[0m\n"; \
      failed++;                                                                        \
    } else {                                                                           \
      std::cout << "\033[32m[PASSED] " << testname << ": " << unitname << "\033[0m\n"; \
    }                                                                                  \
  }

#define ASSERT(A, B) \
  if (A != B) {      \
    unitfailed++;    \
  }

#endif  // SEM3_OOP_CPP_UTILS_H
