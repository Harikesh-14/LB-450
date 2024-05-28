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

void remove_duplicate(Node* &head){
  if(head == nullptr && head->next == nullptr){
    return; 
  }

  Node* curr = head;
  Node* next;

  while(curr->next != nullptr){
    if(curr->data == curr->next->data){
      next = curr->next->next;
      free(curr->next);
      curr->next = next;
    } else {
      curr = curr->next;
    }
  }
}

int main() {
  Node* head = new Node(20);

  insertAtHead(head, 15);
  insertAtHead(head, 13);
  insertAtHead(head, 13);
  insertAtHead(head, 11);
  insertAtHead(head, 11);
  insertAtHead(head, 11);

  printList(head);

  remove_duplicate(head);

  printList(head);

  delete head;

  return 0;
}