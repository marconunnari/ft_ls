/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 20:02:34 by mnunnari          #+#    #+#             */
/*   Updated: 2017/05/18 20:03:14 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		print_dir(char *name, t_args *args)
{
	t_btree		*files;
	t_args		*new_args;

	IFRETURNVOID(!(new_args = (t_args*)malloc(sizeof(t_args))));
	new_args->opts = args->opts;
	new_args->maxlinks = 0;
	new_args->maxsize = 0;
	new_args->blocks = 0;
	files = get_dirfiles(name, new_args);
	new_args->files = files;
	new_args->is_first = 0;
	if (ft_strcont(new_args->opts, 'l'))
		printf("total %lld\n", new_args->blocks);
	ls(new_args);
}

void		process_dir(char *name, t_args *args)
{
	if (args->newline)
		printf("\n");
	printf("%s:\n", name);
	print_dir(name, args);
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
		if (args->is_first)
		{
			process_dir(file->name, args);
			args->newline = 1;
		}
		else if (ft_strcont(args->opts, 'R'))
		{
			args->newline = 1;
			process_dir(file->name, args);
		}
		else
		{
			print_file(file, args);
			args->newline = 1;
		}
	}
}

void		ft_btree_all(t_btree *b, t_args *args)
{
	t_file	*file;

	(void)args;
	file = (t_file*)b->content;
	print_file(file, args);
}

void		ft_btree_not_dirs(t_btree *b, t_args *args)
{
	t_file	*file;

	file = (t_file*)b->content;
	if (file->type != 'd')
	{
		args->newline = 1;
		print_file(file, args);
	}
}

int		onlyonedir(t_args *args)
{
	t_file	*file;

	if (args->files->left || args->files->right)
		return (0);
	file = (t_file*)args->files->content;
	if (file->type != 'd')
		return (0);
	return (1);
}

void		first_call_multiple_files(t_args *args)
{
	ft_btree_apply_infix_ls(args->files, args, &ft_btree_not_dirs);
	ft_btree_apply_infix_ls(args->files, args, &ft_btree_dirs);
}

void		first_call(t_args *args)
{
	if (args->files == NULL)
		print_dir(".", args);
	else if (onlyonedir(args))
		print_dir(((t_file*)args->files->content)->name, args);
	else
		first_call_multiple_files(args);

}

void		not_first_call(t_args *args)
{
	ft_btree_apply_infix_ls(args->files, args, &ft_btree_all);
	if (ft_strcont(args->opts, 'R'))
		ft_btree_apply_infix_ls(args->files, args, &ft_btree_dirs);
}

void			ls(t_args *args)
{
	if (args->is_first)
		first_call(args);
	else
		not_first_call(args);
}
