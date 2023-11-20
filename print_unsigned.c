/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 20:11:12 by deydoux           #+#    #+#             */
/*   Updated: 2023/11/20 07:24:11 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static long long	get_arg(t_flags flags, va_list *ap)
{
	if (flags.size == 0)
		return (va_arg(*ap, unsigned));
	if (flags.size == sizeof(signed char))
		return ((unsigned char)va_arg(*ap, int));
	if (flags.size == sizeof(short))
		return ((unsigned short)va_arg(*ap, int));
	if (flags.size == sizeof(long long))
		return (va_arg(*ap, unsigned long long));
	if (flags.size == sizeof(long))
		return (va_arg(*ap, unsigned long));
	else
		return (va_arg(*ap, unsigned));
}

static int	update_flags(t_flags *flags, unsigned long long n, size_t base_len,
	char *prefix)
{
	int					len;
	unsigned long long	tmp_n;

	if (flags->precision != -1)
		flags->padding = ' ';
	len = n == 0 && flags->precision != 0 && flags->precision != 1;
	tmp_n = n;
	while (tmp_n)
	{
		tmp_n /= base_len;
		len++;
	}
	flags->precision -= len;
	len += (flags->precision * (flags->precision > 0))
		+ ((n != 0 && flags->alternate_form) * ft_strlen(prefix));
	flags->width -= len;
	len += flags->width * (flags->width > 0);
	return (len);
}

static void	print_ull(unsigned long long n, int precision, char *base,
	size_t base_len)
{
	while (precision-- > 0)
		ft_putchar_fd('0', 1);
	if (n >= base_len)
		print_ull(n / base_len, 0, base, base_len);
	ft_putchar_fd(base[n % base_len], 1);
}

int	print_unsigned(t_flags flags, va_list *ap, char *base, char *prefix)
{
	unsigned long long	n;
	size_t				base_len;
	int					len;

	n = get_arg(flags, ap);
	base_len = ft_strlen(base);
	len = update_flags(&flags, n, base_len, prefix);
	if (!flags.left_adjust)
		while (flags.width-- > 0)
			ft_putchar_fd(flags.padding, 1);
	if (n != 0 && flags.alternate_form)
		ft_putstr_fd(prefix, 1);
	if (n == 0 && flags.precision == 1)
		ft_putchar_fd('0', 1);
	else if (n != 0 || flags.precision != 0)
		print_ull(n, flags.precision, base, base_len);
	if (flags.left_adjust)
		while (flags.width-- > 0)
			ft_putchar_fd(' ', 1);
	return (len);
}

int	print_ptr(t_flags flags, va_list *ap)
{
	flags.alternate_form = 1;
	flags.size = sizeof(long);
	return (print_unsigned(flags, ap, "0123456789abcdef", "0x"));
}
