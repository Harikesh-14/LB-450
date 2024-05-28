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

Node* kth_reverse(Node* &head, int k) {
  Node* curr = head;
  Node* next = nullptr;
  Node* prev = nullptr;
  int count = 0;

  while(count != k){
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
    count++;
  }

  if(next != nullptr) {
    head->next = kth_reverse(next, k);
  }

  return prev;
}

int main() {
  Node* head = new Node(6);

  insertAtHead(head, 5);
  insertAtHead(head, 4);
  insertAtHead(head, 3);
  insertAtHead(head, 2);
  insertAtHead(head, 1);

  cout<<"Original Linked List: ";
  printList(head);
  cout<<endl;

  head = kth_reverse(head, 2);

  cout<<"Reversed Linked List: ";
  printList(head);
  cout<<endl;

  delete head;

  return 0;
}