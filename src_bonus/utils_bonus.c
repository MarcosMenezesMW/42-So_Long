/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameneze <mameneze@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 19:49:51 by mameneze          #+#    #+#             */
/*   Updated: 2021/09/08 21:47:47 by mameneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	ft_intlen(int n)
{
	int		len;

	len = 0;
	if (n <= 0)
		len++;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	n_value;
	int		i;

	n_value = n;
	i = ft_intlen(n);
	str = malloc(i + 1);
	if (!str)
		return (NULL);
	str[i--] = '\0';
	if (n_value == 0)
		str[i] = '0';
	while (n_value > 0)
	{
		str[i--] = n_value % 10 + '0';
		n_value /= 10;
	}
	return (str);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

static void	*ft_memset(void *str, int c, size_t n)
{
	unsigned char	*p_str;

	p_str = str;
	while (n > 0)
	{
		*p_str = c;
		p_str++;
		n--;
	}
	return (str);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	ft_memset(ptr, 0, nmemb * size);
	return (ptr);
}
