/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hali-mah <hali-mah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 18:20:40 by hali-mah          #+#    #+#             */
/*   Updated: 2024/10/23 13:15:47 by hali-mah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_hex_length(unsigned long addr)
{
	int	hex_len;

	hex_len = 0;
	if (addr == 0)
	{
		return (1);
	}
	while (addr > 0)
	{
		addr /= 16;
		hex_len++;
	}
	return (hex_len);
}

void	ft_ultoa_base(unsigned long num, char *str, int base)
{
	char	*digits;
	int		i;
	int		j;
	char	temp[20];

	digits = "0123456789abcdef";
	i = 0;
	if (num == 0)
	{
		str[0] = '0';
		str[1] = '\0';
		return ;
	}
	while (num)
	{
		temp[i++] = digits[num % base];
		num = num / base;
	}
	j = 0;
	while (i > 0)
	{
		str[j++] = temp[--i];
	}
	str[j] = '\0';
}

void	hex_pointer(unsigned long addr, int fd)
{
	char	*hex_str;

	hex_str = malloc((get_hex_length(addr) + 1) * sizeof(char));
	if (!hex_str)
	{
		return ;
	}
	if (addr == 0)
	{
		ft_putchar_fd('0', fd);
		free(hex_str);
		return ;
	}
	ft_ultoa_base(addr, hex_str, 16);
	ft_putstr_fd(hex_str, fd);
	free(hex_str);
}

int	ft_putptr(void *ptr, int fd)
{
	unsigned long	addr;

	addr = (unsigned long)ptr;
	ft_putstr_fd("0x", fd);
	hex_pointer(addr, fd);
	if (addr == 0)
	{
		return (3);
	}
	else
	{
		return (get_hex_length(addr) + 2);
	}
}
