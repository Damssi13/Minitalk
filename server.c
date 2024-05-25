/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reddamss <reddamss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 20:18:10 by reddamss          #+#    #+#             */
/*   Updated: 2024/05/25 21:33:47 by reddamss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	if (n == -2147483648)
		write(1, "-2147483648", 11);
	if (n < 0)
	{
		ft_putchar('-');
		n *= -1;
	}
	if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	if (n < 10)
		ft_putchar(n + 48);
}

void	sig_handler(int sig, siginfo_t *info, void *ucontext)
{
	static char	c;
	static int	i;
	static int	pid;

	(void)ucontext;
	if (pid != info->si_pid)
	{
		pid = info->si_pid;
		c = 0;
		i = 0;
	}
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

int	main(void)
{
	struct sigaction	sa;
	pid_t				mypid;

	mypid = getpid();
	sa.sa_sigaction = &sig_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_putnbr(mypid);
	write(1, " = PID\n", 7);
	while (1)
	{
		pause();
	}
	return (0);
}
