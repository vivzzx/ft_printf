/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter_func2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: video-fl <video-fl@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 16:14:05 by video-fl          #+#    #+#             */
/*   Updated: 2022/12/15 16:40:15 by video-fl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void loop_print(char *to_print, int digits)
{
    int counter = 0;
    while (counter < digits)
    {
        ft_putchar_fd(to_print[counter], counter);
        counter++;
    }
}

void check_arg(va_list args, char next)
{
    char *to_print;
    int digits = 1;
    int value_int = 0;

	if (next == '%')
		printf("--> double %% <--");
	if (next == 'c')
		printf("--> c <--");
	if (next == 'd')
    {
        value_int = va_arg(args, int);
        to_print = ft_itoa(value_int);
        digits = ft_strlen(to_print);
        loop_print(to_print, digits);
    }
}


void filter_func2(va_list args)
{
    int i = 0;
    int num_args = 0;
    char *value = va_arg(args, char *);
    int size = ft_strlen(value);

    //printf("\nsize: %d", size);
    while (i < size)
    {
        if (value[i] == '%')
        {
            //printf("\t tem um %% aqui\t");
            check_arg(args, value[i + 1]);
            
            i++;
        }
        else 
            ft_putchar_fd(value[i], 1);
        i++;

    }

}