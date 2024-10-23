/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hali-mah <hali-mah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 13:33:38 by hali-mah          #+#    #+#             */
/*   Updated: 2024/10/23 14:39:17 by hali-mah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
