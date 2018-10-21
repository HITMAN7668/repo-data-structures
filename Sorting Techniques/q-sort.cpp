#include <iostream>
#include <stdlib.h>
using namespace std;

int compare(const void *a, const void *b) {
      return (*(int*)a - *(int*)b);
}

int main(int argc, char const *argv[]) {
      int size;
      cout << "Enter the size of the array: ";
      cin >> size;

      int arr[size];
      cout << "Fill the array: " << endl;
      for(int i = 0; i < size; i++) {
            cin >> arr[i];
      }

      cout << "Sorting the array" << endl;

      cout << "Sorted..." << endl;
      qsort(arr, size, sizeof(int), compare);
      cout << "Sorted array -----" << endl;
      for(int i = 0; i < size; i++) {
            cout << arr[i] << " ";
      }

      cout << endl;
      return 0;
}
