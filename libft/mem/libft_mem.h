#ifndef LIBFT_MEM_H
# define LIBFT_MEM_H

# include <stdlib.h>

void	*ft_calloc(size_t count, size_t size);

int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memchr(const void *str, int c, size_t n);

void	*ft_memset(void *str, int c, size_t n);
void	ft_bzero(void *str, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, void *src, size_t len);
void	*ft_memccpy(void *dst, const void *src, int c, size_t n);

#endif