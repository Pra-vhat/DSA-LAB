#include <iostream>
using namespace std;


typedef struct Node{
    int data;
    Node* next = nullptr;
} Node;

Node* createNode(){
    Node *newNode = new Node;
    if(!newNode){
        cout << "Allocation Failed" << endl;
        exit(1);
    }else{
        return newNode;
    }
}

void printList(Node *head){
    Node *currentNode = head;
    while(currentNode){
        cout << currentNode->data << " ";
        currentNode = currentNode->next;
    }cout << endl;
}


int main(){

    Node *node1 = createNode(), *node2 = createNode(), *node3 = createNode();
    node1->data = 1, node2->data = 3, node3->data = 6;
    node1->next = node2, node2->next = node3;


    printList(node1);
    
    return 0;
}