/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 14:13:09 by emtran            #+#    #+#             */
/*   Updated: 2021/08/04 15:08:54 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <stdio.h>
#include <limits.h>

int main()
{
	int	a;

	a = -2046;
/*	printf("------------------------------------\n");
	printf("LE VRAI PRINTF DIT : %d\n", printf("%d\n", a));
	printf("TON FT_PRINT DIT : %d\n", ft_printf("%d\n", a));
	printf("------------------------------------\n");*/

	printf("===========================================================\n");

	printf("LE VRAI PRINTF DIT : %d\n", printf("%5.15u\n", a));
	printf("TON FT_PRINT DIT : %d\n", ft_printf("%5.15u\n", a));
	printf("------------------------------------\n");
	printf("LE VRAI PRINTF DIT : %d\n", printf("%15.5u\n", a));
	printf("TON FT_PRINT DIT : %d\n", ft_printf("%15.5u\n", a));
	printf("------------------------------------\n");
	printf("LE VRAI PRINTF DIT : %d\n", printf("%10.u\n", a));
	printf("TON FT_PRINT DIT : %d\n", ft_printf("%10.u\n", a));
	printf("------------------------------------\n");
	printf("LE VRAI PRINTF DIT : %d\n", printf("%10u\n", a));
	printf("TON FT_PRINT DIT : %d\n", ft_printf("%10u\n", a));
	printf("------------------------------------\n");
	printf("LE VRAI PRINTF DIT : %d\n", printf("%.10u\n", a));
	printf("TON FT_PRINT DIT : %d\n", ft_printf("%.10u\n", a));
	printf("------------------------------------\n");
	printf("LE VRAI PRINTF DIT : %d\n", printf("%-15.5u\n", a));
	printf("TON FT_PRINT DIT : %d\n", ft_printf("%-15.5u\n", a));
	printf("------------------------------------\n");
	printf("LE VRAI PRINTF DIT : %d\n", printf("%-5.15u\n", a));
	printf("TON FT_PRINT DIT : %d\n", ft_printf("%-5.15u\n", a));
	printf("------------------------------------\n");
	printf("LE VRAI PRINTF DIT : %d\n", printf("%-15.u\n", a));
	printf("TON FT_PRINT DIT : %d\n", ft_printf("%-15.u\n", a));
	printf("------------------------------------\n");
	printf("LE VRAI PRINTF DIT : %d\n", printf("%-15u\n", a));
	printf("TON FT_PRINT DIT : %d\n", ft_printf("%-15u\n", a));
	printf("------------------------------------\n");
	printf("LE VRAI PRINTF DIT : %d\n", printf("%-5.15u\n", a));
	printf("TON FT_PRINT DIT : %d\n", ft_printf("%-5.15u\n", a));
	printf("------------------------------------\n");
	printf("LE VRAI PRINTF DIT : %d\n", printf("%-15.u\n", a));
	printf("TON FT_PRINT DIT : %d\n", ft_printf("%-15.u\n", a));
	printf("------------------------------------\n");
	printf("LE VRAI PRINTF DIT : %d\n", printf("%-15u\n", a));
	printf("TON FT_PRINT DIT : %d\n", ft_printf("%-15u\n", a));
	printf("------------------------------------\n");
	printf("LE VRAI PRINTF DIT : %d\n", printf("%-.15u\n", a));
	printf("TON FT_PRINT DIT : %d\n", ft_printf("%-.15u\n", a));
	printf("------------------------------------\n");

	printf("===========================================================\n");

	printf("LE VRAI PRINTF DIT : %d\n", printf("%05.15u\n", a));
	printf("TON FT_PRINT DIT : %d\n", ft_printf("%05.15u\n", a));
	printf("------------------------------------\n");
	printf("LE VRAI PRINTF DIT : %d\n", printf("%015.5u\n", a));
	printf("TON FT_PRINT DIT : %d\n", ft_printf("%015.5u\n", a));
	printf("------------------------------------\n");
	printf("LE VRAI PRINTF DIT : %d\n", printf("%010.u\n", a));
	printf("TON FT_PRINT DIT : %d\n", ft_printf("%010.u\n", a));
	printf("------------------------------------\n");
	printf("LE VRAI PRINTF DIT : %d\n", printf("%010u\n", a));
	printf("TON FT_PRINT DIT : %d\n", ft_printf("%010u\n", a));
	printf("------------------------------------\n");
	printf("LE VRAI PRINTF DIT : %d\n", printf("%0.10u\n", a));
	printf("TON FT_PRINT DIT : %d\n", ft_printf("%0.10u\n", a));
	printf("------------------------------------\n");
	printf("LE VRAI PRINTF DIT : %d\n", printf("%-015.5u\n", a));
	printf("TON FT_PRINT DIT : %d\n", ft_printf("%-015.5u\n", a));
	printf("------------------------------------\n");
	printf("LE VRAI PRINTF DIT : %d\n", printf("%-05.15u\n", a));
	printf("TON FT_PRINT DIT : %d\n", ft_printf("%-05.15u\n", a));
	printf("------------------------------------\n");
	printf("LE VRAI PRINTF DIT : %d\n", printf("%-015.u\n", a));
	printf("TON FT_PRINT DIT : %d\n", ft_printf("%-015.u\n", a));
	printf("------------------------------------\n");
	printf("LE VRAI PRINTF DIT : %d\n", printf("%-015u\n", a));
	printf("TON FT_PRINT DIT : %d\n", ft_printf("%-015u\n", a));
	printf("------------------------------------\n");
	printf("LE VRAI PRINTF DIT : %d\n", printf("%-05.15u\n", a));
	printf("TON FT_PRINT DIT : %d\n", ft_printf("%-05.15u\n", a));
	printf("------------------------------------\n");
	printf("LE VRAI PRINTF DIT : %d\n", printf("%-015.u\n", a));
	printf("TON FT_PRINT DIT : %d\n", ft_printf("%-015.u\n", a));
	printf("------------------------------------\n");
	printf("LE VRAI PRINTF DIT : %d\n", printf("%-015u\n", a));
	printf("TON FT_PRINT DIT : %d\n", ft_printf("%-015u\n", a));
	printf("------------------------------------\n");
	printf("LE VRAI PRINTF DIT : %d\n", printf("%-0.15u\n", a));
	printf("TON FT_PRINT DIT : %d\n", ft_printf("%-0.15u\n", a));
	printf("------------------------------------\n");
}
