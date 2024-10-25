/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hali-mah <hali-mah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 18:20:40 by hali-mah          #+#    #+#             */
/*   Updated: 2024/10/25 10:53:39 by hali-mah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ptr_len(uintptr_t num)
{
	int	len;

	len = 0;
	if (num == 0)
		return (1);
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

void	ft_put_ptr(uintptr_t num, int fd)
{
	if (num >= 16)
	{
		ft_put_ptr(num / 16, fd);
		ft_put_ptr(num % 16, fd);
	}
	else
	{
		if (num <= 9)
			ft_putchar_fd((num + '0'), fd);
		else
			ft_putchar_fd((num - 10 + 'a'), fd);
	}
}

int	ft_putptr(void *ptr, int fd)
{
	uintptr_t	addr;
	int			print_length;

	addr = (uintptr_t)ptr;
	print_length = 0;
	print_length += write(fd, "0x", 2);
	if (addr == 0)
	{
		print_length += write(fd, "0", 1);
	}
	else
	{
		ft_put_ptr(addr, fd);
		print_length += ft_ptr_len(addr);
	}
	return (print_length);
}
