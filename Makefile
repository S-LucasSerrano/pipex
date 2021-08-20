NAME = pipex

SRC = main.c cmdlist_init.c exec_command.c error.c
OBJ_DIR = _objFiles
OBJ = *.o

FLAGS = -Wall -Wextra -Werror


# --- LIBFT ---
LIBFT_A = libft.a
LIBF_DIR = libft/
LIBFT  = $(addprefix $(LIBF_DIR), $(LIBFT_A))


# --- COlORS ---
NONE='\033[0m'
GREEN='\033[32m'
GRAY='\033[2;37m'
CURSIVE='\033[3m'


# --- RULES ---
all: $(NAME)

$(NAME): $(OBJ_DIR)/$(OBJ)
	@echo $(CURSIVE)$(GRAY) "     - Compiling $(NAME)..." $(NONE)
	@make -C $(LIBF_DIR)
	@gcc $(FLAGS) $(LIBFT) $(OBJ_DIR)/$(OBJ) -o $(NAME)
	@echo $(GREEN)"- Compiled -"$(NONE)

$(OBJ_DIR)/$(OBJ): $(SRC)
	@echo $(CURSIVE)$(GRAY) "     - Making object files..." $(NONE)
	@gcc $(FALGS) -c $(SRC)
	@echo $(CURSIVE)$(GRAY) "     - Moving object files to $(OBJ_DIR)/..." $(NONE)
	@mkdir -p $(OBJ_DIR)
	@mv $(OBJ) $(OBJ_DIR)

clean:
	@echo $(CURSIVE)$(GRAY) "     - Removing object files..." $(NONE)
	@rm -f $(OBJ) $(OBJ_DIR)/$(OBJ)
	@rm -rf $(OBJ_DIR)
	@make -C $(LIBF_DIR) clean
	@echo "   - Clean"

fclean: clean
	@echo $(CURSIVE)$(GRAY) "     - Removing $(NAME)..." $(NONE)
	@rm -rf $(NAME)
	@make -C $(LIBF_DIR) fclean
	@echo "   - All clean"

re: fclean all

norm: $(SRC)
	@echo $(GRAY) ""
	@norminette $(SRC) *.h
	@echo $(NONE)$(GREEN) "\n     NORM OK" $(NONE)

libnorm:
	make -C $(LIBF_DIR) norm
	@echo $(NONE)$(GREEN) "     NORM OK" $(NONE)
