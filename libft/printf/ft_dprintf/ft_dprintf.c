/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 13:01:32 by efinda            #+#    #+#             */
/*   Updated: 2024/06/07 13:01:39 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

static	void	ft_dcheck_identif(va_list args, int fd, const char *s, int *res)
{
	int	ptr[2];

	ptr[0] = fd;
	if (*s == 'x')
	{
		ptr[1] = 16;
		ft_dprintbase(ptr, va_arg(args, unsigned int),
			"0123456789abcdef", res);
	}
	else if (*s == 'X')
	{
		ptr[1] = 16;
		ft_dprintbase(ptr, va_arg(args, unsigned int),
			"0123456789ABCDEF", res);
	}
	else if (*s == 'u')
	{
		ptr[1] = 10;
		ft_dprintbase(ptr, va_arg(args, unsigned int),
			"0123456789", res);
	}
	else if (*s == 'p')
		ft_dprintptr(fd, va_arg(args, void *), res);
	else if (*s == '%')
		ft_dputchar(fd, *s, res);
}

int	ft_dprintf(int fd, const char *s, ...)
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
			if (*s == 'c')
				ft_dputchar(fd, va_arg(args, int), &res);
			else if (*s == 's')
				ft_dputstr(fd, va_arg(args, char *), &res);
			else if (*s == 'd' || *s == 'i')
				ft_dputnbr(fd, va_arg(args, int), &res);
			else
				ft_dcheck_identif(args, fd, s, &res);
		}
		else
			ft_dputchar(fd, *s, &res);
		s++;
	}
	va_end(args);
	return (res);
}
