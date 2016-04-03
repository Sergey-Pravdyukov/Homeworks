#include "stack.h"

void Stack::push(const QChar value)
{
    StackElement *newElement = new StackElement(value);
    if (size != 0)
        newElement->next = head;
    head = newElement;
    ++size;
}

QChar Stack::top()
{
    StackElement *topElement = head;
    return topElement->value;
}

QChar Stack::pop()
{
   --size;
   StackElement topElement = *head;
   StackElement *newTopElement = topElement.next;
   delete head;
   head = newTopElement;
   return topElement.value;
}
