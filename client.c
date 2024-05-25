#include "minitalk.h"

int     ft_atoi(char *str)
{
    int i;
    int sign;
    int number;

    sign = 1;
    i = 0;
    while((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
        i++;
    if(str[i] == '+' || str[i] == '-')
    {
        if (str[i] == '-')
            sign *= -1;
        i++;
    }
    number = 0;
    while(str[i] >= 48 && str[i] <= 57)
    {
        number *= 10;
        number += str[i] - 48;
        i++;
    }
    return(number * sign);
}

size_t    ft_strlen(char *str)
{
    size_t i;

    i = 0;
    while(str[i])
        i++;
    return (i);
}

void    ft_error(char *str)
{
    int i;

    i = 0;
    write(2, "Erorr:\n", 7);
    while(str[i])
    {
        write(2, &str[i], 1);
        i++;
    }
    exit(1);
}

void    send_signal(pid_t pid, char *str, size_t len)
{
    size_t i;
    int shift;
    
    i = 0;
    while(i < len)
    {
        shift = 7;
        while(shift >= 0)
        {
            if((str[i] >> shift) & 1)
            {
                if(kill(pid, SIGUSR1) == -1)
                    ft_error("kill function failed !");
            }
            else
                if(kill(pid, SIGUSR2) == -1)
                    ft_error("kill function failed !");
            usleep(650);
            shift--;
        }
        i++;
    }
}

int main(int ac, char **av)
{
    pid_t pid;

    if (ac != 3 || !av[2][0])
        ft_error("Arguments Problem !");
    pid = ft_atoi(av[1]);
    if (pid == -1 || pid == 0 || pid >= 4194304)
        ft_error("PID is not valid !");
    send_signal(pid, av[2], ft_strlen(av[2]));
    
    
}