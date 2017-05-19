/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 19:26:32 by mnunnari          #+#    #+#             */
/*   Updated: 2017/05/19 17:56:07 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		usage(int code)
{
	printf("%s\n", "usage: ft_ls [-Ralrt] [file ...]");
	exit(code);
}

void		check_opts(char *opts)
{
	int	i;

	i = 0;
	while (opts[i])
	{
		if(!ft_strcont("altrR", opts[i]))
		{
			printf("ls: illegal option -- %c\n", opts[i]);
			usage(2);
		}
		i++;
	}
}

t_args			*init_args()
{
	t_args		*args;

	IFNOTRETURN((args = (t_args*)malloc(sizeof(t_args))), NULL);
	args->opts = ft_strnew(0);
	args->files = NULL;
	args->is_first = 1;
	args->newline = 0;
	args->maxlinks = 0;
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
		REASSIGN(args->opts, ft_strjoin(args->opts, &argv[i][1]));
		i++;
	}
	check_opts(args->opts);
	while (i < argc)
	{
		tfile = get_file(argv[i++], args);
		IFNOTRETURN((file = ft_btreenew(tfile, sizeof(t_file))), NULL);
		if (args->files == NULL)
			args->files = file;
		else
			ft_btreeadd_ls(&args->files, file, args->opts, &ft_btree_cmp);
	}
	return (args);
}
