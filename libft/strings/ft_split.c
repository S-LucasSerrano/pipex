/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slucas-s <slucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 13:34:23 by slucas-s          #+#    #+#             */
/*   Updated: 2021/04/21 18:00:09 by slucas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_str.h"

static int	ft_lettercount(const char *str, char c)
{
	int	lcount;

	lcount = 0;
	while (str[lcount] != c && str[lcount] != '\0')
		lcount++;
	return (lcount);
}

/* Creates -using malloc- a 2D table containing <str>
splited in the strings separated by <c> */
char	**ft_split(const char *str, char c)
{
	char	**output;
	int		wordcount;
	int		wordindex;
	int		lettercount;

	if (str == NULL)
		return (NULL);
	wordcount = ft_wordcount(str, c);
	output = malloc(sizeof(char *) * wordcount + 1);
	if (output == NULL)
		return (NULL);
	wordindex = 0;
	while (wordindex < wordcount)
	{
		while (*str == c)
			str++;
		lettercount = ft_lettercount(str, c);
		output[wordindex] = ft_substr(str, 0, lettercount);
		if (output[wordindex] == NULL)
			return (NULL);
		str += lettercount;
		wordindex++;
	}
	output[wordindex] = NULL;
	return (output);
}
