#ifndef UTILS_H
#define UTILS_H

class Utils {
public:
  template <typename T> static void Swap(T &a, T &b) {
    T c = a;
    a = b;
    b = c;
  }
};

#endif // UTILS_H