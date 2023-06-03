#include <iostream>
#include <string>

using namespace std;

struct StackNode
{
    char value;
    StackNode* next;
};

StackNode* newNode(char value)
{
    StackNode* stackNode = new StackNode();
    stackNode->value = value;
    stackNode->next = NULL;
    return stackNode;
}


bool is_not_Empty(StackNode* pointer)
{
    return pointer;
}

void push(StackNode** pointer, char new_data){
   StackNode* stackNode = newNode(new_data);
   stackNode->next = *pointer;
   *pointer = stackNode;
}
  
void pop(StackNode** pointer){
   StackNode* temp = *pointer;
   *pointer = (*pointer)->next;
   delete temp;
}

char top(StackNode* pointer) {
    return pointer->value;
}

bool revision(string str, StackNode* stack) {
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '(' || str[i] == '[')
        {
            push(&stack, str[i]);
        }

        else if (str[i] == ')' && is_not_Empty(stack) && top(stack) == '(')
        {
            pop(&stack);
        }

        else if (str[i] == ']' && is_not_Empty(stack) && top(stack) == '[')
        {
            pop(&stack);
        }

        else {
            return false;
        }
    }

    if (!is_not_Empty(stack))
    {
        return true;
    }

    else
    {
        return false;
    }
}
  
int main()
{
    string str;
    while (getline(cin, str))
    {
        StackNode* stack = NULL;
        if(revision(str, stack))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}
