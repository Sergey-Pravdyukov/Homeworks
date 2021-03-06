#include "stack.h"

void Stack::push(const QString &value)
{
    StackElement *newElement = new StackElement(value);
    if (size != 0)
        newElement->next = head;
    head = newElement;
    ++size;
}

QString Stack::top()
{
    return head->value;
}

QString Stack::pop()
{
   --size;
   StackElement topElement = *head;
   StackElement *newTopElement = topElement.next;
   delete head;
   head = newTopElement;
   return topElement.value;
}

int Stack::haveSize()
{
    return size;
}
