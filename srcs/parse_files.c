/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_files.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 14:34:00 by mnunnari          #+#    #+#             */
/*   Updated: 2017/05/17 14:34:54 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static t_file	*get_file(char *name)
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
