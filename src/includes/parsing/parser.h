/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerayyad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 18:51:22 by rerayyad          #+#    #+#             */
/*   Updated: 2023/06/10 18:51:24 by rerayyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "../minishell.h"

typedef struct s_parser
{
  int     redirections_count;
  t_mylxr *mylexer;
  t_mylxr *redirections;
  t_data data;
} t_parser;

typedef struct s_cmds
{
  char          *str;
  char          *herdoc;
  t_mylxr       *redirections;
  int           redirections_count;
  // builtins
  struct s_cmds *next;
  struct s_cmds *prev;
} t_cmd;

#endif