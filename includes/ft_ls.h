/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/14 18:21:37 by mnunnari          #+#    #+#             */
/*   Updated: 2017/05/17 16:56:49 by mnunnari         ###   ########.fr       */
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
	t_btree	*files;
	int		is_first;
}				t_args;

typedef struct	s_file
{
	char		*name;
	char		type;
/*	char		*permissions;
	long		links;
	char		*owner;
	char		*group;
	long long	size;
	int			day;
	int			month;
	int			hours;
	int			minutes;*/
}				t_file;

char			get_type(mode_t mode);
char			*get_username(long uid);
char			*get_groupname(long gid);
char			*get_permissions(mode_t mode);
t_args			*parse_args(int argc, char **argv);
void			ls(t_args *args);
int				ft_btree_cmp(t_btree *b1, t_btree *b2);
t_btree			*parse_files(t_list *files);
t_btree			*get_dirfiles(char *dirname);
void	ft_btree_apply_infix_ls(t_btree *root, t_args *args,
		void (*applyf)(t_btree*, t_args *));
t_file			*get_file(char *name);
#endif
