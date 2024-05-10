#include "minitalk.h"

int main(int ac, char **av)
{
    (void)ac;
    size_t i;
    size_t bit;

    i = 0;
    
    pid_t mypid = atoi(av[1]);
    if(mypid == -1 || mypid == 0)
        return 0;
    while(av[2][i])
    {
        bit = 1;
        while(bit < 8)
        {
            if((av[2][i] << bit) & 1)
                kill(mypid,SIGUSR1);
            else
                kill(mypid,SIGUSR2);
            bit++;
        }
        i++;
    }

    kill(mypid, SIGQUIT);
    return(0);
}