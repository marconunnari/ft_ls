/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/14 18:22:33 by mnunnari          #+#    #+#             */
/*   Updated: 2017/05/15 17:47:45 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_btree_strcmp(t_btree *b1, t_btree *b2)
{
	return (ft_strcmp((char*)b1->content, (char*)b2->content));
}

char		get_type(mode_t mode)
{
	int		ft;

	ft = mode & S_IFMT;
	if (ft == S_IFDIR)
		return ('d');
	if (ft == S_IFREG)
		return ('-');
	return (0);
}

char		*get_permissions(mode_t mode)
{
	char		*permissions;

	permissions = ft_strnew(10);
	permissions[0] = mode & S_IRUSR ? 'r' : '-';
	permissions[1] = mode & S_IWUSR ? 'w' : '-';
	permissions[2] = mode & S_IXUSR ? 'x' : '-';
	permissions[3] = mode & S_IRGRP ? 'r' : '-';
	permissions[4] = mode & S_IWGRP ? 'w' : '-';
	permissions[5] = mode & S_IXGRP ? 'x' : '-';
	permissions[6] = mode & S_IROTH ? 'r' : '-';
	permissions[7] = mode & S_IWOTH ? 'w' : '-';
	permissions[8] = mode & S_IXOTH ? 'x' : '-';
	return (permissions);
}

void		ft_btree_putstr(t_btree *b)
{
	struct stat info;

	printf("%s: \n", (char*)b->content);
	stat((char*)b->content, &info);
	printf("\t%s: %c\n", "Type", get_type(info.st_mode));
	printf("\t%s: %s\n", "Modes", get_permissions(info.st_mode));
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
