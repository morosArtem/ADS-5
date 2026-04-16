// Copyright 2021 NNTU-CS
#ifndef INCLUDE_TSTACK_H_
#define INCLUDE_TSTACK_H_

#include <array>

template<typename T, int kSize>
class TStack {
 private:
  std::array<T, kSize> arr;
  int top_ind;

 public:
  TStack() : top_ind(-1) {}

  void push(T value) {
    if (top_ind < kSize - 1) {
      arr[++top_ind] = value;
    }
  }

  T pop() {
    if (top_ind >= 0) {
      return arr[top_ind--];
    }
    return T();
  }

  T top() const {
    if (top_ind >= 0) {
      return arr[top_ind];
    }
    return T();
  }

  bool isEmpty() const {
    return top_ind == -1;
  }

  bool isFull() const {
    return top_ind == kSize - 1;
  }
};

#endif  // INCLUDE_TSTACK_H_
