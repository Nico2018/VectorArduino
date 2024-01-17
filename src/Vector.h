#ifndef VECTOR_H
#define VECTOR_H
#include <Utils.h>

template <class T> class Vector {
private:
  unsigned int _current_elements = 0;
  T *_elements = nullptr;
  void Initialize(T *elements, unsigned int len);

public:
  Vector();
  Vector(T *elements, unsigned int len);
  ~Vector();
  void Clear();
  int Size();
  T &operator[](unsigned int);
  T *GetElements();
  void Sort(bool (*sort)(T &a,
                         T &b)); // sort must return true if swap must be done
  void Push(T element);
};

template <class T> Vector<T>::Vector() {}

template <class T> Vector<T>::Vector(T *elements, unsigned int len) {
  Initialize(elements, len);
}

template <class T> void Vector<T>::Initialize(T *elements, unsigned int len) {

  for (unsigned int i = 0; i < len; i++) {
    Push(elements[i]);
  }
}

template <class T> void Vector<T>::Push(T element) {
  T *new_elements =
      new T[_current_elements + 1]; // Cambiado el nombre de la variable
  memcpy(new_elements, _elements, _current_elements * sizeof(T));
  delete[] _elements;
  _elements = new_elements;
  _elements[_current_elements] = element;
  _current_elements++;
}
template <class T> void Vector<T>::Clear() {
  delete[] _elements;
  _elements = nullptr;
  _current_elements = 0;
}

template <class T> Vector<T>::~Vector() { delete[] _elements; }

template <class T> int Vector<T>::Size() { return _current_elements; }

template <class T> T &Vector<T>::operator[](unsigned int index) {
  if (index >= _current_elements) {
    throw "Index out of range";
  }
  return _elements[index];
}

template <class T> T *Vector<T>::GetElements() { return _elements; }

template <class T> void Vector<T>::Sort(bool (*sort)(T &a, T &b)) {
  if (_current_elements > 1) {
    bool sorted;
    do {
      sorted = true;
      for (unsigned int i = 0; i < _current_elements - 1; i++) {
        if (sort(_elements[i], _elements[i + 1])) {
          Utils::Swap(_elements[i], _elements[i + 1]);
          sorted = false;
        }
      }
    } while (!sorted);
  }
}

#endif // VECTOR_H