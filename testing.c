#include "minitalk.h"

void    ft_error(char *str)
{   
    int i;

    i = 0;
    write(2, "Error\n", 6);
    while(str[i])
    {
        write(2,&str[i], 1);
        i++;
    }
    exit(0);
}

int main(int ac, char **av)
{
    size_t i;
    size_t bit;
    pid_t mypid;    

    i = 0;
    if(ac != 3)
        ft_error("Arguments Probelm !");
    mypid = atoi(av[1]);
    if(mypid == -1 || mypid == 0)
        ft_error("PID is not valid !");
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

    // kill(mypid, SIGQUIT);
    return(0);
}
