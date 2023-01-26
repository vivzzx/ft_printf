/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: video-fl <video-fl@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 12:19:02 by video-fl          #+#    #+#             */
/*   Updated: 2023/01/26 15:48:56 by video-fl         ###   ########.fr       */
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
    filter_func2(str, args);
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
    int b = 255;
    unsigned int hex = 1150;
    char *str = "Hello there";
    // Official Test
    printf("\t Official printf test: \n");
    printf("Teste 0: %s\n", str);
    printf("Teste 1: %x in hexadecimal = %x\n", b, hex);
    // mais um teste aqui
    //printf("oi eu sou" "um print f" "outro aqui %d\n", a);

    // unOfficial Test
    printf("\n\tun-Official printf test:");
    ft_printf("Teste 0: %s\n", str);
    ft_printf("Teste 1: %x in hexadecimal = %x\n", b, hex);
    //ft_printf("teste", "O numero %u significa prosperidade. %%O numero %d, amor; %d: alegria. %d eh o seu numero da sorte. Toma mais um numero ai %d. %cim!\n", a, 2, 52, 55, 987, 'F');
    
    //ft_printf("teste", "String %d: %s\n", 12, "eu sou um novo string");

    //ft_printf("teste", "\nString %d -- endereco: %p\n", 12, &a);
    //ft_printf("Teste 1: %x in hexadecimal = %x\n", b, hex);

    return (0);
}

/*

gcc ft_printf.h ft_printf.c ft_strlen.c filter_func2.c ft_putchar.c loop_print.c ft_itoa.c hex.c count_digits.c && ./a.out
*/