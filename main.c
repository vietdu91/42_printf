/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 14:13:09 by emtran            #+#    #+#             */
/*   Updated: 2021/08/05 21:08:12 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <stdio.h>
#include <limits.h>

int main()
{
//	int	a;

//	a = 2014;
	printf("------------------------------------\n");
	printf("LE VRAI PRINTF DIT : %d\n", printf(" %-9p %-10p ", LONG_MIN, LONG_MAX));
	printf("TON FT_PRINT DIT : %d\n", ft_printf(" %-9p %-10p ", LONG_MIN, LONG_MAX));
	printf("------------------------------------\n");

	printf("===========================================================\n");

/*	printf("LE VRAI PRINTF DIT : %d\n", printf("%5.15p\n", a));
	printf("TON FT_PRINT DIT : %d\n", ft_printf("%5.15p\n", a));
	printf("------------------------------------\n");
	printf("LE VRAI PRINTF DIT : %d\n", printf("%15.5p\n", a));
	printf("TON FT_PRINT DIT : %d\n", ft_printf("%15.5p\n", a));
	printf("------------------------------------\n");
	printf("LE VRAI PRINTF DIT : %d\n", printf("%10.p\n", a));
	printf("TON FT_PRINT DIT : %d\n", ft_printf("%10.p\n", a));
	printf("------------------------------------\n");
	printf("LE VRAI PRINTF DIT : %d\n", printf("%10p\n", a));
	printf("TON FT_PRINT DIT : %d\n", ft_printf("%10p\n", a));
	printf("------------------------------------\n");
	printf("LE VRAI PRINTF DIT : %d\n", printf("%.10p\n", a));
	printf("TON FT_PRINT DIT : %d\n", ft_printf("%.10p\n", a));
	printf("------------------------------------\n");
	printf("LE VRAI PRINTF DIT : %d\n", printf("%-15.5p\n", a));
	printf("TON FT_PRINT DIT : %d\n", ft_printf("%-15.5p\n", a));
	printf("------------------------------------\n");
	printf("LE VRAI PRINTF DIT : %d\n", printf("%-5.15p\n", a));
	printf("TON FT_PRINT DIT : %d\n", ft_printf("%-5.15p\n", a));
	printf("------------------------------------\n");
	printf("LE VRAI PRINTF DIT : %d\n", printf("%-15.p\n", a));
	printf("TON FT_PRINT DIT : %d\n", ft_printf("%-15.p\n", a));
	printf("------------------------------------\n");
	printf("LE VRAI PRINTF DIT : %d\n", printf("%-15p\n", a));
	printf("TON FT_PRINT DIT : %d\n", ft_printf("%-15p\n", a));
	printf("------------------------------------\n");
	printf("LE VRAI PRINTF DIT : %d\n", printf("%-5.15p\n", a));
	printf("TON FT_PRINT DIT : %d\n", ft_printf("%-5.15p\n", a));
	printf("------------------------------------\n");
	printf("LE VRAI PRINTF DIT : %d\n", printf("%-15.p\n", a));
	printf("TON FT_PRINT DIT : %d\n", ft_printf("%-15.p\n", a));
	printf("------------------------------------\n");
	printf("LE VRAI PRINTF DIT : %d\n", printf("%-15p\n", a));
	printf("TON FT_PRINT DIT : %d\n", ft_printf("%-15p\n", a));
	printf("------------------------------------\n");
	printf("LE VRAI PRINTF DIT : %d\n", printf("%-.15p\n", a));
	printf("TON FT_PRINT DIT : %d\n", ft_printf("%-.15p\n", a));
	printf("------------------------------------\n");

	printf("===========================================================\n");

	printf("LE VRAI PRINTF DIT : %d\n", printf("%05.15p\n", a));
	printf("TON FT_PRINT DIT : %d\n", ft_printf("%05.15p\n", a));
	printf("------------------------------------\n");
	printf("LE VRAI PRINTF DIT : %d\n", printf("%015.5p\n", a));
	printf("TON FT_PRINT DIT : %d\n", ft_printf("%015.5p\n", a));
	printf("------------------------------------\n");
	printf("LE VRAI PRINTF DIT : %d\n", printf("%010.p\n", a));
	printf("TON FT_PRINT DIT : %d\n", ft_printf("%010.p\n", a));
	printf("------------------------------------\n");
	printf("LE VRAI PRINTF DIT : %d\n", printf("%010p\n", a));
	printf("TON FT_PRINT DIT : %d\n", ft_printf("%010p\n", a));
	printf("------------------------------------\n");
	printf("LE VRAI PRINTF DIT : %d\n", printf("%0.10p\n", a));
	printf("TON FT_PRINT DIT : %d\n", ft_printf("%0.10p\n", a));
	printf("------------------------------------\n");
	printf("LE VRAI PRINTF DIT : %d\n", printf("%-015.5p\n", a));
	printf("TON FT_PRINT DIT : %d\n", ft_printf("%-015.5p\n", a));
	printf("------------------------------------\n");
	printf("LE VRAI PRINTF DIT : %d\n", printf("%-05.15p\n", a));
	printf("TON FT_PRINT DIT : %d\n", ft_printf("%-05.15p\n", a));
	printf("------------------------------------\n");
	printf("LE VRAI PRINTF DIT : %d\n", printf("%-015.p\n", a));
	printf("TON FT_PRINT DIT : %d\n", ft_printf("%-015.p\n", a));
	printf("------------------------------------\n");
	printf("LE VRAI PRINTF DIT : %d\n", printf("%-015p\n", a));
	printf("TON FT_PRINT DIT : %d\n", ft_printf("%-015p\n", a));
	printf("------------------------------------\n");
	printf("LE VRAI PRINTF DIT : %d\n", printf("%-05.15p\n", a));
	printf("TON FT_PRINT DIT : %d\n", ft_printf("%-05.15p\n", a));
	printf("------------------------------------\n");
	printf("LE VRAI PRINTF DIT : %d\n", printf("%-015.p\n", a));
	printf("TON FT_PRINT DIT : %d\n", ft_printf("%-015.p\n", a));
	printf("------------------------------------\n");
	printf("LE VRAI PRINTF DIT : %d\n", printf("%-015p\n", a));
	printf("TON FT_PRINT DIT : %d\n", ft_printf("%-015p\n", a));
	printf("------------------------------------\n");
	printf("LE VRAI PRINTF DIT : %d\n", printf("%-0.15p\n", a));
	printf("TON FT_PRINT DIT : %d\n", ft_printf("%-0.15p\n", a));
	printf("------------------------------------\n");*/
}
