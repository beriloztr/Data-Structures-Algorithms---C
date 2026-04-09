//
// Stack Implementation, CTIS 152
//
#define STACK_SIZE  100

typedef int SType;

SType  STACK_EMPTY = -987654321;

typedef struct
{	int	top;
	SType data[STACK_SIZE];
} stack_t;

//Functions in this file...
void initializeS (stack_t *s);
int isEmptyS (stack_t *s);
int isFullS (stack_t *s);
void push (stack_t *s, SType item);
SType pop (stack_t *s);

//------------------------------------------------------------------------------

void DisplayStack(stack_t S)
{
	int temp;
	while(!isEmptyS(&S)){
		temp = pop(&S);
		printf("%d\n", temp);
	}
}

//------------------------------------------------------------------------------

void initializeS (stack_t *s)
{
	s->top = -1;
}

//------------------------------------------------------------------------------

int CountStack(stack_t S)
{
	int count = 0;
	while (S.top != -1)
	{
		count++;
		S.top--;
	}
	return count;
}
//------------------------------------------------------------------------------

void RemMaxStack(stack_t *S)
{
	stack_t Stemp;
	initializeS(&Stemp);
	int temp;
	int max;

	temp = pop(S);
	max = temp;
	push(&Stemp, temp);

	while (!isEmptyS(S))
	{
		temp = pop(S);
		if (max < temp)
			max = temp;
		push(&Stemp, temp);
	}
	
	while (!isEmptyS(&Stemp))
	{
		temp = pop(&Stemp);
		if (temp != max)
			push(S, temp);
	}
}

//------------------------------------------------------------------------------
void SendNthToEnd(stack_t* S, int n)
{
	stack_t Stemp;
	initializeS(&Stemp);
	int t, x; //temp
	
	int i = 1;
	while (!isEmptyS(S))
	{
		t = pop(S);
		if (i == n)
			x = t;
		else
			push(&Stemp, t);
		i++;
	}
	push(S, x);
	while (!isEmptyS(&Stemp))
	{
		push(S, pop(&Stemp));
	}
}


//------------------------------------------------------------------------------

int isEmptyS (stack_t *s)
{
	if (s->top == -1)
		return 1;
	return 0;
}

//------------------------------------------------------------------------------

int isFullS (stack_t *s)
{
	if (s->top == STACK_SIZE - 1)
		return 1;
	return 0;
}

//------------------------------------------------------------------------------

void push (stack_t *s, SType item)
{
	if (isFullS (s))
		printf("Error: Stack is full!\n");
	else
	{
		(s->top)++;
		s->data[s->top] = item;
	}
}

//------------------------------------------------------------------------------

SType pop (stack_t *s)
{
	SType item;
	if (isEmptyS(s))
	{	printf("Error: Stack is empty!\n");
		item = STACK_EMPTY;	
	}
	else
	{	item = s->data[s->top];
		(s->top)--;
	}		    	
	return (item);
}
