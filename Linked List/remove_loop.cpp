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

void detect_remove_loop(Node* &head){
  if(head == nullptr || head->next == nullptr){
    return;
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

  if(slow == fast){
    slow = head;

    if(slow == fast){
      while(fast->next != slow){
        fast = fast->next;
      }
    } else {
      while(slow->next != fast->next){
        slow = slow->next;
        fast = fast->next;
      }
    }

    fast->next = nullptr;
  }
}

int main() {
  Node* head = new Node(5);

  insertAtHead(head, 4);
  insertAtHead(head, 3);
  insertAtHead(head, 2);
  insertAtHead(head, 1);

  head->next->next->next->next->next = head->next;

  detect_remove_loop(head);

  printList(head);

  return 0;
}