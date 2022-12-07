/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: video-fl <video-fl@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 12:19:02 by video-fl          #+#    #+#             */
/*   Updated: 2022/12/07 16:39:46 by video-fl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "ft_printf.h"
#include <stdio.h>
#include <stdarg.h>
#include <string.h>

int ft_printf(const char *str, ...)
{
    int j = 0;
    va_list args;

    va_start(args, str);

    while (j < 3)
    {
        printf("\narg %d: %c\n", j, str[j]);
        if (str[j] == '%')
            printf("\ntem uma porcentagem aqui\n");
        j++;
    }

    for (int i = 0; i < 3; i++)
    {
        char *value = va_arg(args, char *);
        printf("%d: %s\n", i, value);
    }

    va_end(args);
    
    return (0);
}

int main()
{
    // Official Test
    //printf("\tOfficial printf test:\n");
    // mais um teste aqui
    //printf();

    // unOfficial Test
    printf("\tunOfficial printf test:\n");
    ft_printf("teste", "hola", "que %dqueisso", "tal");

    return (0);
}