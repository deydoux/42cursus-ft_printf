/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_decimal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 12:16:21 by deydoux           #+#    #+#             */
/*   Updated: 2023/11/17 09:18:23 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static long long	get_arg(t_flags flags, va_list *ap)
{
	if (flags.size == 0)
		return (va_arg(*ap, int));
	if (flags.size == sizeof(signed char))
		return ((signed char)va_arg(*ap, int));
	if (flags.size == sizeof(short))
		return ((short)va_arg(*ap, int));
	if (flags.size == sizeof(long long))
		return (va_arg(*ap, long long));
	if (flags.size == sizeof(long))
		return (va_arg(*ap, long));
	else
		return (va_arg(*ap, int));
}

static int	ll_len(long long n, t_flags flags)
{
	int	len;

	len = (n == 0 && flags.precision != 0)
		+ (n <= 0 && flags.positive_sign);
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static void	ft_putll(long long n)
{
	if (n == LLONG_MIN)
	{
		ft_putll(n / 10);
		return (ft_putll(n % 10 * -1));
	}
	if (n < 0)
	{
		ft_putchar_fd('-', 1);
		n *= -1;
	}
	if (n >= 10)
		ft_putll(n / 10);
	ft_putchar_fd(n % 10 + '0', 1);
}

int	convert_decimal(t_flags flags, va_list *ap)
{
	long long	n;
	int			len;

	n = get_arg(flags, ap);
	len = ll_len(n, flags);
	flags.width -= flags.precision * (flags.precision > 0);
	if (flags.precision + 1)
		flags.padding = ' ';
	while (len <= flags.width)
		ft_putchar_fd(flags.padding, 1);
	if (n >= 0 && flags.positive_sign)
		ft_putchar_fd(flags.positive_sign, 1);
	while (len <= flags.precision)
	{
		ft_putchar_fd('0', 1);
		len++;
	}
	if (n == 0 && flags.precision != 0)
		ft_putll(n);
	return (len);
}
