int		ft_btree_strcmp(t_btree *b1, t_btree *b2)
{
	return (ft_strcmp((char*)b1->content, (char*)b2->content));
}

void		ft_btree_putstr(t_btree *b)
{
	struct stat info;

	printf("%s: \n", (char*)b->content);
	stat((char*)b->content, &info);
	printf("\t%s: %c\n", "Type", get_type(info.st_mode));
	printf("\t%s: %s\n", "Modes", get_permissions(info.st_mode));
	printf("\t%s: %ld\n", "Links number", (long)info.st_nlink);
	printf("\t%s: %s\n", "Owner", get_username((long)info.st_uid));
	printf("\t%s: %s\n", "Owner group", get_groupname((long)info.st_gid));
	printf("\t%s: %lld\n", "Size", (long long)info.st_size);
	printf("\t%s: %s\n", "Last file modification", ctime(&info.st_mtime));
}

int		boh()
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
