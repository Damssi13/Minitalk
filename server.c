#include "minitalk.h"

static int i;
static char c;
int bit;

void    sig_handler(int sig)
{
    if(sig == SIGUSR1)
        bit = 1;
    else if(sig == SIGUSR2)
        bit = 0;
    
    while(i < 8)
    {
        c = (c << 1)| bit;
        i++;
    }
    write(1, &c, 1);
}

int main()
{
    pid_t mypid;

    mypid =  getpid();
    printf("this is my pid :%d\n",mypid);

    // signal(SIGQUIT, print_it);
    while(1)
    {
        signal(SIGUSR1, sig_handler);
        signal(SIGUSR2, sig_handler);
    
        usleep(1000);
    }
    return 0;
}