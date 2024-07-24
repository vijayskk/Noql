#include <stdio.h>
#include <stdlib.h>

typedef struct InputBuffer {
    char * buffer;
    size_t buf_size;
    size_t inputlen;
} InputBuffer;

extern InputBuffer * new_ipbuff(){
    InputBuffer * buff = (InputBuffer *) malloc(sizeof(InputBuffer));
    buff->buffer = NULL;
    buff->buf_size = 0;
    return buff;
}

extern void read_ipbuff(InputBuffer * buff){
    int byteread = getline(&buff->buffer,&buff->buf_size,stdin);
    buff->inputlen = byteread - 1;
    buff->buffer[buff->inputlen] = 0;
}

extern void debug_ipbuff(InputBuffer * buff){
    printf("\nCommand : %s,Length: %zu",buff->buffer,buff->inputlen);
}

extern void print_prompt(){
    printf("\n>> ");
}