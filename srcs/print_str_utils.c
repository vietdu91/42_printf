/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 17:51:45 by emtran            #+#    #+#             */
/*   Updated: 2021/08/13 11:43:04 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_putchar(char c)
{	
	write(1, &c, 1);
}

void	ft_putstr(char *str, t_printf *t_structor)
{
	int	i;

	if (!str)
		return ;	
	i = 0;
	if (str == 0)
		return ;
	while (*(str + i))
	{
		write(1, (str + i), 1);
		i++;
		t_structor->total++;
	}
}

void	the_remplisseur_str(char *str, t_printf *t_structor)
{
	int tmp;

	tmp = t_structor->precision - ft_strlen(str);
	if (t_structor->precistor == 0 && t_structor->widthor > 0)
		the_remplisseur_str_simple(str, t_structor);
	else if (t_structor->precistor > 0 && t_structor->widthor > 0)
		the_remplisseur_str_doub(str, t_structor, tmp);
}

void	the_remplisseur_str_simple(char *str, t_printf *t_structor)
{
	if (t_structor->zero == 1 && t_structor->crash == 1)
		print_zero(t_structor->width, t_structor->precistor, t_structor);
	else if (t_structor->zero == 1)
		print_zero(t_structor->width, ft_strlen(str), t_structor);
	else if (t_structor->crash == 1)
		print_space(t_structor->width, t_structor->precistor, t_structor);
	else if (t_structor->minus == 1 && t_structor->dot == 1)
		print_space(t_structor->width + 1, ft_strlen(str), t_structor);
	else
		print_space(t_structor->width, ft_strlen(str), t_structor);
}

void	the_remplisseur_str_doub(char *str, t_printf *t_structor, int tmp)
{
	while (tmp > 0 && t_structor->precision <= ft_strlen(str))
		tmp = the_temporisation(tmp, t_structor);
	if (t_structor->precistor == 0 && t_structor->crash == 0)
		print_zero(t_structor->width, ft_strlen(str), t_structor);
	else if (t_structor->zero == 1 && t_structor->precistor > t_structor->width)
		print_zero(t_structor->width, ft_strlen(str), t_structor);
	else if (t_structor->zero == 1 && t_structor->precistor > 0 
		&& t_structor->precistor < ft_strlen(str))
		print_zero(t_structor->width + 1, ft_strlen(str), t_structor);
	else if (t_structor->precistor > t_structor->widthor
		&& t_structor->minus == 1)
		print_space(t_structor->precistor + 1, t_structor->widthor, t_structor);
	else
		print_space(t_structor->widthor, t_structor->precistor, t_structor);
}