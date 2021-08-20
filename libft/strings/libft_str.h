#ifndef LIBFT_STR_H
# define LIBFT_STR_H

# include <stdlib.h>

char	**ft_split(const char *str, char c);

char	*ft_strchr(const char *str, int c);
char	*ft_strrchr(const char *str, int c);
char	*ft_strdiffc(const char *str, const char *set);
char	*ft_strrdiffc(const char *str, const char *set);

int		ft_strncmp(const char *str1, const char *str2, size_t n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);

char	*ft_strdup(const char *str);
char	*ft_substr(char const *str, unsigned int start, size_t len);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_strtrim(const char *str, const char *set);
char	*ft_strmapi(char const	*str, char (*f)(unsigned int, char));

size_t	ft_strlen(const char *str);
int		ft_wordcount(const char *str, char c);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);

#endif
