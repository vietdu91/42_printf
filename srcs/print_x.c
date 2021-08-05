/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 13:48:22 by emtran            #+#    #+#             */
/*   Updated: 2021/08/05 20:04:13 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	print_little_hexa(t_printf *t_structor, va_list ap)
{
	unsigned long int	nbr;
	int					len;

	if (!ap)
		return ;
	nbr = (unsigned int)va_arg(ap, unsigned long int);
	len = ft_nbrlen_u(nbr, B16LX);
	inspection_douaniere(t_structor);
	t_structor->little_x = 1;
	if (t_structor->minus == 1 && t_structor->precision < t_structor->width)
		print_zero(t_structor->precision, len, t_structor);
	if (t_structor->minus == 0)
		remplisseur_hexa(len, t_structor);
	if (nbr != 0)
		xxxtentacion(t_structor);
	if (t_structor->precision > 0 || t_structor->width > 0)
		putn_hx(nbr, B16LX, len, t_structor);
	else
		put_hexa(nbr, B16LX, t_structor);
	if (t_structor->minus == 1)
		remplisseur_hexa(len, t_structor);
	t_structor->tmp = 0;
}

void	print_big_hexa(t_printf *t_structor, va_list ap)
{
	unsigned long int	nbr;
	int					len;

	if (!ap)
		return ;
	nbr = (unsigned int)va_arg(ap, unsigned long int);
	len = ft_nbrlen_u(nbr, B16BX);
	inspection_douaniere(t_structor);
	t_structor->big_x = 1;
	if (t_structor->minus == 1 && t_structor->precision < t_structor->width)
		print_zero(t_structor->precision, len, t_structor);
	if (t_structor->minus == 0)
		remplisseur_hexa(len, t_structor);
	if (nbr != 0)
		xxxtentacion(t_structor);
	if (t_structor->precision > 0 || t_structor->width > 0)
		putn_hx(nbr, B16BX, len, t_structor);
	else
		put_hexa(nbr, B16BX, t_structor);
	if (t_structor->minus == 1)
		remplisseur_hexa(len, t_structor);
	t_structor->tmp = 0;
}

void	put_hexa(unsigned long int nbr, char *base, t_printf *t_structor)
{
	unsigned long long int	i;
	unsigned long long int	j;

	if (!base)
		return ;
	i = nbr;
	j = ft_strlen(base);
	if (i >= j)
	{
		put_hexa(i / j, base, t_structor);
		t_structor->total++;
	}
	else
		t_structor->total++;
	ft_putchar(base[i % j]);
}

void	putn_hx(unsigned long int n, char *b, int ln, t_printf *t_structor)
{
	unsigned long int	i;
	unsigned long int	j;

	if (!b)
		return ;
	i = n;
	j = ft_strlen(b);
	if (i >= j && ln >= 0)
	{
		ln--;
		putn_hx(i / j, b, ln, t_structor);
		t_structor->total++;
	}
	else
		t_structor->total++;
	ft_putchar(b[i % j]);
}

void	x_rays(t_printf *t_structor)
{
	if (t_structor->hashtag == 1 && t_structor->minus == 1
		&& t_structor->precision < t_structor->width
		&& t_structor->little_x == 1)
	{	
		t_structor->tmp = 1;
		print_little_x(t_structor);
	}
	else if (t_structor->hashtag == 1 && t_structor->minus == 1
		&& t_structor->precision < t_structor->width
		&& t_structor->big_x == 1)
	{	
		t_structor->tmp = 1;
		print_big_x(t_structor);
	}
}