/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakaha <katakaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 17:23:46 by katakaha          #+#    #+#             */
/*   Updated: 2026/02/19 17:23:46 by katakaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*free_all(char **bad_array, size_t index)
{
	while (index > 0)
	{
		index--;
		free(bad_array[index]);
	}
	free(bad_array);
	return (NULL);
}

static int	is_whitespace(unsigned char c)
{
	return (c == '\t' || c == '\n' || c == ' ' || c == '\v' || c == '\f' || c == '\r');
}

static size_t	count_words(char *str)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		while (str[i] && is_whitespace(str[i])) // str[i]のチェックはいらないが、後でwhitespaceに'\0'が追加されたらのディフェンシブプログラミング用
			i++;
		if (str[i] && !is_whitespace(str[i])) // ここと下は必要
			count++;
		while (str[i] && !is_whitespace(str[i]))
			i++;
	}
	return (count);
}

static char	*get_next_word(char *str, size_t *len)
{
	size_t	i;
	size_t	j;
	char	*next_word;

	i = 0;
	j = 0;
	while (str[i] && !is_whitespace(str[i]))
		i++;
	*len = i;
	next_word = malloc(i + 1);
	if (!next_word)
		return (NULL);
	while (j < i)
	{
		next_word[j] = str[j];
		j++;
	}
	next_word[j] = '\0';
	return (next_word);
}

char	**ft_split(char *str)
{
	char	**res;
	size_t	word_c;
	size_t	len;
	size_t	i;

	i = 0;
	word_c = count_words(str);
	res = malloc(sizeof(char *) * (word_c + 1));
	if (!res)
		return (NULL);
	while (*str != '\0')
	{
		while (is_whitespace(*str))
			str++;
		if (*str != '\0')
		{
			res[i] = get_next_word(str, &len);
			if (!res[i])
				return (free_all(res, i));
			str += len;
			i++;
		}
	}
	res[i] = NULL;
	return (res);
}

// void	explode_test(char *str)
// {
// 	char	**result;
// 	int		i;

// 	i = 0;
// 	printf("Testing string: [%s]\n", str);
// 	result = ft_split(str);
// 	if (!result)
// 	{
// 		printf("Result is NULL\n\n");
// 		return ;
// 	}
// 	while (result[i] != NULL)
// 	{
// 		printf("  word[%d]: {%s}\n", i + 1, result[i]);
// 		free(result[i]); // 各単語を解放
// 		i++;
// 	}
// 	free(result); // 配列自体を解放
// 	printf("Total words: %d\n", i);
// 	printf("------------------------------\n\n");
// }

// int	main(void)
// {
// 	// ケース1: 通常の文章
// 	explode_test("hello world 42 tokyo");

// 	// ケース2: 先頭と末尾に大量の空白・タブ・改行
// 	explode_test("   \t  lots of    spaces \n  ");

// 	// ケース3: 単語が1つだけ
// 	explode_test("solo");

// 	// ケース4: 空文字列
// 	explode_test("");

// 	// ケース5: 空白のみ
// 	explode_test("   \t\n   ");

// 	// ケース6: NULL（一応の安全策）
// 	// explode_test(NULL); // 実行するとセグフォする設計ならコメントアウト

// 	return (0);
// }
