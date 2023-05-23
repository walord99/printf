/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bplante <bplante@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 13:55:59 by bplante           #+#    #+#             */
/*   Updated: 2023/05/23 11:54:17 by bplante          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft.h"
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_options
{
	char	flag;
	int		width;
	int		precision;
	char	specifier;
}			t_options;

int			ft_printf(const char *str, ...);
int			get_flag(char *str, t_options *options);
int			get_width(char *str, t_options *options);
int			get_precision(char *str, t_options *options);
int			get_specifier(char *str, t_options *options);
int			get_options(char *str, t_options *options);
int			number_char_amount(int n);
char		*char_to_str(char c);
char		*arg_to_int(int i);
char		*arg_to_str(char *str);
char		*arg_to_uint_hex(unsigned long num, int is_caps);
char		num_to_hex(int num, int is_caps);
char		*arg_to_uint(unsigned int num);
char		*arg_to_ptr(void *ptr);
int			ft_putstr_e(char *str, t_options *options);
int			format(va_list args, char **str, int char_amount);
char		*specifier_selector(va_list args, char c);

#endif
