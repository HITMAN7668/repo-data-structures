#include <iostream>
using namespace std;

struct node {
      int key;
      int data;
};

class Hashing {
public:
      int size;
      struct node *item = NULL, *temp = NULL, *hashArray[];

      Hashing(int num) {
            this->size = num;
            hashArray[size];
      }

      int sizeOfHashTable(void) {
            return this->size;
      }

      int hashCode(int key) {
            return (key % size);
      }

      struct node *search(int key) {
            int index = hashCode(key);

            while(hashArray[index] != NULL) {
                  if(hashArray[index]->key == key) {
                        return hashArray[index];
                  }
                  ++index;
                  index %= size;
            }

            return NULL;
      }

      void displayHashTable(void) {
            for(int i = 0; i < size; i++) {
                  if(hashArray[i] != NULL)
                        cout << hashArray[i]->key << " | " << hashArray[i]->data << endl;
                  else
                        cout << " ~~ " << endl;
            }
      }

      void insert(int key, int data) {
            struct node *item = new struct node;
            item->key = key;
            item->data = data;

            int index = hashCode(key);

            while(hashArray[index] != NULL && hashArray[index]->key != -1) {
                  ++index;
                  index %= size;
            }

            hashArray[index] = item;
      }

      void remove(struct node *ptr) {
            int key = ptr->key;

            int index = hashCode(key);

            while(hashArray[index] != NULL) {
                  if(hashArray[index]->key == key) {
                        struct node *cell = hashArray[index];
                        hashArray[index] = temp;
                  }
                  ++index;
                  index %= size;
            }
      }
};

int main(int argc, char const *argv[]) {
      int key, size, value;
      cout << "Choose the size of the hash table : " << endl;
      cin >> size;

      Hashing hash(size);

      hash.temp = new struct node;
      hash.temp->key = -1;
      hash.temp->data = -1;

      cout << "Enter (key | value) pairs for the hash table : " << endl;
      for(int i = 0; i < (size - 1); i++) {
            cin >> key;
            cout << "-----";
            cin >> value;
            hash.insert(key, value);
      }

      cout << "Enter a key to be deleted : ";
      cin >> key;

      hash.item = hash.search(key);
      hash.remove(hash.item);

      cout << endl;
      cout << "Size of hash table -> " << hash.sizeOfHashTable() << endl;
      cout << "-----------" << endl;
      hash.displayHashTable();
      cout << "-----------" << endl;

      return 0;
}
