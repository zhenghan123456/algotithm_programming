#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;

struct Stack {
    int data[maxn];
    int top = -1;
    int size = 0;

    void push(int x) {
        data[++top] = x;
        size++;
    }

    int pop() {
        top--;
        return data[top + 1];
    }

    int top() {
        return data[top];
    }
};
