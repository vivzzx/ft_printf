/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: video-fl <video-fl@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 15:42:53 by video-fl          #+#    #+#             */
/*   Updated: 2022/12/20 16:20:24 by video-fl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void loop_print(char *to_print)
{
    int counter;
    int size;

    counter = 0;
    size = ft_strlen(to_print);
    //printf("\n counter inicio: %d\n", counter);
    while (counter < size)
    {
        ft_putchar(to_print[counter], 1);
        //printf("\n counter: %d -- char: %c", counter, to_print[counter]);
        counter++;
    }
}