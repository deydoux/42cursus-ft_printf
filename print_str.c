/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 15:56:36 by deydoux           #+#    #+#             */
/*   Updated: 2023/11/20 08:17:20 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	update_flags(t_flags *flags, const char *s)
{
	int	len;

	len = 0;
	while (s[len] && (flags->precision < 0 || len < flags->precision))
		len++;
	flags->precision = len;
	flags->width -= len;
	len += flags->width * (flags->width > 0);
	return (len);
}

int	print_str(va_list *ap, t_flags flags)
{
	const char	*s;
	int			len;

	s = va_arg(*ap, const char *);
	if (!s)
		s = "(null)";
	len = update_flags(&flags, s);
	if (!flags.left_adjust)
		while (flags.width-- > 0)
			ft_putchar_fd(flags.padding, 1);
	write(1, s, flags.precision);
	if (flags.left_adjust)
		while (flags.width-- > 0)
			ft_putchar_fd(' ', 1);
	return (len);
}
