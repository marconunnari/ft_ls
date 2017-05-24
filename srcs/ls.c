/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 20:02:34 by mnunnari          #+#    #+#             */
/*   Updated: 2017/05/24 16:17:55 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

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
	else if (args->files->content == NULL)
		return ;
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

void		ft_btree_free(t_btree *b)
{
	t_file	*tfile;

	tfile = (t_file*)b->content;
	if (tfile != NULL)
	{
		free(tfile->name);
		free(tfile->permissions);
		free(tfile);
	}
	free(b);
}

void			ls(t_args *args)
{
	if (args->is_first)
		first_call(args);
	else
		not_first_call(args);
	ft_btree_apply_suffix(args->files, &ft_btree_free);
	free(args->opts);
	free(args);
}
