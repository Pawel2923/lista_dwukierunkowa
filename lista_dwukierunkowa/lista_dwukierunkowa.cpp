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
    List() : first(nullptr), last(nullptr), counter(0) {}
    ~List() {
        while (first) {
            ListElement* element = first->next;
            delete first;
            first = element;
        }
    }

    unsigned unshift(int newKey) {
        ListElement* element = new ListElement;
        element->key = newKey;

        element->next = first;
        element->prev = nullptr;

        if (first) {
            first->prev = element;
        }
        first = element;
        if (!last) {
            last = first;
        }
        return ++counter;
    }

    unsigned push(int newKey) {
        ListElement* element = new ListElement;
        element->key = newKey;

        element->next = nullptr;
        element->prev = last;

        if (last) {
            last->next = element;
        }
        last = element;
        if (!first) {
            first = last;
        }
        return ++counter;
    }

    void printList() {
        if (!first) {
            cout << "\nLista jest pusta\n";
            return;
        }

        ListElement* element = first;

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

    // Wypisanie pustej listy
    list1.printList();

    // Dodanie 5 elementów na początek listy
    for (size_t i = 0; i < 5; i++)
    {
        list1.unshift(i + 1);
    }

    list1.printList();

    // Dodanie elementu na koniec listy
    list1.push(6);
    list1.push(9);

    list1.printList();
}