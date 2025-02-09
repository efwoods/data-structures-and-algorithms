#include "DoublyLinkedList.h"
#include <iostream>

using namespace std;
DoublyLinkedList::DoublyLinkedList(int value){
    Node* newNode = new Node(value);
    head = newNode;
    tail = newNode;
    length = 1;
}

DoublyLinkedList::~DoublyLinkedList(){
    Node* temp = head;
    while(head){
        head = head->next;
        delete temp;
        temp = head;
    }
}

void DoublyLinkedList::printList() {
    Node* temp = head;
    while(temp){
        cout << temp->value << endl;
        temp = temp->next;
    }
}

void DoublyLinkedList::append(int value){
    Node* newNode = new Node(value);
    if(tail){
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    } else {
        head = newNode;
        tail = newNode;
    }
    length++;
}

void DoublyLinkedList::deleteLast(){
    if(length > 1){
        Node* temp = tail;
        tail = tail->prev;
        tail->next = nullptr;
        delete temp;
        length--;
    } else if (length == 1) {
        delete tail;
        head = nullptr;
        tail = nullptr;
        length = 0;
    } else {
        return;
    }
}

void DoublyLinkedList::prepend(int value){
    Node* newNode = new Node(value);
    if(head){
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        length++;
    }
    else {
        head = newNode;
        tail = newNode;
        length = 1;
    }
}

void DoublyLinkedList::deleteFirst(){
    if(length > 1){
        Node* temp = head;
        head = head->next;
        delete temp;
        length--;
    } else if (length == 1){
        delete head;
        head = nullptr;
        tail = nullptr;
        length = 0;
    } else {
        return;
    }
}

Node* DoublyLinkedList::get(int index){
    if (index == 0){
        return head;
    } else if (index >= length || index < 0) {
        return nullptr;
    } else {
        Node* temp;
        if((length / 2) - 1 >= index){
            // head is closer
            temp = head;
            int i = 0;
            while(i < index){
                temp = temp->next;
                i++;
            }
        } else {
            // tail is closer
            temp = tail;
            int i = length -1;
            while(i > index){
                temp = temp->prev;
                i--;
            }
        }
        return temp;
    }
}

bool DoublyLinkedList::set(int index, int value){
    if(length == 0){
        return false;
    }
    else if (index == 0){
        head->value = value;
    } else if (index >= length || index < 0) {
        return false;
    } else {
        Node* temp;
        if((length / 2) - 1 >= index){
            // head is closer
            temp = head;
            int i = 0;
            while(i < index){
                temp = temp->next;
                i++;
            }
        } else {
            // tail is closer
            temp = tail;
            int i = length -1;
            while(i > index){
                temp = temp->prev;
                i--;
            }
        }
        temp->value = value;
    }
    return true;
}

bool DoublyLinkedList::insert(int index, int value){
    if (index < 0 || index > length){
        return false;
    } else if(index == length) {
        append(value);
    } else if(index == 0){
        prepend(value);
    } else {
        Node* temp;
        int i;
        if((length / 2) - 1 >= index){
            // head is closer
            temp = head;
            i = 0;
            while(i < index){
                temp = temp->next;
                i++;
            }
        } else {
            // tail is closer
            temp = tail;
            i = length - 1;
            while(i > index){
                temp = temp->prev;
                i--;
            }
        }
        Node* newNode = new Node(value);
        Node* swap = temp->prev;
        
        swap->next = newNode;
        newNode->prev = swap;

        newNode->next = temp;
        temp->prev = newNode;
        length++;
    }
    return true;
}

void DoublyLinkedList::deleteNode(int index){
    if (length == 0 || index > length || index < 0){
        return;
    } else if (index == length - 1) {
        deleteLast();
    } else if (index == 0){
        deleteFirst();
    } else {
        int i = 0;
        Node* temp;
        if((length / 2) - 1 >= index){
            // head is closer
            temp = head;
            i = 0;
            while(i < index){
                temp = temp->next;
                i++;
            }
        } else {
            // tail is closer
            temp = tail;
            i = length - 1;
            while(i > index){
                temp = temp->prev;
                i--;
            }
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        temp->next = nullptr;
        temp->prev = nullptr;
        delete temp;
        length--;
    }
}

void DoublyLinkedList::reverse(){
    if(length < 2){
        return;
    }
    Node* current = head->next;
    Node* temp;
    
    while(current != tail){
        temp = current->next;
        current->next = current->prev;
        current->prev = temp;
        current = current->prev;
    }
    temp = head;
    head = current;
    tail = temp;
    head->next = head->prev;
    head->prev = nullptr;
    tail->prev = tail->next;
    tail->next = nullptr;
}

bool DoublyLinkedList::isPalindrome(){
    if (length < 2){
        return true;
    }
    Node* forwardNode = head;
    Node* backwardNode = tail;

    for(int i = 0; i < length / 2; i++){
        if(forwardNode->value != backwardNode->value){
            return false;
        }
        forwardNode = forwardNode->next;
        backwardNode = backwardNode->prev;
    }
    return true;
}

void DoublyLinkedList::swapPairs(){
    if(length < 2){
        return;
    }
    Node* first = head;
    Node* second = first->next;
    Node* previousNode;
    for(int i = 0; i < length/2; i++){
        Node* temp = new Node(0);
        temp->next = first->next;
        temp->prev = first->prev;
        first->next = second->next;
        first->prev = second;
        second->prev = temp->prev;
        second->next = first;
        if(i != 0){
            second->prev = previousNode;
            previousNode->next = second;
        }
        if (i == 0){
            head = second;
        }

        if(i != length/2 -1){ // not at the end
            previousNode = first;
            first = first->next;
            second = first->next;
        } else {
            if (length%2 == 0){ // if even
                tail = first;
            } else { // if odd
                tail->prev = first;
            }
        }
        delete temp;
    }
}

Node* DoublyLinkedList::getHead() {
    return head;
}

Node* DoublyLinkedList::getTail(){
    return tail;
}

int DoublyLinkedList::getLength(){
    return length;
}
