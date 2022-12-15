/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter_func2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: video-fl <video-fl@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 16:14:05 by video-fl          #+#    #+#             */
/*   Updated: 2022/12/15 18:22:06 by video-fl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void loop_print(char *to_print)
{
    int counter;
    int size;

    counter = 0;
    size = ft_strlen(to_print);
    //printf("\n counter inicio: %d\n", counter);
    while (counter < size)
    {
        ft_putchar_fd(to_print[counter], 1);
        //printf("\n counter: %d -- char: %c", counter, to_print[counter]);
        counter++;
    }
}

void check_arg(va_list args, char next)
{
    char *to_print;
    int size = 1;
    // values
    char value_char = '\0';
    int value_int = 0;
    unsigned int value_ui = 0;
    unsigned long value_hex = 0;

	if (next == '%') // ok
		ft_putchar_fd('%', 1);
	if (next == 'c') // ok
    {
        value_char = va_arg(args, int); //implicit conversion **note 1
		ft_putchar_fd(value_char, 1);
    }
	if (next == 'd' || next == 'i') // ok
    {
        value_int = va_arg(args, int);
        to_print = ft_itoa(value_int);
        loop_print(to_print);
    }
    if (next == 's') // string
    {
        to_print = va_arg(args, char *);
        //printf("\nto_print: %s | digitos: %d", to_print, size);
        loop_print(to_print);
    }
    if (next == 'u') // unsigned int --> OK
    {
        value_ui = va_arg(args, unsigned int);
        //printf("\n unsigned int %u \n", value_ui);
        to_print = ft_itoa(value_ui);
        loop_print(to_print);
    }
    if (next == 'p') // memory address
    {
        //value_hex = va_arg(args, void *);
        //printf("\n%p\n", value_hex);
    }
    if (next == 'x') // hexadecimal
    {
        // usar unsigned long -> ver como funciona
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