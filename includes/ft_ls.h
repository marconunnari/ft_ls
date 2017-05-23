/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/14 18:21:37 by mnunnari          #+#    #+#             */
/*   Updated: 2017/05/23 19:31:23 by mnunnari         ###   ########.fr       */
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
# include <limits.h>

# ifndef __APPLE__
#  define st_atimespec            st_atim
#  define st_mtimespec            st_mtim
#  define st_ctimespec            st_ctim
#  define st_birthtimespec        st_birthtim
# endif

typedef struct	s_args
{
	char		*opts;
	t_btree		*files;
	int			is_first;
	int			newline;
	int			maxlinks;
	int			maxuser;
	int			maxgroup;
	int			maxsize;
	int			considerdirsize;
	long long	blocks;
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
	dev_t		devtype;
}				t_file;

char			get_file_type(mode_t mode);
char			*get_username(long uid);
char			*get_groupname(long gid);
char			*get_permissions(mode_t mode);
t_args			*parse_args(int argc, char **argv);
void			ls(t_args *args);
t_btree			*parse_files(t_list *files);
t_btree			*get_dirfiles(char *dirname, t_args *args);
t_file			*get_file(char *name, t_args *args);
long			ft_btree_cmp_ls(t_btree *b1, t_btree *b2, char *opts);
void			ft_btree_apply_infix_ls(t_btree *root, t_args *args,
				void (*applyf)(t_btree*, t_args *));
void			ft_btreeadd_ls(t_btree **root, t_btree *new, char *opts,
				long (*cmpf)(t_btree*, t_btree*, char*));
void			print_file(t_file *file, t_args *args);
char			*removepath(char *name);
void			error(char *filename, t_args *args);
void			print_dir(char *name, t_args *args);
void			ft_btree_not_dirs(t_btree *b, t_args *args);
void			ft_btree_dirs(t_btree *b, t_args *args);
void			ft_btree_all(t_btree *b, t_args *args);
void			print_long(t_file *file, t_args *args);
#endif
