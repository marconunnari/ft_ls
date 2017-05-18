/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/14 18:21:37 by mnunnari          #+#    #+#             */
/*   Updated: 2017/05/18 19:03:49 by mnunnari         ###   ########.fr       */
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
	int		newline;
}				t_args;

typedef struct	timespec
				t_time;

typedef struct	s_file
{
	char		*name;
	char		type;
	char		*permissions;
	long		links;
	char		*user;
	char		*group;
	long long	size;
	t_time		mtime;
}				t_file;

char			get_type(mode_t mode);
char			*get_username(long uid);
char			*get_groupname(long gid);
char			*get_permissions(mode_t mode);
t_args			*parse_args(int argc, char **argv);
void			ls(t_args *args);
t_btree			*parse_files(t_list *files);
t_btree			*get_dirfiles(char *dirname, t_args *args);
t_file			*get_file(char *name);
long			ft_btree_cmp(t_btree *b1, t_btree *b2, char *opts);
void			ft_btree_apply_infix_ls(t_btree *root, t_args *args,
				void (*applyf)(t_btree*, t_args *));
void			ft_btreeadd_ls(t_btree **root, t_btree *new, char *opts,
				long (*cmpf)(t_btree*, t_btree*, char*));
void			print_file(t_file *file, t_args *args);
char			*get_file_name_without_path(char *name);
#endif
