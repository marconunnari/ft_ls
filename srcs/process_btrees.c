/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_btrees.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 19:25:25 by mnunnari          #+#    #+#             */
/*   Updated: 2017/05/30 20:18:31 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		process_dir(char *name, t_args *args)
{
	if (args->newline)
		ft_printf("\n");
	ft_printf("%s:\n", name);
	print_dir(name, args);
}

int			is_current_or_parent(char *name)
{
	name = removepath(name);
	return (ft_strequ(name, ".") || ft_strequ(name, ".."));
}

void		ft_btree_dirs(t_btree *b, t_args *args)
{
	t_file		*file;

	file = (t_file*)b->content;
	if (file == NULL)
		return ;
	if (file->type == 'd')
	{
		if (args->is_first)
		{
			process_dir(file->name, args);
			args->newline = 1;
		}
		else if (!is_current_or_parent(file->name))
		{
			if (ft_strcont(args->opts, 'R'))
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
}

void		ft_btree_all(t_btree *b, t_args *args)
{
	t_file	*file;

	file = (t_file*)b->content;
	if (file == NULL)
		return ;
	print_file(file, args);
}

void		ft_btree_not_dirs(t_btree *b, t_args *args)
{
	t_file	*file;

	file = (t_file*)b->content;
	if (file == NULL)
		return ;
	if (file->type != 'd')
	{
		args->newline = 1;
		print_file(file, args);
	}
}
