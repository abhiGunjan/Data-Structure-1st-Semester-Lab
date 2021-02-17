#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX 20
int stack[MAX];
int top = -1;
void push(int element);
int pop();
bool is_palindrome(str);
void display();
bool is_full();
bool is_empty();
int main(){
    int choice,element;
    char str[20];
    while(1)
    {
        printf("\t1.Push an element\n");
        printf("\t2.Pop an element\n");
        printf("\t3.Check Palindrome\n");
        printf("\t4.Display all elements of stack\n");
        printf("\t5.Check overflow\n");
        printf("\t6.Check underflow\n");
        printf("\t7.Quit\n");
        printf("Enter the desired option: ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("Enter element to push: ");
            scanf("%d",&element);
            push(element);
            break;
        case 2:
            element = pop(element);
            printf("Item %d is removed\n",element);
            break;
        case 3:
            printf("Enter string to check palindrome: ");
            scanf("%s",str);
            if(is_palindrome(str)){
            printf("The string %s is palindrome\n",str);
           }
           else
            printf("The string %s is not palindrome\n",str);
            break;
        case 4:
            display();
            break;
        case 5:
            if(is_full()){
                printf("Stack overflow\n");
            }
            else
                printf("No overflow\n");
            break;
        case 6:
            if(is_empty())
            {
                printf("Stack Underflow\n");
            }
            else
                printf("No underflow\n");

            break;
        case 7:
            exit(1);
        default:
            printf("Invalid choice\n");
        }

    }
return 0;
}
void push(int element)
{
   if(!is_full())
    {
        top++;
        stack[top] = element;

    }
    else
        printf("Stack overflow\n");

}
int pop(){
    if(!is_empty())
    {
        int item;
        item = stack[top];
        top--;
        return item;
    }
    else
        printf("Stack underflow\n");
        exit(0); //to terminates the calling process(avoiding return)

}
void display(){
    if(is_empty())
    {
        printf("No element in Stack\n");
    }
    int i;
    for(i = top;i>=0;i--){
        printf("%d\n",stack[i]);
    }
}
bool is_full()
{
    if(top == MAX-1){
        return true;
    }
    else
        return false;
}
bool is_empty(){
    if(top == -1){
        return true;
    }
    else
        return false;
}
bool is_palindrome(char str[20])
{
    int i,len = strlen(str);
    for(i = 0;i<len;i++)
    {
        push(str[i]);
    }
    for(i = 0;i<len;i++)
    {
        if(pop() != str[i])
        {
            return false;
        }
    }
    return true;
}
