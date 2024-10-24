/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hali-mah <hali-mah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:07:39 by hali-mah          #+#    #+#             */
/*   Updated: 2024/10/24 11:37:06 by hali-mah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_fd(int n, int fd)
{
	char	c;
	int		len;

	len = 0;
	if (n == -2147483648)
	{
		len += ft_putstr_fd("-2147483648", fd);
	}
	else
	{
		if (n < 0)
		{
			len += ft_putchar_fd('-', fd);
			n = -n;
		}
		if (n >= 10)
		{
			len += ft_putnbr_fd(n / 10, fd);
		}
		c = (n % 10) + '0';
		len += ft_putchar_fd(c, fd);
	}
	return (len);
}
