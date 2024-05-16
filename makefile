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
ARGV		= 393 322 173 151 244 43 372 154 463 331 107 253 206 492 398 347 494 20 172 189 2 404 298 461 138 21 250 60 17 489 220 447 92 217 194 358 22 429 6 191 263 109 254 280 469 365 137 471 168 384 267 424 46 7 94 342 362 95 391 289 127 498 314 491 350 452 33 32 179 143 300 334 485 5 368 84 490 203 167 96 74 341 313 359 357 264 42 270 123 129 411 83 193 385 73 255 101 355 201 45 139 239 223 382 55 140 496 262 450 207 208 36 375 248 308 156 321 11 299 258 420 171 427 40 141 378 149 444 468 184 406 288 303 307 296 256 474 163 394 319 435 177 399 160 233 292 218 81 438 351 421 246 118 475 13 104 117 181 499 302 348 195 63 458 38 50 367 8 328 19 361 317 488 225 414 325 39 56 459 437 99 120 284 323 282 286 57 281 330 115 376 363 311 483 3 252 133 51 269 371 374 80 185 131 364 285 354 349 344 266 29 481 212 24 229 97 34 484 339 369 238 221 478 224 242 387 312 249 500 360 278 49 400 192 205 345 214 145 180 166 112 324 222 72 304 48 283 268 442 176 121 169 419 275 343 386 61 10 4 333 309 237 329 122 130 443 402 227 62 47 315 116 265 415 165 493 76 413 245 416 449 126 135 273 476 430 305 486 15 235 445 480 251 466 202 473 291 294 14 142 213 287 147 18 67 1 85 436 159 106 337 295 215 170 433 52 77 175 417 90 211 247 423 426 182 381 178 240 318 448 467 152 290 316 388 373 44 144 158 405 198 35 209 389 428 30 465 472 210 432 479 37 41 418 164 153 16 28 86 197 338 108 457 272 412 336 379 409 66 228 383 310 124 440 453 408 439 155 190 470 390 88 75 91 64 105 460 119 89 241 482 69 320 128 54 113 103 234 132 455 431 183 23 356 125 407 188 65 87 422 352 93 200 59 216 370 327 456 297 232 204 82 410 397 12 306 259 186 395 71 9 230 25 261 277 100 27 271 219 441 199 196 162 462 293 464 446 78 68 136 257 148 161 425 366 335 260 340 79 58 477 301 31 98 403 454 53 102 226 26 434 401 495 146 487 380 111 243 174 187 326 392 70 274 276 497 346 353 114 279 377 396 157 110 231 150 332 236 451 134


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
	git checkout -f $(BRANCH);
	git reset --hard origin/$(BRANCH);
	git submodule update --init --remote --recursive
	make -C $(LIBFT_DIR) pull

$(LIBFT): $(LIBFT_DIR) $(shell find $(LIBFT_DIR) -name "*.c")
	make -C $(LIBFT_DIR) all

$(LIBFT_DIR):
	touch .gitmodules
	git submodule add --force git@github.com:stanX19/libft.git $(LIBFT_DIR)
	git config -f .gitmodules submodule.$(LIBFT_DIR).branch main
	git submodule update --init --recursive --remote

init_libft: $(LIBFT_DIR)

.PHONY: all clean fclean re bonus push .c.o