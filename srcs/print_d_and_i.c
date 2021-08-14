/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d_and_i.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 17:59:04 by emtran            #+#    #+#             */
/*   Updated: 2021/08/14 15:23:38 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	print_nbr(t_printf *t_structor, va_list ap)
{
	long int	nbr;
	int			len;

	if (!ap)
		return ;
	nbr = (long int)va_arg(ap, int);
	len = ft_nbrlen(nbr, B10, t_structor);
	inspection_douaniere(t_structor);
	t_structor->d_and_i = 1;
	highway_arpajon(nbr, len, t_structor);
	if (t_structor->space == 1 && nbr >= 0)
		print_space(1, 0, t_structor);
	else if (t_structor->plus == 1 && nbr >= 0)
		print_plus(t_structor);
	if (t_structor->minus == 1)
		fork_of_minus(nbr, t_structor);
	if (t_structor->precision > len
		&& t_structor->precision < t_structor->widthor)
		print_zero(t_structor->precision, len, t_structor);
	if (t_structor->precision > 0 || t_structor->width > 0)
		ft_putnnbr(nbr, len, t_structor);
	else
		ft_putnbr(nbr, t_structor);
	highway_montargis(nbr, len, t_structor);
	clean_prec_and_width(t_structor);
}

void	ft_putnnbr(long int nbr, int len, t_printf *t_structor)
{
	if (nbr == -2147483648)
		t_structor->total -= 2;
	if (nbr == 0 && (t_structor->crash == 1 || t_structor->zero_prec == 1))
		return ;
	print_minus(nbr, t_structor);
	if (nbr < 0)
		nbr = nbr * -1;
	if (nbr >= 10 && len >= 0)
	{
		len--;
		ft_putnnbr(nbr / 10, len, t_structor);
	}
	ft_putchar(nbr % 10 + 48);
	t_structor->total++;
}

void	fork_of_minus(int nbr, t_printf *t_structor)
{
	if (nbr < 0)
	{
		print_minus(nbr, t_structor);
		t_structor->tmp = 1;
	}
}

void	being_overwhelmed(int nbr, int len, int tmp, t_printf *t_structor)
{
	while (tmp > 0)
		tmp = the_temporisation(tmp, t_structor);
	if (t_structor->zero == 1 && t_structor->precision > t_structor->width
		&& t_structor->minus == 1)
	{		
		fork_of_minus(nbr, t_structor);
		print_zero(t_structor->width, len, t_structor);
	}
	else if (t_structor->zero == 1 && t_structor->precision > 0
		&& t_structor->precision > len && t_structor->minus == 1)
	{			
		fork_of_minus(nbr, t_structor);
		print_zero(t_structor->width, len, t_structor);
	}
	print_space(t_structor->width, len, t_structor);
	if (t_structor->minus == 0)
		fork_of_minus(nbr, t_structor);
}

void	bulls_eye(int nbr, int len, t_printf *t_structor)
{
	if (t_structor->width == 0 && t_structor->widthor > 0)
		return ;
	else if (len < t_structor->precision)
	{
		fork_of_minus(nbr, t_structor);
		print_zero(t_structor->precision, len, t_structor);
	}
}
