/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_factory.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 18:03:10 by emtran            #+#    #+#             */
/*   Updated: 2021/08/04 13:32:54 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	print_zero(int start, int end, t_printf *t_structor)
{
	int	i;

	i = 0;
	while (i < start - end)
	{
		ft_putchar('0');
		i++;
		t_structor->total++;
	}
	return (i);
}

int	print_space(int start, int end, t_printf *t_structor)
{
	int	i;

	i = 0;
	while (i < start - end)
	{
		ft_putchar(' ');
		i++;
		t_structor->total++;
	}
	return (i);
}

void	print_minus(int nbr, t_printf *t_structor)
{
	if (nbr < 0)
	{
		if (nbr == -2147483648)
		{
			write(1, "-2", 2);
			t_structor->total += 2;
		}
		else
		{
			ft_putchar('-');
			t_structor->total++;
		}
	}
}

void	print_plus(t_printf *t_structor)
{
	ft_putchar('+');
	t_structor->total++;
}
