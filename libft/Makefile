NAME = libft.a

SRC = $(CHAR_SRC) $(LST_SRC) $(MEM_SRC) $(NBR_SRC) $(STR_SRC) $(TBL_SRC) $(PUT_SRC)
OBJ_DIR = _objFiles
OBJ = *.o
FLAGS = -Wall -Werror -Wextra

# FILES
CHAR_C = alphas.c is_chars.c
CHAR_SRC = $(addprefix chars/, $(CHAR_C))

LST_C = lst_fts.c lst.c lst_get.c
LST_SRC = $(addprefix list/, $(LST_C))

MEM_C = mem_alloc.c mem_cmp.c mem_set.c
MEM_SRC = $(addprefix mem/, $(MEM_C))

NBR_C = digitcount.c ft_atoi.c ft_itoa.c
NBR_SRC = $(addprefix numbers/, $(NBR_C))

STR_C = ft_split.c str_chr.c str_cmp.c str_malloc.c str.c
STR_SRC = $(addprefix strings/, $(STR_C))

TBL_C = tables.c
TBL_SRC = $(addprefix tables/, $(TBL_C))

PUT_C = put_hex.c put_nbr.c put.c
PUT_SRC = $(addprefix write/, $(PUT_C))

# COLORS
NONE='\033[0m'
GRAY='\033[2;37m'
CURSIVE='\033[3m'

# RULES
all: $(NAME)

$(NAME): $(OBJ)
	@echo $(CURSIVE)$(GRAY)"      - Generating $(NAME)"$(NONE)
	@ar rc $(NAME) $(OBJ_DIR)/$(OBJ)	

$(OBJ): $(SRC)
	@gcc $(FLAGS) -c $(SRC)
	@mkdir -p $(OBJ_DIR)
	@mv $(OBJ) $(OBJ_DIR)

clean:
	@echo $(CURSIVE)$(GRAY) "     - Cleaning Libft..." $(NONE)
	@rm -f $(OBJ) $(OBJ_DIR)/$(OBJ)
	@rm -rf $(OBJ_DIR)

fclean: clean
	@echo $(CURSIVE)$(GRAY) "     - Removing $(NAME)..." $(NONE)
	@rm -f $(NAME)

re: fclean all

norm:
	@echo "\n   Libft norminette..." $(GRAY)$(CURSIVE)
	@norminette $(SRC) *.h */*.h
	@echo ""$(NONE)