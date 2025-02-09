#pragma once

class Node {
    public:
        int value;
        Node* next;

        Node(int value){
            this->value = value;
            next = nullptr;
        }
};

class Queue {
    private:
        Node* first;
        Node* last;
        int length;

    public:
        Queue(int value);
        ~Queue();
        Node* getFirst();
        Node* getLast();
        int getLength();
        void printQueue();
        void enqueue(int value);
        int dequeue();
};