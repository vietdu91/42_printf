/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 09:17:01 by emtran            #+#    #+#             */
/*   Updated: 2021/08/05 19:59:36 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define B10 "0123456789"
# define B16LX "0123456789abcdef"
# define B16BX "0123456789ABCDEF"

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_structor
{
	int		total;
	int		count;
	int		plus;
	int		space;
	int		hashtag;
	int		zero;
	int		minus;
	int		dot;
	int		precision;
	int		width;
	int		crash;
	int		d_and_i;
	int		little_x;
	int		big_x;
	int		adress;
	int		tmp;
}				t_printf;

/* FT_PRINTF the base */

int			ft_printf(const char *str, ...);
void		checker_cocktail(const char *str, t_printf *t_structor, va_list ap);
t_printf	back_to_birth(t_printf *t_structor);

/* Checkpoint */

void		check_flag(char c, t_printf *t_structor);
void		check_width(const char *str, t_printf *t_structor);
void		check_precision(const char *str, t_printf *t_structor);
void		check_conversion(char c, t_printf *t_structor, va_list ap);

/* Inspecteur Gadget */

int			roulette_a_flags(char c);
int			ft_isdigit(int c);
void		inspection_douaniere(t_printf *t_structor);

/* Gestion of flags */

void		flag_plus(t_printf *t_structor);
void		flag_space(t_printf *t_structor);
void		flag_hashtag(t_printf *t_structor);
void		flag_zero(t_printf *t_structor);
void		flag_minus(t_printf *t_structor);

/** Usine of flags */

int			print_zero(int start, int end, t_printf *t_structor);
int			print_space(int start, int end, t_printf *t_structor);
void		print_minus(int nbr, t_printf *t_structor);
void		print_plus(t_printf *t_structor);
void		xxxtentacion(t_printf *t_structor);

/* La grandeur d'un homme peut se mesurer à la grandeur 
des choses qui l'angoissent */

int			ft_strlen(const char *str);
int			ft_nbrlen(long int n, char *base, t_printf *t_structor);
int			ft_nbrlen_u(unsigned int n, char *base);
int			the_temporisation(int tmp, t_printf *t_structor);

/* UTILS Print les string */

void		ft_putchar(char c);
void		ft_putstr(char *str, t_printf *t_structor);
void		the_remplisseur_str(char *str, t_printf *t_structor);
void		the_remplisseur_str_simple(char *str, t_printf *t_structor);
void		the_remplisseur_str_doub(char *str, t_printf *t_structor, int tmp);

/* Un homme de caractère n'a pas bon caractère [C] */

void		print_char(t_printf *t_structor, va_list ap);
void		print_char_inv(t_printf *t_structor, char c);

/* Une chaîne a la force de son maillon le plus faible [S] */

void		print_str(t_printf *t_structor, va_list ap);
void		ft_putnstr_simple_p(char *str, t_printf *t_structor);
void		ft_putnstr_simple_w(char *str, t_printf *t_structor);
void		ft_putnstr_double(char *str, t_printf *t_structor);

/* UTILS Print les numbers */

void		ft_putnbr(long int n, t_printf *t_structor);
int			ft_atoi(const char *str, t_printf *t_structor);
void		the_remplisseur_nbr(int nbr, int len, t_printf *t_structor);
void		the_remplisseur_nbr_simple(int nbr, int len, t_printf *t_structor);
void		the_remp_nbr_doub(int nbr, int len, t_printf *t_structor, int tmp);

/* Le nombre des saveurs est infini. [D & I] */

void		print_nbr(t_printf *t_structor, va_list ap);
void		ft_putnnbr(long int nbr, int len, t_printf *t_structor);
void		fork_of_minus(int nbr, t_printf *t_structor);
void		being_overwhelmed(int nbr, int len, int tmp, t_printf *t_structor);

/* UTILS Print les numbers non-signés */

void		remplisseur_unbr(unsigned int nbr, int len, t_printf *t_structor);
void		rp_unbr_simple(unsigned int nbr, int len, t_printf *t_structor);
void		rp_unb_d(unsigned int nbr, int len, t_printf *t_structor, int tmp);

/* Il ne faut jamais signer avant de voir le diable. [U] */

void		print_uns_nbr(t_printf *t_structor, va_list ap);
void		ft_put_unsnbr(unsigned int n, t_printf *t_structor);
void		ft_putn_unsnbr(unsigned int n, int len, t_printf *t_structor);

/* UTILS Print les hexas */

void		print_big_x(t_printf *t_structor);
void		print_little_x(t_printf *t_structor);
void		remplisseur_hexa(int len, t_printf *t_structor);
void		rp_hexa_simple(int len, t_printf *t_structor);
void		rp_hexa_d(int len, t_printf *t_structor, int tmp);

/* Quiconque né en ce lieu est condamné à y rester jusqu'à la mort. [xX] */

void		print_little_hexa(t_printf *t_structor, va_list ap);
void		print_big_hexa(t_printf *t_structor, va_list ap);
void		put_hexa(unsigned long int nbr, char *base, t_printf *t_structor);
void		putn_hx(unsigned long int n, char *b, int ln, t_printf *t_structor);
void		x_rays(t_printf *t_structor);

/* C'est par l'adresse que vaut le bûcheron, bien plus que par la force. [P] */

void		print_adress(t_printf *t_structor, va_list ap);
void		remplisseur_addr(int len, t_printf *t_structor);
void		rp_addr_simple(int len, t_printf *t_structor);
void		rp_addr_d(int len, t_printf *t_structor, int tmp);

/* Taux reduit d'imposition des plus-values à long terme [%] */

void		print_percent(t_printf *t_structor);
void		print_percent_inv(t_printf *t_structor);

#endif