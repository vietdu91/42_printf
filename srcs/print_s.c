/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 18:58:15 by emtran            #+#    #+#             */
/*   Updated: 2021/08/03 16:58:24 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	print_str(t_printf *t_structor, va_list ap)
{
	char	*str;

	if (!ap)
		return ;
	str = va_arg(ap, char *);
	inspection_douaniere(t_structor);
	if (t_structor->crash == 1 && t_structor->width <= 0)
		return ;
	else if (t_structor->precision > 0 && t_structor->width > 0)
		ft_putnstr_double(str, t_structor);
	else if (t_structor->width > 0)
		ft_putnstr_simple_w(str, t_structor);
	else if (t_structor->precision > 0)
		ft_putnstr_simple_p(str, t_structor);
	else
		ft_putstr(str, t_structor);
}

void	ft_putnstr_simple_p(char *str, t_printf *t_structor)
{
	int	i;

	if (!str)
		return ;
	i = 0;
	if (str == 0)
		return ;
	while (*(str + i) && t_structor->precision > 0)
	{
		ft_putchar(*(str + i));
		i++;
		t_structor->total++;
		t_structor->precision--;
	}
}

void	ft_putnstr_simple_w(char *str, t_printf *t_structor)
{
	int i;

	if (!str)
		return ;
	i = 0;
	if (str == 0)
		return ;
	if (t_structor->minus == 0)
		the_remplisseur_str(str, t_structor);
	while (*(str + i) && t_structor->crash == 0)
	{
		ft_putchar(*(str + i));
		i++;
		t_structor->total++;
	}
	if (t_structor->minus == 1)
		the_remplisseur_str(str, t_structor);
}

void	ft_putnstr_double(char *str, t_printf *t_structor)
{
	int i;

	if (!str)
		return ;
	i = 0;
	if (str == 0)
		return ;
	if (t_structor->minus == 0)
		the_remplisseur_str(str, t_structor);
	while (*(str + i) && t_structor->precision > 0)
	{
		ft_putchar(*(str + i));
		i++;
		t_structor->total++;
		t_structor->precision--;
	}
	if (t_structor->minus == 1)
		the_remplisseur_str(str, t_structor);
}