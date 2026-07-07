class myStack {
public:
    int *arr;
    int top;
    int size;

    myStack(int n) {
        size = n;
        arr = new int[size];
        top = -1;
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == size - 1;
    }

    void push(int x) {
        if (!isFull()) {
            arr[++top] = x;
        }
    }

    void pop() {
        if (!isEmpty()) {
            top--;
        }
    }

    int peek() {
        if (isEmpty())
            return -1;
        return arr[top];
    }
};