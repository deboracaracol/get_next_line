/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaracol <dcaracol@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 13:05:50 by dcaracol          #+#    #+#             */
/*   Updated: 2023/06/05 17:46:29 by dcaracol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*cat;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s1)
	{
		s1 = malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	cat = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!cat)
		return (NULL);
	while (s1[i] != '\0')
	{
		cat[i] = s1[i];
		i++;
	}
	free(s1);
	while (s2[j] != '\0')
		cat[i++] = s2[j++];
	cat[i] = '\0';
	return (cat);
}

int	ft_recap(char *content)
{
	int	i;
	int	j;
	int	tf;

	i = 0;
	j = 0;
	tf = 0;
	while (content[i])
	{
		if (tf == 1)
			content[j++] = content[i];
		if (content[i] == '\n')
			tf = 1;
		content[i++] = '\0';
	}
	return (tf);
}

void	ft_clean_content(char *content)
{
	int	i;

	i = 0;
	while (content[i])
		content[i++] = '\0';
}
