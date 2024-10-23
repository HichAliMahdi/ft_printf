/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uhex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hali-mah <hali-mah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:23:29 by hali-mah          #+#    #+#             */
/*   Updated: 2024/10/23 14:20:03 by hali-mah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_hex_length(unsigned int n)
{
	int	len;

	len = 0;
	if (n == 0)
	{
		return (1);
	}
	while (n > 0)
	{
		n /= 16;
		len++;
	}
	return (len);
}

static void	fill_hex_result(unsigned int n, char *result, int len, char *hex)
{
	while (n > 0)
	{
		result[--len] = hex[n % 16];
		n /= 16;
	}
}

static void	write_hex_result(char *result, unsigned int n, int fd)
{
	int	i;

	if (n == 0)
	{
		ft_putchar_fd('0', fd);
	}
	else
	{
		i = 0;
		while (result[i] != '\0')
		{
			ft_putchar_fd(result[i], fd);
			i++;
		}
	}
}

int	ft_uhex(unsigned int n, int fd)
{
	char	*hex;
	int		len;
	char	*result;

	hex = "0123456789ABCDEF";
	len = get_hex_length(n);
	result = malloc((len + 1) * sizeof(char));
	if (!result)
	{
		return (-1);
	}
	result[len] = '\0';
	if (n == 0)
	{
		result[0] = '0';
	}
	else
	{
		fill_hex_result(n, result, len, hex);
	}
	write_hex_result(result, n, fd);
	free(result);
	return (0);
}
