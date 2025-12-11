// sort the stack using recursion and without using extra space

#include <bits/stdc++.h>
using namespace std;

void sortedInsert(stack<int> &stack, int num) {
    //base case
    if(stack.empty() || (!stack.empty() && stack.top() < num) ) {
        stack.push(num);
        return;
    }
    
    int n = stack.top();
    stack.pop();
    
    //recusrive call
    sortedInsert(stack, num);
    
    stack.push(n);
}

void sortStack(stack<int> &stack)
{
		//base case
    	if(stack.empty()) {
            return ;
        }
    
    	int num = stack.top();
    	stack.pop();
    
    	//recursive call
    	sortStack(stack);
    
    	sortedInsert(stack, num);
}

int main()
{
    stack<int> s;
    s.push(2);
    s.push(-4);
    s.push(9);
    s.push(6);

    sortStack(s);
    return 0;
}
