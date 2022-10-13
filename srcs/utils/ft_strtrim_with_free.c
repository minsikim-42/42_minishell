/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim_with_free.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 16:01:24 by bahn              #+#    #+#             */
/*   Updated: 2022/01/24 15:49:40 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*start_point(char const *first, char const *set)
{
	char	*start;
	char	*last;

	start = (char *)first;
	last = start + ft_strlen(start) - 1;
	while (ft_strchr((char *)set, *start) && start < last)
		start++;
	return (start);
}

static char	*last_point(char const *first, char const *set)
{
	char	*last;

	if (ft_strlen((char *)first) == 0)
		return ((char *)first);
	last = (char *)(first + ft_strlen((char *)first) - 1);
	while (ft_strchr((char *)set, *last) && last > first)
		last--;
	return (last);
}

static int	set_checker(char *str, char const *set)
{
	char	*ptr;

	if (ft_strlen(str) == 0)
		return (1);
	ptr = (char *)set;
	if (ft_strlen(str) == 1)
	{
		while (*ptr != '\0')
		{
			if (*ptr == *str)
				return (1);
			ptr++;
		}
		return (0);
	}
	return (0);
}

char	*ft_strtrim_with_free(char *str, char const *set)
{
	char	*result;
	char	*s1_first;
	char	*s1_last;

	if (!str)
		return (NULL);
	s1_first = start_point(str, set);
	s1_last = last_point(str, set);
	if (set_checker(str, set) || s1_first > s1_last)
	{
		free(str);
		return (ft_strdup(""));
	}
	result = (char *)malloc(s1_last - s1_first + 2);
	if (result == NULL)
		return (NULL);
	ft_strlcpy(result, s1_first, s1_last - s1_first + 2);
	free(str);
	return (result);
}
