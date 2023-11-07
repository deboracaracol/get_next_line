/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaracol <dcaracol@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 13:05:50 by dcaracol          #+#    #+#             */
/*   Updated: 2023/06/12 15:14:18 by dcaracol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	static char		content[FOPEN_MAX][BUFFER_SIZE + 1];
	char			*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || fd > FOPEN_MAX)
		return (NULL);
	if (read(fd, content[fd], 0) < 0)
	{
		ft_clean_content(content[fd]);
		free (line);
		return (NULL);
	}
	while (content[fd][0] || (read(fd, content[fd], BUFFER_SIZE)))
	{
		line = ft_strjoin(line, content[fd]);
		if (!line)
			line = ft_clean_all(content[fd], line);
		if (ft_recap(content[fd]) == 1)
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
