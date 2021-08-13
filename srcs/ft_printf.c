/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 17:32:39 by emtran            #+#    #+#             */
/*   Updated: 2021/08/13 16:12:06 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_printf(const char *str, ...)
{
	t_printf	t_structor;
	va_list		ap;

	va_start(ap, str);
	back_to_birth(&t_structor);
	while (*(str + t_structor.count) != '\0')
	{
		checker_cocktail(str, &t_structor, ap);
	}
	va_end(ap);
	return (t_structor.total);
}

void	checker_cocktail(const char *str, t_printf *t_structor, va_list ap)
{
	if (*(str + t_structor->count) == '%')
	{
		t_structor->count++;
		while (roulette_a_flags(*(str + t_structor->count)) == 1)
			check_flag(*(str + t_structor->count), t_structor);
		if (ft_isdigit(*(str + t_structor->count)) == 1)
			check_width(str, t_structor);
		if (*(str + t_structor->count) == '.')
		{
			t_structor->dot = 1;
			check_precision(str, t_structor);
		}
		check_conversion(*(str + t_structor->count), t_structor, ap);
	}
	else
	{
		ft_putchar(*(str + t_structor->count));
		t_structor->count++;
		t_structor->total++;
	}
}

t_printf	back_to_birth(t_printf *t_structor)
{
	t_structor->count = 0;
	t_structor->total = 0;
	t_structor->plus = 0;
	t_structor->space = 0;
	t_structor->hashtag = 0;
	t_structor->zero = 0;
	t_structor->minus = 0;
	t_structor->dot = 0;
	t_structor->precision = 0;
	t_structor->precistor = 0;
	t_structor->width = 0;
	t_structor->widthor = 0;
	t_structor->crash = 0;
	t_structor->d_and_i = 0;
	t_structor->s = 0;
	t_structor->little_x = 0;
	t_structor->big_x = 0;
	t_structor->adress = 0;
	t_structor->tmp = 0;
	t_structor->tmp2 = 0;
	t_structor->zero_prec = 0;
	t_structor->filtre = 0;
	return (*t_structor);
}

void	clean_prec_and_width(t_printf *t_structor)
{
	t_structor->precision = 0;
	t_structor->width = 0;
	t_structor->tmp = 0;
	t_structor->tmp2 = 0;
	t_structor->zero = 0;
	t_structor->minus = 0;
	t_structor->d_and_i = 0;
	t_structor->s = 0;
	t_structor->little_x = 0;
	t_structor->big_x = 0;
	t_structor->adress = 0;
	t_structor->hashtag = 0;
}
