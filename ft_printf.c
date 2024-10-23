/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hali-mah <hali-mah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 13:33:38 by hali-mah          #+#    #+#             */
/*   Updated: 2024/10/23 11:54:32 by hali-mah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format(const char format, va_list args, int fd)
{
	if (format == 'c')
		return (ft_putchar_fd(va_arg(args, int), fd));
	if (format == 's')
		return (ft_putstr_fd(va_arg(args, char *), fd));
	if (format == 'p')
		return (ft_putptr(va_arg(args, void *), fd));
	if (format == 'd' || format == 'i')
		return (ft_putnbr_fd(va_arg(args, int), fd));
	if (format == 'u')
		return (ft_unsnbr(va_arg(args, unsigned int), fd));
	if (format == 'x')
		return (ft_lhex(va_arg(args, unsigned int), fd));
	if (format == 'X')
		return (ft_uhex(va_arg(args, unsigned int), fd));
	if (format == '%')
		return (ft_putchar_fd('%', fd));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	list;
	int		i;
	int		result;

	i = 0;
	result = 0;
	va_start(list, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			result += ft_format(format[i], list, 1);
		}
		else
		{
			result += ft_putchar_fd(format[i], 1);
		}
		i++;
	}
	va_end(list);
	return (result);
}
