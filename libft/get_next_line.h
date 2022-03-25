/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tratanat <tawan.rtn@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 09:34:32 by tratanat          #+#    #+#             */
/*   Updated: 2022/03/22 20:52:24 by tratanat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

# define BUFFER_SIZE 1

typedef struct s_storedlst
{
	int					fd;
	char				*stored;
	struct s_storedlst	*next;
}	t_storedlst;

char	*get_next_line(int fd);
int		checknl(char **output, char *buffer, int fd, t_storedlst **readlst);
int		storeline(char *buffer, int fd, t_storedlst **readlst);
int		getstored(t_storedlst **readlst, char **output, int fd);
void	ft_bzero(char *buffer, int size);
int		ft_strlen(char *str);
char	*ft_strnjoin(char *dst, char *src, int n);
void	ft_lstdelone(t_storedlst **readlst, t_storedlst *target);
char	*ft_strdup(char *src);

#endif
