/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atouba <atouba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 10:45:42 by atouba            #+#    #+#             */
/*   Updated: 2022/05/09 12:27:01 by atouba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Header/header.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		write(1, &s[i++], 1);
}

void	ft_putnbr(int n)
{
	long long	res;

	res = n;
	if (res >= 0 && res <= 9)
	{
		ft_putchar(res + '0');
	}
	if (res < 0)
	{
		ft_putchar('-');
		res *= -1;
		if (res >= 0 && res <= 9)
		{
			ft_putchar(res + '0');
			return ;
		}
	}
	if (res >= 10)
	{
		ft_putnbr(res / 10);
		ft_putchar((res % 10) + '0');
	}
}
