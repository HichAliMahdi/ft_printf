/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hali-mah <hali-mah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 13:33:38 by hali-mah          #+#    #+#             */
/*   Updated: 2024/10/23 11:40:44 by hali-mah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format(const chat format, va_list args, int fd)
{
	if (format == 'c')
		return (ft_putchar_fd(va_args(args, int), fd));
	if (format == 's')
		return (ft_putstr_fd(va_args(args, char *), fd));
	if (format == 'p')
		return (ft_putptr(va_args(args, void *), fd));
	if (format == 'd' || format == 'i')
		return (ft_putnbr_fd(va_args(args, int), fd));
	if (format == 'u')
		return (ft_unsnbr(va_args(args, unsigned int), fd));
	if (format == 'x')
		return (ft_lhex(va_args(args, unsigned int), fd));
	if (format == 'X')
		return (ft_uhex(va_args(args, unsigned int), fd));
	if (format == '%')
		return (ft_putchar_fd('%', fd));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	
}
