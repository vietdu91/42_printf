/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   highways.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 15:05:41 by emtran            #+#    #+#             */
/*   Updated: 2021/08/14 15:10:07 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	highway_torcy(unsigned long int nbr, int ln, t_printf *t_structor)
{
	if (t_structor->minus == 1 && t_structor->precision > 0
		&& t_structor->width > 0 && t_structor->precision == t_structor->width)
	{
		rp_hexa(nbr, ln, t_structor);
		t_structor->filtre = 1;
	}
	else if (t_structor->minus == 0)
		rp_hexa(nbr, ln, t_structor);
	if (t_structor->precision > ln && t_structor->minus == 1
		&& t_structor->precision != t_structor->width)
	{
		print_zero(t_structor->precision, ln, t_structor);
		t_structor->tmp2 = 1;
	}
}

void	highway_arpajon(long int nbr, int len, t_printf *t_structor)
{
	if (t_structor->minus == 1 && t_structor->precision > 0
		&& t_structor->width > 0 && t_structor->precision == t_structor->width)
	{
		the_remplisseur_nbr(nbr, len, t_structor);
		t_structor->filtre = 1;
	}
	else if (t_structor->minus == 1 && t_structor->precision > 0
		&& t_structor->precision > len && t_structor->width <= 0)
	{
		the_remplisseur_nbr(nbr, len, t_structor);
		t_structor->filtre = 1;
	}
	else if (t_structor->minus == 0)
		the_remplisseur_nbr(nbr, len, t_structor);
}

void	highway_montargis(long int nbr, int len, t_printf *t_structor)
{
	if (t_structor->minus == 1 && t_structor->filtre == 1)
		return ;
	if (t_structor->minus == 1)
		the_remplisseur_nbr(nbr, len, t_structor);
}

void	highway_chatou(unsigned int n, int len, t_printf *t_structor)
{
	if (t_structor->minus == 1 && t_structor->precision > 0
		&& t_structor->width > 0 && t_structor->precision == t_structor->width)
	{
		remplisseur_unbr(n, len, t_structor);
		t_structor->filtre = 1;
	}
	else if (t_structor->minus == 0)
		remplisseur_unbr(n, len, t_structor);
}

void	highway_argenteuil(unsigned int n, int len, t_printf *t_structor)
{
	if (t_structor->minus == 1 && t_structor->filtre == 1)
		return ;
	if (t_structor->minus == 1)
		remplisseur_unbr(n, len, t_structor);
}
