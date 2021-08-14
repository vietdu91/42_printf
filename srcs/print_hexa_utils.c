/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexa_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 13:23:15 by emtran            #+#    #+#             */
/*   Updated: 2021/08/14 15:23:51 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	print_big_x(t_printf *t_structor)
{
	ft_putchar('0');
	ft_putchar('X');
	t_structor->total += 2;
}

void	print_little_x(t_printf *t_structor)
{
	ft_putchar('0');
	ft_putchar('x');
	t_structor->total += 2;
}

void	rp_hexa(unsigned long int nbr, int len, t_printf *t_structor)
{
	int	tmp;

	tmp = t_structor->precision - len;
	if (t_structor->hashtag == 1)
		t_structor->width -= 2;
	if (t_structor->precision <= 0 && t_structor->width > 0)
		rp_hexa_s(nbr, len, t_structor);
	else if (t_structor->precision > 0 && t_structor->width <= 0)
		rp_hexa_s(nbr, len, t_structor);
	else if (t_structor->precision > 0 && t_structor->width > 0)
		rp_hexa_d(len, t_structor, tmp);
}

void	rp_hexa_s(unsigned long int nbr, int len, t_printf *t_structor)
{
	if (t_structor->precision > 0)
	{
		xxxtentacion(t_structor);
		if (t_structor->width == 0 && t_structor->widthor >= 0
			&& t_structor->tmp2 == 1)
			return ;
		else if (len < t_structor->precision)
			print_zero(t_structor->precision, len, t_structor);
	}
	else
	{
		if (nbr == 0 && (t_structor->crash == 1 || t_structor->zero_prec == 1))
			len = 0;
		if (t_structor->zero == 1 && t_structor->crash == 0
			&& t_structor->zero_prec == 0)
			print_zero(t_structor->width, len, t_structor);
		else
			print_space(t_structor->width, len, t_structor);
		xxxtentacion(t_structor);
	}
}

void	rp_hexa_d(int len, t_printf *t_structor, int tmp)
{
	if (t_structor->precision < t_structor->width)
	{
		while (tmp > 0)
			tmp = the_temporisation(tmp, t_structor);
		if (t_structor->zero == 1 && t_structor->precision > t_structor->width
			&& t_structor->minus == 1)
			print_zero(t_structor->width, len, t_structor);
		else if (t_structor->zero == 1 && t_structor->precision > 0
			&& t_structor->precision > len && t_structor->minus == 1)
			print_zero(t_structor->width, len, t_structor);
		print_space(t_structor->width, len, t_structor);
		xxxtentacion(t_structor);
		if (t_structor->minus == 0)
			print_zero(t_structor->precision, len, t_structor);
	}
	else
	{
		xxxtentacion(t_structor);
		if (len < t_structor->precision)
			print_zero(t_structor->precision, len, t_structor);
		else if (t_structor->precision >= t_structor->width)
			print_zero(t_structor->precision, len, t_structor);
	}	
}
