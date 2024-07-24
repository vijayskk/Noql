#include "../lib/ipmanagement.h"
#include "../lib/startupmgr.h"

int main()
{
    InputBuffer * buff = new_ipbuff();
    welcomeMessage();
    while (1==1)
    {
        print_prompt();
        read_ipbuff(buff);
        processCommand(buff);
    }
    
    return 0;
}
