/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 20:02:34 by mnunnari          #+#    #+#             */
/*   Updated: 2017/05/17 19:21:37 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char		*get_file_name_without_path(char *name)
{
	char	*slash;

	if ((slash = ft_strrchr(name, '/')))
		name = slash + 1;
	return (name);
}

void		print_file(char *name)
{
	name = get_file_name_without_path(name);
	printf("%s\n", name);
}

void		process_dir(char *name, t_args *args)
{
	t_btree		*files;
	t_args		*new_args;

	printf("\n%s:\n", name);
	files = get_dirfiles(name, args);
	IFRETURNVOID(!(new_args = (t_args*)malloc(sizeof(t_args))));
	new_args->files = files;
	new_args->is_first = 0;
	new_args->opts = args->opts;
	ls(new_args);
}

int			is_current_or_parent(char *name)
{
	name = get_file_name_without_path(name);
	return (ft_strequ(name, ".") || ft_strequ(name, ".."));
}

void		ft_btree_dirs(t_btree *b, t_args *args)
{
	t_file		*file;

	file = (t_file*)b->content;
	if (file->type == 'd' && !is_current_or_parent(file->name))
	{
		if (args->is_first || ft_strcont(args->opts, 'R'))
			process_dir(file->name, args);
		else
			print_file(file->name);
	}
}

void		ft_btree_all(t_btree *b, t_args *args)
{
	(void)args;
	t_file *file = (t_file*)b->content;
	print_file(file->name);
}

void		ft_btree_not_dirs(t_btree *b, t_args *args)
{
	(void)args;
	t_file *file = (t_file*)b->content;
	if (file->type != 'd')
		print_file(file->name);
}

void			ls(t_args *args)
{
	if (args->is_first)
	{
		ft_btree_apply_infix_ls(args->files, args, ft_btree_not_dirs);
		ft_btree_apply_infix_ls(args->files, args, &ft_btree_dirs);
	}
	else
	{
		ft_btree_apply_infix_ls(args->files, args, &ft_btree_all);
		if (ft_strcont(args->opts, 'R'))
			ft_btree_apply_infix_ls(args->files, args, &ft_btree_dirs);
	}
}
