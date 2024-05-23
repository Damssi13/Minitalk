#include "minitalk.h"

size_t  ft_strlen(char *str)
{
    int i;

    i = 0;
    while(str[i])
        i++;
    return (i);
}

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
    size_t  len;
    size_t  i;
    size_t  shift;


    
    len = ft_strlen(av[2]);
    if(ac != 3)
        ft_error("Arguments problem !!");

    i = 0;
    while(i < len)
    {
        shift = 7;
        while((av[2][i] >> 7)& 1)
            kill(av[1], SIGUSR1);//sigusr1 = 1
            
    }

}