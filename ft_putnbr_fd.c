/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hali-mah <hali-mah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:07:39 by hali-mah          #+#    #+#             */
/*   Updated: 2024/10/23 15:07:54 by hali-mah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_fd(int n, int fd)
{
	char	buffer[11];
	int		len;

	len = 0;
	if (n < 0)
	{
		len += write(fd, "-", 1);
		n = -n;
	}
	if (n == 0)
	{
		len += write(fd, "0", 1);
		return (len);
	}
	while (n > 0)
	{
		buffer[len++] = (n % 10) + '0';
		n /= 10;
	}
	while (len > 0)
	{
		len--;
		write(fd, &buffer[len], 1);
	}
	return (len);
}