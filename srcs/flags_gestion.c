/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_gestion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 18:00:13 by emtran            #+#    #+#             */
/*   Updated: 2021/08/14 15:03:40 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	flag_plus(t_printf *t_structor)
{
	t_structor->plus = 1;
	t_structor->count++;
}

void	flag_space(t_printf *t_structor)
{
	t_structor->space = 1;
	t_structor->count++;
}

void	flag_hashtag(t_printf *t_structor)
{
	t_structor->hashtag = 1;
	t_structor->count++;
}

void	flag_zero(t_printf *t_structor)
{
	t_structor->zero = 1;
	t_structor->count++;
}

void	flag_minus(t_printf *t_structor)
{
	t_structor->minus = 1;
	t_structor->count++;
}
