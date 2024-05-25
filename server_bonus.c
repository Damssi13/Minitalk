/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reddamss <reddamss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 20:18:07 by reddamss          #+#    #+#             */
/*   Updated: 2024/05/25 21:56:15 by reddamss         ###   ########.fr       */
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

void	put_error(char *str)
{
	int	i;

	i = 0;
	write(2, "Erorr:\n", 7);
	while (str[i])
	{
		write(2, &str[i], 1);
		i++;
	}
	exit(1);
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
		if (c == '\0')
			if (kill(info->si_pid, SIGUSR1) == -1)
				put_error("kill function failed !");
		write(1, &c,1);
		i = 0;
		c = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;
	pid_t				mypid;

	sa.sa_sigaction = &sig_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	mypid = getpid();
	ft_putnbr(mypid);
	write(1, " = PID\n", 7);
	while (1)
	{
		pause();
	}
	return (0);
}
