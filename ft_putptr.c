/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hali-mah <hali-mah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 18:20:40 by hali-mah          #+#    #+#             */
/*   Updated: 2024/10/25 15:29:13 by hali-mah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	count_digits(uintptr_t num, int base)
{
	int	len;

	len = 0;
	if (num == 0)
		return (1);
	while (num != 0)
	{
		len++;
		num /= base;
	}
	return (len);
}

static char	*convert_to_hex(uintptr_t num, char *str, int base, int len)
{
	char	*digits;

	digits = "0123456789abcdef";
	str[len] = '\0';
	while (len--)
	{
		str[len] = digits[num % base];
		num /= base;
	}
	return (str);
}

char	*ft_itoa_base(uintptr_t num, int base)
{
	char	*str;
	int		len;

	len = count_digits(num, base);
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	return (convert_to_hex(num, str, base, len));
}

int	ft_putptr(void *ptr)
{
	char		*hex_str;
	uintptr_t	addr;
	int			len;

	if (!ptr)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	addr = (uintptr_t)ptr;
	hex_str = ft_itoa_base(addr, 16);
	if (!hex_str)
		return (0);
	ft_putstr_fd("0x", 1);
	ft_putstr_fd(hex_str, 1);
	len = 2 + ft_strlen(hex_str);
	free(hex_str);
	return (len);
}
