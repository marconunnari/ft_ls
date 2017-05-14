/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/14 18:22:33 by mnunnari          #+#    #+#             */
/*   Updated: 2017/05/14 18:22:56 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_btree_strcmp(t_btree *b1, t_btree *b2)
{
	return (ft_strcmp((char*)b1->content, (char*)b2->content));
}

char		*get_type(mode_t mode)
{
	switch (mode & S_IFMT)
	{
	case S_IFBLK:  return ("block device");
	case S_IFCHR:  return ("character device");
	case S_IFDIR:  return ("directory");
	case S_IFIFO:  return ("FIFO/pipe");
	case S_IFLNK:  return ("symlink");
	case S_IFREG:  return ("regular file");
	case S_IFSOCK: return ("socket");
	default:       return ("unknown?");
	}
}

void		ft_btree_putstr(t_btree *b)
{
	struct stat info;

	printf("%s: \n", (char*)b->content);
	stat((char*)b->content, &info);
	printf("\t%s: %s\n", "Type", get_type(info.st_mode));
	printf("\t%s: %lo\n", "Modes", (unsigned long)info.st_mode);
	printf("\t%s: %ld\n", "Links number", (long)info.st_nlink);
	printf("\t%s: %ld\n", "Owner", (long)info.st_uid);
	printf("\t%s: %ld\n", "Owner group", (long)info.st_gid);
	printf("\t%s: %lld\n", "Size", (long long)info.st_size);
	printf("\t%s: %s\n", "Last file modification", ctime(&info.st_mtime));
}

int		main()
{
	t_btree *entries = NULL;
	DIR *dirp = opendir(".");
	struct dirent *entry;
	while ((entry = readdir(dirp)))
	{
		if (entries == NULL)
			entries = ft_btreenew(entry->d_name, 0);
		else
			ft_btreeadd(&entries, ft_btreenew(entry->d_name, 0),
				&ft_btree_strcmp);
	}
	ft_btree_apply_infix(entries, &ft_btree_putstr);
	closedir(dirp);
}
