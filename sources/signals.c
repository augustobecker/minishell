#include "minishell.h"

// stop the process and redisplay the command prompt.
void    handle_sigint(int  signal)
{
    (void)signal;
    write(1, "\n", 1);
    rl_replace_line("", 0);
    ft_printf(PURPLE);
    rl_on_new_line();
    rl_redisplay();

}
 
//SIGTERM (Exit Code 143)
/* void    handle_sigterm(int signal)
{
  (void)signal;
  rl_clear_history();
  ft_printf("exit\n");
  exit(0);
} */

void    handle_signal(void)
{
  signal(SIGINT, handle_sigint);
  signal(SIGQUIT, SIG_IGN);
  //signal(SIGTERM, handle_sigterm);
}

