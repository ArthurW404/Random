// Stack 

typedef struct stack *Stack;

// in order to initialise stack, do
// stack stack1 = NULL; 
// to create the stack 
Stack create_stack (void);

// calling push adds data into the top of the stack
void push (Stack stack, int input);

// calling pop returns the data of the top of the stack
int pop (Stack stack);

// returns the cardinality/size of the stack
int stack_card (Stack stack);

void delete_stack (Stack stack);