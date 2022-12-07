# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: video-fl <video-fl@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/07 12:04:57 by video-fl          #+#    #+#              #
#    Updated: 2022/12/07 12:58:09 by video-fl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Variables
NAME = libftprintf.a
HEADER = libftprintf.h
SRC = #ver o q colocar aqui
OBJ = $(SRC:.c=.o) #ver essa parte
CC = gcc
CFLAGS = -Wall -Wextra -Werror -MMD #??? precisa desse mmd??? 
RM = rm -f #talvez seja desnecessario 

#Colors
DEFCOLOR = \033[0m
YELLOW = \033[3;33m
RED = \033[3;31m

## rever essa parte tbm ## 
## rever a parte que checa as dependencias para recompilar e atualizar caso a lib seja modificada ##
.c.o: $(CC) $(CFLAGS) -I $(HEADER) -c $< -o $(<:.c=.o)

#Rules
all:	$(NAME)

$(NAME): $(OBJ) $(HEADER)
	ar rcs $(NAME) $(OBJ)
	ranlib $(NAME)
	@echo "📖 $(YELLOW)Library created$(DEFCOLOR)"

.PHONY:	all clean fclean re

## rever os cleans, pq no outro faltou limpar os arquivos .d ##

clean:
	@echo "$(RED)🧹 Cleaning $(DEFCOLOR)"
	$(RM) $(OBJ)

fclean:	clean
	@echo "$(RED)🧹 FClean starting $(DEFCOLOR)"
	$(RM) $(NAME)

re:	fclean all
