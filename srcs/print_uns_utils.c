/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_uns_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 15:13:24 by emtran            #+#    #+#             */
/*   Updated: 2021/08/04 15:59:01 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	remplisseur_unbr(unsigned int nbr, int len, t_printf *t_structor)
{
	int tmp;

	tmp = t_structor->precision - len;
	if (t_structor->precision == 0 && t_structor->width > 0)
		rp_unbr_simple(nbr, len, t_structor);
	else if (t_structor->precision > 0 && t_structor->width == 0)
		rp_unbr_simple(nbr, len, t_structor);
	else if (t_structor->precision > 0 && t_structor->width > 0)
		rp_unb_d(nbr, len, t_structor, tmp);
}

void	rp_unbr_simple(unsigned int nbr, int len, t_printf *t_structor)
{
	if (nbr < 0)
		t_structor->width--;
	if (t_structor->precision > 0)
	{
		if (len < t_structor->precision)
			print_zero(t_structor->precision, len, t_structor);
	}
	else
	{
		if (t_structor->zero == 1 && t_structor->crash == 0)
			print_zero(t_structor->width, len, t_structor);
		else
			print_space(t_structor->width, len, t_structor);
	}
}

void	rp_unb_d(unsigned int nbr, int len, t_printf *t_structor, int tmp)
{
	if (nbr < 0)
		t_structor->width--;
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
	}
	else
	{
		if (len < t_structor->precision)
			print_zero(t_structor->precision, len, t_structor);
		else if (t_structor->precision >= t_structor->width)
			print_zero(t_structor->precision, len, t_structor);
	}
}