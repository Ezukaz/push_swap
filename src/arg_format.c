/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_format.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ezukaz <katakaha@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 15:34:47 by Ezukaz            #+#    #+#             */
/*   Updated: 2026/03/06 15:34:47 by Ezukaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

/**
 * @brief Checks if argument has at least one whitespace (space or tab). If so,
 * @brief 	we must split that argument
 * 
 * @param str Argument
 * @return int True or False
 */

static int	has_whitespace(const char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		if (ft_iswhitespace(str[i]))
			return (1);
		i++;
	}
	return (0);
}

static void	put_dup_arg(t_args *res, char *arg_nospace)
{
	char	*arg;

	arg = ft_strdup(arg_nospace);
	if (!arg)
	{
		res->err = ERR;
		return ;
	}
	res->args[res->count++] = arg;
}

static void	put_split_arg(t_args *res, char *arg_with_spaces)
{
	char	**split_args;
	int		i;

	split_args = ft_split(arg_with_spaces);
	if (!split_args)
	{
		res->err = ERR;
		return ;
	}
	i = 0;
	while (split_args[i])
		res->args[res->count++] = split_args[i++];
	free(split_args);
}

/**
 * @brief Explodes arguments with spaces, and adds all single and exploded
 * @brief arguments to an array
 * 
 * @param char** Input args
 * @return t_args Input args correctly formatted into a struct array with count
 *
 * @note Must validate there is input before passing
 */

t_args	ps_arg_format(char **argv)
{
	t_args	res;
	int		i;

	i = 1;
	res.count = 0;
	res.err = 0;
	while (argv[i])
	{
		if (has_whitespace(argv[i]))
			put_split_arg(&res, argv[i]);
		else
			put_dup_arg(&res, argv[i]);
		if (res.err == ERR)
				break ;
		i++;
	}
	res.args[res.count] = NULL;
	return (res);
}
