/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 19:26:32 by mnunnari          #+#    #+#             */
/*   Updated: 2017/05/26 00:14:29 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		usage(int code)
{
	//ft_printf("%s\n", "usage: ft_ls [-Ralrt] [file ...]");
	dprintf(2, "%s\n", "usage: ls [-ABCFGHLOPRSTUWabcdefghiklmnopqrstuwx1] [file ...]");
	exit(code);
}

void		check_opts(char *opts)
{
	int	i;

	i = 0;
	while (opts[i])
	{
		if(!ft_strcont("altrR1", opts[i]))
		{
			//ft_printf("ls: illegal option -- %c\n", opts[i]);
			dprintf(2, "/bin/ls: illegal option -- %c\n", opts[i]);
			usage(1);
		}
		i++;
	}
}

t_args			*init_args()
{
	t_args		*args;

	if (!(args = (t_args*)malloc(sizeof(t_args))))
		return (NULL);
	args->opts = ft_strnew(0);
	args->files = NULL;
	args->is_first = 1;
	args->newline = 0;
	args->maxlinks = 0;
	args->maxuser = 0;
	args->maxgroup = 0;
	args->maxsize = 0;
	args->considerdirsize = 0;
	args->blocks = 0;
	return (args);
}

t_args			*parse_args(int argc, char **argv)
{
	int			i;
	t_args		*args;
	t_file		*tfile;
	t_btree		*file;

	i = 1;
	args = init_args();
	while (i < argc && argv[i][0] == '-' && ft_strlen(argv[i]) > 1)
	{
		if (!(ft_strlen(argv[i]) == 2 && argv[i][1] == '-'))
			args->opts = ft_strmerge(args->opts, ft_strdup(&argv[i][1]));
		i++;
	}
	check_opts(args->opts);
	while (i < argc)
	{
		tfile = get_file(argv[i++], args);
		if (!(file = ft_btreenew(tfile, sizeof(t_file))))
			return (NULL);
		free(tfile);
		if (args->files == NULL)
			args->files = file;
		else
			ft_btreeadd_ls(&args->files, file, args->opts, &ft_btree_cmp_ls);
	}
	return (args);
}
