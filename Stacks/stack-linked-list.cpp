#include <iostream>
using namespace std;

struct node {
      int data;
      struct node *stk;
} *top = NULL, *ptr, *temp;

void push(int data);
void pop(void);
void ifEmpty(void);
void printStack(void);
void destroyStack(void);

int main(int argc, char const *argv[]) {
      // This program implements operations on Stacks using linked lists

      int size, value, choice;

      cout << "Enter the size of the stack : " << endl;
      cin >> size;

      cout << "Enter 1 to fill " << size << " elements in the stack : " << endl;
      cin >> choice;

      while (choice != 0) {
            switch (choice) {
                  case 1:
                        cout << "Enter the elements..." << endl;
                        for(int i = 0; i < size; i++) {
                              cin >> value;
                              push(value);
                        }
                        break;
                  case 2:
                        cout << "Enter the element..." << endl;
                        cin >> value;
                        push(value);
                        break;
                  case 3:
                        cout << "Removing an element form the stack..." << endl;
                        pop();
                        break;
                  case 4:
                        cout << "-----------------------------------" << endl;
                        printStack();
                        cout << "-----------------------------------" << endl;
                        break;
                  default:
                        cout << "Invalid choice..." << endl;
                        break;
            }
            cout << "Enter a selection to continue..." << endl;
            cout << "Enter 2 to insert a new element in the stack..." << endl;
            cout << "Enter 3 to remove an element from the stack..." << endl;
            cout << "Enter 4 to display the stack..." << endl;
            cout << "Enter 0 to quit" << endl;
            cin >> choice;
      }

      destroyStack();

      cout << endl;
      return 0;
}

void push(int data) {
      if(top == NULL) {
            top = new struct node;
            top->stk = NULL;
            top->data = data;
      }
      else {
            temp = new struct node;
            temp->stk = top;
            temp->data = data;
            top = temp;
      }
}

void pop(void) {
      ptr = top;

      if(ptr == NULL) {
            cout << "Error, Empty Stack !" << endl;
            return;
      }
      else {
            ptr = ptr->stk;
      }

      free(top);
      top = ptr;
}

void ifEmpty(void) {
      if(top == NULL) {
            cout << "Stack is empty..." << endl;
      }
      else {
            cout << "Stack isn't empty..." << endl;
      }
}

void printStack(void) {
      ptr = top;

      if(ptr == NULL) {
            cout << "Stack is empty..." << endl;
            return;
      }

      while(ptr != NULL) {
            cout << ptr->data << " ";
            ptr = ptr->stk;
      }
      cout << endl;
}

void destroyStack(void) {
      ptr = top;

      while(ptr != NULL) {
            ptr = top->stk;
            free(top);
            top = ptr;
            ptr = ptr->stk;
      }
      free(ptr);
      top = NULL;

      cout << "Stack destroyed..!" << endl;
}
