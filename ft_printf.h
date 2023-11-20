/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 12:10:20 by deydoux           #+#    #+#             */
/*   Updated: 2023/11/20 11:07:42 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "Libft/libft.h"
# include <stdarg.h>
# include <limits.h>

typedef struct s_flags
{
	int		alternate_form;
	char	padding;
	int		left_adjust;
	char	positive_sign;
	int		width;
	int		precision;
	size_t	size;
	int		ptr;
}			t_flags;

int		ft_printf(const char *format, ...);
t_flags	get_flags(const char **format, va_list *ap);
int		print_signed(va_list *ap, t_flags flags);
int		print_unsigned(va_list *ap, t_flags flags, char *base, char *prefix);
int		print_char(va_list *ap, t_flags flags);
int		print_str(va_list *ap, t_flags flags);
int		print_ptr(va_list *ap, t_flags flags);
int		put_nil(t_flags flags);

#endif
