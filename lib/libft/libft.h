/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bekhodad <bekhodad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 10:50:44 by bekhodad          #+#    #+#             */
/*   Updated: 2023/06/09 10:50:44 by bekhodad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdio.h>
# include <stdlib.h>

// typedef struct s_list
// {
// 	void			*content;
// 	struct s_list	*next;
// }				t_list;

int			ft_atoi(const char *nptr);
char		**ft_split(char const *s, char c);
size_t		ft_strlen(const char *str);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
size_t		ft_wordcount(char const *s, char c);
char		*ft_strnstr(const char *big, const char *little, size_t len);

#endif
