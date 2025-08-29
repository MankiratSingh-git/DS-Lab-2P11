#include<iostream>
using namespace std;

class CircularQueue {
  int size;
  int front = -1;
  int rear = -1;
  char *arr;
  public:
  CircularQueue(int n): size(n), arr(new char[n]) {};
  ~CircularQueue() { delete[] arr; };

  bool isEmpty() {
    return (front == -1 && rear == -1);
  }

  bool isFull() {
    return (front == (rear + 1) % size);
  }

  void enqueue(char x) {
    if (isEmpty()) {
      front = rear = 0;
      arr[rear] = x;
      return;
    }
    if (isFull()) {
      cout << "Overflow" << endl;
      return;
    }
    else{
      rear = (rear + 1) % size;
      arr[rear] = x;
    }
  }

  char dequeue() {
    if (isEmpty()) {
      cout << "Underflow" << endl;
      return -1;
    }

    char temp = arr[front];
    if (front == rear) {
      front = rear = -1;
    } else {
      front = (front + 1) % size;
    }
    return temp;
  }

  void display() {
    if (isEmpty()) {
      cout << "Queue is Empty" << endl;
      return;
    }

    int i = front;
    while (true) {
      cout << arr[i] << " ";
      if (i == rear) break;
      i = (i + 1) % size;
    }
    cout << endl;
  }

  char peek() {
    if (!isEmpty()) {
      return arr[front];
    }
    else return -1;
  }
};

int main() {
  string characters = "aabc";
  int size = characters.length();
  CircularQueue Q(size);
  int freq[256] = {0};

  for (char c : characters) {
    freq[c]++;
    Q.enqueue(c);

    while (!Q.isEmpty() && freq[Q.peek()] > 1) {
      Q.dequeue();
    }

    if (Q.isEmpty()) {
      cout << -1 << " ";
    }
    else {
      cout << Q.peek() << " ";
    }
  }
}
