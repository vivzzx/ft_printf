/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: video-fl <video-fl@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 12:27:55 by video-fl          #+#    #+#             */
/*   Updated: 2022/12/20 16:20:41 by video-fl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

int ft_printf(const char *str, ...);

/* Helper Functions */
size_t	ft_strlen(const char *s);
void loop_print(char *to_print);
void	ft_putchar(char c, int fd);
//void filter_func(char *arg);
void filter_func2(va_list args);
char	*ft_itoa(int n);


#endif