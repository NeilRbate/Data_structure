GCC = gcc
SRCS = simply_linked_list/simply_linked_list.c \
       doubly_linked_list/doubly_linked_list.c
HEADER = -I build/data_structure.h
OBJS = ${SRCS:.c=.o}
NAME = datastructure.a
CFLAGS = -Wall -Wextra -Werror

.c.o:
	@${GCC} ${CFLAGS} ${HEADER} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
	ar rcs ${NAME} ${OBJS}

all: ${OBJS} ${NAME}

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all
