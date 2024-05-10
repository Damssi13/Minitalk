#include "minitalk.h"
#include <signal.h>

static int i;
static char c;

void    handler1(int sig)
{
    if(sig == SIGUSR1)
        c = c << 1;
    usleep(50);
}

void    print_it(int sig)
{   
    (void)sig;
    printf("%c", c);
}

void    handler0(int sig)
{
    (void)sig;
    c += 0;
    usleep(50);
}

int main()
{
    pid_t mypid;

    mypid =  getpid();
    printf("this is my pid :%d\n",mypid);
    signal(SIGUSR1, handler0);
    signal(SIGUSR2, handler1);
    signal(SIGQUIT, print_it);
    while(1)
    {
        printf("waiting for a signal...\n");
        sleep(1);
    }
    return 0;
}