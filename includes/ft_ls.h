/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/14 18:21:37 by mnunnari          #+#    #+#             */
/*   Updated: 2017/05/14 18:21:57 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <stdio.h>

# include "libft.h"
# include <dirent.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <time.h>
# include <pwd.h>
# include <grp.h>

# ifndef __APPLE__
#  define st_atimespec            st_atim
#  define st_mtimespec            st_mtim
#  define st_ctimespec            st_ctim
#  define st_birthtimespec        st_birthtim
# endif

typedef struct	s_args
{
	char	*opts;
	t_list	*files;
}		t_args;

char		get_type(mode_t mode);
char		*get_username(long uid);
char		*get_groupname(long gid);
char		*get_permissions(mode_t mode);

#endif
