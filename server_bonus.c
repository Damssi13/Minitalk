#include "minitalk_bonus.h"

void    ft_putchar(char c)
{
    write(1, &c,1);
}

void    ft_putnbr(int n)
{
    if(n == -2147483648)
        write(1, "-2147483648", 11);
    if(n < 0)
    {
        ft_putchar('-');
        n *= -1;
    }
    if(n > 9)
    {
        ft_putnbr(n / 10);
        ft_putnbr(n % 10);
    }
    if(n < 10)
        ft_putchar(n + 48);

}

void    sig_handler(int sig)
{
    static char c;
    static int i;
    
    if (sig == SIGUSR1)
        c = (c << 1) | 1;
    else
        c = (c << 1);
    i++;
    if (i == 8)
    {
        write(1, &c, 1);
        i = 0;
        c = 0;
    }
}

int main()
{
    pid_t mypid;

    mypid =  getpid();
    ft_putnbr(mypid);
    write(1," = PID\n",7);
    signal(SIGUSR1, sig_handler);
    signal(SIGUSR2, sig_handler);

    while(1)
    {
        pause();
    }
    return 0;
}