#include <iostream>
using namespace std;

class Arrays {
public:
      int size, value, position;
      int array[];

      Arrays(int num) {
            cout << "------------------------------------------------------------------------" << endl;
            cout << "Initialising the array..." << endl;
            initialise(num);
            cout << "Initialised..." << endl;
            cout << "------------------------------------------------------------------------" << endl;
      }

      void initialise(int num) {
            size = num;
            array[size];
      }

      void insertElements() {
            cout << "------------------------------------------------------------------------" << endl;
            for(int i = 0; i < size; i++) {
                  cin >> array[i];
            }
            cout << "------------------------------------------------------------------------" << endl;
      }

      void insertElementAtIndex() {
            cout << "------------------------------------------------------------------------" << endl;
            cout << "Enter the position at which you'd like to insert the element: ";
            cin >> position;
            cout << "Enter the value of the element: ";
            cin >> value;

            for(int i = (size - 1); i >= (position - 1); i--) {
                  array[i + 1] = array[i];
            }

            array[position - 1] =  value;
            cout << "------------------------------------------------------------------------" << endl;
      }

      void deleteAnElementWithValue() {
            cout << "------------------------------------------------------------------------" << endl;
            cout << "Enter value of element: ";
            cin >> value;

             position = findElement(value);

            if(position == -1) {
                  cout << "Element not found..." << endl;
            }

            for(int i = position; i < (size - 1); i++) {
                  array[i] = array[i + 1];
            }

            size -= 1;
            cout << "------------------------------------------------------------------------" << endl;
      }

      int findElement(int num) {
            cout << "------------------------------------------------------------------------" << endl;
            for(int i = 0; i < size; i++) {
                  if(array[i] == num) {
                        return i;
                  }
            }

            return -1;
            cout << "------------------------------------------------------------------------" << endl;
      }

      void deleteAnElementWithIndex() {
            cout << "------------------------------------------------------------------------" << endl;
            cout << "Enter the index to be deleted: ";
            cin >> position;

            for(int i = (position - 1); i < size; i++) {
                  array[i] == array[i + 1];
            }

            size -= 1;
            cout << "------------------------------------------------------------------------" << endl;
      }

      void linearSearch() {
            cout << "------------------------------------------------------------------------" << endl;
            int flag = 0;
            cout << "Enter the value to be searched: ";
            cin >> value;

            for(int i = 0; i < size; i++) {
                  if(array[i] == value) {
                        cout << "Element was found at " << i << endl;
                        flag = 1;
                  }
            }
            if(flag == 0) {
                  cout << "Element wasn't found" << endl;
            }
            cout << "------------------------------------------------------------------------" << endl;
      }

      void binarySearch(int low, int high, int element) {
            int flag = 0;
            cout << "------------------------------------------------------------------------" << endl;
            while(low <= high) {
                  int mid = low + ((high - low) / 2);

                  if(array[mid] == element) {
                        cout << "Element found at " << mid << endl;
                        flag = 1;
                  }

                  if(array[mid] < element) {
                        low = mid + 1;
                  }
                  else {
                        high = mid - 1;
                  }
            }
            if(flag == 0) {
                  cout << "Element wasn't found." << endl;
            }
            cout << "------------------------------------------------------------------------" << endl;
      }

      void bubbleSort() {
            cout << "------------------------------------------------------------------------" << endl;
            for(int i = 0; i < size - 1; i++) {
                  for(int j = 0; j < (size - i - 1); j++) {
                        if(array[j] > array[j + 1]) {
                              swap(&array[j], &array[j + 1]);
                        }
                  }
            }
            cout << "------------------------------------------------------------------------" << endl;
      }

      void printArray() {
            cout << "------------------------------------------------------------------------" << endl;
            for(int i = 0; i < size; i++) {
                  cout << array[i] << " ";
            }
            cout << endl;
            cout << "------------------------------------------------------------------------" << endl;
      }

      void clearArray() {
            cout << "------------------------------------------------------------------------" << endl;
            for(int i = 0; i < size; i++) {
                  array[i] = '\0';
            }
            cout << "------------------------------------------------------------------------" << endl;
      }

      void swap(int *a, int *b) {
            int temp = *a;
            *a = *b;
            *b = temp;
      }
};

int main(int argc, char const *argv[]) {
      cout << "------------------------------------------------------------------------" << endl;
      // This Program function implements all the operations on the Array Class;
      int size, value, choice, position;
      cout << "Enter the size for the array: ";
      cin >> size;

      Arrays arr(size);

      cout << "Enter 1 to fill " << size << " elements in the array." << endl;
      cin >> choice;

      while(choice != 0) {
            switch (choice) {
                  case 1:
                        cout << "Inserting array elements" << endl;
                        arr.insertElements();
                        break;
                  case 2:
                        cout << "Insertion at specified position" << endl;
                        arr.insertElementAtIndex();
                        break;
                  case 3:
                        cout << "Deletion of element" << endl;
                        arr.deleteAnElementWithValue();
                        break;
                  case 4:
                        cout << "Deletion of element" << endl;
                        arr.deleteAnElementWithIndex();
                        break;
                  case 5:
                        cout << "Performing Linear Search" << endl;
                        arr.linearSearch();
                        break;
                  case 6:
                        cout << "Performing Binary Search \n------------------------------------------------------------------------" << endl;
                        cout << "Enter the value: ";
                        cin >> value;
                        arr.binarySearch(0, (arr.size - 1), value);
                        break;
                  case 7:
                        cout << "Performing Bubble Sort" << endl;
                        arr.bubbleSort();
                        break;
                  case 8:
                        cout << "------------------------->" << endl;
                        arr.printArray();
                        break;
                  case 9:
                        cout << "Clearing all elements in the array" << endl;
                        arr.clearArray();
                        break;
                  default:
                        cout << "Enter a valid value..." << endl;
                        break;
            }

            cout << "Enter a selection to continue" << endl;
            cout << "Enter 2 to insert a new element at a specified position." << endl;
            cout << "Enter 3 to delete an element with a provided value." << endl;
            cout << "Enter 4 to delete an element with a provided position/index." << endl;
            cout << "Enter 5 to find the location of an element by Linear Search" << endl;
            cout << "Enter 6 to find the location of an element by Binary Search" << endl;
            cout << "Enter 7 to perform a Bubbble sort on the array." << endl;
            cout << "Enter 8 to display the array." << endl;
            cout << "Enter 9 to clear the whole array" << endl;
            cout << "Enter 0 to quit." << endl;
            cin >> choice;
      }

      cout << "------------------------------------------------------------------------" << endl;
      return 0;
}
