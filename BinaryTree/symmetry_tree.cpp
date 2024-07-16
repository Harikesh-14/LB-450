#include<iostream>
#include<vector>
using namespace std;

class Node{
  public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
      this->data = data;
      this->left = nullptr;
      this->right = nullptr;
    }
};

bool isMirror(Node* left, Node* right){
  if (left == nullptr && right == nullptr) return true;
  if (left == nullptr || right == nullptr) return false;

  return (left->data == right->data) && isMirror(left->left, right->right) && isMirror(left->right, right->left);
}

bool isSymmetric(Node* root){
  if (root == nullptr) return true;
  
  Node* left = root->left;
  Node* right = root->right;

  return isMirror(left, right);
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
  root->right = new Node(2);
  root->left->left = new Node(3);
  root->left->right = new Node(4);
  root->right->left = new Node(4);
  root->right->right = new Node(3);
  
  vector<int> arr;
  printTree(root, arr);
  
  cout << "Original Tree: ";
  for (int i = 0; i < arr.size(); i++){
    cout << arr[i] << " ";
  } cout << endl;

  if (isSymmetric(root)){
    cout << "The tree is symmetric." << endl;
  } else {
    cout << "The tree is not symmetric." << endl;
  }

  return 0;
}