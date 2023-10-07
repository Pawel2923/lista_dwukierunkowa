#include <iostream>

struct ListElement {
    ListElement* prev;
    ListElement* next;
    std::string data;
    int key;
};

class List {
private:
    ListElement* first, * last;
    unsigned counter;
public:
    List() {
        first = last = NULL;
        counter = 0;
    }
    ~List() {
        ListElement* element;
        while (first) {
            element = first->next;
            delete first;
            first = element;
        }
    }
};

int main()
{
    List list1;
}