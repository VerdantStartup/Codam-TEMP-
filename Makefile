NAME = libft.a

SRCS = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_memchr.c ft_memcmp.c ft_memmove.c ft_memset.c ft_strchr.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_tolower.c ft_toupper.c ft_calloc.c ft_memcpy.c ft_strdup.c ft_substr.c

OFILES = $(SRCS:.c=.o)

INCLUDES = libft.h

all: $(NAME)

$(NAME): $(OFILES) $(INCLUDES)
	ar rcs $(NAME) $?
	@echo "\033[92mCompiling library\033[0m"

%.o: %.c
	$(CC) -Wall -Wextra -Werror -c -o $@ $^

clean:
	rm -rf $(OFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all