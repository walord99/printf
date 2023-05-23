/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_options.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bplante <bplante@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 11:41:49 by bplante           #+#    #+#             */
/*   Updated: 2023/05/23 11:55:51 by bplante          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_flag(char *str, t_options *options)
{
	if (ft_strchr("-+ #0", str[0]))
	{
		options->flag = str[0];
		return (1);
	}
	return (0);
}

int	get_width(char *str, t_options *options)
{
	if (ft_isdigit(str[0] && str[0] != '0'))
	{
		options->width = ft_atoi((const char *)&str[0]);
		return (number_char_amount(options->width));
	}
	return (0);
}

int	get_precision(char *str, t_options *options)
{
	if (str[0] == '.')
	{
		options->precision = ft_atoi((const char *)&str[1]);
		return (number_char_amount(options->precision) + 1);
	}
	return (0);
}

int	get_specifier(char *str, t_options *options)
{
	if (ft_strchr("cspdiuxX%", str[0]))
	{
		options->specifier = str[0];
		return (1);
	}
	return (0);
}

int	get_options(char *str, t_options *options)
{
	int	i;

	str += get_flag(str, options);
	str += get_width(str, options);
	str += get_precision(str, options);
	i = get_specifier(str, options);
	if (i <= 0)
		return (-1);
	return (0);
}
