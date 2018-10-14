#include <iostream>
using namespace std;

struct node
{
      int data;
      struct node *left;
      struct node *right;
};

class Tree
{
    public:
      struct node *root;
      struct node *newNode;

      Tree()
      {
            cout << "Initializing the tree..." << endl;
            initialize();
            cout << "Initialized..." << endl;
      }

      void initialize()
      {
            root = NULL;
      }

      struct node *createNode(int data)
      {
            newNode = new struct node;

            this->newNode->data = data;
            this->newNode->left = NULL;
            this->newNode->right = NULL;

            return (newNode);
      }

      struct node *insertElement(struct node *root, int data)
      {
            if (root == NULL)
            {
                  return createNode(data);
            }
            else
            {
                  if (data <= root->data)
                  {
                        root->left = insertElement(root->left, data);
                  }
                  else
                  {
                        root->right = insertElement(root->right, data);
                  }
            }

            return root;
      }

      void printPreOrder(struct node *root)
      {
            if (root)
            {
                  cout << root->data << " ";
                  printPreOrder(root->left);
                  printPreOrder(root->right);
            }
      }

      void printInOrder(struct node *root)
      {
            if (root)
            {
                  printInOrder(root->left);
                  cout << root->data << " ";
                  printInOrder(root->right);
            }
      }

      void printPostOrder(struct node *root)
      {
            if (root)
            {
                  printPostOrder(root->left);
                  printPostOrder(root->right);
                  cout << root->data << " ";
            }
      }

      struct node *minValueNode(struct node *root)
      {
            struct node *temp = root;

            while (temp->left != NULL)
            {
                  temp = temp->left;
            }

            return temp;
      }

      struct node *largestValueNode(struct node *root)
      {
            struct node *temp = root;

            while (temp->right != NULL)
            {
                  temp = temp->right;
            }

            return temp;
      }

      struct node *deleteElement(struct node *root, int data)
      {
            if (root == NULL)
            {
                  return root;
            }

            if (data < root->data)
            {
                  root->left = deleteElement(root->left, data);
            }
            else if (data > root->data)
            {
                  root->right = deleteElement(root->right, data);
            }
            else
            {
                  if (root->left == NULL)
                  {
                        struct node *temp = root->right;
                        free(root);

                        return temp;
                  }
                  else if (root->right == NULL)
                  {
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

      struct node *deleteBinaryTree(struct node *root)
      {
            if (root == NULL)
            {
                  return root;
            }

            deleteBinaryTree(root->left);

            deleteBinaryTree(root->right);

            free(root);

            return 0;
      }

      int treeHeight(struct node *root)
      {
            int leftHeight = 0;
            int rightHeight = 0;

            if (root == NULL)
            {
                  return 0;
            }

            leftHeight = treeHeight(root->left);
            rightHeight = treeHeight(root->right);

            if (leftHeight > rightHeight)
            {
                  return (int)(leftHeight + 1);
            }
            else
            {
                  return (int)(rightHeight + 1);
            }
      }

      int countTotalNodes(struct node *root)
      {
            if (root == NULL)
            {
                  return 0;
            }
            else
            {
                  int count = countTotalNodes(root->left) + countTotalNodes(root->right) + 1;

                  return count;
            }
      }

      int countInternalNodes(struct node *root)
      {
            if (root == NULL || (root->left == NULL && root->right == NULL))
            {
                  return 0;
            }

            return 1 + countInternalNodes(root->left) + countInternalNodes(root->right);
      }

      void mirrorImage(struct node *root)
      {
            if (root == NULL)
            {
                  return;
            }
            else
            {
                  struct node *temp;

                  mirrorImage(root->left);
                  mirrorImage(root->right);

                  temp = root->left;
                  root->left = root->right;
                  root->right = temp;
            }
      }
};

int main(int argc, char const *argv[])
{
      Tree tree;
      char ch = 'n';
      int n = 0, value = 0;
      bool choice = true;

      cout << "Enter the number of elements you would like to enter in the tree : ";
      cin >> n;

      cout << "Enter the tree elements : " << endl;
      for (int i = 0; i < n; i++)
      {
            cin >> value;
            tree.root = tree.insertElement(tree.root, value); // Important //
      }

      cout << "The tree is as follows : \n"
           << endl;

      cout << "Pre-Order Approach ->" << endl;
      tree.printPreOrder(tree.root);
      cout << endl;

      cout << "In-Order Approach ->" << endl;
      tree.printInOrder(tree.root);
      cout << endl;

      cout << "Post-Order Approach ->" << endl;
      tree.printPostOrder(tree.root);
      cout << endl;

      cout << "Height of tree : " << tree.treeHeight(tree.root) << endl;
      cout << "Minimum element value in the tree : " << tree.minValueNode(tree.root)->data << endl;
      cout << "Maximum element value in the tree : " << tree.largestValueNode(tree.root)->data << endl;
      cout << "Total Nodes in the Tree : " << tree.countTotalNodes(tree.root) << endl;
      cout << "Total Leaf nodes : " << (tree.countTotalNodes(tree.root) - tree.countInternalNodes(tree.root)) << endl;
      cout << "Total Internal Nodes : " << tree.countInternalNodes(tree.root) << endl;
      cout << "The mirror of the present Tree : ";
      tree.mirrorImage(tree.root);
      tree.printInOrder(tree.root);
      cout << endl;

      while (choice != false)
      {
            cout << "Enter the tree element you'd like to remove : ";
            cin >> value;

            tree.root = tree.deleteElement(tree.root, value);
            cout << endl;

            cout << "Current Tree : " << endl;
            tree.printInOrder(tree.root);
            cout << endl;

            cout << "Do you want to delete another ? : ";
            cin >> ch;

            if (ch == 'n' || ch == 'N')
            {
                  choice = false;
            }
            else if (ch == 'y' || ch == 'Y')
            {
                  choice = true;
            }
            else
            {
                  cout << "Enter a valid option" << endl;
                  break;
            }
      }

      cout << "Height of tree : " << tree.treeHeight(tree.root) << endl;
      cout << "Total nodes in the Tree : " << tree.countTotalNodes(tree.root) << endl;
      cout << "The mirror of the present Tree : ";
      tree.mirrorImage(tree.root);
      tree.printInOrder(tree.root);

      cout << "\n Deleting the Tree...!" << endl;
      tree.deleteBinaryTree(tree.root);

      return 0;
}
