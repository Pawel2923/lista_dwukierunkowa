#include <iostream>

using namespace std;

struct ListElement {
    ListElement* prev;
    ListElement* next;
    int key;
};

class List {
private:
    ListElement* first, * last;
    unsigned counter;
public:
    List() : first(NULL), last(NULL), counter(0) {}
    ~List() {
        ListElement* element;
        while (first) {
            element = first->next;
            delete first;
            first = element;
        }
    }
    
    unsigned unshift(ListElement* element) {
        element->next = first;
        element->prev = NULL;

        if (first) {
            first->prev = element;
        }
        first = element;
        if (!last) {
            last = first;
        }
        
        return ++counter;
    }

    void printList() {
        if (!first) {
            cout << "\nLista jest pusta\n";
            return;
        }

        ListElement* element;
        element = first;

        cout << "----------------Wszystkie elementy listy----------------\n";
        while (element)
        {
            cout << element->key << " ";
            element = element->next;
        }
        cout << "\n--------------------------------------------------------\n";
    }
};

int main()
{
    List list1;
    ListElement* element;

    // Dodanie 5 elementów na początek listy
    for (unsigned i = 0; i < 5; i++)
    {
        element = new ListElement;
        element->key = i + 1;
        list1.unshift(element);
    }

    list1.printList();
}