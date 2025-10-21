/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumarque <jumarque@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 19:56:38 by juagomez          #+#    #+#             */
/*   Updated: 2025/08/27 12:11:24 by jumarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

// OWN LIBRARIES
# include "../lib/libft/libft.h"
# include "../lib/gnl/get_next_line.h"

// EXTERNAL LIBRARIES PARSER
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdbool.h>
# include <readline/readline.h>
# include <readline/history.h>

// EXTERNAL LIBRARIES BUILTINS
# include <stdlib.h>

// EXTERNAL LIBRARIES EXECUTOR
# include <sys/wait.h>
# include <unistd.h>
# include <signal.h>

# define MAX_PIDS 999

// VALORES EXIT_STATUS
# define FAILURE			-1
# define SUCCESS			0
# define ERROR				1
# define SYNTAX_ERROR		2

# define COMMAND_NOT_FOUND	127
# define EXIT_SIGINT		130
# define EXIT_SIGQUIT		131

// ERRORES GENERALES
# define ERROR_ENVIRONMENT "Error\n Environment unavailable or empty\n"
# define ERROR_OPEN_FILE "Error\n Opening file\n"
# define ERROR_INPUT_READER "Error\n Error read input\n"
# define ERROR_CHECK_SYNTAX "Error\n Check syntax input Error\n"
# define ERROR_ADVANCE_INDEX "Error\n Index advance error\n"

// ERRORES DE SINTAXIS Y PARSING
# define ERROR_QUOTE_SYNTAX "Error\n Syntax error: Unmatched quotes detected\n"
# define ERROR_REDIRECTION_SYNTAX "Error\n Syntax error: \
				 Invalid redirection syntax\n"
# define ERROR_PIPE_SYNTAX "Error\n Syntax error: Invalid pipe syntax\n"

// ERRORES CONSTRUCCION
# define ERROR_INIT "Error\n Initialization error\n" 
# define ERROR_COMMAND_INIT "Error\n Command structure initialization failed\n" 
# define ERROR_WORD_INIT "Error\n Word structure initialization failed\n" 
# define ERROR_TOKEN_INIT "Error\n Token structure initialization failed\n" 
# define ERROR_EXPAND_INIT "Error\n Expand structure initialization failed\n" 

// ERRORES DE VALIDACIÓN
# define ERROR_INVALID_INPUT "Error\n Invalid input parameter\n"
# define ERR_MEM_ALLOC "Error\n Memory allocation failed\n"
# define ERROR_COMMAND_EMPTY "Error\n Empty command detected\n"
# define ERROR_FILE_NOT_FOUND ": No such file or directory"
# define ERROR_PERMISSION_DENIED ": Permission denied"
# define ERROR_CLOSING_FILE ": Closing file"

// PROMPT
//# define PROMPT "minishell$ "
# define PROMPT "\e[43;30mminishell\e[0m\e[1;33m\e[0m"
//# define PROMPT "\e[43;30m$\e[0m\e[1;33m\e[0m"

// LIBERACIÓN MEMORIA
# define FREE_ALL_SHELL			"Free\n Total cleaning minishell... OK\n"
# define FREE_ITERATION_INPUT	"Free\n Iteration Input...\t\t\t OK\n"
# define FREE_COMMANDS_LIST		"Free\n Commands list...\t\t\t OK\n"
# define FREE_WORDS_LIST		"Free\n Words list...\t\t\t\t OK\n"
# define FREE_TOKENS_LIST		"Free\n Tokens List...\t\t\t\t OK\n"
# define FREE_EXPANDS_LIST		"Free\n Expands List...\t\t\t OK\n"
# define FREE_MATRIX			"Free\n Cleaning matrix...\t\t\t OK\n"

// CATEGORIZACION WORDS
# define WORD					'W'
# define OUTFILE				'O'
# define APPEND					'A'
# define INFILE					'I'
# define HERE_DOC				'H'
# define PIPE					'P'

// categorizacion TOKENS
# define NO_QUOTES				1
# define SINGLE_QUOTES			2
# define DOUBLE_QUOTES			3
# define OPERATOR				4
	// 4 -> operador (< << > >> |)

// categorizacion VARIABLES EXPANDIDAS
# define BASIC_EXPANSION		1
# define CURLY_BRACES			2
# define LAST_EXIT_STATUS		3
# define LITERAL				4

///--------------------------- STRUCT ----------------------

//--------------------------- GLOBAL VARIABLE
extern int	g_signal_flag;

//--------------------------- VARIABLES EXPANDIDAS
typedef struct s_expand
{
	int				type;
	int				first_index;
	int				last_index;
	char			*substitution_str;
	char			*key;
	char			*value;
	struct s_expand	*next;
}	t_expand;

//--------------------------- TOKEN
typedef struct s_token
{
	int				type;
	char			*raw_token;	
	char			*expanded_token;
	char			*noquotes_token;
	t_expand		*expands_list;
	struct s_token	*next;
}	t_token;

typedef struct s_data_token
{
	char	*rw_word;
	int		start_index;
	int		token_len;
	int		token_type;
}	t_data_token;

//--------------------------- WORD TOKENS
typedef struct s_word
{
	char			word_type;
	char			*raw_word;
	char			*processed_word;
	t_token			*tokens_list;	
	struct s_word	*next;
}	t_word;

typedef struct s_data_word
{
	char	*cmd_input;
	int		start_index;
	int		w_len;
	int		w_type;
}	t_data_word;

//--------------------------- COMMANDS
typedef struct s_cmd
{
	char			*command;
	char			**args;
	char			*infile;
	char			*outfile;
	char			*delimiter;
	bool			append;
	bool			hd;
	bool			is_btn;
	int				exit_status;
	t_word			*words_list;
	struct s_cmd	*next;
}	t_cmd;

//--------------------------- SHELL
typedef struct s_shell
{
	char		*input;
	char		**environment;
	int			exit_status;
	int			last_exit_status;
	char		**readonly_vars;
	t_cmd		*commands_list;
}	t_shell;

///------------------------------- MAIN ---------------

// 00_main.c
int			main(int argc, char **argv, char **environment);
void		cleanup_minishell(t_shell *shell);
int			validate_environment(char **environment);
t_shell		*initialize_shell(void);
int			load_environment_variables(t_shell *shell, char **environment);

// 01_execute_shell.C
int			execute_shell(t_shell *shell);
void		process_commands(t_shell *shell); //11_test_parser.c 
int			read_user_input(t_shell *shell, char *prompt, char *input);
int			process_input(t_shell *shell);

///------------------------------ PARSER -------------------

// 01.1_check_syntax.c
int			validate_syntax(t_shell *shell);
int			check_pipe_syntax(char *input, int index, bool in_single_quotes,
				bool in_double_quotes);
int			check_quotes_balanced(const char *input);
int			check_redirection_syntax(char *input);
int			validate_redirection_at_position(char *input, int *pos);

//--------------------------- ANÁLISIS SINTÁCTICO ---------

// 02_command_generate.c	# Análisis sintáctico inicial
void		create_commands_structure(t_shell *shell);
int			generate_command(t_shell *shell, int start_index);
int			create_clean_command(t_cmd **commands_list, char *raw_input,
				int start_index, int command_len);

// 02.1_command_check.c		# Validacion sintaxis estructura comandos
int			validate_command_structure(t_shell *shell);
int			validate_pipe_structure(t_cmd *command);
int			validate_redirections_structure(t_cmd *command);
int			count_commands_nodes(t_cmd *command_list);

// 02.2_command_builder.c	# Constructor de comandos
void		add_command_node(t_cmd **commands_list, char *input);

///--------------------------- ANÁLISIS LÉXICO -------------

// 03_lexical_analyzer.c	# Análisis léxico
void		lexical_analyzer(t_cmd *current_command, t_shell *shell);

// 03.1_word_builder.c		# Constructor de palabras
int			create_word(t_word **word_list, t_data_word *data_word);
t_word		*find_word_last_node(t_word *word_list);

//------------------------------ TOKENIZACIÓN -------------

// 04_tokenizer.c			# Tokenización
void		tokenizer(t_word *words_list, t_shell *shell);

// 04.1_token_builder.c		# Constructor de tokens
int			create_token(t_token **token_list, t_data_token *data_tkn);
int			is_a_arg(t_data_token data_token, int index);
//void	print_tokens_list(t_token *token_list);

//---------------------------  EXPANSIÓN DE VARIABLES ------

//  05_variable_expander.c	# Expansión de variables
void		variable_expander(t_word *words_list, t_shell *shell);

//  05.1_expand_list.c		# Lista de expansiones
int			basic_expander(t_token *token, int first_index);
int			last_exit_status_expander(t_token *token, int first_index);
int			curly_braces_expander(t_token *token, int first_index,
				bool success);
int			literal_expander(t_token *token, int first_index, bool success);

//  05.2_expand_extractor.c	# Extractor de variables
char		*extract_key(char *token, int first_index);
char		*get_environment_var(char **env, char *variable);
char		*ft_expander(t_expand *expand_node, t_shell *shell);
int			subs_len_asign(t_token *tkn, int i);

//	05.3_expand_builder.c	 # Constructor de expansiones
void		print_expand_nodes_list(t_expand *expand_list);
int			insert_expand_node_value(t_token *token, int last_pst);
t_expand	*add_expand_node(t_expand **expand_list,
				char *substitution_variable, int first_index, int expand_type);

//  05.4_dequotizer.c		# Eliminación de comillas
void		dequotize_tokens(t_word *words_list, t_shell *shell);
void		update_quote_state(char character, bool *in_single_quotes,
				bool *in_double_quotes);

//--------------------------- PROCESAMIENTO FINAL ---------
// 06_word_processor.c		
void		generate_processed_word(t_word *words_list, t_shell *shell);

// 07_semantic_check.c
int			validate_command_semantics(t_shell *shell);

// 08_execution_builder.c 
void		build_execution_structure(t_cmd *commands_list, t_shell *shell);
int			process_infile(t_cmd *command, t_word *word);
int			process_outfile(t_cmd *command, t_word *word);
int			process_append(t_cmd *command, t_word *word);
int			process_heredoc(t_cmd *command, t_word *word);

// 08.1_execution_redict.c
int			process_infile(t_cmd *command, t_word *word);
int			process_outfile(t_cmd *command, t_word *word);
int			process_append(t_cmd *command, t_word *word);
int			process_heredoc(t_cmd *command, t_word *word);

// 08.1_execution_utils.c
void		ft_proccess_words_list(t_cmd *command, t_word *word, int index);
//--------------------------- UTILIDADES Y TESTING --------

// 10_utils_core.c		 # Utilidades gestion comillas
int			find_pipe_outside_quotes(char *input, int start_index);
int			find_redirection_outside_quotes(char *input, int start_index);
int			find_word_end_outside_quotes(char *input, int start_index);
int			find_next_expansion_outside_single_quotes(const char *input,
				int start_index);
int			find_matching_quote_position(const char *input,
				int quote_start_index);

// 10.1_utils_strings.c
int			advance_index_by_length(int current_index, int length);
char		*ft_strjoin_free(char *str1, char *str2);
void		free_matrix(char **matrix);
int			is_expansion_char(char character);
int			is_space(char character);

// 10.2_utils_basic.c		# Utilidades básicas
int			get_operator_length(char *input, int index);
int			is_word_delimiter(char character);
int			is_redirection(char character);
int			is_pipe(char character);
int			is_quote(char character);

// 10.2_free_manager.c		# Gestión de memoria
void		free_iteration_input(t_shell *shell);
void		free_commands_list(t_cmd **commands_list);
void		free_words_list(t_word **words_list);
void		free_tokens_list(t_token **token_list);
void		free_expands_list(t_expand **expands_list);

// 10.3_utils_debug.c 		# Utilidades de debug
//void	print_commands_list(t_cmd *commands_list);
//void	print_config_shell(t_shell *shell);
//void	print_strings_array(char **array);

///--------------------------- EXECUTOR --------------------

//--------------------------- UTILES ----------------------
// 00_utils_clean.c

void		ft_free_cmd_args(t_cmd *cmd);
void		ft_free_cmd_files(t_cmd *cmd);

// 00_utils.c

void		ft_exit_error(char *error);
void		*safe_malloc(size_t bytes);
char		**ft_copy_env(char **env);
char		*ft_substr_malloc(const char *input, int start, int len);
void		ft_shellevel(t_shell *shell);

//--------------------------- SEÑALES ITERRUPCION ----------

// 01_signals.c
void		setup_signals(void);
void		ft_handle_sigint(int signum);
void		ft_check_exitstat(int status, t_shell *shell);
void		ft_handle_sigquit(int signum);

//--------------------------- EJECUCIÓN -------------------

// 02.00_executer.c
void		exec_commands(t_shell *ms); // src/01_execute_shell.c
pid_t		exec_single_cmd(t_cmd *cmd, int *prevfd, int *pipefd, t_shell *ms);
void		child_process(t_cmd *cmd, int prevfd, int pipefd[2], t_shell *ms);
void		parent_process(t_shell *ms, int *prevfd, int pipefd[2]);
void		wait_all_processes(pid_t *pids, t_shell *ms);

// 02.01_executer_command.c
void		execute_command(t_shell *shell, t_cmd *cmd);
void		handle_command_execution(t_shell *shell, t_cmd *cmd, char *path);
char		*search_in_paths(char **paths, char *comm);
char		*ft_path(char *path, char **comm);

///--------------------------- REDIRECCIONAMIENTO ----------

// 03_redirections.c
int			redirections(t_shell *shell, t_cmd *cmd);
int			redir_heredoc(t_shell *shell, t_cmd *cmd);
int			redir_infile(char *infile);
int			redir_outfile(char *outfile, int append);

// 03.01_heredoc.c
char		*expand_heredoc(char *buffer, char **env, int exit_st);
char		*expand_variable(int *i, char *buffer, char **env, int exit_st);
char		*not_expand(int *i, char *buffer);

///--------------------------- BUILTINS --------------------

// 00_exec_builtins.c
void		exec_builtins(t_shell *shell, t_cmd *cmd, int prev_fd);

// 00_utils_builtins_00.c
int			ft_mtrx_size(char **mtrx);
int			ft_search_index_env(char **env, char *str);
int			ft_valid_env_var(char *env_var);
char		**ft_copy_mtrx(char **mtrx);
void		ft_swap_mtrx(char **s1, char **s2);

// 00_utils_builtins_01.c
int			ft_strcmp(char *s1, char *s2);
char		*ft_find_plus_pos(char *var);
void		sort_alphabetic_mtrx(char **mtrx);
char		*ft_get_keyvar(char *var);

// 00_utils_builtins_02.c
char		**ft_create_new_env(char **env, char *var);
char		*ft_process_new_var(char *var);

// 00_utils_builtins_03.c
char		**ft_append_env_var_value(char **env, char *var, int index);
char		*ft_create_appended_var(char *new_val, char *old_val,
				char *plus_pos);

// 01_exec_echo.c
int			exec_echo(t_cmd *cmd);
void		ft_print_echo(char **args);
int			check_option_echo(char *str);
int			stdout_to_outfile(char *outfile, int append);

// 02_exec_cd.c
int			exec_cd(t_cmd *cmd, t_shell *shell);

// 03_exec_pwd.c
int			exec_pwd(void);

// 04_exec_export.c
int			exec_export(t_cmd *cmd, t_shell *shell);
void		print_export(char **env_export);
char		**ft_add_modify_env(char **env, char *var, int flag);
char		**check_flags(int index, int flag, char **env, char *var);
void		print_after_equal(char *equal, char *new_var);

// 05_exec_unset.c
int			exec_unset(t_shell *shell, t_cmd *cmd);
char		**ft_change_env(char **env, char *str);
int			ft_is_readonly(char **readonly_vars, char *var_name);
void		print_invalid_errors(t_shell *shell, char *arg);
void		print_readonly_errors(t_shell *shell, char *arg);

// 06_exec_env.c
int			exec_env(t_shell *shell);

// 07_exec_exit.c
void		exec_exit(t_shell *shell, t_cmd *cmd, int prev_fd);
int			ft_valid_arg_exit(char *arg);

#endif
