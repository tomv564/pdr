#include "List.h"
#include "ListNode.h"

List::List()
{
    head = new ListNode();
    tail = new ListNode();
    head->next = tail;
    tail->previous = head;
    count = 0;
}

// Copy constructor
// Called when the code looks something like List list2 = list1;
// (In other words, it is called when you are trying to construct a **new** list from an existing one)
List::List(const List& source) {
    head=new ListNode();
    tail=new ListNode();
    head->next=tail;
    tail->previous=head;
    count=0;

    // Make a deep copy of the list
    ListItr iter(source.head->next);
    while (!iter.isPastEnd()) {
        insertAtTail(iter.retrieve());
        iter.moveForward();
    }
}

// Copy assignment operator
// Called when the code looks something like list2 = list1;
// (In other words, it is called when you are trying to set an **existing** list equal to another one)
List& List::operator=(const List& source) {
    if (this == &source) {
        // The two are the same list; no need to do anything
        return *this;
    } else {
        // Clear out anything this list contained
        // before copying over the items from the other list
        makeEmpty();

        // Make a deep copy of the list
        ListItr iter(source.head->next);
        while (!iter.isPastEnd()) {
            insertAtTail(iter.retrieve());
            iter.moveForward();
        }
    }
    return *this;
}

List::~List()
{
    makeEmpty();
    delete(head);
    delete(tail);
}

void List::insertAtTail(int x)
{
    ListNode* node = new ListNode();
    tail->previous->next = node;
    
    node->previous = tail->previous;
    node->next = tail;
    node->value = x;
    
    tail->previous = node;
    
    count++;
}

ListItr List::find(int x)
{
    ListItr itr(head);
    
    while (!itr.isPastEnd() && itr.current->value != x)
        itr.moveForward();
    
    return itr;
}

void List::insertAfter(int x, ListItr position)
{
    ListNode* node = new ListNode();
    
    node->previous = position.current;
    node->next = position.current->next;
    node->value = x;
    
    position.current->next->previous = node;
    position.current->next = node;
    
    count++;    
}

void List::insertBefore(int x, ListItr position)
{
    ListNode* node = new ListNode();
    node->value = x;
    node->next = position.current;
    node->previous = position.current->previous;
    
    position.current->previous->next = node;
    position.current->previous = node;
    
    count++;

}

void List::remove(int x)
{
    ListItr itr = find(x);
    if (!itr.isPastEnd())
    {
        itr.current->previous->next = itr.current->next;
        itr.current->next->previous = itr.current->previous;
        delete(itr.current);
    } 
}

bool List::isEmpty() const
{
    return head->next == tail;    
}

void List::makeEmpty()
{
    while (head->next != tail)
    {
        ListNode* removed = head->next;
        head->next = head->next->next;
        delete(removed);  
    
    
    tail->previous = head;
    count = 0;}
}

int List::size() const
{
    return count;
}

ListItr List::first()
{
    ListItr itr(head);
    itr.moveForward();
    return itr;
}

ListItr List::last()
{
    ListItr itr(tail);
    itr.moveBackward();
    return itr;
}

void printList(List& source, bool forward)
{
    if (forward)
    {
        ListItr itr = source.first();
        while (!itr.isPastEnd())
        {
            cout << itr.retrieve() << " ";
            itr.moveForward();                
        }
            
        cout << endl;           
    }
    else 
    {
        ListItr itr = source.last();
        while(!itr.isPastBeginning())
        {
            cout << itr.retrieve() << " ";
            itr.moveBackward();
        }
        cout << endl;
    }
}