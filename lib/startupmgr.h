#include <stdio.h>
#include "../lib/defenitions.h"

extern void welcomeMessage(){
    printf("\x1b[2J");
    printf("\x1b[H");
    printf("%s -- version %s",PROJECT_NAME,PROJECT_VERSION);
}