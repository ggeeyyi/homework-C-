#include <stdio.h>
#define STACK_SIZE 100  //定义了栈的最大的元素个数为100
struct Stack    //构造栈的结构体
{
    int top; //栈顶，用于操作栈的指针
    int buffer[STACK_SIZE]; //栈的缓冲区（储存区）
};
bool stack_push(struct Stack *s,int i)  //进栈（栈的插入操作）
{
    if(s->top==STACK_SIZE-1)  //判断指针top是否指向最大元素个数
    {
        printf("Stack is overflow.\n"); //如果是，则为满栈
        return false;
    }
    else
    {
        s->buffer[++(s->top)]=i;  //若不是,栈顶指针增加一，并将新插入元素赋值给栈顶空间
        return true;
    }
}

bool stack_pop(struct Stack *s,int *i) //出栈（栈的删除操作）
{
    if(s->top==-1)  //判断top是否指向栈底
    {
        printf("Stack is empty.\n");  //若是，则为空栈
        return false;
    }
    else
    {
        *i=s->buffer[(s->top)--]; //若栈不空，栈顶指针减一，输出top的下一个元素，
        return true;
    }
}

int main()
{
    struct Stack st1,st2;
    int x;
    st1.top=-1;   //定义st1的栈底
    st2.top=-1;   //定义st2的栈底

    stack_push(&st1,12); //向st1中加入12这一个元素
    stack_pop(&st1,&x);  //从st1这个栈中读取一个元素x
    //printf("%d",x);
    stack_push(&st2,20); //从st2中加入20这一个元素
    stack_pop(&st2,&x);  //从st2这个栈中读取一个元素x
    //printf("%d",x); 若加入输出后可发现输出为12 20
    return 0;
}