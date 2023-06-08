#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <unistd.h>
# include "mylib.h"
# include "parsing/macros.h"
# include "parsing/mylexer.h"


typedef struct s_data
{
  char    **vars;
  char    **paths;
  char    *pwd;
  char    *old_pwd;
  char    *input;
  t_mylxr mylexer;
  int     color;

} t_data;


/*::: janitor :::*/
void    ft_errors_buster(int id, t_data *data);


/* -------------------Parsing-----------------------*/
/*::: core functions :::*/
void    ft_shell_starter(t_data *data);

/*::: env_vars :::*/
int     ft_env_setter(t_data *data, char **env);
void    ft_pwd_finder(t_data *data);
void	  ft_paths_parser(t_data *data);
char	  *ft_path_finder(char **vars);

/*::: quotes :::*/
int     ft_quotes_counter(char *input);
int     ft_quotes_matcher(char *input, int i, int quote);

/*::: tokens :::*/
int     ft_token_scanner(t_data *data);
int     ft_token_parser(char *str, t_mylxr mylexer, int *node_id, int id);
int     ft_token_detector(t_data *data, int i);
void    ft_add_node(t_mylxr *mylxr, t_mylxr new);
int     ft_new_node(t_mylxr *new, int id, char *str);


/* -------------------Execution-----------------------*/




#endif
