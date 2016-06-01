#include "uniquelist.h"

void UniqueList::add(const int &value) throw(ElementAlreadyExistsException)
{
    if (ArrayLinkedList::find(value) != notFoundIndex)
        throw ElementAlreadyExistsException();
    ArrayLinkedList::add(value);
}

