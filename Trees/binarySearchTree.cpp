#include <iostream>
using namespace std;

struct node {
      int data;
      struct node *left;
      struct node *right;
};

class Tree {
    public:
      struct node *root;
      struct node *newNode;

      Tree() {
            cout << "Initializing the tree..." << endl;
            root = NULL;
            cout << "Initialized..." << endl;
      }

      struct node *createNode(int data) {
            newNode = new struct node;

            this->newNode->data = data;
            this->newNode->left = NULL;
            this->newNode->right = NULL;

            return (newNode);
      }

      struct node *insertElement(struct node *root, int data) {
            if (root == NULL) {
                  return createNode(data);
            }
            else {
                  if (data <= root->data) {
                        root->left = insertElement(root->left, data);
                  }
                  else {
                        root->right = insertElement(root->right, data);
                  }
            }

            return root;
      }

      void printPreOrder(struct node *root) {
            if (root) {
                  cout << root->data << " ";
                  printPreOrder(root->left);
                  printPreOrder(root->right);
            }
      }

      void printInOrder(struct node *root) {
            if (root) {
                  printInOrder(root->left);
                  cout << root->data << " ";
                  printInOrder(root->right);
            }
      }

      void printPostOrder(struct node *root) {
            if (root) {
                  printPostOrder(root->left);
                  printPostOrder(root->right);
                  cout << root->data << " ";
            }
      }

      struct node *minValueNode(struct node *root) {
            struct node *temp = root;

            while (temp->left != NULL) {
                  temp = temp->left;
            }

            return temp;
      }

      struct node *largestValueNode(struct node *root) {
            struct node *temp = root;

            while (temp->right != NULL) {
                  temp = temp->right;
            }

            return temp;
      }

      struct node *deleteElement(struct node *root, int data) {
            if (root == NULL) {
                  return root;
            }

            if (data < root->data) {
                  root->left = deleteElement(root->left, data);
            }
            else if (data > root->data) {
                  root->right = deleteElement(root->right, data);
            }
            else {
                  if (root->left == NULL) {
                        struct node *temp = root->right;
                        free(root);
                        return temp;
                  }
                  else if (root->right == NULL) {
                        struct node *temp = root->left;
                        free(root);
                        return temp;
                  }

                  struct node *temp = minValueNode(root->right);
                  root->data = temp->data;
                  root->right = deleteElement(root->right, temp->data);
            }

            return root;
      }

      struct node *deleteBinaryTree(struct node *root) {
            if (root == NULL) {
                  return root;
            }

            deleteBinaryTree(root->left);
            deleteBinaryTree(root->right);
            free(root);

            return 0;
      }

      struct node* search(struct node* root, int data) {
            if (root == NULL || root->data == data)  {
                  return root;
            }

            if (root->data < data) {
                  return search(root->right, data);
            }

            return search(root->left, data);
      }

      int treeHeight(struct node *root) {
            int leftHeight = 0;
            int rightHeight = 0;

            if (root == NULL) {
                  return 0;
            }

            leftHeight = treeHeight(root->left);
            rightHeight = treeHeight(root->right);

            if (leftHeight > rightHeight) {
                  return (int)(leftHeight + 1);
            }
            else {
                  return (int)(rightHeight + 1);
            }
      }

      int countTotalNodes(struct node *root) {
            if (root == NULL) {
                  return 0;
            }
            else {
                  int count = countTotalNodes(root->left) + countTotalNodes(root->right) + 1;
                  return count;
            }
      }

      int countInternalNodes(struct node *root) {
            if (root == NULL || (root->left == NULL && root->right == NULL)) {
                  return 0;
            }

            return 1 + countInternalNodes(root->left) + countInternalNodes(root->right);
      }

      void mirrorImage(struct node *root) {
            if (root == NULL) {
                  return;
            }
            else {
                  struct node *temp;

                  mirrorImage(root->left);
                  mirrorImage(root->right);

                  temp = root->left;
                  root->left = root->right;
                  root->right = temp;
            }
      }
};

int main(int argc, char const *argv[]) {
      cout << "-----------------------------------" << endl;
      // This Program function implements all the operations on a Binary Search Tree;
      int size, value, choice;
      Tree tree;
      char ch;

      cout << "Enter the number of elements you would like to enter in the tree : ";
      cin >> size;

      cout << "Enter 1 to fill " << size << " elements in the Binary Search Tree." << endl;
      cin >> choice;

      while(choice != 0) {
            switch (choice) {
                  case 1:
                        cout << "-----------------------------------" << endl;
                        cout << "Enter the tree elements : " << endl;
                        for (int i = 0; i < size; i++) {
                              cin >> value;
                              tree.root = tree.insertElement(tree.root, value);
                        }
                        break;
                  case 2:
                        cout << "-----------------------------------" << endl;
                        cout << "Display the tree according to format: " << endl;
                        cout << "For Pre-Order enter 'a' " << endl;
                        cout << "For In-Order enter 'b' " << endl;
                        cout << "For Post-Order enter 'c' " << endl;
                        cout << "Enter 'e' to exit. : ";
                        cin >> ch;
                        switch (ch) {
                              case 'a':
                                    cout << "-----------------------------------" << endl;
                                    cout << "Pre-Order Approach >" << endl;
                                    tree.printPreOrder(tree.root);
                                    cout << "\n-----------------------------------" << endl;
                                    break;
                              case 'b':
                                    cout << "-----------------------------------" << endl;
                                    cout << "In-Order Approach >" << endl;
                                    tree.printInOrder(tree.root);
                                    cout << "\n-----------------------------------" << endl;
                                    break;
                              case 'c':
                                    cout << "-----------------------------------" << endl;
                                    cout << "Post-Order Approach >" << endl;
                                    tree.printPostOrder(tree.root);
                                    cout << "\n-----------------------------------" << endl;
                                    break;
                              default:
                                    cout << "Choose a valid input..." << endl;
                                    break;
                        }
                        break;
                  case 3:
                        cout << "-----------------------------------" << endl;
                        cout << "Insertion of element" << endl;
                        cout << "Enter a value: ";
                        cin >> value;
                        tree.root = tree.insertElement(tree.root, value);
                        break;
                  case 4:
                        cout << "-----------------------------------" << endl;
                        cout << "Deleting..." << endl;
                        while (choice != false) {
                              cout << "Enter the tree element you'd like to remove : ";
                              cin >> value;

                              tree.root = tree.deleteElement(tree.root, value);
                              cout << endl;

                              cout << "Current Tree : " << endl;
                              tree.printInOrder(tree.root);
                              cout << endl;

                              cout << "Do you want to delete another ? : ";
                              cin >> ch;
                              if (ch == 'n' || ch == 'N') {
                                    choice = false;
                              }
                              else if (ch == 'y' || ch == 'Y') {
                                    choice = true;
                              }
                              else {
                                    cout << "Enter a valid option" << endl;
                                    break;
                              }
                        }
                        break;
                  case 5:
                        cout << "-----------------------------------" << endl;
                        cout << "Searching..." << endl;
                        cout << "Enter a value to be searched: " << endl;
                        cin >> value;
                        tree.root = tree.search(tree.root, value);
                        break;
                  case 6:
                        cout << "-----------------------------------" << endl;
                        cout << "Other details of the present tree: " << endl;

                        cout << "Height of tree : " << tree.treeHeight(tree.root) << endl;
                        cout << "Minimum element value in the tree : " << tree.minValueNode(tree.root)->data << endl;
                        cout << "Maximum element value in the tree : " << tree.largestValueNode(tree.root)->data << endl;
                        cout << "Total Nodes in the Tree : " << tree.countTotalNodes(tree.root) << endl;
                        cout << "Total Internal Nodes : " << tree.countInternalNodes(tree.root) << endl;
                        cout << "Total Leaf nodes : " << (tree.countTotalNodes(tree.root) - tree.countInternalNodes(tree.root)) << endl;

                        break;
                  case 7:
                        cout << "-----------------------------------" << endl;
                        tree.mirrorImage(tree.root);
                        cout << "Mirror Tree of the present tree has been generated >" << endl;
                        tree.printInOrder(tree.root);
                        break;
                  case 8:
                        cout << "-----------------------------------" << endl;
                        tree.deleteBinaryTree(tree.root);
                        break;
                  default:
                        cout << "Enter a valid value..." << endl;
                        break;
            }

            cout << "Enter a selection to continue" << endl;
            cout << "Enter 2 to traverse the tree." << endl;
            cout << "Enter 3 to insert a new element."  << endl;
            cout << "Enter 4 to delete an element with a provided value." << endl;
            cout << "Enter 5 to search for an element" << endl;
            cout << "Enter 6 to display the other details of the tree." << endl;
            cout << "Enter 7 to generate the mirror tree of the current tree." << endl;
            cout << "Enter 8 to delete the binary search tree." << endl;
            cout << "Enter 0 to quit" << endl;
            cin >> choice;
      }

      cout << "-----------------------------------" << endl;
      return 0;
}
