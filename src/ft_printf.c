#include "ft_printf.h"
#include <stdlib.h>

int		check_flags(const char *str, va_list args, unsigned int *char_amount);
char	*find_type_flag(const char *str, const char *flagset);
int		char_flag(char c);
int		str_flag(char *str);
int		int_flag(int i);
int		uint_hex_flag(unsigned long uint, int is_caps);
int		perc_flag(void);
int		uint_flag(unsigned int num);
char	num_to_hex(int num, int is_caps);
int		ptr_flag(void *ptr);

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
			i += check_flags(&str[i + 1], args, &char_amount) + 1;
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

int	check_flags(const char *str, va_list args, unsigned int *char_amount)
{
	char	*flag;

	flag = find_type_flag(str, "cspdiuxX%");
	if (*flag == 'c')
		*char_amount += char_flag(va_arg(args, int));
	else if (*flag == 's')
		*char_amount += str_flag(va_arg(args, char *));
	else if (*flag == 'd' || *flag == 'i')
		*char_amount += int_flag(va_arg(args, int));
	else if (*flag == 'x')
		*char_amount += uint_hex_flag(va_arg(args, unsigned int), 0);
	else if (*flag == 'X')
		*char_amount += uint_hex_flag(va_arg(args, unsigned int), 1);
	else if (*flag == '%')
		*char_amount += perc_flag();
	else if (*flag == 'u')
		*char_amount += uint_flag(va_arg(args, unsigned int));
	else if (*flag == 'p')
		*char_amount += ptr_flag(va_arg(args, void *));
	return (flag - str);
}

char	*find_type_flag(const char *str, const char *flagset)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (flagset[j])
		{
			if (str[i] == flagset[j])
				return ((char *)&str[i]);
			j++;
		}
		i++;
	}
	return ((char *)str);
}

int	char_flag(char c)
{
	write(1, &c, 1);
	return (1);
}
int	str_flag(char *str)
{
	ft_putstr(str);
	return (ft_strlen(str));
}
int	int_flag(int i)
{
	char	*str;

	str = ft_itoa(i);
	ft_putstr(str);
	return (ft_strlen(str));
}
int	uint_hex_flag(unsigned long num, int is_caps)
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
	ft_putstr(str);
	i = ft_strlen(str);
	free(str);
	return (i);
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

int	perc_flag(void)
{
	write(1, "%", 1);
	return (1);
}

int	uint_flag(unsigned int num)
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
	ft_putstr(str);
	i = ft_strlen(str);
	free(str);
	return (i);
}

int	ptr_flag(void *ptr)
{
	ft_putstr("0x");
	return (2 + uint_hex_flag((unsigned long)ptr, 0));
}
