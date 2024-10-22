/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lhex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hali-mah <hali-mah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:05:06 by hali-mah          #+#    #+#             */
/*   Updated: 2024/10/22 18:44:26 by hali-mah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_lhex(unsigned int n, int fd) // handles lowercase hexa //
{
	char	*hex;

	hex = "0123456789abcdef";
	if (n >= 16)
		ft_lhex(n / 16, fd);
	ft_putchar_fd(hex[n % 16], fd);
	return (0);
}
