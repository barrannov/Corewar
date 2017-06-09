# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oklymeno <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/29 11:45:35 by oklymeno          #+#    #+#              #
#    Updated: 2017/06/09 19:24:20 by dkhlopov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1 = asm
NAME2 = corewar
NAME3 = decompiler
LIBFT = libft/libft.a
SRC1 = asm_main.c \
	 asm_push_data.c \
	 asm_op.c \
	 asm_write_instr.c \
	 asm_set_arg_type.c \
	 asm_set_lable_val.c \
	 asm_check_add.c \
	 asm_validation_arg_2.c \
	 asm_validation_arg_3.c \
	 asm_validation_arg_4.c \
	 asm_validation_arg_5.c \
	 asm_validation_arg.c \
	 asm_validation_label.c \
	 asm_validation_name.c \
	 asm_validation.c \
	 asm_main_val.c \
	 asm_split.c
SRC2 = VM/src/controller/main.c\
	 VM/src/controller/vm_validation.c\
	 VM/src/controller/vm_flags.c\
	 VM/src/view/usage.c\
	 VM/src/view/visualize.c\
	 VM/src/view/status.c\
	 VM/src/view/print_map.c\
	 VM/src/view/key_hook.c\
	 VM/src/view/say_live.c\
	 VM/src/view/file_error.c\
	 VM/src/view/ft_itoa_base.c\
	 VM/src/model/create_map.c\
	 VM/src/model/logic/logic.c\
	 VM/src/model/logic/logic1.c\
	 VM/src/model/logic/logic2.c\
	 VM/src/model/logic/logic3.c\
	 VM/src/model/logic/free_all.c\
	 VM/src/model/operations/ld.c\
	 VM/src/model/operations/lld.c\
	 VM/src/model/operations/lldi.c\
	 VM/src/model/operations/st.c\
	 VM/src/model/operations/add.c\
	 VM/src/model/operations/and.c\
	 VM/src/model/operations/sub.c\
	 VM/src/model/operations/fork.c\
	 VM/src/model/operations/lfork.c\
	 VM/src/model/operations/live.c\
	 VM/src/model/operations/or.c\
	 VM/src/model/operations/xor.c\
	 VM/src/model/operations/ldi.c\
	 VM/src/model/operations/sti.c\
	 VM/src/model/operations/zjmp.c\
	 VM/src/model/operations/aff.c\
	 VM/src/model/help.c\
	 VM/src/model/get_processes.c\
	 VM/src/model/handle_check.c\
	 VM/src/model/steps.c\
	 VM/src/model/dir_ind.c
SRC3 = algorythm.c \
	 decomp_main.c \
	 write_oper_1_5.c \
	 write_oper_6_10.c \
	 write_oper_11_15.c \
	 write_types.c \
	 value_manipulations.c

FLAGS=-Wall -Wextra -Werror
OBJ1=$(SRC1:.c=.o)
OBJ2=$(SRC2:.c=.o)
OBJ3=$(SRC3:.c=.o)

all: $(LIBFT) $(NAME1) $(NAME2) $(NAME3)

$(LIBFT):
	make -C libft/

%.o: ./ASM/src/%.c
	gcc $(FLAGS) -c -o $@ $< -I./ASM/includes

%.o: ./ASM/decompile/src/%.c
	gcc $(FLAGS) -c -o $@ $< -I./ASM/decompile/includes

%.o: ./VM/src/%.c
	gcc $(FLAGS) -c -o $@ $< -I./includes

$(NAME1):$(OBJ1)
	gcc -g -o $(NAME1) $(OBJ1) -L. $(LIBFT) 

$(NAME2):$(OBJ2)
	gcc -g -o $(NAME2) $(OBJ2) -lncurses -L. $(LIBFT)

$(NAME3):$(OBJ3)
	gcc -g -o $(NAME3) $(OBJ3) -L. $(LIBFT) 

clean:
	make -C libft/ clean
	rm -Rf $(OBJ1) $(OBJ2) $(OBJ3)

fclean: clean
	rm -Rf libft/libft.a
	rm -Rf $(NAME1) $(NAME2) $(NAME3)

re: fclean all
