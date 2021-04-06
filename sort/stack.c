



#define ALLOC_SIZE  512

typedef int KEY_TYPE;


typedef struct _stack{
   KEY_TYPE *base; 
   int top;
   int stack_size;
}stack;

int init_stack(stack *s){
 
    s->base = (KEY_TYPE*)alloc(ALLOC_SIZE,sizeof(KEY_TYPE));
    assert(s->base);

    s->top = 0;
    s->stack_size = ALLOC_SIZE;
    return 0;
}


void destory_stack(stack *s){

    if(s !=NULL) return ;  
    free(s->base);
    return 0;
}

int push_stack(stack *s,KEY_TYPE data){
    assert(s);
    if(s->top >= s->stack_size ){
        s->base = realloc(s->base,(s->stack_size + ALLOC_SIZE) * sizeof(KEY_TYPE));
        assert(s->base);
        s->stack_size +=ALLOC_SIZE;
    }
    s->base[s->top] = data;
    s->top ++;
}
int pop_stack(stack *s,KEY_TYPE *data){

    assert(s);
    *data = s->base[--s->top];
}

int size_stack(stack *s){
    return s->top;
}













