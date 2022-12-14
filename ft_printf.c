/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: video-fl <video-fl@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 12:19:02 by video-fl          #+#    #+#             */
/*   Updated: 2022/12/08 20:13:24 by video-fl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf(const char *str, ...)
{
    int i = 0;
    //contador - 1o arg e terminador
    int count = ft_strlen(str) - 2;
    //printf("\ncount: %d\n", count);
    va_list args;

    va_start(args, str);

    while (i < count)
    {
        char *value = va_arg(args, char *);
        //printf("%d: %s\n", i, value);
        check_arg(value);
        i++;
    }

    va_end(args);
    
    return (0);
}

int main()
{
    //int a = 42;
    // Official Test
    //printf("\tOfficial printf test:\n");
    // mais um teste aqui
    //printf("oi eu sou" "um print f" "outro aqui %d\n", a);

    // unOfficial Test
    printf("\tunOfficial printf test:\n");
    ft_printf("teste", "hola", "que %dqueisso", "tal");

    return (0);
}

/*
gcc ft_printf.h ft_printf.c ft_strlen.c check_arg.c && ./a.out
*/