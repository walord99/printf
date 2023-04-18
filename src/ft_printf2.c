/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bplante <bplante@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 22:46:28 by Ben               #+#    #+#             */
/*   Updated: 2023/04/18 13:35:20 by bplante          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

char	*format(char *str, va_list args, unsigned int *char_amount);
int		number_char_amount(int n);
int		arg_to_string(va_list args, char *str, char *specifier);
char	*pad_zero(char *input, int pad_len);

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

char	*format(char *str, va_list args, unsigned int *char_amount)
{
	char	*flags_ptr;

	flags_ptr = str;
	while (!ft_isalpha(*str) && !str)
		str++;
	if (str)
		return (str);
	*char_amount += arg_to_string(args, flags_ptr, str);
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
// c s p d i u x X %
// precision
// left pad with 0
// left align
// 0x/0X on hex
// add space in front of number
// add + if number is positive
//
// if left pad with zero works with + and ' '

int	arg_to_string(va_list args, char *flags_start, char *specifier)
{
	return (0);
}

char	*precision(char *str, char *input, unsigned int flags_len)
{
	size_t	precision_len;
	char	*output;

	precision_len = 0;
	while (flags_len)
	{
		if (str[flags_len - 1] == '.')
			precision_len = ft_atoi(&str[flags_len]);
		flags_len--;
	}
	if (precision_len > ft_strlen(input))
		output = pad_zero(input, precision_len);
	else
		output = input;
	return (output);
}

int	minimum_width(char *str)
{
	while (!ft_isdigit(*str))
		str++;
	if (*str == '0')
		str++;
	if (ft_isdigit(*str))
		return (ft_atoi(str));
	return (0);
}

char	*left_pad_space(char *input, int pad_len)
{
	int		str_len;
	int		i;
	char	*output;

	output = input;
	str_len = ft_strlen(input);
	if (pad_len > str_len)
	{
		output = ft_calloc(pad_len + 1, sizeof(char));
		i = 0;
		while (i++ < pad_len - str_len)
			output[i - 1] = ' ';
		ft_strlcat(output, input, pad_len + 1);
		free(input);
	}
	return (output);
}

char	*right_pad_space(char *input, int pad_len)
{
	int		str_len;
	int		i;
	char	*output;

	output = input;
	str_len = ft_strlen(input);
	if (pad_len > str_len)
	{
		output = ft_calloc(pad_len + 1, sizeof(char));
		ft_strlcat(output, input, pad_len + 1);
		i = pad_len;
		while (i-- > str_len)
			output[i] = ' ';
		free(input);
	}
	return (output);
}

char	*pad_zero(char *input, int pad_len)
{
	char	*output;

	output = ft_calloc(pad_len + 1, sizeof(char));
	ft_strlcpy(output + (pad_len - ft_strlen(input)), input, 3);
	pad_len -= ft_strlen(input);
	while (pad_len--)
		output[pad_len] = '0';
	free(input);
	return (output);
}
