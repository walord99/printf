/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ben <benplante99@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 22:46:28 by Ben               #+#    #+#             */
/*   Updated: 2023/04/05 01:50:43 by Ben              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

char	*format(char *str, va_list args, unsigned int *char_amount);
int		number_char_amount(int n);
char	*arg_to_string(char specifier, va_list args, char flag, int width,
			int precision);

int	ft_printf(const char *str, ...)
{
	unsigned int	i;
	unsigned int	char_amount;
	va_list			args;

	i = 0;
	char_amount = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
			i += (format((char *)str + i + 1, args, &char_amount) - str) + 1;
		else
		{
			ft_putchar_fd(str[i], 1);
			char_amount++;
		}
		i++;
	}
	va_end(args);
	return (char_amount);
}

// #+ -0 https://cplusplus.com/reference/cstdio/printf/
// atoi
//aoit
// put them in struct
char	*format(char *str, va_list args, unsigned int *char_amount)
{
	char	*output;
	char	flag;
	int		width;
	int		precision;

	if ((flag = *ft_strchr("#+ -0", *str)))
		str++;
	if ((width = ft_atoi(str)))
		str += number_char_amount(width);
	if (*str == '.')
	{
		precision = ft_atoi(++str);
		str += number_char_amount(precision);
	}
	else
		precision = 0;
	output = arg_to_string(*str, args, flag, width, precision);
	ft_putstr(output);
	*char_amount = ft_strlen(output);
	return (str);
}

int	number_char_amount(int n)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (n / j != 0)
	{
		i++;
		j *= 10;
	}
	return (1);
}

char	*arg_to_string(char specifier, va_list args, char flag, int width,
		int precision)
{
	va_arg(args, int);
	specifier = (char)specifier;
	flag = (char)flag;
	width = (int)width;
	precision = (int)precision;
	return ("hello");
}
