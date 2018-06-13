#include <iostream>

template <typename T>
struct Node {
    T data;
    Node<T> * next;
    Node(T data, Node<T> * next) : data(data), next(next) { }
};

template <typename T>
struct Queue {
    Node<T> * head;
    Node<T> * tail;

    void enqueue(T);
    T front();
    T dequeue();
    void print();

    Queue() : head(), tail() { }
    Queue(T data) {
        enqueue(data);
    }
    Queue(Node<T> set_head) {
        head = &set_head;
        tail = &set_head;
    }
};

/**
 * Inserts an element into the queue
 * @param data The element to be added to the queue
 */
template <typename T>
void Queue<T>::enqueue(T data) {
    Node<T> * new_node = new Node<T>(data, nullptr);
    if (head == nullptr) {
        head = new_node;
        tail = new_node;
    } else {
        tail->next = new_node;
        tail = tail->next;
    }
}

/**
 * Returns the front element of the queue
 * @return the data at the front of the queue
 */
template <typename T>
T Queue<T>::front() {
    if (tail != nullptr) {
        return head->data;
    }
    return T();
}

/**
 * Removed an element from the queue
 * @return the data at the removed node
 */
template <typename T>
T Queue<T>::dequeue() {
    if (head != nullptr) {
        T data = head->data;
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            tail = nullptr;
        } else {
            Node<T> * to_delete = head;
            head = head->next;
            delete to_delete;
            to_delete = nullptr;
        }
        return data;
    }
    return T();
}

/**
 * Prints the LinkedList to the console in order with the front at the left
 */
template <typename T>
void Queue<T>::print() {
    if (head != nullptr) {
        Node<T> * current = head;
        std::cout << "Linked List: ";
        while (current->next != nullptr) {
            std::cout << current->data << " -> ";
            current = current->next;
        }
        if (current != nullptr) {
            std::cout << current->data << std::endl;
        }
    } else {
        std::cout << "The queue is empty." << std::endl;
    }
}

int main() {
    // Testing
    Queue<int> q;
    q.enqueue(-1);
    q.enqueue(1);
    q.enqueue(2);
    q.print();
    std::cout << "Front: " << q.front() << std::endl;
    std::cout << "Removed: " << q.dequeue() << std::endl;
    q.print();
    std::cout << "Removed: " << q.dequeue() << std::endl;
    q.print();
    std::cout << "Removed: " << q.dequeue() << std::endl;
    q.print();
}
