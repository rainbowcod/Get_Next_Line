/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmatske <olmatske@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 14:22:43 by olmatske          #+#    #+#             */
/*   Updated: 2025/08/20 20:13:45 by olmatske         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

typedef struct s_list
{
	char *str;

}	t_list;

# ifndef BUFFER_SIZE
#	define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);


# endif