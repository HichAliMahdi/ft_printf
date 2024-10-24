/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hali-mah <hali-mah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:15:38 by hali-mah          #+#    #+#             */
/*   Updated: 2024/10/24 11:42:27 by hali-mah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_unsnbr(unsigned int n, int fd)
{
	int	len;

	len = 0;
	if (n >= 10)
		len += ft_unsnbr(n / 10, fd);
	len += ft_putchar_fd((n % 10) + '0', fd);
	return (len);
}
