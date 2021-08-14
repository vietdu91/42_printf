/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 17:52:19 by emtran            #+#    #+#             */
/*   Updated: 2021/08/14 15:22:14 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_putnbr(long int nbr, t_printf *t_structor)
{	
	if (nbr == -2147483648)
		t_structor->total -= 2;
	if (nbr == 0 && (t_structor->crash == 1 || t_structor->zero_prec == 1))
		return ;
	print_minus(nbr, t_structor);
	if (nbr < 0)
		nbr = nbr * -1;
	if (nbr >= 10)
		ft_putnbr(nbr / 10, t_structor);
	ft_putchar(nbr % 10 + 48);
	t_structor->total++;
}

int	ft_atoi(const char *str, t_printf *t_structor)
{
	int	i;
	int	a;
	int	signe;

	i = 0;
	a = 0;
	signe = 1;
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\t' || str[i] == '\v')
	{
		i++;
	}
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			signe = signe * -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		a = a * 10 + str[i] - 48;
		i++;
	}
	t_structor->count += i;
	return (a * signe);
}

void	the_remplisseur_nbr(int nbr, int len, t_printf *t_structor)
{
	int	tmp;

	tmp = t_structor->precision - len;
	if (t_structor->precision <= 0 && t_structor->width > 0)
		the_remplisseur_nbr_simple(nbr, len, t_structor);
	else if (t_structor->precision > 0 && t_structor->width <= 0)
		the_remplisseur_nbr_simple(nbr, len, t_structor);
	else if (t_structor->precision > 0 && t_structor->width > 0)
		the_remp_nbr_doub(nbr, len, t_structor, tmp);
}

void	the_remplisseur_nbr_simple(int nbr, int len, t_printf *t_structor)
{
	if (nbr < 0)
		t_structor->width--;
	if (t_structor->precision > 0)
		bulls_eye(nbr, len, t_structor);
	else
	{
		if (nbr == 0 && (t_structor->crash == 1 || t_structor->zero_prec == 1))
			len = 0;
		if (t_structor->zero == 1 && t_structor->crash == 0
			&& t_structor->zero_prec == 0)
		{
			fork_of_minus(nbr, t_structor);
			print_zero(t_structor->width, len, t_structor);
		}
		else
		{
			print_space(t_structor->width, len, t_structor);
			if (t_structor->minus == 0)
				fork_of_minus(nbr, t_structor);
		}
	}
}

void	the_remp_nbr_doub(int nbr, int len, t_printf *t_structor, int tmp)
{
	if (nbr < 0)
		t_structor->width--;
	if (t_structor->precision < t_structor->width)
		being_overwhelmed(nbr, len, tmp, t_structor);
	else
	{
		if (len < t_structor->precision)
		{			
			fork_of_minus(nbr, t_structor);
			print_zero(t_structor->precision, len, t_structor);
		}
		else if (t_structor->precision >= t_structor->width)
		{		
			fork_of_minus(nbr, t_structor);
			print_zero(t_structor->precision, len, t_structor);
		}
	}
}
