/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 14:55:03 by emtran            #+#    #+#             */
/*   Updated: 2021/08/14 15:25:58 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	print_uns_nbr(t_printf *t_structor, va_list ap)
{
	unsigned int	nbr;
	unsigned int	nbrmax;
	int				len;

	if (!ap)
		return ;
	nbr = va_arg(ap, unsigned int);
	nbrmax = 4294967295;
	len = ft_nbrlen_u(nbrmax + nbr + 1, B10);
	inspection_douaniere(t_structor);
	highway_chatou(nbr, len, t_structor);
	if (t_structor->precision > len
		&& t_structor->precision < t_structor->widthor)
		print_zero(t_structor->precision, len, t_structor);
	if (t_structor->precision > 0 || t_structor->width > 0)
		ft_putn_unsnbr(nbr, len, t_structor);
	else
		ft_put_unsnbr(nbr, t_structor);
	highway_argenteuil(nbr, len, t_structor);
	clean_prec_and_width(t_structor);
}

void	ft_put_unsnbr(unsigned int n, t_printf *t_structor)
{	
	if (n == 0 && (t_structor->crash == 1 || t_structor->zero_prec == 1))
		return ;
	if (n >= 10)
		ft_put_unsnbr(n / 10, t_structor);
	ft_putchar(n % 10 + 48);
	t_structor->total++;
}

void	ft_putn_unsnbr(unsigned int n, int len, t_printf *t_structor)
{	
	if (n == 0 && (t_structor->crash == 1 || t_structor->zero_prec == 1))
		return ;
	if (n >= 10 && len >= 0)
	{
		len--;
		ft_putn_unsnbr(n / 10, len, t_structor);
	}
	ft_putchar(n % 10 + 48);
	t_structor->total++;
}
