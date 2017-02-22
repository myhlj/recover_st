#include <stdlib.h>
#include <assert.h>
#include "gStack.h"
#include <string.h>

#define fir 1
#define sec 2
#define thr 3
#define fou 4

void StackNew(stack* s,int elemsize,void(*release)(void*))
{
	s->elemsize = elemsize;
	s->loglength = 0;
	s->alloclength = 4;
	s->elems = malloc(4*s->elemsize);

	s->release = release;

	assert(s->elems!=NULL);
}


int StackEmpty(stack* s)
{
	return s->loglength;
}

void StackTop(stack* s,void* target)
{
	if(s->loglength > 0)
	{
		void* source = (char*)s->elems + ((s->loglength-1) * s->elemsize);
		memcpy(target,source,s->elemsize);
	}
}

void StackDispos(stack* s)
{
	if(s->release != NULL)
	{
		int i = 0;
		for(i;i<s->loglength;i++)
		{
			s->release( (char*)s->elems + (i * s->elemsize));
		}
	}
	free(s->elems);
}

void StackPush(stack* s,void* elem)
{
	if(s->loglength == s->alloclength)
	{
		s->alloclength*=2;
		s->elems = realloc(s->elems,s->alloclength);
		assert(s->elems!=NULL);
	}

//	(char*)((char*)s->elems + (s->elemsize*s->loglength)) = elem;
	void *addr = (char*)s->elems + (s->elemsize*s->loglength);
	memcpy(addr,elem,s->elemsize);
	s->loglength++;
}


void  StackPop(stack *s,void* destelem)
{
	if(s->loglength>0)
	{
		s->loglength--;
		void* source = (char*)s->elems + (s->loglength * s->elemsize);
		memcpy(destelem,source,s->elemsize);
	}
}

struct Data
{
	int first;
	double seconed;
	long third;
};
typedef struct Data* pData;


void Release(void* elem)
{
	free(*((struct Data**)elem));
}

int main()
{
	
	stack example;
	StackNew(&example,sizeof(char*),NULL);
	char* str = "123456";
	char* str1 = "hjklmn";
	StackPush(&example,&str);
	StackPush(&example,&str1);
	char* dest = NULL;
	StackPop(&example,&dest);
	printf("%s\n",dest);
	/*
	double x = 4.5;
	double y = 3.1415926;
	double z = 3.23879;
	double re = 0;
	StackNew(&example,sizeof(double));
	StackPush(&example,&x);
	StackPush(&example,&y);
	StackPush(&example,&z);
	StackPop(&example,&re);
//	StackPop(&example,&x);
	printf("%f\n",re);
	StackDispose(&example);
	stack strexample;
	char *str1="123456";
	char *str2="abcee";
	char *str3="mjkl";
	StackNew(&strexample,sizeof(char*));
	StackPush(&strexample,str1);
	StackPush(&strexample,str2);
	StackPush(&strexample,str3);
	char result[255];
	StackPop(&strexample,result);
	printf("%s\n",result);
	StackDispose(&strexample);

	const char* friends[] = {"ai","bi","ci"};
	stack stringStack;
	StackNew(&stringStack,sizeof(char*));
	int i=0;
	for(i;i<3;i++)
	{
		char* copy = strdup(friends[i]);//深拷贝并复制相当于malloc,memcpy
		StackPush(&stringStack,&copy);
	}
	char* name;
	int j=0;
	for(j;j<3;j++)
	{
		StackPop(&stringStack,&name);
		printf("%s\n",name);
		free(name);
	}
	StackDispose(&stringStack);
	*/
	stack s;
	StackNew(&s,sizeof(struct Data*),Release);
	pData one = malloc(sizeof(struct Data));
	pData two = malloc(sizeof(struct Data));
	one->first=1;one->seconed=89;one->third=78;
	two->first=2;two->seconed=2.089;two->third=678;

	StackPush(&s,&one);StackPush(&s,&two);
//	pData pDest=NULL;
//	StackPop(&s,&pDest);
//	printf("%d\n",pDest->first);
//	printf("%f\n",pDest->seconed);
//	printf("%d\n",pDest->third);
	StackDispos(&s);

/*
	const char notes[10]="[](){}[)]";

	int i=0;
	for(i;i<9;i++)
	{
		if(notes[i] == '[' || notes[i] == '('
				|| notes[i] == '{')
		{
			char c = notes[i];
			StackPush(&s,&c);
		}
		if(notes[i] == ']' || notes[i] == ')'
				|| notes[i] == '}')
		{
			char target;
			StackPop(&s,&target);
			if(notes[i] == ']' && target != '[')
				printf("位置:%d符号:%c\n",i,notes[i]);
			else if(notes[i] == ')' && target != '(')
				printf("位置:%d符号:%c\n",i,notes[i]);
			else if(notes[i] == '}' && target != '{')
				printf("位置:%d符号:%c\n",i,notes[i]);
		}
	}
	//后缀表达式的应用
//	const char houzhui[]="6523+8*+3+*";
//	i = 0;

	while(StackEmpty(&s))
	{
		char value;
		StackPop(&s,&value);
	}

	char target[] = "(1+4)*6+8*7+5";
	char output[256]={0};
	char top = '0';
	i = 0;
	int j = 0;
	for(i;i<13;i++)
	{
		StackTop(&s,&top);

		char c = target[i];
		if(c>='0' && c<='9')
		{
			output[j++] = c;
			continue;
		}
		else if( c=='+' || c=='*' || c=='(' || c==')' || c=='-' || c=='/')
		{

			int flag = StackEmpty(&s);
			if(!flag)
			{
				StackPush(&s,&c);
				continue;
			}
			
			int num;
			switch(c)
			{
				case '+':
					num = fir;
					break;
				case '-':
					num = fir;
					break;
				case '*':
					num = sec;
					break;
				case '/':
					num = sec;
					break;
				case '(':
					num = thr;
					break;
				case ')':
					num = fou;
					break;
				default:
					num = 0;
					break;
			}
			
			int num1;
			char top;
			StackTop(&s,&top);
			switch(top)
			{
				case '+':
					num1 = fir;
					break;
				case '-':
					num1 = fir;
					break;
				case '*':
					num1 = sec;
					break;
				case '/':
					num1 = sec;
					break;
				case '(':
					num1 = thr;
					break;
				case ')':
					num1 = fou;
					break;
				default:
					num1 = 0;
					break;
			}
			
			if(num1 == thr)
			{
				StackPush(&s,&c);
			}
			else if(num1 < num && num != fou)
			{
				StackPush(&s,&c);
			}
			else if( (num1 > num || num1 == num) && num1 != thr)
			{
				StackPop(&s,&top);
				output[j++] = top;
				while(StackEmpty(&s))
				{
					StackTop(&s,&top);
					switch(top)
					{
					case '+':
						num1 = fir;
						break;
					case '-':
						num1 = fir;
						break;
					case '*':
						num1 = sec;
					break;
					case '/':
						num1 = sec;
					break;
					case '(':
						num1 = thr;
						break;
					case ')':
						num1 = fou;
						break;
					default:
						num1 = 0;
					break;
					}
					if((num1 > num || num1 == num) && num1 != thr)
					{
						StackPop(&s,&top);
						output[j++] = top;	
					}
					else
					{
						break;
					}
				}

				StackPush(&s,&c);
			}
			else if( num == fou )
			{
				while(StackEmpty(&s))
				{
					StackTop(&s,&top);
					if(top == '(')
					{
						StackPop(&s,&top);
						break;
					}
					else 
					{
						StackPop(&s,&top);
						output[j++] = top;
					}
				}

			}
		}


//			switch(c)
//			{
				
//					break;
//				case '*':
//					{
//						if(!flag)
//						{
//							StackPush(&s,&c);
//						}
//						else
//						{
//							switch(top)
//							{
//								case '+':
//									StackPush(&s,&c);
//									break;
//								case '*':
//									output[j++]=c;
//									break;
//								case '(':
///									StackPush(&s,&c);
//									break;
//								case ')':
//									while(StackEmpty(&s))
//									{
//										StackPop(&s,&top);
//										if(top!='(')
//											output[j++] = top;
//										else 
//											break;
//									}
//									break;
//								default:
//									break;
//							}
//						}
//					}
//					break;
//				case '(':
//					{
//						StackPush(&s,&c);	
//					}
//					break;
//				case ')':
//					{
//						while(StackEmpty(&s))
//						{
//							StackPop(&s,&top);
//							if(top!='(')
//							{
//								output[j++] = top;
//							}
//							else
//							{
//								break;
//							}
//						}
//					}
//					break;
//				default:
//					break;
//			}
//		}
	}
	
	char temp;
	while(StackEmpty(&s))
	{
		StackPop(&s,&temp);
		output[j++] = temp;
	}
	printf("%s\n",output);
	*/
	return 0;
}
