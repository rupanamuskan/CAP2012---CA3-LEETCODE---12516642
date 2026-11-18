class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int top = -1; 
        int j = 0;    

        for (int i = 0; i < pushed.size(); i++) {
            top++;
            pushed[top] = pushed[i]; 

            while (top >= 0 && pushed[top] == popped[j]) {
                top--; 
                j++;
            }
        }
        return top == -1;
    }
};
