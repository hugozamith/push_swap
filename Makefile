# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hteixeir <hteixeir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/20 15:18:53 by hteixeir          #+#    #+#              #
#    Updated: 2024/07/22 15:43:33 by hteixeir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Lista de arquivos .c (todos os arquivos .c no diretório atual)
SRC = $(wildcard *.c)

# Lista de arquivos .o correspondentes
OBJS = $(SRC:.c=.o)

# Nome do compilador
CC = gcc

# Flags de compilação
CFLAGS = -Wall -Werror -Wextra

# Comando para remover arquivos
RM = rm -rf

# Nome do executável
NAME = push_swap

# Regra padrão para criar o executável
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

# Regra para compilar todos os arquivos .c em .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Regra para compilar o projeto inteiro
all: $(NAME)

# Regra para limpar os arquivos .o
clean:
	$(RM) $(OBJS)

# Regra para limpar os arquivos .o e o executável
fclean: clean
	$(RM) $(NAME)

# Regra para recompilar o projeto do zero
re: fclean all

# Indica que essas regras não são arquivos
.PHONY: all clean fclean re
