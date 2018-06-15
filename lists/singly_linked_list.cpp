#include <iostream>

template <typename T>
struct Node {
    T data;
    Node<T> * next;
    Node(T data, Node<T> * next) : data(data), next(next) { }
};

template <typename T>
struct LinkedList {
    Node<T> * head;
    int size;

    void insert(T);
    bool insert(T, int);
    bool remove(T);
    int find(T);
    void print();
    int length();

    LinkedList() : head(), size(0) { }
    LinkedList(T data) {
        size = 0;
        insert(data);
    }
    LinkedList(Node<T> set_head) {
        head = set_head;
        size = 1;
    }
};

/**
 * Inserts an element into the start of the linked list
 * @param data The element to be added to the list
 */
template <typename T>
void LinkedList<T>::insert(T data) {
    if (head == nullptr) {
        head = new Node<T>(data, nullptr);
    } else {
        head = new Node<T>(data, head);
    }
    size++;
}

/**
 * Inserts an element into the linked list at a specific index
 * @param data The element to be added to the list
 * @index index The index to insert the element
 * @return if the element was successfully inserted
 */
template <typename T>
bool LinkedList<T>::insert(T data, int index) {
    if (index > size || index < 0) {
        return false;
    }
    if (index == 0) {
        insert(data);
        return true;
    }
    Node<T> * current = head;
    for (int i = 0; i < index - 1; i++) {
        current = current->next;
    }
    current->next = new Node<T>(data, current->next);
    size++;
    return true;
}

/**
 * Removed an element from the linked list
 * @param data The element to be removed
 * @return if the element was successfully removed
 */
template <typename T>
bool LinkedList<T>::remove(T data) {
    if (head == nullptr) {
        return false;
    }
    if (head->next == nullptr) {
        if (head->data == data) {
            delete head;
            head = nullptr;
            size--;
            return true;
        } else {
            return false;
        }
    }
    if (head->data == data) {
        // takes care of case that the head needs to be removed
        Node<T> * temp = head;
        head = head->next;
        delete temp;
        temp = nullptr;
        size--;
        return true;
    }
    Node<T> * current = head;
    while (current->next != nullptr && current->next->data != data) {
        current = current->next;
    }
    if (current->next == nullptr) {
        return false;
    } else {
        if (current->next->next != NULL) {
            Node<T> * temp = current->next;
            current->next = current->next->next;
            delete temp;
            temp = nullptr;
        } else {
            Node<T> * temp = current->next;
            delete temp;
            temp = nullptr;
            current->next = nullptr;
        }
        size--;
        return true;
    }
}

/**
 * Returns the index of the element in the list.
 * @param data The data element to find in linked list
 * @return index of element or -1 if not found
 */
template <typename T>
int LinkedList<T>::find(T data) {
    int i = 0;
    Node<T> * current = head;
    while (current != nullptr && current->data != data) {
        current = current->next;
        i++;
    }
    if (current != nullptr && current->data == data) {
        return i;
    }
    return -1;
}

/**
 * Prints the linked list to the console in order
 */
template <typename T>
void LinkedList<T>::print() {
    Node<T> * current = head;
    std::cout << "Linked List: ";
    while (current->next != nullptr) {
        std::cout << current->data << " -> ";
        current = current->next;
    }
    if (current != nullptr) {
        std::cout << current->data << std::endl;
    }
}

/**
 * Returns the size of the linked list.
 * @return the size of the linked list
 */
template <typename T>
int LinkedList<T>::length() {
    return size;
}

int main() {
    LinkedList<int> list;
    list.insert(-1);
    list.insert(1);
    std::cout << list.length() << std::endl;
    list.insert(2);
    // list.insert(-2, 8);
    list.print();
    std::cout << list.length() << std::endl;
    // list.insert(0, 4);
    // list.insert(-2, 7);
    // std::cout << list.remove(5) << std::endl;
    list.print();
    std::cout << "FIND " << list.find(0) << std::endl;
    std::cout << list.length() << std::endl;
}
