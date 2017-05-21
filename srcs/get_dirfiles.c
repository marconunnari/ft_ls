/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_dirfiles.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 16:08:48 by mnunnari          #+#    #+#             */
/*   Updated: 2017/05/21 23:30:52 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_btree			*get_dirfiles(char *dirname, t_args *args)
{
	t_btree		*files;
	t_btree		*file;
	t_file		*tfile;
	char		*filename;

	files = NULL;
	dirname = ft_strjoin(dirname, "/");
	DIR *dirp = opendir(dirname);
	if (dirp == NULL)
	{
		error(dirname, args);
		return (NULL);
	}
	struct dirent *entry;
	while ((entry = readdir(dirp)))
	{
		if (entry->d_name[0] == '.' && !ft_strcont(args->opts, 'a'))
			continue;
		filename = ft_strjoin(dirname, entry->d_name);
		if (!(tfile = get_file(filename, args)))
			continue;
		if (!(file = ft_btreenew(tfile, sizeof(t_file))))
			return (NULL);
		if (files == NULL)
			files = file;
		else
			ft_btreeadd_ls(&files, file, args->opts, &ft_btree_cmp);
	}
	closedir(dirp);
	return (files);
}
