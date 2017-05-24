/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_dirfiles.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 16:08:48 by mnunnari          #+#    #+#             */
/*   Updated: 2017/05/24 15:45:35 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int				parse_entry(char *dirname, t_args *args,
						struct dirent *entry, t_btree **files)
{
	t_btree		*file;
	t_file		*tfile;
	char		*filename;

	if (entry->d_name[0] == '.' && !ft_strcont(args->opts, 'a'))
		return (1);
	filename = ft_strjoin(dirname, entry->d_name);
	if (!(tfile = get_file(filename, args)))
		return (1);
	free(filename);
	if (!(file = ft_btreenew(tfile, sizeof(t_file))))
		return (0);
	free(tfile);
	if (files == NULL)
		*files = file;
	else
		ft_btreeadd_ls(files, file, args->opts, &ft_btree_cmp_ls);
	return (1);
}

t_btree			*get_dirfiles(char *dirname, t_args *args)
{
	t_btree		*files;
	struct dirent	*entry;

	files = NULL;
	dirname = ft_strjoin(dirname, "/");
	DIR *dirp = opendir(dirname);
	if (dirp == NULL)
	{
		error(dirname, args);
		return (NULL);
	}
	while ((entry = readdir(dirp)))
	{
		if (parse_entry(dirname, args, entry, &files) == 0)
			return (0);
	}
	free(dirname);
	closedir(dirp);
	return (files);
}
