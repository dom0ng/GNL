/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 01:47:53 by julin             #+#    #+#             */
/*   Updated: 2018/04/23 04:09:42 by julin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
**** Get the file descriptor five in param.
*/

static	t_list		*ft_get_fd(int fd, t_list **start)
{
	t_list			*current;
	t_list			*test;

	current = (*start);
	test = current;
	while (current)
	{
		if ((int)current->content_size == fd)
			return (current);
		current = current->next;
	}
	current = ft_lstnew("\0", 1);
	current->content_size = fd;
	if (current == NULL)
		return (NULL);
	ft_lstadd(start, current);
	return (current);
}

/*
**** Copy the string/line before the first '\n' encountered.
*/

static	int			ft_copy_line(char **line, char *src)
{
	int				index;
	int				len;

	len = 0;
	index = 0;
	while (src[len] != '\n' && src[len])
		len++;
	(*line) = (char*)malloc(sizeof(char) * (len + 1));
	if ((*line) == NULL)
		return (-1);
	(*line)[len] = 0;
	while (src[index] != '\n' && src[index])
	{
		(*line)[index] = src[index];
		index++;
	}
	return (len);
}

/*
**** Read the file until it reach the end or
**** if it found a new line in the read content
*/

static	char		*ft_strjoin_and_free(char *s1, char *s2, char **line)
{
	size_t			len;
	char			*str;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	str = (char*)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	str[len] = 0;
	str = ft_strcpy(str, s1);
	str = ft_strcat(str, s2);
	if (s1 && s1 != *line)
		free(s1);
	return (str);
}

static	void		ft_decal_n_free(int size, t_list **new)
{
	char	*tmp;
	char	*tmp2;

	if ((*new)->content != NULL)
	{
		tmp = (*new)->content;
		if (ft_strlen((*new)->content) != (size_t)size)
			(*new)->content = (*new)->content + (size + 1);
		else
			(*new)->content = (*new)->content + (size);
		tmp2 = ft_strdup((*new)->content);
		free(tmp);
		(*new)->content = tmp2;
	}
}

/*
**** Get the next line of the file descriptor given in param.
*/

int					get_next_line(const int fd, char **line)
{
	int				ret[2];
	static t_list	*start;
	t_list			*new;
	char			buf[BUFF_SIZE + 1];

	ret[1] = 0;
	if (fd < 0 || line == NULL)
		return (-1);
	*line = NULL;
	new = ft_get_fd(fd, &start);
	while ((ret[0] = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret[0]] = 0;
		if ((new->content = ft_strjoin_and_free(new->content,
						buf, line)) == NULL)
			return (-1);
		if (ft_strchr(new->content, '\n') != NULL)
			break ;
	}
	if (ret[0] == 0 && ft_strlen(new->content) == 0)
		return (0);
	if ((ret[1] = ft_copy_line(line, new->content)) == -1 || ret[0] == -1)
		return (-1);
	ft_decal_n_free(ret[1], &new);
	return (1);
}
