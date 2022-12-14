/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter_func2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: video-fl <video-fl@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 16:14:05 by video-fl          #+#    #+#             */
/*   Updated: 2022/12/14 17:42:39 by video-fl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void filter_func2(va_list args, int count)
{
    int i = 0;
    int num_args = 0;
    char *value = va_arg(args, char *);
    int size = ft_strlen(value);

    while (num_args < count) // loop em todos os args
    {
        while (i < size)
        {
            printf("\narg %d: %s", num_args, value);
            i++;
        }


        num_args++;
    }
}