cmake_minimum_required(VERSION 3.9)
project(ft_printf2 C)

set(CMAKE_C_STANDARD 99)

add_executable(ft_printf2 main.c ft_printf.h ft_put.c ft_is.c ft_itoi_base.c unicode.c flags.c ft_is_cont.c width.c octal.c ft_is_num.c ft_is_point.c hexidecimal.c other_chars.c hexidecimal_print.c string.c unicode_print.c more_unicode.c print_octal.c)