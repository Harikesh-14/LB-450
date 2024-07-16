#include<iostream>
#include<vector>
using namespace std;

class Node{
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
      data = val;
      left = NULL;
      right = NULL;
    }

    ~Node(){
      delete left;
      delete right;
    }
};

Node* invertTree(Node* root){
  if (root == nullptr) return nullptr;

  Node* right = invertTree(root->right);
  Node* left = invertTree(root->left);

  root->left = right;
  root->right = left;

  return root;
}

void printTree(Node* root, vector<int>& arr){
  if (root == nullptr) return;

  arr.push_back(root->data);
  printTree(root->left, arr);
  printTree(root->right, arr);
}

int main() {
  Node* root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);
  root->left->left = new Node(4);
  root->left->right = new Node(5);
  root->right->left = new Node(6);
  root->right->right = new Node(7);

  vector<int> arr;
  printTree(root, arr);

  cout << "Original Tree: ";
  for (int i = 0; i < arr.size(); i++){
    cout << arr[i] << " ";
  } cout << endl;

  Node* newRoot = invertTree(root);
  arr.clear();
  printTree(newRoot, arr);

  cout << "Inverted Tree: ";
  for (int i = 0; i < arr.size(); i++){
    cout << arr[i] << " ";
  } cout << endl;

  delete root;

  return 0;
}