/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hali-mah <hali-mah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:15:38 by hali-mah          #+#    #+#             */
/*   Updated: 2024/10/22 18:45:23 by hali-mah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_unsnbr(unsigned int n, int fd) // handles unsigned int
{
	if (n >= 10)
		ft_unsnbr(n / 10, fd);
	ft_putchar_fd((n % 10) + '0', fd);
	return (0);
}
