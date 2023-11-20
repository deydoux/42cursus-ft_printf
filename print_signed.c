/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_signed.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 12:16:21 by deydoux           #+#    #+#             */
/*   Updated: 2023/11/20 06:55:21 by deydoux          ###   ########.fr       */
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

static int	update_flags(t_flags *flags, long long n)
{
	int			len;
	long long	tmp_n;

	if (flags->precision != -1)
		flags->padding = ' ';
	len = n == 0 && flags->precision != 0 && flags->precision != 1;
	tmp_n = n;
	while (tmp_n)
	{
		tmp_n /= 10;
		len++;
	}
	flags->precision -= len;
	len += (flags->precision * (flags->precision > 0))
		+ (n < 0 || flags->positive_sign);
	flags->width -= len;
	len += flags->width * (flags->width > 0);
	return (len);
}

static void	put_sign(long long n, char positive_sign)
{
	if (n < 0)
		ft_putchar_fd('-', 1);
	else if (positive_sign)
		ft_putchar_fd(positive_sign, 1);
}

static void	print_ll(long long n, int precision)
{
	if (n == LLONG_MIN)
	{
		print_ll(n / 10, precision);
		return (print_ll(n % 10 * -1, 0));
	}
	if (n < 0)
		n *= -1;
	while (precision-- > 0)
		ft_putchar_fd('0', 1);
	if (n >= 10)
		print_ll(n / 10, 0);
	ft_putchar_fd(n % 10 + '0', 1);
}

int	print_signed(t_flags flags, va_list *ap)
{
	long long	n;
	int			len;

	n = get_arg(flags, ap);
	len = update_flags(&flags, n);
	if (flags.padding == '0')
		put_sign(n, flags.positive_sign);
	if (!flags.left_adjust)
		while (flags.width-- > 0)
			ft_putchar_fd(flags.padding, 1);
	if (flags.padding != '0')
		put_sign(n, flags.positive_sign);
	if (n == 0 && flags.precision == 1)
		ft_putchar_fd('0', 1);
	else if (n != 0 || flags.precision != 0)
		print_ll(n, flags.precision);
	if (flags.left_adjust)
		while (flags.width-- > 0)
			ft_putchar_fd(' ', 1);
	return (len);
}
