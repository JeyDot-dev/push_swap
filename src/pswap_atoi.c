/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pswap_atoi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsousa-a <jsousa-a@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 15:16:03 by jsousa-a          #+#    #+#             */
/*   Updated: 2023/09/16 14:34:43 by jsousa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long int	too_many_lines(const char *str, nb, isneg)
{
	if (*str || nb > 2147483647 || nb < -2147483648)
		return (2147483648);
	if (isneg == 1)
		return (nb *= -1);
	return (nb);
}

long long int	ps_atoi(const char *str)
{
	long long int	nb;
	int				isneg;

	isneg = 0;
	nb = 0;
	while ((*str && *str >= 9 && *str <= 13) || (*str && *str == 32))
		str++;
	if (*str == 43)
		str++;
	else if (*str == 45)
	{
		str++;
		isneg = 1;
	}
	if (*str < '0' || *str > '9')
		nb = 2147483848;
	while (ft_isdigit(*str))
	{
		nb *= 10;
		nb += *str - 48;
		str++;
	}
	return (too_many_lines(str, nb, isneg));
}
