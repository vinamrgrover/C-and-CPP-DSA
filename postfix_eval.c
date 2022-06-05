#include<stdio.h> 
#include<stdlib.h> 
#include<ctype.h> 
#include<string.h>
#include<stdbool.h>
struct stack
{
		int top; 
		unsigned int capacity; 
		int *array; 
}; 
struct stack *create_stack(const unsigned int capacity)
{
		struct stack *new_stack = (struct stack *)malloc(sizeof(struct stack)); 
		new_stack -> top = -1; 
		new_stack -> capacity = capacity; 
		new_stack -> array = (int *)malloc(sizeof(int)*capacity); 
		return new_stack; 
}

bool isEmpty(struct stack *new_stack)
{
		return new_stack->top == -1; 
}

void push(struct stack *new_stack, const char x)
{
		++new_stack->top; 
		new_stack->array[new_stack->top] = x; 
}
char pop(struct stack *new_stack)
{
		--new_stack->top;
		return new_stack->array[new_stack->top+1]; 
}

int post_fix(char *str)
{
		struct stack *new_stack=create_stack(strlen(str)); 

		for(int i=0; str[i]; ++i)
		{
				if(isdigit(str[i]))		
						push(new_stack, str[i] - '0'); /*converts the character to the digit*/
				else
				{
						int a = pop(new_stack); 
						int b = pop(new_stack); 

						switch(str[i])
						{
								case '+':
										{
												int val = b+a; 
												push(new_stack, val); 
												break; 
										}

								case '-':
										{				
												int val = b-a; 
												push(new_stack, val); 
												break; 
										}

								case '*':
										{
												int val = b * a; 
												push(new_stack, val); 
												break;
										}

								case '/':
										{
												int val = b/a; 
												push(new_stack, val); 
												break; 
										}
						}

				}
		}
		return pop(new_stack); 
}

int main()
{
		char str[]="231*+9-"; 
		printf("POSTFIX = %d\n", post_fix(str)); 
		return 0; 
}

		
