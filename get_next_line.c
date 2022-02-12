/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidrissi <yidrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 18:48:03 by yidrissi          #+#    #+#             */
/*   Updated: 2022/02/12 02:54:40 by yidrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
#endif

void	ft_bzero(char *str)
{
	int		i;

	i = 0;
	while (str && str[i])
	{
		*(str + i) = 0;
		i++;
	}
}

char	*ft_calloc(int count, int size)
{
	char	*result;
	int		i;

	i = 0;
	result = malloc(count * size);
	if (!result)
		return (0);
	while (i < (count * size))
	{
		*(result + i) = 0;
		i++;
	}
	return (result);
}

void	ft_init_rest(char **temp, char **result, char **rest, char **str_sub)
{
	*temp = 0;
	*result = 0;
	*str_sub = 0;
	if (*rest && *rest[0] != 0 && ft_strchr(*rest) == -1)
	{
		*result = ft_my_strjoin(*rest, *result, 0);
		*rest = 0;
	}
	else if (*rest && *rest[0] != 0)
	{
		*result = ft_my_substr(*rest, 0, ft_strchr(*rest) + 1, 0);
		*rest = ft_my_substr(*rest, ft_strchr(*rest) + 1, ft_strlen(*rest), 1);
	}
}

char	*get_next_line(int fd)
{
	char			*result;
	char			*temp;
	static char		*rest = 0;
	char			*str_sub;

	ft_init_rest(&temp, &result, &rest, &str_sub);
	temp = (char *)ft_calloc(BUFFER_SIZE + 1, 1);
	if (!temp)
		return (0);
	while (ft_strchr(result) == -1 && read(fd, temp, BUFFER_SIZE) > 0)
	{
		if (ft_strchr(temp) == -1)
			result = ft_my_strjoin(result, temp, 0);
		else
		{
			str_sub = ft_my_substr(temp, 0, ft_strchr(temp) + 1, 0);
			result = ft_my_strjoin(result, str_sub, 1);
			rest = ft_my_substr(temp, ft_strchr(temp) + 1, ft_strlen(temp), 0);
		}
		ft_bzero(temp);
	}
	ft_free_str(&temp);
	if ((rest && *rest == 0) || (rest && !result))
		ft_free_str(&rest);
	return (result);
}

// int	main(void)
// {
// 	char	*temp;
// 	int		fd;
// 	int		i;

// 	i = 1;
// 	fd = open("test.txt", O_RDONLY);
// 	while (i < 5)
// 	{
// 		temp = get_next_line(fd);
// 		printf("%d-%s", i++, temp);
// 	}
// }
