class MyStack {
private:
    int q1[100], front1, rear1;
    int q2[100], front2, rear2;

public:
    MyStack() {
        front1 = 0; rear1 = -1;
        front2 = 0; rear2 = -1;
    }

    void push(int x) {
        front2 = 0;
        rear2 = -1;
        rear2++;
        q2[rear2] = x;

        while (front1 <= rear1) {
            rear2++;
            q2[rear2] = q1[front1];
            front1++;
        }

        front1 = 0;
        rear1 = -1;
        while (front2 <= rear2) {
            rear1++;
            q1[rear1] = q2[front2];
            front2++;
        }
    }

    int pop() {
        int topVal = q1[front1];
        front1++;
        return topVal;
    }

    int top() {
        return q1[front1];
    }

    bool empty() {
        return front1 > rear1;
    }
};
