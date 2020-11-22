/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerebus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 19:34:13 by cerebus           #+#    #+#             */
/*   Updated: 2020/11/15 19:34:17 by cerebus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t i;

	i = 0;
	if (!dst || !src)
		return (0);
	if (dstsize == 0)
		return (0);
	while ((i < dstsize - 1) && (src[i] != '\0'))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (0);
}

static int		ft_count_words(char const *s, char c)
{
	int i;
	int words_num;

	i = 0;
	words_num = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			words_num++;
		while (s[i] != '\0' && s[i] != c)
			i++;
	}
	return (words_num);
}

static char		**ft_get_mem(int arr_num, char **res, int start, int end)
{
	res[arr_num] = (char *)malloc((end - start + 2) * sizeof(char));
	if (!res[arr_num])
	{
		arr_num = arr_num - 1;
		while (arr_num >= 0)
		{
			free(res[arr_num]);
			arr_num--;
		}
		free(res);
		return (NULL);
	}
	return (res);
}

static char		**ft_fill_res(char **res, char const *s, char c, int words_num)
{
	int i;
	int start;
	int end;
	int arr_num;

	i = 0;
	start = 0;
	end = 0;
	arr_num = 0;
	while (s[i] != '\0' && arr_num < words_num)
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		start = i;
		while (s[i] != c && s[i] != '\0')
			i++;
		end = i - 1;
		if (!ft_get_mem(arr_num, res, start, end))
			return (NULL);
		ft_strlcpy(res[arr_num], &s[start], end - start + 2);
		arr_num++;
	}
	res[arr_num] = NULL;
	return (res);
}

char			**ft_split(char const *s, char c)
{
	int		words_num;
	char	**res;

	if (!s || !c)
		return (NULL);
	words_num = ft_count_words(s, c);
	res = (char **)malloc((words_num + 1) * sizeof(char **));
	if (!res)
		return (NULL);
	return (ft_fill_res(res, s, c, words_num));
}
