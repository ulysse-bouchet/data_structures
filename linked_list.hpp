/**
 * @brief Linked list implementation using struct and templates
 * @author Ulysse Bouchet
 * @date 15/03/2020
 */

#ifndef CPP_LINKED_LIST_HPP
#define CPP_LINKED_LIST_HPP

#include <stdexcept>

/**
 * @brief Linked list implementation
 * @tparam T The type/class of the list elements
 */
template <typename T>
class LinkedList {
    /**
     * @brief Linked list node implementation
     */
    struct Node {
        T m_value; //Node value
        Node* m_next; //Pointer to the next node
    };

    private:
        Node* m_head; //The node at the front of the list
        int m_size; //The size of the list

    public:
        LinkedList();
        T get (int index);
        void add (T value);
        int size ();
};

/**
 * @brief Default list constructor
 * @tparam T The type/class of the list elements
 */
template <typename T>
LinkedList<T>::LinkedList() : m_size {0}, m_head {NULL} { }

/**
 * @brief Returns the value of the node at a given index
 * @tparam T The type/class of the list elements
 * @param index The index of the node in the list
 * @return the value corresponding to the index
 */
template <typename T>
T LinkedList<T>::get (int index) {
    if (index >= size())
        throw std::out_of_range("Index out of range.");

    Node* cur = m_head;

    int cpt = 0;
    while (cpt++ != index)
        cur = cur->m_next;

    return cur->m_value;
}

/**
 * @brief Adds a value at the end of the list
 * @tparam T The type/class of the list elements
 * @param value the value to add to the list
 */
template <typename T>
void LinkedList<T>::add (T value) {
    Node *n = new Node();
    n->m_value = value;
    n->m_next = NULL;

    if (m_head == NULL) {
        m_head = n;
        ++m_size;
        return;
    }

    Node *cur = m_head;
    while (cur->m_next != NULL) {
        cur = cur->m_next;
    }

    cur->m_next = n;
    ++m_size;
}

/**
 * @brief Returns the size of the list
 * @tparam T The type/class of the list elements
 * @return the size of the list
 */
template <typename T>
int LinkedList<T>::size () {
    return m_size;
}

#endif //CPP_LINKED_LIST_HPP