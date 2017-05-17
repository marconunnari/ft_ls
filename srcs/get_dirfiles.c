/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_dirfiles.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 16:08:48 by mnunnari          #+#    #+#             */
/*   Updated: 2017/05/17 18:04:42 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_btree			*get_dirfiles(char *dirname)
{
	t_btree		*files;
	t_btree		*file;
	t_file		*tfile;
	char		*filename;

	files = NULL;
	dirname = ft_strjoin(dirname, "/");
	DIR *dirp = opendir(dirname);
	struct dirent *entry;
	while ((entry = readdir(dirp)))
	{
		if (entry->d_name[0] == '.')
			continue;
		filename = ft_strjoin(dirname, entry->d_name);
		IFNOTRETURN((tfile = get_file(filename)), NULL);
		IFNOTRETURN((file = ft_btreenew(tfile, sizeof(t_file))), NULL);
		if (files == NULL)
			files = file;
		else
			ft_btreeadd(&files, file, &ft_btree_cmp);
	}
	closedir(dirp);
	return (files);
}
