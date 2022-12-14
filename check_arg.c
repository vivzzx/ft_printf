/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: video-fl <video-fl@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 19:36:13 by video-fl          #+#    #+#             */
/*   Updated: 2022/12/08 20:12:45 by video-fl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_strrchr(const char *s, int c)
{
	int	size;

	size = ft_strlen(s);
	while (size >= 0)
	{
		if (s[size] == (char)c)
			return ((char *)s + size);
		size--;
	}
	return (NULL);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	n_len;
	char	*str;

	i = 0;
	str = (char *)haystack;
	n_len = ft_strlen(needle);
	if (needle[0] == '\0')
		return (str);
	while (str[i] != '\0' && i < len)
	{
		j = 0;
		while ((str[i + j] != '\0') && (needle[j] != '\0')
			&& (str[i + j] == needle[j]) && (i + j < len))
			j++;
		if (j == n_len)
			return (str + i);
		i++;
	}
	return (0);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void check_arg(char *arg)
{
    int symbol;
    int len;
    int i;

    i = 0;
    len = ft_strlen(arg);
    //printf("\narg: %s, len = %d\n", arg, len);
    if (ft_strrchr(arg, '%') == NULL)
        symbol = 0;
    else
        symbol = 1;

    if (symbol == 0)
        printf("\n%s", arg);
    else {
        while (i < len)
        {
            if (arg[i] == '%')
                printf("temos um %%");
            else
                printf("%c", arg[i]);
            i++;
        }
    }
    //if ()    
    //printf("\nsymbol %%: %d\n", symbol);

    /* 
    Nessa parte, eu tenho que criar a busca das variaveis dentro da string para
    imprimir da forma correta. Da pra usar o strnstr pra buscar como needle.
    */
}