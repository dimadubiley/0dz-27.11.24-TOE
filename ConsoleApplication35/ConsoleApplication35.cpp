#include <iostream>

using namespace std;

template <typename T>
class Node
{
public:
    T data;
    Node<T>* next;
    Node<T>* prev;

    Node(T value) : data(value), next(nullptr), prev(nullptr) {}
};

template <typename T>
class List
{
    Node<T>* head;
    Node<T>* tail;

public:
    List() : head(nullptr), tail(nullptr) {}

    void push_back(T value)
    {
        Node<T>* new_node = new Node<T>(value);
        if (!head)
        {
            head = tail = new_node;
        }
        else
        {
            tail->next = new_node;
            new_node->prev = tail;
            tail = new_node;
        }
    }

    void print()
    {
        Node<T>* current = head;
        while (current)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    ~List()
    {
        Node<T>* current = head;
        while (current)
        {
            Node<T>* next_node = current->next;
            delete current;
            current = next_node;
        }
    }

    List<T>* operator+(const List<T>& other)
    {
        List<T>* new_list = new List<T>();

        Node<T>* current = head;
        while (current)
        {
            new_list->push_back(current->data);
            current = current->next;
        }

        current = other.head;
        while (current)
        {
            new_list->push_back(current->data);
            current = current->next;
        }

        return new_list;
    }

    List<T>* operator*(const List<T>& other)
    {
        List<T>* new_list = new List<T>();

        Node<T>* current = head;
        while (current)
        {
            Node<T>* other_current = other.head;
            while (other_current)
            {
                if (current->data == other_current->data)
                {
                    new_list->push_back(current->data);
                    break;
                }
                other_current = other_current->next;
            }
            current = current->next;
        }

        return new_list;
    }
};

int main()
{
    List<int> list1;
    list1.push_back(1);
    list1.push_back(2);
    list1.push_back(3);

    List<int> list2;
    list2.push_back(2);
    list2.push_back(3);
    list2.push_back(4);

    cout << "List 1: ";
    list1.print();

    cout << "List 2: ";
    list2.print();

    List<int>* merged_list = list1 + list2;
    cout << "Merged List: ";
    merged_list->print();

    List<int>* common_list = list1 * list2;
    cout << "Common List: ";
    common_list->print();

    delete merged_list;
    delete common_list;

}
