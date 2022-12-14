/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: video-fl <video-fl@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 19:36:13 by video-fl          #+#    #+#             */
/*   Updated: 2022/12/14 15:58:36 by video-fl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


char	*ft_strchr(const char *s, int c)
{ // busca primeira ocorrencia de c e retorna resultante
	while (*s != (char)c)
	{
		if (*s == '\0' && (char)c != '\0')
			return (0);
		s++;
	}
	return ((char *)s);
}

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

void check_arg(char *arg, int index)
{
	if (arg[index + 1] == '%')
		printf("--> double %% <--");
	else if (arg[index + 1] == 'c')
		printf("--> c <--");
	if (arg[index + 1] == 'd')
		printf("%d", 12);
	/*
		aqui nao deu certo pq n tenho acesso a lista dos argumentos, entao n consigo
		acessar o prox argumento que seria o numero ncessario
	*/
}

void filter_func(char *arg)
{
    //int symbol;
    int len;
    int i;

    i = 0;
    len = ft_strlen(arg);
    //printf("\narg: %s, len = %d\n", arg, len);

	while (i < len)
	{
		if (arg[i] != '%')
			ft_putchar_fd(arg[i], 1);
		else 
		{
			//printf("\npassou aqui no else\n");
			check_arg(arg, i);
			i++;
		}
		i++;
	}
	/*
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
	*/

    /* 
    Nessa parte, eu tenho que criar a busca das variaveis dentro da string para
    imprimir da forma correta. Da pra usar o strnstr pra buscar como needle.
    */
}

