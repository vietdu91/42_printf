/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexa_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 13:23:15 by emtran            #+#    #+#             */
/*   Updated: 2021/08/04 13:24:16 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	print_big_x(t_printf *t_structor)
{
	ft_putchar('0');
	ft_putchar('X');
	t_structor->total += 2;
}

void	print_little_x(t_printf *t_structor)
{
	ft_putchar('0');
	ft_putchar('x');
	t_structor->total += 2;
}