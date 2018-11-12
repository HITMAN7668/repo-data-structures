#include <iostream>
using namespace std;

class Stack {
      int top, size;
public:
      int array[];
      Stack(int size) {
            this->size = size;
            top = -1;
            array[size];
      }

      void push(int data) {
            if(top >= (size - 1)) {
                  cout << "Stack Overflow" << endl;
                  return;
            }
            else {
                  array[++top] = data;
                  return;
            }
      }

      int pop(void) {
            if(isEmpty()) {
                  cout << "Stack Underflow" << endl;
                  return 0;
            }
            else {
                  int num = array[top--];
                  size--;
                  return num;
            }
      }

      void printStack(void) {
            for(int i = 0; i < size; i++) {
                  cout << array[i] << " ";
            }
            cout << endl;
      }

      bool isEmpty(void) {
            return (top < 0);
      }
};

int main(int argc, char const *argv[]) {
      // This program implements operations on Stack class using arrays

      int  num, size, value, choice;

      cout << "Enter the size of the stack : " << endl;
      cin >> size;

      Stack stk(size);

      cout << "Enter 1 to enter " << size << " elements in the stack..." << endl;
      cin >> choice;

      while (choice != 0) {
            switch (choice) {
                  case 1:
                        cout << "Enter the elements : " << endl;
                        for(int i = 0; i < size; i++) {
                              cin >> value;
                              stk.push(value);
                        }
                        break;
                  case 2:
                        cout << "Removing an element... " << endl;
                        num = stk.pop();
                        cout << num << " has been removed..." << endl;
                        break;
                  case 3:
                        cout << "-----------------------" << endl;
                        stk.printStack();
                        cout << "-----------------------" << endl;
                        break;
                  default:
                        cout << "Invalid input..." << endl;
                        break;
            }

            cout << "Enter a selection to continue..." << endl;
            cout << "Enter 2 to remove an element from the stack" << endl;
            cout << "Enter 3 to view the stack..." << endl;
            cout << "Enter 0 to quit." << endl;
            cin >> choice;
      }

      cout << endl;
      return 0;
}
