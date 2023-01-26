/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: video-fl <video-fl@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 11:51:19 by video-fl          #+#    #+#             */
/*   Updated: 2023/01/26 15:39:04 by video-fl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char *print_hex(unsigned int value_hex)
{
    char *result;
    unsigned int remainder;
    unsigned int division;
    result = malloc(count_digits(value_hex) * sizeof(char));
    int i;
    //result = (char *)(value_hex);
    i = 0;
    remainder = value_hex % 16;
    division = value_hex / 16;
    
    if (remainder >= 10)
    {
        switch (remainder)
        {
        case 10:
            result[i] = 'a';
            i++;
            break;
        case 11:
            result[i] = 'b';
            i++;
            break;
        case 12:
            result[i] = 'c';
            i++;
            break;
        case 13:
            result[i] = 'd';
            i++;
            break;
        case 14:
            result[i] = 'e';
            i++;
            break;
        case 15:
            result[i] = 'f';
            i++;
            break;
        default:
            break;
        }
    }
    
    //printf("\nresult: %s", result);
    return result;
}