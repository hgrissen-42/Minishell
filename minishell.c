/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-fcht <sel-fcht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 16:15:26 by sel-fcht          #+#    #+#             */
/*   Updated: 2021/10/26 21:35:19 by sel-fcht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void ft_bzero(void *ptr)
int escape(char *s, int pos)
{
    int i;
    int c;
    c = 0;
    i = 0;
    while(pos>=i)
    {
        if (s[pos] == '\\')
            c++;
        else
            break;
        pos--;
    }
    if (c%2 != 0)
        return (1);
    return (0);
}
void klawi(char *line, int *end, int *in, char **tmp)
{
    if ((*tmp = insi(line + 1, end , *line)))
    {
        *in = 1;
        free(*tmp);
    }
}
int is_quoted(char c)
{
    if (c == '\'' || c == '\"')
        return (1);
    else
        return (0);
}

char *get_arguments(char *line, char c, int *pos)
{
    int i;
    int end;
    int in;
    char *tmp[2];

    i = 0;
    in = 0;
    ft_bzero(tmp, 2 * sizeof(char *));
    while(line[i])
    {
        if((in = 0) && !escape(line, i - 1) && is_quoted(line[i]))
        {
            end = i + 1;
            klawi(&line[i], &end, &in, &tmp[1]);
        }
        if (i + 1 == end)
            in = 0;
        if (line[i] == c && in == 0 && !escape(line, i - 1))
        {
            *pos += i;
            break;
        }
        tmp[0] = append(tmp[0], line[i++]);
    }
    if (line[i] == '\0')
        *pos += i -1;
}
char **parser_split(char *line, char c)
{
    int i;
    int nbr;
    char **split;
    int j;
    char *tmp;

    i = 0;
    j = 0;
    nbr = parsing(line, c);
    if (!(split = (char **)malloc(sizeof(char *) * (nbr + 1))))
        return(NULL);
    i = 0;
    while(i < nbr)
    {
        tmp = get_arguments(line + j, c, &j);
        split[i] = ft_strtrim(tmp, " \t");
        free(tmp);
        j++;
        i++;
    }
    split[i] = NULL;
    return (split);
}

char *ft_putstr(char *str)
{
    int i;
    i = 0;
    while (str[i])
    {
        write(1,&str[i],1);
        i++;
    }
    return (str);
}

char * parse_second_arg(char *str)
{
    int i;
    int j = 0;
    char *tmp;
    tmp = (char *)malloc(sizeof(str));
    i = 0;
    while(str[i]!= '\0')
    {
    if (str[i] == ' ')
            i++;
    if (str[i] == '-' )
        {
            while(str[i]    != '\0')
            {
                tmp[j] = str[i];
                i++;
            j   ++;
            }
        }
        else
            i++;
    }
   return(tmp);
}
char *take_second(char *str)
{
    int i;
    char *tmp;
    tmp = (char *)malloc(sizeof(str));
    int j = 0;
    i = 0;
    while(str[i] != '\0' && str[i] != ' ')
        i++;
    while(str[i]!= '\0')
    {
        tmp[j] = str[i];
        i++;
        j++;
    }
    return (tmp);
}
int  subtstr(char *str)
{
    int i; 
    i = 0;
    while(str[i]!= '\0')
    {
        i++;
    }
    printf("Lenght of the str is %d\n",i);
    return (i);
}
void check_modulo(char *str)
{
    int i;
    int flag;
    i = 0;
    flag = 0;
    while(str[i] != '\0')
    {
        if (str[i] == '\"' || str[i] == '\'')
            {
                flag++;
                i++;
            }
        else
            i++;
    }
    if (flag % 2 == 1)
        exit(0);
}

char *treat_quotes(char *str)
{
    int i;
    int j;
    char *tmp;
    i = 0;
    j = 0;
    tmp = (char *)malloc(sizeof(str));
    check_modulo(str);
    while(str[i] != '\0')
    {
        if (str[i] == '\"' || str[i] =='\'' )
            i++;
        else
        {
            tmp[j] = str[i];
            j++;    
        }
    i++;
    }
    return (tmp);
}
int	ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}
void pwd_execute()
{
    system("pwd");
}
void clear_execute()
{
    system("clear");
}
void ls_execute()
{
    int i;
    i= system("ls");
    printf("value returned :%d \n",i);
}
void echo_execute()
{
   system("echo");
}
void execute(char *all, char *arg)
{
    int i;
    i = 0;
    if (ft_strcmp(arg,"echo") == 0)
        echo_execute();
    else if (ft_strcmp(arg,"ls")==0)
        ls_execute();
    else if (ft_strcmp(arg, "exit" ) == 0)
        exit(0);
    else if (ft_strcmp(arg, "clear")==0)
        clear_execute();
    else if (ft_strcmp(arg, "pwd") == 0)
        pwd_execute();
    else
            ft_putstr("Command not Found$\n");
        
}
void parse(char *str)
{
    t_shell *shell;
    shell = malloc(sizeof(t_shell));
    
    int i;
    i = 0; 
    shell->first = (char *)malloc(ft_strlen(str) + 1);
    while(str[i] != '\0' && str[i] != ' ')
    {
        shell->first[i] = str[i];
        i++;
    }
    shell->first[i] = '\0';
    //shell->val = subtstr(str);
    shell->second = take_second(str);
    shell->second = parse_second_arg(shell->second);
    printf("Second Argument is : %s\n",shell->second);
    shell->first = treat_quotes(shell->first);
    execute(shell->str, shell->first);
}

int tab_len(char **s) {

    int len;

    len = 0;
    if (s)
        while (s[len])
            len++;
    return len;
}

char    **realloc_tokens(char **s, char *t) {

    int i;
    int len;
    char    **n;

    i = 0;
    len =  tab_len(s);
    n =  (char **)malloc(sizeof(char *) * (len + 2));
    while (i < len)
    {
        n[i] = s[i];
        i++;
    }
    if (t)
    {
        n[i] = t;
        i++;
    }
    n[i] = NULL;
    return n;

}

char    *fill_tokens(char *line, int *pos, char c) {

    int i;
    char *t;
    int insgl;
    int indbl;
    
    i = 0;
    insgl = 0;
    indbl = 0;
    while (line[i] != '\0')
    {
        while (line[i] == '\"')
        {
            i++;
            indbl++;
        }    
        while (line[i] == '\'')
        {
            i++;
            insgl++;
        }
        if (line[i] == c && (indbl % 2 == 0) && (insgl % 2 == 0))
            break ;
        i++;
    }
    t = (char *)malloc(sizeof(char) * (i + 1));
    i = 0;
    while (line[i] != '\0') 
    {
        while (line[i] == '\"')
        {
            i++;
            indbl++;
        }    
        while (line[i] == '\'')
        {
            i++;
            insgl++;
        }
        if (line[i] == c && (indbl % 2 == 0) && (insgl % 2 == 0))
            break ;
        else
        {
            t[i] = line[i];
            i++;
        }
    }
    *pos += i;
    return t;
}
char    *get_inquotes(char *line, int *pos, int *insgl, int *indbl, char c) {

    int i;
    char *t = NULL;
    int a = *insgl;
    int b = *indbl;
    
    
    i = 0;
    while (line[i] != '\0') {
        
        while (line[i] == '\"')
        {
            i++;
            (a)++;
        }    
        while (line[i] == '\'')
        {
            i++;
            (b)++;
        }
        if (line[i] == c  && ((a) % 2 == 0) && ((b) % 2 == 0))
            break ;
        i++;
    }
    t = (char *)malloc(sizeof(char) * (i + 1));
    i = 0;
    while (i < strlen(line) && line[i] != '\0') {

        while (i < strlen(line) && line[i] == '\"')
        {
            i++;
            (*indbl)++;
        }    
        while (i < strlen(line) && line[i] == '\'')
        {
            i++;
            (*insgl)++;
        }
        if (i < strlen(line) && line[i] == c )
            break ;
        else {
            if (i < strlen(line)) {
                t[i] = line[i];
                i++;
            }
        }
    }
    t[i] = '\0';
    *pos += i + 1;
    return t;
}
char    **split_quotes( char *s , char c) {

    int i;
    int insgl;
    int indbl;
    int cnt = 0;

    i = 0;
    insgl = 0;
    indbl = 0;
    char    **tokens = NULL;
    cnt = check_quotes(s);
    while (i < strlen(s) && s[i] != '\0') 
    {
        while (i < strlen(s) &&  s[i] == '\"')
        {
            i++;
            indbl++;
        }    
        while (i < strlen(s) && s[i] == '\'')
        {
            i++;
            insgl++;
        }  
        printf("--->DOUBLE QUOTES = %d\n",indbl); 
        while (i < strlen(s) &&  s[i] == c)
            i++;
        if (i < strlen(s) &&  s[i] != c )
            tokens = realloc_tokens(tokens, fill_tokens(s + i, &i, c));
        else
            tokens = realloc_tokens(tokens, get_inquotes(s + i, &i, &insgl, &indbl, c)); //blan
        if (s[i] == c && (indbl % 2 == 0) && (insgl % 2 == 0))
           i++;
    }
    printf("--> HOW MUCH I EQUAL = %d",i);
    i = 0;
    if (tokens)
    {
        while (tokens[i] != NULL) {
        printf("|%s|", tokens[i]);
        i++;
    }
    }
    return tokens;
}

int main(int ac, char **av, char **env)
{
    t_shell *sh;
    hh = 0;
    char **line;
    sh = malloc(sizeof(t_shell));
    sh->str = (char*)malloc(sizeof(char) + 4);
    while(1)
    {
        sh->str = readline("Minishell $>: ");
        if (sh->str == NULL)
        {
            ft_putstr("exit");
            exit(0);
        }
        if (*sh->str == '\0')
        {
            ft_putstr("Enter a command\n");
            continue;
        }
        add_history(sh->str);
       // start_shit(sh->str);
        line = split_quotes(sh->str, ' ');
        
        //parse(sh->str);
    }
 
    return(0);
}