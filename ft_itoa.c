/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: video-fl <video-fl@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 16:10:23 by video-fl          #+#    #+#             */
/*   Updated: 2022/12/15 16:20:43 by video-fl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	check_neg(int n)
{
	if (n < 0)
		return (1);
	else
		return (0);
}

static size_t	digits(size_t n)
{
	unsigned int	counter;

	counter = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 10;
		counter++;
	}
	return (counter);
}

char	*ft_itoa(int n)
{
	long int	number;
	int			size;
	char		*result;
	int			negative;

	number = n;
	negative = check_neg(n);
	if (negative == 1)
	{
		number = number * -1;
	}
	size = negative + digits(number);
	result = (char *)malloc((size + 1) * sizeof(char));
	if (!result)
		return (NULL);
	if (negative == 1)
		result[0] = '-';
	result[size] = '\0';
	while (size > negative)
	{
		result[(size - 1)] = (number % 10) + '0';
		number /= 10;
		size--;
	}
	return (result);
}
/*
int	main(void)
{
	char *result1;

	printf("\n*-* My function Test *-*");
	printf("\n\tTest 1:");
	result1 = ft_itoa(-2147483648);
	printf("\tResult 1: %s\n\n", result1);
	return (0);
}
*/