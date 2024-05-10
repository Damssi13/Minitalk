#include "minitalk.h"

size_t  ft_strlen(char *str)
{
    int i;

    i = 0;
    while(str[i])
        i++;
    return (i);
}


int main(int ac, char **av)
{
    size_t  len;
    size_t i;
    size_t shift;


    shift = 7;
    
    len = ft_strlen(av[2]);
    if(ac != 3)
        return 0;
    i = 0;
    while(i < len)
    {
        while(shift)
        {
            if((av[1][i] >> shift) == 0)
                kill(av[1], SIGUSR1);

        }
    }
    return 0;
}