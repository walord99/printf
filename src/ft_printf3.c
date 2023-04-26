/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bplante <bplante@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 14:16:27 by bplante           #+#    #+#             */
/*   Updated: 2023/04/25 19:14:53 by bplante          ###   ########.fr       */
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

char	*arg_to_char(char c)
{
	char	*output;

	output = ft_calloc(2, sizeof(char));
	output[0] = c;
	return (output);
}

char	*arg_to_int(int i)
{
	return (ft_itoa(i));
}

char	*arg_to_str(char *str)
{
	char	*output;

	if (!str)
		output = ft_strdup("(null)");
	else
		output = ft_strdup(str);
	return (output);
}

char	*arg_to_uint_hex(unsigned long num, int is_caps)
{
	unsigned long	n_cpy;
	unsigned long	i;
	char			*str;

	n_cpy = num;
	i = 0;
	while (++i && n_cpy)
		n_cpy /= 16;
	if (num == 0)
		i++;
	str = ft_calloc(1, i);
	if (!str)
		return (0);
	else if (num == 0)
		str[0] = '0';
	while (num != 0)
	{
		str[i - 2] = num_to_hex(num % 16, is_caps);
		num /= 16;
		i--;
	}
	return (str);
}

char	num_to_hex(int num, int is_caps)
{
	char	maj;

	maj = 'a';
	if (is_caps)
		maj = 'A';
	if (num > 9)
		return (num - 10 + maj);
	return (num + '0');
}

char	*arg_to_uint(unsigned int num)
{
	unsigned int	n_cpy;
	unsigned int	i;
	char			*str;

	n_cpy = num;
	i = 0;
	while (++i && n_cpy)
		n_cpy /= 10;
	if (num == 0)
		i++;
	str = ft_calloc(1, i);
	if (!str)
		return (0);
	else if (num == 0)
		str[0] = '0';
	while (num != 0)
	{
		str[i - 2] = num % 10 + '0';
		num /= 10;
		i--;
	}
	return (str);
}

char	*arg_to_ptr(void *ptr)
{
	char	*output;
	char	*str;

	str = arg_to_uint_hex((unsigned long)ptr, 0);
	output = ft_strjoin("0x", str);
	free(str);
	return (output);
}

char	*percentage(void)
{
	return (ft_strdup("%"));
}

int	ft_printf(const char *str, ...)
{
	int		char_amount;
	va_list	args;

	char_amount = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str != '%')
		{
			if (write(1, str, 1) == -1)
				return (-1);
			char_amount++;
		}
		else
		{
			str++;
			char_amount = format(args, (char **)&str, char_amount);
			if (char_amount == -1)
				return (-1);
		}
		str++;
	}
	va_end(args);
	return (char_amount);
}

int		ft_putstr_e(char *str, t_options *options);
{
	int i;

	i = 0;
	if (options->specifier == 'c')
	{
		i = 1;
		write(1, &str[0], 1);
	}
	while (str[i])
	{
		if (write(1, str + i, 1) == -1)
			return (-1);
		i++;
	}
	return (i);
}

int	format(va_list args, char **str, int char_amount)
{
	char		*output;
	int			i;
	t_options	*options;

	options = ft_calloc(sizeof(t_options), 1);
	if (get_options(*str, options) == -1)
		return (-1);
	*str = ft_strchr(*str, options->specifier);
	output = specifier_selector(args, options->specifier);
	//output = apply_options(output, options);
	i = ft_putstr_e(output, options);
	free(options);
	free(output);
	if (i == -1)
		return (-1);
	return (char_amount + i);
}

char	*specifier_selector(va_list args, char c)
{
	if (c == 'c')
		return (arg_to_char(va_arg(args, unsigned int)));
	else if (c == 's')
		return (arg_to_str(va_arg(args, char *)));
	else if (c == 'd' || c == 'i')
		return (arg_to_int(va_arg(args, int)));
	else if (c == 'x')
		return (arg_to_uint_hex(va_arg(args, unsigned int), 0));
	else if (c == 'X')
		return (arg_to_uint_hex(va_arg(args, unsigned int), 1));
	else if (c == '%')
		return (percentage());
	else if (c == 'u')
		return (arg_to_uint(va_arg(args, unsigned int)));
	else
		return (arg_to_ptr(va_arg(args, void *)));
}

// char	*apply_options(char *str, t_options options)
// {
// 	if(options.width != 0)
// 	{

// 	}
// }
