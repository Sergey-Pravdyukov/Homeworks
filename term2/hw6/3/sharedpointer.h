#pragma once

template <typename T>
class SharedPointer
{
public:
    SharedPointer(T *object):
        pointer(new Pointer(object))
    {}

    SharedPointer(const SharedPointer<T> &currentPointer);

    ~SharedPointer();

    int getCount() const;

    T &operator * () const
    {
        return *pointer->object;
    }

    void operator = (const SharedPointer<T> currentPointer)
    {
        deletePointer();
        pointer = currentPointer.pointer;
        ++pointer->count;
    }

private:

    class Pointer
    {
    public:
        Pointer(T *currentPointer):
            object(currentPointer),
            count(1)
        {}

        ~Pointer()
        {
            delete object;
        }

        T *object;
        int count;
    };

    Pointer *pointer;

    void deletePointer();
};

//--------------------------------------------------------------------------

template <typename T>
SharedPointer<T>::SharedPointer(const SharedPointer<T> &currentPointer)
{
    pointer = currentPointer.pointer;
    ++pointer->count;
}

template <typename T>
SharedPointer<T>::~SharedPointer()
{
    deletePointer();
}

template <typename T>
int SharedPointer<T>::getCount() const
{
    return pointer->count;
}

template <typename T>
void SharedPointer<T>::deletePointer()
{
    --pointer->count;
    if (pointer->count == 0)
        delete pointer;
}
