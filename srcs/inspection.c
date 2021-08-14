/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inspection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 18:44:15 by emtran            #+#    #+#             */
/*   Updated: 2021/08/14 15:07:01 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	roulette_a_flags(char c)
{
	if (!c)
		return (0);
	if (c == ' ' || c == '+' || c == '-' || c == '#' || c == '0')
	{
		return (1);
	}
	else
		return (0);
}

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

void	inspection_douaniere(t_printf *t_structor)
{
	if (t_structor->minus == 1 && t_structor->zero == 1)
		t_structor->zero = 0;
	if (t_structor->plus == 1 && t_structor->space == 1)
		t_structor->space = 0;
	if (t_structor->s == 0)
	{
		if (t_structor->precision > 0 && t_structor->width > 0
			&& t_structor->width < t_structor->precision)
			t_structor->minus = 0;
	}
	else if (t_structor->precision > 0 && t_structor->width == 0
		&& t_structor->d_and_i == 0)
		t_structor->minus = 0;
}
