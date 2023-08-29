#include <iostream>
using namespace std;

struct node {
  int value;
  node *right;
  node *left;

  node(int val) : left(nullptr), value(val), right(nullptr) {}
};

node *insert(node *root, int value) {
  if (root == nullptr) {
    return new node(value);
  }

  if (value < root->value) {
    root->left = insert(root->left, value);
  } else {
    root->right = insert(root->right, value);
  }

  return root;
}

int findMaximum(node *root) {
  if (root == nullptr) {
    cout << "Tree is empty" << endl;
    return -1;
  }

  while (root->right != nullptr) {
    root = root->right;
  }

  return root->value;
}

int findMinimum(node *root) {
  if (root == nullptr) {
    cout << "Tree is empty" << endl;
    return -1;
  }

  while (root->left != nullptr) {
    root = root->left;
  }

  return root->value;
}

bool isBST(node *root, int &prevValue) {
  if (root == nullptr) {
    return true;
  }

  if (!isBST(root->left, prevValue)) {
    return false;
  }

  if (root->value <= prevValue) {
    return false;
  }
  prevValue = root->value;

  return isBST(root->right, prevValue);
}

bool isBinarySearchTree(node *root) {
  int prevValue = -999999;
  return isBST(root, prevValue);
}

void displayMenu() {
  cout << "Menu:" << endl;
  cout << "1. Insert data" << endl;
  cout << "2. Find maximum value" << endl;
  cout << "3. Find minimum value" << endl;
  cout << "4. Check whether the tree is a Binary Search Tree or Nah" << endl;
  cout << "5. Exit" << endl;
  cout << "Enter your choice: ";
}

int main() {
  node *root = nullptr;
  int choice, value;

  do {
    displayMenu();
    cin >> choice;

    switch (choice) {
    case 1:
      cout << "Enter value to insert: ";
      cin >> value;
      root = insert(root, value);
      break;
    case 2:
      cout << "Maximum value in the tree: " << findMaximum(root) << endl;
      break;
    case 3:
      cout << "Minimum value in the tree: " << findMinimum(root) << endl;
      break;
    case 4:
      cout << "Is the tree a Binary Search Tree? "
          << (isBinarySearchTree(root) ? "Yes" : "No") << endl;
      break;
    case 5:
      cout << "Exiting..." << endl;
      break;
    default:
      cout << "Invalid choice." << endl;
    }
  } while (choice != 5);
  return 0;
}
