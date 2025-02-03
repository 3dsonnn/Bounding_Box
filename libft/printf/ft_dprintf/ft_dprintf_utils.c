/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 13:02:30 by efinda            #+#    #+#             */
/*   Updated: 2024/06/07 13:02:33 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

void	ft_dputchar(int fd, char c, int *res)
{
	write(fd, &c, 1);
	(*res)++;
}

void	ft_dputstr(int fd, char *s, int *res)
{
	if (!s)
		ft_dputstr(fd, "(null)", res);
	else
	{
		while (*s)
		{
			ft_dputchar(fd, *s, res);
			s++;
		}
	}
}

void	ft_dputnbr(int fd, int nbr, int *res)
{
	if (nbr == INT_MAX)
		ft_dputstr(fd, "-2147483648", res);
	else if (nbr < 0)
	{
		ft_dputchar(fd, '-', res);
		nbr *= -1;
		ft_dputnbr(fd, nbr, res);
	}
	else if (nbr > 9)
	{
		ft_dputnbr(fd, (nbr / 10), res);
		ft_dputchar(fd, ((nbr % 10) + 48), res);
	}
	else
		ft_dputchar(fd, (nbr + 48), res);
}

void	ft_dprintbase(int ptr[2], unsigned long long nbr, char *simbol,
			int *res)
{
	if (nbr >= (unsigned long long)ptr[1])
		ft_dprintbase(ptr, nbr / ptr[1], simbol, res);
	ft_dputchar(ptr[0], simbol[nbr % ptr[1]], res);
}

void	ft_dprintptr(int fd, void *ptr, int *res)
{
	int				pt[2];
	unsigned long	p;

	pt[0] = fd;
	pt[1] = 16;
	p = (unsigned long)ptr;
	if (ptr)
	{
		ft_dputstr(fd, "0x", res);
		ft_dprintbase(pt, p, "0123456789abcdef", res);
	}	
	else
		ft_dputstr(fd, "(nil)", res);
}
