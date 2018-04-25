/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enennige <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 16:59:38 by enennige          #+#    #+#             */
/*   Updated: 2018/04/24 22:28:09 by enennige         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>

int	main(void)
{
	printf("hello %2s I am %+#12.5d years old.", "world", 28);
	printf("\n");
	ft_printf("hello %2s I am %+#12.5d years old.", "world", 28);
	printf("\n");
}
