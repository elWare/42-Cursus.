/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   08.2_execution_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumarque <jumarque@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 21:16:26 by juagomez          #+#    #+#             */
/*   Updated: 2025/08/20 16:52:20 by jumarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	ft_proccess_words_list(t_cmd *command, t_word *word, int index)
{
	while (word)
	{
		if (word->word_type == WORD)
		{
			if (ft_strcmp(word->processed_word, "") == 0 && word->next)
			{
				word = word->next;
				continue ;
			}
			command->args[index] = ft_strdup(word->processed_word);
			if (!command->args[index])
				return (ft_putendl_fd(ERR_MEM_ALLOC, STDERR_FILENO));
			index++;
		}
		else if (word->word_type != WORD && word->word_type != PIPE)
		{
			word = word->next;
			if (word && word->word_type == WORD)
				word = word->next;
			continue ;
		}
		word = word->next;
	}
	command->args[index] = NULL;
}
