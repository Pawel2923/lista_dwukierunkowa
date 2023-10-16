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

    unsigned insert(int newKey, unsigned position) {
        if (position == 0) {
			return unshift(newKey);
		}
        if (position >= counter) {
			return push(newKey);
		}

		ListElement* element = new ListElement;
		element->key = newKey;

		ListElement* current = first;
        for (size_t i = 0; i < position - 1; i++)
        {
			current = current->next;
		}

		element->next = current->next;
		element->prev = current;

		current->next->prev = element;
		current->next = element;

		return ++counter;
	}

    // metoda do usunięcia elementu z początku listy
    int shift() {
        if (!first) {
			cout << "\nLista jest pusta\n";
			return 0;
		}

		ListElement* element = first;
		int key = element->key;

		first = first->next;
        if (first) {
			first->prev = nullptr;
		}
        else {
			last = nullptr;
		}

		delete element;
		counter--;
		return key;
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

    // Dodanie elementu na pozycję 3
    list1.insert(7, 3);

    // Dodanie elementu na pozycję 0
    list1.insert(0, 0);

    // Dodanie elementu na pozycję 10
    list1.insert(10, 10);

    list1.printList();

    // Usunięcie elementu z początku listy
    list1.shift();

    list1.printList();
}