#include<iostream>
using namespace std;

class Node{
  public:
    int data;
    Node* next;

  Node(int data) {
    this->data = data;
    this->next = nullptr;
  }

  ~Node(){
    delete next;
  }
};

void insertAtHead(Node* &root, int data) {
  Node* newNode = new Node(data);

  if(root == nullptr){
    root = newNode;
    return;
  }

  newNode->next = root;
  root = newNode;
}

bool detectLoop(Node* &head) {
  Node* fast = head;
  Node* slow = head;

  while(slow && fast && fast->next){
    slow = slow->next;
    fast = fast->next->next;

    if(slow == fast){
      return true;
    }
  }

  return false;
}

int main() {
  Node* head = new Node(4);

  insertAtHead(head, 3);
  insertAtHead(head, 2);
  insertAtHead(head, 1);

  head->next->next->next->next = head;

  bool res = detectLoop(head);

  if(res == true){
    cout<<"Loop detected"<<endl;
  } else {
    cout<<"Loop not detected"<<endl;
  }

  return 0;
}