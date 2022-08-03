#include <iostream>

#include "list.h"

using namespace std;

int main() {
  // Creating a new list
  List nums = {3, 8, 1, 4, 2};  // int nums[] = { ... };
  // List<10> nums = {0, 8, 1, 4, 2}; // int nums[N] = { ... };
  nums.display();

  // Inserting a new item
  int n;
  cout << "Enter a number to insert: ";
  cin >> n;
  nums.insert(n);
  nums.display();

  // Sorting the list
  cout << "Sorting the list..." << endl;
  nums.sort();
  nums.display();

  // Linear Search
  int search;
  cout << "Enter a number to search: ";
  cin >> search;
  cout << "'" << search << "' is at index " << nums.lsearch(search) << endl;

  // Binary Search
  cout << "Enter a number to search: ";
  cin >> search;
  cout << "'" << search << "' is at index " << nums.bsearch(search) << endl;

  // Getting element at index
  int index;
  cout << "Enter a index: ";
  cin >> index;
  cout << "\nnums[" << n << "] => " << nums.at(n);

  return 0;
}
