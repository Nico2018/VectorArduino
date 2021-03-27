#ifndef VECTOR_H
#define VECTOR_H
#include <Arduino.h>
#include <Utils.h>

template <class T>
class Vector
{
private:
    unsigned int _current_elements = 0;
    T *_elements;
    void Initialize(T elements);
    void Initialize(T *elements, unsigned int len);
    void Push(T element, bool back = true);
    T *Pop(bool back = true);

public:
    Vector();
    Vector(T *elements, unsigned int len);
    ~Vector();
    void Clear();
    int Size();
    T &operator[](unsigned int);
    T *GetElements();
    void Sort(bool (*sort)(T &a, T &b)); //sort must return true if swap must be done
    void PushBack(T element);
    void PushFront(T element);
    T *PopFront();
    T *PopBack();
};

template <class T>
Vector<T>::Vector() {}

template <class T>
Vector<T>::Vector(T *elements, unsigned int len)
{
    Initialize(elements, len);
}

template <class T>
void Vector<T>::Initialize(T element)
{
    Push(element);
}

template <class T>
void Vector<T>::Initialize(T *elements, unsigned int len)
{

    for (unsigned int i = 0; i < len; i++)
    {
        Push(elements[i]);
    }
}

template <class T>
T *Vector<T>::PopFront()
{
    return Pop(false);
}

template <class T>
T *Vector<T>::PopBack()
{
    return Pop();
}

template <class T>
T *Vector<T>::Pop(bool back)
{
    if (_current_elements > 1)
    {
        T elements[_current_elements - 1];
        T element;
        if (back)
        {
            for (unsigned int i = 0; i < _current_elements - 1; i++)
            {
                elements[i] = _elements[i];
            }
            element = _elements[_current_elements - 1];
        }
        else
        {
            for (unsigned int i = 0, j = 1; i < _current_elements - 1; i++, j++)
            {
                elements[i] = _elements[j];
            }
            element = _elements[0];
        }
        delete[] _elements;
        _current_elements--;
        _elements = new T[_current_elements];
        for (unsigned int i = 0; i < _current_elements; i++)
        {
            _elements[i] = elements[i];
        }
        return new T(element);
    }
    else if (_current_elements == 1)
    {
        T element = _elements[0];
        delete[] _elements;
        _current_elements = 0;
        return new T(element);
    }
    else if (!_current_elements)
    {
        Utils::DBG("Error, vector does not have any element");
    }
    return nullptr;
}

template <class T>
void Vector<T>::Push(T element, bool back)
{
    if (_current_elements > 0)
    {
        T elements[_current_elements];
        for (unsigned int i = 0; i < _current_elements; i++)
        {
            elements[i] = _elements[i];
        }
        delete[] _elements;
        _current_elements++;
        _elements = new T[_current_elements];
        if (back)
        {
            for (unsigned int i = 0; i < _current_elements - 1; i++)
            {
                _elements[i] = elements[i];
            }
            _elements[_current_elements - 1] = element;
        }
        else
        {
            for (unsigned int i = 1, j = 0; i < _current_elements; i++, j++)
            {
                _elements[i] = elements[j];
            }
            _elements[0] = element;
        }
    }
    else
    {
        _elements = new T[1];
        _elements[0] = element;
        _current_elements++;
    }
}

template <class T>
void Vector<T>::PushBack(T element)
{
    Push(element);
}

template <class T>
void Vector<T>::PushFront(T element)
{
    Push(element, false);
}

template <class T>
void Vector<T>::Clear()
{
    delete[] _elements;
    _current_elements = 0;
}

template <class T>
Vector<T>::~Vector()
{
    delete[] _elements;
}

template <class T>
int Vector<T>::Size()
{
    return _current_elements;
}

template <class T>
T &Vector<T>::operator[](unsigned int index)
{

    if (index > _current_elements)
    {
        Utils::DBG("index " + String(index) + " is out of edges");
        for (;;)
            ;
    }
    return _elements[index];
}

template <class T>
T *Vector<T>::GetElements()
{
    return _elements;
}

template <class T>
void Vector<T>::Sort(bool (*sort)(T &a, T &b))
{
    if (_current_elements > 1)
    {
        bool sorted;
        do
        {
            sorted = true;
            for (unsigned int i = 0; i < _current_elements - 1; i++)
            {
                if (sort(_elements[i], _elements[i + 1]))
                {
                    Utils::Swap(_elements[i], _elements[i + 1]);
                    sorted = false;
                }
            }
        } while (!sorted);
    }
}

#endif //VECTOR_H