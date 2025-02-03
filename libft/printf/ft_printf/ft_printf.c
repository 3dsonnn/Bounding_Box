/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 13:01:32 by efinda            #+#    #+#             */
/*   Updated: 2024/06/07 13:01:39 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

static	void	ft_check_identif(va_list args, const char *s, int *res)
{
	if (*s == 'c')
		ft_putchar(va_arg(args, int), res);
	else if (*s == 's')
		ft_putstr(va_arg(args, char *), res);
	else if (*s == 'd' || *s == 'i')
		ft_putnbr(va_arg(args, int), res);
	else if (*s == 'x')
	{
		ft_printbase(va_arg(args, unsigned int),
			"0123456789abcdef", res, 16);
	}
	else if (*s == 'X')
	{
		ft_printbase(va_arg(args, unsigned int),
			"0123456789ABCDEF", res, 16);
	}
	else if (*s == 'u')
	{
		ft_printbase(va_arg(args, unsigned int),
			"0123456789", res, 10);
	}
	else if (*s == 'p')
		ft_printptr(va_arg(args, void *), res);
	else if (*s == '%')
		ft_putchar(*s, res);
}

int	ft_printf(const char *s, ...)
{
	int			res;
	va_list		args;

	va_start(args, s);
	res = 0;
	while (*s)
	{
		if (*s == '%')
		{
			s++;
			ft_check_identif(args, s, &res);
		}
		else
			ft_putchar(*s, &res);
		s++;
	}
	va_end(args);
	return (res);
}
