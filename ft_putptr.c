/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hali-mah <hali-mah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 18:20:40 by hali-mah          #+#    #+#             */
/*   Updated: 2024/10/22 18:44:18 by hali-mah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(void *ptr, int fd) // handles pointers //
{
	unsigned long	addr;

	addr = (unsigned long)ptr;
	ft_putstr_fd("0x", fd);
	if (addr == 0)
		ft_putchar_fd('0', fd);
	else
		ft_lhex(addr, fd);
	return (0);
}
