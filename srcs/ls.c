/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 20:02:34 by mnunnari          #+#    #+#             */
/*   Updated: 2017/05/16 23:19:50 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_file			*get_file(char *name)
{
	t_file		*res;
	struct stat	info;

	stat(name, &info);
	res = (t_file*)malloc(sizeof(t_file));
	res->name = name;
	res->type = get_type(info.st_mode);
	return (res);
}

t_btree			*parse_files(t_list *files)
{
	int				i;
	t_btree			*entries;
	t_btree			*entry;
	t_file			*file;

	i = 0;
	entries = NULL;
	while (files)
	{
		file = get_file(files->content);
		if (!(entry = ft_btreenew(file, sizeof(t_file))))
			return (NULL);
		if (entries == NULL)
			entries = entry;
		else
			ft_btreeadd(&entries, entry, &ft_btree_cmp);
		files = files->next;
	}
	return (entries);
}

void		ft_btree_putstr(t_btree *b)
{
	t_file *file = (t_file*)b->content;
	printf("name: %s\n", file->name);
	printf("type: %c\n", file->type);
}

void			ls(t_args *args, int first)
{
	(void)first;
	t_btree		*entries;

	entries = parse_files(args->files);
	ft_btree_apply_infix(entries, &ft_btree_putstr);
/*
	parse files in binary tree
	for file in files:
		if is a file:
			print it
			and remove from files binary tree
	for dir in dirs:
		if (!args->first)
			print "name :"
		set args->files to the files of dir
		ls with new args
	printf("\t%s: %c\n", "Type", get_type(info.st_mode));
*/
}
