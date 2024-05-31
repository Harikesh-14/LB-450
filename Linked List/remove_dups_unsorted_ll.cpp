#include<iostream>
#include<unordered_set>
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

void remove_duplicate(Node* &head) {
  unordered_set<int> seen;

  Node* curr = head;
  Node* prev = nullptr;

  while(curr != nullptr){
    if(seen.find(curr->data) != seen.end()){
      prev->next = curr->next;
      Node* temp = curr;
      curr = curr->next;
      temp->next = nullptr;
      delete temp;
    } else {
      seen.insert(curr->data);
      prev = curr;
      curr = prev->next;
    }
  }
}

int main() {
  Node* head = new Node(20);

  insertAtHead(head, 13);
  insertAtHead(head, 11);
  insertAtHead(head, 15);
  insertAtHead(head, 11);
  insertAtHead(head, 13);
  insertAtHead(head, 11);

  printList(head);

  remove_duplicate(head);

  printList(head);

  return 0;
}