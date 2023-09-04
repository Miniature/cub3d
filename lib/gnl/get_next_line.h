/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdavey <wdavey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 14:20:36 by wdavey            #+#    #+#             */
/*   Updated: 2023/07/19 15:25:28 by wdavey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifdef BUFFER_SIZE
#  if BUFFER_SIZE < 1
#   error BUFFER_SIZE is less than 1
#  endif
# else
#  define BUFFER_SIZE 1028
# endif

char	*get_next_line(int fd);

#endif
