/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_factory.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 18:03:10 by emtran            #+#    #+#             */
/*   Updated: 2021/08/05 20:32:03 by emtran           ###   ########.fr       */
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
	if (nbr < 0 && t_structor->tmp == 0)
	{
		ft_putchar('-');
		t_structor->total++;
	}
}

void	print_plus(t_printf *t_structor)
{
	ft_putchar('+');
	t_structor->total++;
}

void	xxxtentacion(t_printf *t_structor)
{
	if (t_structor->adress == 1 && t_structor->tmp == 0)
	{
		t_structor->tmp = 1;
		print_little_x(t_structor);
	}
	else if (t_structor->hashtag == 1 && t_structor->little_x == 1
		&& t_structor->tmp == 0)
	{	
		t_structor->tmp = 1;
		print_little_x(t_structor);
	}
	else if (t_structor->hashtag == 1 && t_structor->big_x == 1
		&& t_structor->tmp == 0)
	{	
		t_structor->tmp = 1;
		print_big_x(t_structor);
	}
}
