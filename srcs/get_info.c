#include "ft_ls.h"

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
	permissions[2] = mode & S_IXUSR ? 'x' : '-';
	permissions[3] = mode & S_IRGRP ? 'r' : '-';
	permissions[4] = mode & S_IWGRP ? 'w' : '-';
	permissions[5] = mode & S_IXGRP ? 'x' : '-';
	permissions[6] = mode & S_IROTH ? 'r' : '-';
	permissions[7] = mode & S_IWOTH ? 'w' : '-';
	permissions[8] = mode & S_IXOTH ? 'x' : '-';
	return (permissions);
}
