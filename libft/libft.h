/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swquinc <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 15:49:30 by swquinc           #+#    #+#             */
/*   Updated: 2020/07/30 01:39:10 by hovalygta        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stddef.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

typedef struct	s_specifiers
{
	int				flag_min;
	int				flag_zero;
	int				width;
	int				precision;
}				t_specifiers;

void			ft_bzero(void *s, size_t n);
void			*ft_memset(void *a, int b, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
size_t			ft_strlen(const char *string);
size_t			ft_strlcpy(char *dst, const char *src, size_t s);
size_t			ft_strlcat(char *dst, const char *src, size_t s);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strnstr(const char *stack, const char *needle, size_t len);
char			*ft_salloc(size_t size);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_atoi(const char *str);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);
void			*ft_calloc(size_t count, size_t size);
char			*ft_strdup(const char *s1);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char *s1, char const *s2);
char			*ft_strtrim(char const *s1, char const *set);
char			**ft_split(char const *s, char c);
char			*ft_itoa(int n);
char			*ft_uitoa(unsigned int n);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *c, int fd);
void			ft_putendl_fd(char *c, int fd);
void			ft_putnbr_fd(int n, int fd);
int				ft_printf(const char *src, ...);
int				fill_width(va_list arg, char num, int z, t_specifiers *format);
int				fill_precision(va_list arg, char num, int z, t_specifiers *f);
int				print_c(t_specifiers *format, va_list args);
int				print_s(t_specifiers *format, va_list args);
int				print_p(t_specifiers *format, va_list args);
int				print_di(t_specifiers *format, va_list args);
int				print_u(t_specifiers *format, va_list args);
int				print_x(t_specifiers *format, va_list args);
int				print_big_x(t_specifiers *format, va_list args);
int				print_percent(t_specifiers *format);
int				print_precision(char *str, t_specifiers *format, int di);
int				print_width(t_specifiers *format, char *str, int di);
int				print_width_s(t_specifiers *format, int len);
int				zero01(int i, int len, int printed_char, t_specifiers *format);
char			*convert_p(unsigned long int p, int *i);
char			*convert_x(unsigned int p, int *i);
char			*convert_big_x(unsigned int p, int *i);
char			*full_p(unsigned long int a);
char			*full_x(unsigned int a);
char			*full_big_x(unsigned int a);

#endif
