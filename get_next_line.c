/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaracol <dcaracol@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 13:05:50 by dcaracol          #+#    #+#             */
/*   Updated: 2023/06/05 17:56:59 by dcaracol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_clean_all(char *content, char *line)
{
	ft_recap(content);
	free (line);
	return (NULL);
}

char	*ft_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\n' && line[i])
		i++;
	if (line[i + 1] != '\0')
		line[i + 1] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	static char		content[BUFFER_SIZE + 1];
	char			*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (read(fd, content, 0) < 0)
	{
		ft_clean_content(content);
		free (line);
		return (NULL);
	}
	while (content[0] || (read(fd, content, BUFFER_SIZE)))
	{
		line = ft_strjoin(line, content);
		if (!line)
			line = ft_clean_all(content, line);
		if (ft_recap(content) == 1)
		{
			line = ft_line(line);
			break ;
		}
	}
	return (line);
}

//ar -rcs get_next_line.a *.c
//cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 <files>.c

// int    main(void)
// {
// 	int    a = open("exemplo.txt", O_RDONLY);
// 	//char *y = NULL;
// 	char *x;
// 	x = get_next_line(a);
// 	printf("%s", x);
// 	free(x);
// 	//x = get_next_line(a);
// 	x = get_next_line(a);
// 	printf("%s", x);
// 	free(x);
// 	//x = get_next_line(a);
// 	x = get_next_line(a);
// 	printf("%s", x);
// 	free(x);
// 	//x = get_next_line(a);
// 	x = get_next_line(a);
// 	printf("%s", x);
// 	free(x);
// 	x = get_next_line(a);
// 	printf("%s", x);
// 	free(x);
// 	x = get_next_line(a);
// 	printf("%s", x);
// 	free(x);
// 	x = get_next_line(a);
// 	printf("%s", x);
// 	free(x);
// 	x = get_next_line(a);
// 	printf("%s", x);
// 	free(x);
// 	 close(a);
// 	return (0);
// }
