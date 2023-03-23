#include "ListItr.h"
#include <cstddef>

ListItr::ListItr()
{
    current = nullptr;
}

ListItr::ListItr(ListNode* theNode)
{
    current = theNode;
}

bool ListItr::isPastBeginning() const
{
    if (current)
        return !current->previous;
        
    return false;
}

bool ListItr::isPastEnd() const 
{
    if (current)
        return !current->next;
        
    return false;
}

void ListItr::moveBackward()
{
    if (current)
        current = current->previous;
}

void ListItr::moveForward()
{
    if (current)
        current = current->next;
}

int ListItr::retrieve() const
{
    return current->value;
}
