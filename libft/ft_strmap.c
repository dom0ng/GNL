/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 19:13:41 by julin             #+#    #+#             */
/*   Updated: 2017/11/30 22:28:10 by julin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(const char *s, char (*f)(char))
{
	char	*new_str;
	int		i;

	new_str = NULL;
	if (s != NULL && (f) != NULL)
	{
		i = 0;
		while (s[i] != '\0')
			i++;
		new_str = malloc(sizeof(char) * i + 1);
		i = 0;
		if (new_str != NULL)
		{
			while (s[i] != '\0')
			{
				new_str[i] = (f)(s[i]);
				i++;
			}
			new_str[i] = '\0';
		}
	}
	return (new_str);
}
