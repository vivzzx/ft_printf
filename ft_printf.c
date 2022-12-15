/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: video-fl <video-fl@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 12:19:02 by video-fl          #+#    #+#             */
/*   Updated: 2022/12/15 18:08:06 by video-fl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf(const char *str, ...)
{
    int i = 0;
    //contador - 1o arg e terminador
    int count = ft_strlen(str) - 1;
    //printf("\ncount: %d\n", count);
    va_list args;

    va_start(args, str);
    filter_func2(args);
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
    unsigned int a = 42;
    int b = 0;
    // Official Test
    //printf("\tOfficial printf test:\n");
    // mais um teste aqui
    //printf("oi eu sou" "um print f" "outro aqui %d\n", a);

    // unOfficial Test
    printf("\tunOfficial printf test:\n");
    //ft_printf("teste", "O numero %u significa prosperidade. %%O numero %d, amor; %d: alegria. %d eh o seu numero da sorte. Toma mais um numero ai %d. %cim!\n", a, 2, 52, 55, 987, 'F');
    
    //ft_printf("teste", "String %d: %s\n", 12, "eu sou um novo string");

    ft_printf("teste", "\nString %d -- endereco: %p\n", 12, &a);


    return (0);
}

/*
gcc ft_printf.h ft_printf.c ft_strlen.c filter_func2.c ft_itoa.c && ./a.out
*/