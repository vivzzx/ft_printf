/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_digits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: video-fl <video-fl@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 12:20:09 by video-fl          #+#    #+#             */
/*   Updated: 2023/01/26 12:29:37 by video-fl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int count_digits(int num)
{
    int count;
    long long n;

    count = 0;
    n = num;
    while (n != 0)
    {
        n = n / 10;
        count++;
    }
    return (count);
}