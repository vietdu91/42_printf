/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_percent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 18:49:43 by emtran            #+#    #+#             */
/*   Updated: 2021/08/14 15:22:35 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	print_percent(t_printf *t_structor)
{
	inspection_douaniere(t_structor);
	if (t_structor->minus == 1)
		print_percent_inv(t_structor);
	else
	{
		if (t_structor->zero == 1)
			print_zero(t_structor->width - 1, 0, t_structor);
		else
			print_space(t_structor->width - 1, 0, t_structor);
		ft_putchar('%');
		t_structor->total++;
	}
}

void	print_percent_inv(t_printf *t_structor)
{
	ft_putchar('%');
	print_space(t_structor->width - 1, 0, t_structor);
	t_structor->total++;
}
