/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 18:49:00 by mnunnari          #+#    #+#             */
/*   Updated: 2017/05/22 19:29:40 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char		get_file_type(mode_t mode)
{
	int		ft;

	ft = mode & S_IFMT;
	if (ft == S_IFDIR)
		return ('d');
	else if (ft == S_IFLNK)
		return ('l');
	else if (ft == S_IFCHR)
		return ('c');
	else if (ft == S_IFBLK)
		return ('b');
	else if (ft == S_IFSOCK)
		return ('s');
	else if (ft == S_IFIFO)
		return ('f');
	else
		return ('-');
	return (0);
}

char		*get_username(long uid)
{
	struct passwd user;

	user = *getpwuid(uid);
	return (user.pw_name);
}

char		*get_groupname(long gid)
{
	struct group *grp;

	grp = getgrgid(gid);
	return (grp->gr_name);
}


char		*get_permissions(mode_t mode)
{
	char		*permissions;

	permissions = ft_strnew(10);
	permissions[0] = mode & S_IRUSR ? 'r' : '-';
	permissions[1] = mode & S_IWUSR ? 'w' : '-';
	if (mode & S_ISUID)
		permissions[2] = mode & S_IXUSR ? 's' : 'S';
	else
		permissions[2] = mode & S_IXUSR ? 'x' : '-';
	permissions[3] = mode & S_IRGRP ? 'r' : '-';
	permissions[4] = mode & S_IWGRP ? 'w' : '-';
	if (mode & S_ISGID)
		permissions[5] = mode & S_IXGRP ? 's' : 'S';
	else
		permissions[5] = mode & S_IXGRP ? 'x' : '-';
	permissions[6] = mode & S_IROTH ? 'r' : '-';
	permissions[7] = mode & S_IWOTH ? 'w' : '-';
	if (mode & S_ISVTX)
		permissions[8] = mode & S_IXOTH ? 't' : 'T';
	else
		permissions[8] = mode & S_IXOTH ? 'x' : '-';
	return (permissions);
}
