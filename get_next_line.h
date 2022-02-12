/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidrissi <yidrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 17:37:16 by yidrissi          #+#    #+#             */
/*   Updated: 2022/02/12 02:47:22 by yidrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

char	*get_next_line(int fd);
int		ft_strlen(char *src);
char	*ft_my_strjoin(char *src, char *mot, int a);
char	*ft_my_substr(char *s, int start, int len, int free_or_not);
char	*ft_calloc(int count, int size);
int		ft_strchr(char *str);
void	ft_free_str(char **p);

#endif