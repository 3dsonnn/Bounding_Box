/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 13:02:30 by efinda            #+#    #+#             */
/*   Updated: 2024/06/07 13:02:33 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

void	ft_putchar(char c, int *res)
{
	write(1, &c, 1);
	(*res)++;
}

void	ft_putstr(char *s, int *res)
{
	if (!s)
		ft_putstr("(null)", res);
	else
	{
		while (*s)
		{
			ft_putchar(*s, res);
			s++;
		}
	}
}

void	ft_putnbr(int nbr, int *res)
{
	if (nbr == INT_MAX)
		ft_putstr("-2147483648", res);
	else if (nbr < 0)
	{
		ft_putchar('-', res);
		nbr *= -1;
		ft_putnbr(nbr, res);
	}
	else if (nbr > 9)
	{
		ft_putnbr((nbr / 10), res);
		ft_putchar(((nbr % 10) + 48), res);
	}
	else
		ft_putchar((nbr + 48), res);
}

void	ft_printbase(unsigned long long nbr, char *simbol,
			int *res, unsigned int base)
{
	if (nbr >= base)
		ft_printbase(nbr / base, simbol, res, base);
	ft_putchar(simbol[nbr % base], res);
}

void	ft_printptr(void *ptr, int *res)
{
	unsigned long	p;

	p = (unsigned long)ptr;
	if (ptr)
	{
		ft_putstr("0x", res);
		ft_printbase(p, "0123456789abcdef", res, 16);
	}	
	else
		ft_putstr("(nil)", res);
}		
