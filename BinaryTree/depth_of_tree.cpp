#include<iostream>
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

    ~Node(){
      delete left;
      delete right;
    }
};

int depth(Node* root){
  if(root == nullptr) return 0;

  int left = depth(root->left);
  int right = depth(root->right);

  int ans = max(left, right) + 1;

  return ans;
}

int main() {
  Node* root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);
  root->left->left = new Node(4);
  root->left->right = new Node(5);
  root->right->left = new Node(6);
  root->right->right = new Node(7);
  root->right->right->right = new Node(8);

  cout << depth(root) << endl; // 4

  return 0;
}