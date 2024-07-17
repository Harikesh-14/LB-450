#include<iostream>
#include<unordered_map>
using namespace std;

class Node{
  public:
    int data;
    Node* next;
    Node* random;

  Node(int data) {
    this->data = data;
    this->next = nullptr;
    this->random = nullptr;
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

Node* copyRandomList(Node* head){
  if (!head) return nullptr;

  unordered_map<Node*, Node*> nodeMap;
  Node* current = head;

  // Create a new list with the same data
  while(current){
    nodeMap[current] = new Node(current->data);
    current = current->next;
  }

  // Assign the next and random pointers
  current = head;
  while(current){
    nodeMap[current]->next = nodeMap[current->next];
    nodeMap[current]->random = nodeMap[current->random];
    current = current->next;
  }

  return nodeMap[head];
}

int main() {
  Node* head = nullptr;

  insertAtHead(head, 3);
  insertAtHead(head, 2);
  insertAtHead(head, 1);

  head->random = head->next;
  head->next->random = head->next->next;
  head->next->next->random = head;

  printList(head);

  Node* newHead = copyRandomList(head);
  printList(newHead);

  delete newHead;
  delete head;

  return 0;
}