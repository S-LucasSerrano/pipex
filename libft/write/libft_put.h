#ifndef LIBFT_PUT_H
# define LIBFT_PUT_H

void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *str, int fd);
void	ft_putendl_fd(char	*str, int fd);
void	ft_putnbr_fd(int nbr, int fd);
void	ft_putlong_fd(long nbr, int fd);
void	ft_puthex_fd(unsigned int nbr, int fd);
void	ft_putlonghex_fd(unsigned long nbr, int fd);
void	ft_putupperhex_fd(unsigned int nbr, int fd);

#endif