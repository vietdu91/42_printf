/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 15:15:22 by emtran            #+#    #+#             */
/*   Updated: 2021/08/05 21:11:06 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <limits.h>

void	print_adress(t_printf *t_structor, va_list ap)
{
	unsigned long int	nbr;
	int					len;

	if (!ap)
		return ;
	nbr = va_arg(ap, unsigned long int);
	len = ft_nbrlen_u(nbr, B16LX);
	t_structor->adress = 1;
	inspection_douaniere(t_structor);
	t_structor->width -= 2;
	if (t_structor->minus == 1 && t_structor->precision < t_structor->width)
		print_zero(t_structor->precision, len, t_structor);
	if (t_structor->minus == 0 && nbr != ULONG_MAX
		&& nbr != (unsigned long int)LONG_MIN)
		remplisseur_addr(len, t_structor);
	xxxtentacion(t_structor);
	put_hexa(nbr, B16LX, t_structor);
	if (t_structor->minus == 1 && nbr != ULONG_MAX
		&& nbr != (unsigned long int)LONG_MIN)
		remplisseur_addr(len, t_structor);
	t_structor->tmp = 0;
}

void	remplisseur_addr(int len, t_printf *t_structor)
{
	int	tmp;

	tmp = t_structor->precision - len;
	if (t_structor->precision <= 0 && t_structor->width > 0)
		rp_addr_simple(len, t_structor);
	else if (t_structor->precision > 0 && t_structor->width <= 0)
		rp_addr_simple(len, t_structor);
	else if (t_structor->precision > 0 && t_structor->width > 0)
		rp_addr_d(len, t_structor, tmp);
}

void	rp_addr_simple(int len, t_printf *t_structor)
{
	if (t_structor->precision > 0)
	{
		xxxtentacion(t_structor);
		if (len < t_structor->precision)
			print_zero(t_structor->precision, len, t_structor);
	}
	else
	{
		if (t_structor->zero == 1 && t_structor->crash == 0)
			print_zero(t_structor->width, len, t_structor);
		else
			print_space(t_structor->width, len, t_structor);
		xxxtentacion(t_structor);
	}
}

void	rp_addr_d(int len, t_printf *t_structor, int tmp)
{
	if (t_structor->precision < t_structor->width)
	{
		while (tmp > 0)
			tmp = the_temporisation(tmp, t_structor);
		if (t_structor->zero == 1 && t_structor->precision > t_structor->width)
			print_zero(t_structor->width, len, t_structor);
		else if (t_structor->zero == 1 && t_structor->precision > 0
			&& t_structor->precision < len
			&& t_structor->precision > t_structor->width)
			print_zero(t_structor->width, len, t_structor);
		else
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