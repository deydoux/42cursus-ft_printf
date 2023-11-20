/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 15:38:06 by deydoux           #+#    #+#             */
/*   Updated: 2023/11/20 12:29:49 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(va_list *ap, t_flags flags)
{
	int	len;

	flags.width--;
	len = (flags.width * (flags.width > 0)) + 1;
	if (!flags.left_adjust)
		while (flags.width-- > 0)
			ft_putchar_fd(flags.padding, 1);
	ft_putchar_fd((unsigned char)va_arg(*ap, int), 1);
	while (flags.width-- > 0)
		ft_putchar_fd(' ', 1);
	return (len);
}
