#include <iostream>
using namespace std;

struct node {
      int data;
      struct node *next;
      struct node *prev;
};

class DoublyLinkedList {
public:
      int size;
      struct node *head;
      struct node *last;

      DoublyLinkedList(int num) {
            cout << "--------------------------------" << endl;
            cout << "Initialising List..." << endl;
            this->size = num;
            this->head = NULL;
            cout << "Doubly-Linked list initialised" << endl;
            cout << "--------------------------------" << endl;
      }

      void insertElements(struct node **head, int data) {
            cout << "--------------------------------" << endl;
            struct node *newNode = new struct node;

            newNode->data = data;
            newNode->next = (*head);
            newNode->prev = NULL;

            if((*head) != NULL) {
                  (*head)->prev = newNode;
            }

            (*head) = newNode;
            this->last = newNode;
            cout << "--------------------------------" << endl;
      }

      void insertElementAfter(struct node *previous, int position, int value) {
            cout << "--------------------------------" << endl;
            if(previous == NULL) {
                  cout << "Operation can't be performed..." << endl;
                  return;
            }

            struct node *temp = new struct node;

            for(int i = 0; i < (position + 1); i++) {
                  if(temp != NULL && temp->next != NULL) {
                        temp = temp->next;
                  }
            }

            temp->data = value;
            temp->next = previous->next;
            previous->next = temp;
            temp->prev = previous;

            if(temp->next != NULL) {
                  temp->next->prev = temp;
            }
            cout << "--------------------------------" << endl;
      }

      void insertAtBeginning(struct node **head, int data) {
            cout << "--------------------------------" << endl;
            struct node *newNode = new struct node;

            newNode->data = data;
            newNode->next = (*head);
            newNode->prev = NULL;

            if((*head) != NULL) {
                  (*head)->prev = newNode;
            }

            (*head) = newNode;
            cout << "--------------------------------" << endl;
      }

      void insertAtEnd(struct node **head, int data) {
            cout << "--------------------------------" << endl;
            struct node *temp = new struct node;
            struct node *last = (*head);

            temp->data = data;
            temp->next = NULL;

            if((*head) == NULL) {
                  temp->prev = NULL;
                  (*head) = temp;
                  return;
            }

            while(last->next != NULL) {
                  last = last->next;
            }

            last->next = temp;
            temp->prev = last;

            return;
            cout << "--------------------------------" << endl;
      }

      void deleteAnElement(struct node **head, int data) {
            cout << "--------------------------------" << endl;
            struct node *temp = (*head);
            struct node *ptr;

            for(int i = 0; i < data && temp != NULL; i++) {
                  temp = temp->next;
            }

            if(data == 1) {
                  if((*head) == NULL) {
                        cout << "Operation can't be performed..." << endl;
                  }
                  else {
                        ptr = (*head);
                        (*head) = (*head)->next;

                        if((*head) != NULL) {
                              (*head)->prev = NULL;
                        }

                        free(ptr);
                  }
            }
            else if(temp != NULL) {
                  temp->prev->next = temp->next;
                  temp->next->prev = temp->prev;

                  free(temp);
            }
            else if(data == last->data) {
                  if(last == NULL) {
                        cout << "Operation can't be performed..." << endl;
                  }
                  else {
                        ptr = last;
                        last = last->prev;

                        if(last != NULL) {
                              last->next = NULL;
                        }

                        free(ptr);
                  }
            }
            else {
                  cout << "Operation can't be performed..." << endl;
            }
            cout << "--------------------------------" << endl;
      }

      void searchElement(struct node *head, int data) {
            cout << "--------------------------------" << endl;
            bool flag = false;
            struct node *temp = head;

            if(temp == NULL) {
                  cout << "Operation can't be performed..." << endl;
            }

            while(temp != NULL) {
                  if(temp->data == data) {
                        cout << "Element found" << endl;
                        flag = true;
                        break;
                  }

                  temp = temp->next;
            }

            if(flag = false) {
                  cout << "Element wasn't found" << endl;
            }
            cout << "--------------------------------" << endl;
      }

      void printList(struct node *head) {
            cout << "--------------------------------" << endl;
            struct node *last;

            while(head != NULL) {
                  cout << head->data << " ";
                  last = head;
                  head = head->next;
            }

            cout << "\n--------------------------------" << endl;
      }

      void deleteList(struct node **head, struct node *ptr) {
            cout << "--------------------------------" << endl;
            if((*head) == NULL || ptr == NULL) {
                  return;
            }

            if((*head) == ptr) {
                  (*head) = ptr->next;
            }

            if(ptr->next != NULL) {
                  ptr->next->prev = ptr->prev;
            }

            if(ptr->prev != NULL) {
                  ptr->prev->next = ptr->next;
            }

            free(ptr);
            return;
            cout << "--------------------------------" << endl;
      }
};

int main(int argc, char const *argv[]) {
      cout << "--------------------------------" << endl;
      // This Program function implements all the operations on the Doubly Linked List Class;
      int size, value, choice, position;

      cout << "Enter the size of the doubly-linked list: ";
      cin >> size;

      DoublyLinkedList dList(size);

      cout << "Enter 1 to fill " << size << " elements in the doubly-linked list." << endl;
      cin >> choice;

      while(choice != 0) {
            switch (choice) {
                  case 1:
                        cout << "Inserting elements" << endl;
                        cout << "Enter the elements: " << endl;
                        for(int i = 0; i < size; i++) {
                              cin >> value;
                              dList.insertElements(&dList.head, value);
                        }
                        break;
                  case 2:
                        cout << "Insertion at specified position" << endl;
                        cout << "Enter a position: ";
                        cin >> position;
                        cout << "Enter a value: ";
                        cin >> value;
                        dList.insertElementAfter(dList.head, position, value);
                        break;
                  case 3:
                        cout << "Insertion of element" << endl;
                        cout << "Enter a value: ";
                        cin >> value;
                        dList.insertAtEnd(&dList.head, value);
                        break;
                  case 4:
                        cout << "Insertion of element" << endl;
                        cout << "Enter a value: ";
                        cin >> value;
                        dList.insertAtBeginning(&dList.head, value);
                        break;
                  case 5:
                        cout << "Deleting..." << endl;
                        cout << "Enter a position: ";
                        cin >> position;
                        dList.deleteAnElement(&dList.head, position);
                        break;
                  case 6:
                        cout << "Performing Search \n Enter a value: " << endl;
                        cin >> value;
                        dList.searchElement(dList.head, value);
                        break;
                  case 7:
                        cout << endl;
                        dList.printList(dList.head);
                        break;
                  case 8:
                        cout << "------------------------->" << endl;
                        for(int i = 0; i < size; i++) {
                              dList.deleteList(&dList.head, dList.head);
                        }
                        break;
                  default:
                        cout << "Enter a valid value..." << endl;
                        break;
            }

            cout << "Enter a selection to continue" << endl;
            cout << "Enter 2 to insert a new element after an element." << endl;
            cout << "Enter 3 to insert a new element at the end."  << endl;
            cout << "Enter 4 to insert a new element at the beginning." << endl;
            cout << "Enter 5 to delete an element with a provided value." << endl;
            cout << "Enter 6 to search for an element" << endl;
            cout << "Enter 7 to display the doubly-linked list." << endl;
            cout << "Enter 8 to clear the whole doubly-linked list" << endl;
            cout << "Enter 0 to quit" << endl;
            cin >> choice;
      }

      cout << "--------------------------------" << endl;
      return 0;
}
