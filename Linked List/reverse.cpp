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

void printList(Node* head){
  if(head == nullptr){
    return;
  }

  Node* temp = head;

  while(temp != nullptr ){
    cout << temp->data << " ";
    temp = temp->next;
  } cout << endl;
}

void reverseLL(Node* &head) {
  Node* curr = head;
  Node* prev = nullptr;
  Node* next = nullptr;

  while(curr != nullptr){
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }

  head = prev;
}

int main() {
  Node* head = new Node(3);

  insertAtHead(head, 2);
  insertAtHead(head, 1);

  cout<<"Original Linked List: ";
  printList(head);
  cout<<endl;

  reverseLL(head);

  cout<<"Original Linked List: ";
  printList(head);
  cout<<endl;

  delete head;

  return 0;
}