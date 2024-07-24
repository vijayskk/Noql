#include <stdlib.h>

typedef struct Token{
    char content[30];
    size_t length;
} Token;

typedef struct CommandBuffer{
    Token tokens[10];
    int tokencount;
}CommandBuffer;

void handleExit(){
    printf("bye\n");
}


// -----------------Process Here------------------------------


void processCommand(CommandBuffer * cmdBuff){
    if ( strcmp( cmdBuff->tokens[0].content,"exit") == 0 && cmdBuff->tokencount == 1)
    {
        atexit(handleExit);
        exit(0);
    }else if( strcmp(cmdBuff->tokens[0].content,"create") == 0 ){
        if (cmdBuff->tokencount == 2 && strcmp(cmdBuff->tokens[1].content,"") != 0 )
        {
            printf("DB %s created.",cmdBuff->tokens[1].content);
        }else{
            printf("ERROR: A DB name expected!!!");
        }
    }else if( strcmp(cmdBuff->tokens[0].content,"use") == 0 ){
        if (cmdBuff->tokencount == 2 && strcmp(cmdBuff->tokens[1].content,"") != 0 )
        {
            printf("DB %s is active now.",cmdBuff->tokens[1].content);
        }else{
            printf("ERROR: A DB name expected!!!");
        }
    }
    else if( strcmp(cmdBuff->tokens[0].content,"insert") == 0 ){
        if (cmdBuff->tokencount > 2 && strcmp(cmdBuff->tokens[1].content,"into") == 0 )
        {
            printf("Inserting into %s.",cmdBuff->tokens[2].content);
        }else{
            printf("ERROR: Bad Command!!!");
        }
    }else{
        printf("ERROR: Bad Command!!!");
    }
}