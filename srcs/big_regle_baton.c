/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_regle_baton.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 18:10:37 by emtran            #+#    #+#             */
/*   Updated: 2021/08/04 13:56:46 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_strlen(const char *str)
{
	unsigned int	c;

	if (!str)
		return (0);
	c = 0;
	while (*(str + c))
	{
		c++;
	}
	return (c);
}

int	ft_nbrlen(long int n, char *base, t_printf *t_structor)
{
	size_t			base_nbr;
	unsigned int	i;

	base_nbr = ft_strlen(base);
	i = 0;
	if (n == 0)
		return (1);
	if (n == -2147483648)
	{
		n = 147483648;
		t_structor->total += 2;
	}
	if (n < 0)
		n = n * -1;
	while (n != 0)
	{
		n /= base_nbr;
		i++;
	}
	return (i);
}

int	ft_nbrlen_u(unsigned int n, char *base)
{
	size_t			base_nbr;
	unsigned int	i;

	base_nbr = ft_strlen(base);
	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		n = n * -1;
	while (n != 0)
	{
		n /= base_nbr;
		i++;
	}
	return (i);
}

int	the_temporisation(int tmp, t_printf *t_structor)
{
	t_structor->width--;
	tmp--;
	return (tmp);
}