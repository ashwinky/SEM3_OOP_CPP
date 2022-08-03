#ifndef SEM3_OOP_CPP_LIST_H
#define SEM3_OOP_CPP_LIST_H

#include <iostream>

// Custom array type to make operations easy
template <int N>
struct List {
  // Array of N integers
  int items[N]{};

  // Size of the array

  bool isSorted = false;

  // find the index of last element +1
  int findTop() {
    int last = N;
    for (int i = N - 1; i >= 0; --i) {
      if (items[i] == 0) {
        last = i;
      } else {
        break;
      }
    }
    return last;
  };

  // Track the index of last non-empty element,
  // so we can exclude the rest of the array from operations
  int top = findTop();

  // length of the array
  const int length = N;

  // Linear Search for `item` in the list
  int lsearch(int item) {
    for (int i = 0; i < top; ++i) {
      if (item == items[i]) return i;
    }
    return -1;
  }

  // Binary Search for item in the list
  int bsearch(int item) {
    int low = 0;         // set the lowest point
    int high = top - 1;  // set the highest point

    while (low <= high) {                // loop until `low` and `high` converge at `mid`
      int mid = low + (high - low) / 2;  // set the mid-point index

      if (item == items[mid]) {  // if item is equal to mid-element
        return mid;
      } else if (item < items[mid]) {  // if item is lesser than mid-element
        high = mid - 1;
      } else {  // if item is greater than mid-element
        low = mid + 1;
      }
    }
    // if element not found in list, return `-1`
    return -1;
  }

  // Sort the list
  void sort() {
    for (int i = 0; i < top; i++) {
      int min = i;
      for (int j = i + 1; j < top; j++) {
        // check whether any element less than current min value
        if (items[j] < items[min]) {
          min = j;  // update index accordingly
        }
      }
      // swap min value and element at the ith index
      std::swap(items[min], items[i]);
    }

    isSorted = true;
  }

  // Insert `item` at correct position
  void insert(int item) {
    // overflow check
    if (top == N) {
      std::cout << "\nError: Cannot add '" << item << "'. The list is full";
      return;
    }

    if (!isSorted) {      // if list is not sorted
      items[top] = item;  // Insert at the end
      top++;              // increment top
    } else {              // otherwise place it to correct position
      int pos = 0;
      // Going through each element and find correct position for element
      for (int i = 0; i < top - 1; i++) {
        if (items[i] <= item && item <= items[i + 1]) {  // if `item` is between `items[i]` and
          // `items[i+1]`
          pos = i + 1;  // set index to `i + 1`
          break;        // break from the loop
        }
      }

      // if all elements are smaller than the element
      if (pos == 0) {
        pos = top;  // insert at the end
      }

      // shift all element to make room for new element
      for (int i = top; i > pos; i--) {
        items[i] = items[i - 1];
      }

      top++;              // Increment the value of top.
      items[pos] = item;  // Assign the value to the correct index in the array
    }
  }

  int at(int index) {
    // Handle +ve overflow
    while (index >= top) {
      index = index - top;
    }

    // Handle -ve overflow
    while (index < 0) {
      index = index + top;
    }

    return items[index];
  }

  // output all the items in list
  void display() {
    // Print type and size of list
    std::cout << "\nList[" << N << "] { ";

    // Going through each non-empty element in the list
    for (int i = 0; i < top; i++) {
      if (i >= 10) {                                 // if there are too many elements
        std::cout << "... " << top - i << " more ";  // truncate the list items
        break;
      }
      std::cout << items[i] << " ";  // Print the element
    }
    std::cout << "}";

    // if there are any empty elements
    if (top != N) {
      // Print the number of empty elements
      std::cout << " (" << N - top << " empty)";
    }
  }
};

template <typename... N>
List(N...) -> List<sizeof...(N)>;

#endif  // SEM3_OOP_CPP_LIST_H
