#include "list.h"

#include "utils.h"

TEST("list", {
  UNIT("empty list", {
    List<5> list;

    ASSERT(list.top, 0);
    ASSERT(list.length, 5);
  });

  UNIT("list with 5 element", {
    List list = {1, 2, 3, 4, 5};
    ASSERT(list.top, 5);
    ASSERT(list.length, 5);
  });

  UNIT("linear search", {
    List list = {1, 2, 3, 4, 5};

    ASSERT(list.lsearch(1), 0);
    ASSERT(list.lsearch(3), 2);
    ASSERT(list.lsearch(5), 4);
    ASSERT(list.lsearch(6), -1);
  })

  UNIT("binary search", {
    List list = {1, 2, 3, 4, 5};

    ASSERT(list.bsearch(1), 0);
    ASSERT(list.bsearch(3), 2);
    ASSERT(list.bsearch(5), 4);
    ASSERT(list.bsearch(6), -1);
  })

  UNIT("sort", {
    List list = {5, 4, 3, 2, 1};

    list.sort();

    ASSERT(list.isSorted, true);

    ASSERT(list.top, 5);

    for (int i = 0; i < list.top; i++) {
      ASSERT(list.items[i], i + 1);
    }
  })

  UNIT("insert", {
    List<6> list = {0, 1, 2, 4, 5};
    list.sort();

    ASSERT(list.top, 5);
    ASSERT(list.length, 6);

    list.insert(3);

    ASSERT(list.top, 6);

    for (int i = 0; i < list.top; i++) {
      ASSERT(list.items[i], i);
    }
  })

  UNIT("insert (smallest element)", {
    List<6> list = {1, 2, 3, 4, 5};
    list.sort();

    ASSERT(list.top, 5);
    ASSERT(list.length, 6);

    list.insert(0);

    ASSERT(list.top, 6);

    for (int i = 0; i < list.top; i++) {
      ASSERT(list.items[i], i);
    }
  })

  UNIT("insert (largest element)", {
    List<6> list = {1, 2, 3, 4, 5};
    list.sort();

    ASSERT(list.top, 5);
    ASSERT(list.length, 6);

    list.insert(6);

    ASSERT(list.top, 6);

    for (int i = 0; i < list.top; i++) {
      ASSERT(list.items[i], i + 1);
    }
  })
})