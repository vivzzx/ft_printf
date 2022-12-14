/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: video-fl <video-fl@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 12:19:02 by video-fl          #+#    #+#             */
/*   Updated: 2022/12/14 17:52:58 by video-fl         ###   ########.fr       */
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
    filter_func2(args, count);
    /*
    while (i < count)
    {
        char *value = va_arg(args, char *);
        printf("%d: %s\n", i, value);
        //filter_func(value);
        i++;
    }*/

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
    ft_printf("teste", "aqui %d um numero %d vai shsu%dhs", 12, 2.2, 29);

    return (0);
}

/*
gcc ft_printf.h ft_printf.c ft_strlen.c filter_func.c && ./a.out
*/