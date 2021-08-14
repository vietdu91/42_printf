/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkpoint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 17:43:12 by emtran            #+#    #+#             */
/*   Updated: 2021/08/14 15:03:48 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	check_flag(char c, t_printf *t_structor)
{
	if (!c)
		return ;
	if (c == '-')
		flag_minus(t_structor);
	if (c == '+')
		flag_plus(t_structor);
	if (c == '#')
		flag_hashtag(t_structor);
	if (c == '0')
		flag_zero(t_structor);
	if (c == ' ')
		flag_space(t_structor);
}

void	check_width(const char *str, t_printf *t_structor)
{
	if (!str)
		return ;
	if (ft_isdigit(*(str + t_structor->count)) != 1)
		return ;
	while (*(str + t_structor->count) == 48)
		t_structor->count++;
	t_structor->width = ft_atoi((str + t_structor->count), t_structor);
	t_structor->widthor = t_structor->width;
}

void	check_precision(const char *str, t_printf *t_structor)
{
	if (!str)
		return ;
	t_structor->count++;
	if (ft_isdigit(*(str + t_structor->count)) == 0)
	{
		if (*(str + t_structor->count - 1) == '.')
			t_structor->crash = 1;
		return ;
	}
	while (*(str + t_structor->count) == 48)
		t_structor->count++;
	t_structor->precision = ft_atoi((str + t_structor->count), t_structor);
	t_structor->precistor = t_structor->precision;
	if (t_structor->precision == 0)
		t_structor->zero_prec = 1;
}

void	check_conversion(char c, t_printf *t_structor, va_list ap)
{
	if (!c || !ap)
		return ;
	if (c == 'c')
		print_char(t_structor, ap);
	if (c == 's')
		print_str(t_structor, ap);
	if (c == 'p')
		print_adress(t_structor, ap);
	if (c == 'd')
		print_nbr(t_structor, ap);
	if (c == 'i')
		print_nbr(t_structor, ap);
	if (c == 'u')
		print_uns_nbr(t_structor, ap);
	if (c == 'x')
		print_little_hexa(t_structor, ap);
	if (c == 'X')
		print_big_hexa(t_structor, ap);
	if (c == '%')
		print_percent(t_structor);
	t_structor->count++;
}
