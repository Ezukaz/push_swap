/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iswhitespace.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ezukaz <katakaha@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 11:42:05 by Ezukaz            #+#    #+#             */
/*   Updated: 2026/02/22 11:42:05 by Ezukaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iswhitespace(int c)
{
	return (c == '\t' || c == ' ');
}
// Originally should be:
// return (c == '\t' || c == '\n' || c == ' '
//		|| c == '\v' || c == '\f' || c == 'r');
// but I changed it for push_swap
