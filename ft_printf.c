/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 12:10:12 by deydoux           #+#    #+#             */
/*   Updated: 2023/11/17 09:24:34 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	convert(const char **format, va_list *ap)
{
	const char	*percent_ptr;
	t_flags		flags;

	percent_ptr = ++(*format);
	flags = get_flags(format, ap);
	if (**format == 'd' || **format == 'i')
		return (convert_decimal(flags, ap));
	else if (**format == 'o')
	{

	}
	else if (**format == 'u')
	{

	}
	else if (**format == 'x')
	{

	}
	else if (**format == 'X')
	{

	}
	else if (**format == 'c')
	{

	}
	else if (**format == 's')
	{

	}
	else if (**format == 'p')
	{

	}
	else if (**format == '%')
	{

	}
	ft_putchar_fd('%', 1);
	*format = percent_ptr;
	return (1);
}

int	ft_printf(const char *format, ...)
{
	int		len;
	va_list	ap;

	len = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
			len += convert(&format, &ap);
		else
		{
			ft_putchar_fd(*format++, 1);
			len++;
		}
	}
	va_end(ap);
	return (len);
}
