/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 18:52:00 by emtran            #+#    #+#             */
/*   Updated: 2021/08/14 15:04:22 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	print_char(t_printf *t_structor, va_list ap)
{
	char		c;

	if (!ap)
		return ;
	c = va_arg(ap, int);
	inspection_douaniere(t_structor);
	if (t_structor->minus == 1)
		print_char_inv(t_structor, c);
	else
	{
		if (t_structor->zero == 1)
			print_zero(t_structor->width - 1, 0, t_structor);
		else
			print_space(t_structor->width - 1, 0, t_structor);
		ft_putchar(c);
		t_structor->total++;
	}
	clean_prec_and_width(t_structor);
}

void	print_char_inv(t_printf *t_structor, char c)
{
	ft_putchar(c);
	print_space(t_structor->width - 1, 0, t_structor);
	t_structor->total++;
}
