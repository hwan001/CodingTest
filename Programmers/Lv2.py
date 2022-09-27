from my_package import *

# ÃÖ´ñ°ª°ú ÃÖ¼Ú°ª
# https://school.programmers.co.kr/learn/courses/30/lessons/12939
def solution_12939(s):
    list_s = [int(x) for x in s.split(" ")]
    return f'{min(list_s)} {max(list_s)}'

