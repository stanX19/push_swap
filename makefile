SRCDIR		= srcs
SRCS		:= $(shell find $(SRCDIR) -name '*.c')

OBJDIR		= objs
OBJDIRS		= $(sort $(dir $(OBJS)))
OBJS		= $(subst $(SRCDIR),$(OBJDIR),$(subst .c,.o,$(SRCS)))

CWD			:= $(shell pwd)
INCLUDE_DIR	= includes
HEADER_DIR	= headers
HEADERS		:= $(shell find $(HEADER_DIR) -name '*.h') $(shell find $(INCLUDE_DIR) -name '*.h')
HEADERS_INC	= $(addprefix -I,$(sort $(dir $(HEADERS))))

LIBFT_DIR	= $(INCLUDE_DIR)/libft
LIBFT		= $(LIBFT_DIR)/libft.a

LIBS		= $(LIBFT)

IFLAGS		:= -I. $(HEADERS_INC)

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -fsanitize=address -g3
AR			= ar -rcs
RM			= rm -rf
UP			= \033[1A
FLUSH		= \033[2K

NAME		= push_swap
ARGV		= "213 1 23 1233 12312  213 1 24 1 213 21 312  312 321 3 3ewscsdd d12 123131"

run: all
	./$(NAME) $(ARGV)

$(NAME): $(LIBS) $(OBJDIRS) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(IFLAGS) $(LIBS) -o $(NAME)

all: $(NAME)

$(OBJDIRS):
	mkdir -p $@
	@echo "$(UP)$(FLUSH)$(UP)$(FLUSH)$(UP)"

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(HEADERS) $(LIBS)
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@
	@echo "$(UP)$(FLUSH)$(UP)$(FLUSH)$(UP)$(FLUSH)$(UP)"

clean:
	@$(RM) $(OBJS)

fclean:	clean
	make -C $(LIBFT_DIR) fclean
	@$(RM) $(NAME)
	@$(RM) $(TESTDIR)
	@$(RM) $(OBJDIRS)
	@$(RM) ./a.out

re: fclean $(NAME)

push:
	@echo -n "Commit name: "; read name; make fclean;\
	cd $(LIBFT_DIR); git add .; git commit -m "$$name"; git push;\
	cd $(CWD); git add .; git commit -m "$$name"; git push;\

BRANCH := $(shell git rev-parse --abbrev-ref HEAD)
ifeq ($(BRANCH),HEAD)
BRANCH := main
endif
pull:
	git fetch --all
	git reset --hard $(BRANCH);
	git checkout $(BRANCH);
	git reset --hard origin/$(BRANCH);
	git submodule update --init --remote --recursive

$(LIBFT): $(LIBFT_DIR) $(shell find $(LIBFT_DIR) -name "*.c")
	make -C $(LIBFT_DIR) all

$(LIBFT_DIR):
	touch .gitmodules
	git submodule add --force git@github.com:stanX19/libft.git $(LIBFT_DIR)
	git config -f .gitmodules submodule.$(LIBFT_DIR).branch main
	git submodule update --init --recursive --remote

init_libft: $(LIBFT_DIR)

.PHONY: all clean fclean re bonus push .c.o