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

Node* loop_start(Node* &head) {
  if(head == nullptr || head->next == nullptr){
    return head;
  }

  Node* slow = head;
  Node* fast = head;

  while(slow && fast && fast->next){
    slow = slow->next;
    fast = fast->next->next;

    if(slow == fast){
      break;
    }
  }

  if(slow != fast){
    return nullptr;
  }

  slow = head;

  while(fast != slow){
    fast = fast->next;
    slow = slow->next;
  }

  return slow;
}

int main() {
  Node* head = new Node(5);

  insertAtHead(head, 4);
  insertAtHead(head, 3);
  insertAtHead(head, 2);
  insertAtHead(head, 1);

  head->next->next->next->next->next = head->next->next;

  Node* res = loop_start(head);
  cout<<"Starting node of the loop is: "<<res->data<<endl;

  return 0;
}