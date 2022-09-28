from my_package import *

# 최댓값과 최솟값
# https://school.programmers.co.kr/learn/courses/30/lessons/12939
def solution_12939(s):
    list_s = [int(x) for x in s.split(" ")]
    return f'{min(list_s)} {max(list_s)}'


# 소수 찾기
# https://school.programmers.co.kr/learn/courses/30/lessons/42839
def func_42839(num):
    if num <2:
        return 0
    
    j = 2
    for j in range(2, int(num/j)+1):
        if num % j == 0:
            return 0
        
    return 1

def solution_42839(numbers):
    answer = 0
    
    arr_num = [x for x in numbers]
    arr_all = []
    
    for i in range(1, len(arr_num)+1):
        # 각 자리 수로 나올 수 있는 경우의 수
        result = list(itertools.permutations(arr_num, i))
        
        # 해당 자리 수 일 경우 연산
        if i == i:
            for tmp in result:
                # 문자열 조립
                sum_tmp = ""
                for tmp_2 in tmp:
                    sum_tmp += tmp_2
                    
                arr_all.append(int(sum_tmp))
          
    dup_arr_all = list(set(arr_all))
    #print(dup_arr_all)
    cnt = 0
    
    for i in range(0, len(dup_arr_all)):
        if func_42839(dup_arr_all[i]):
            cnt+=1
            #print(dup_arr_all[i])
            
    answer = cnt
    return answer


# 카펫
# https://school.programmers.co.kr/learn/courses/30/lessons/42842
def solution_42842(brown, yellow):
    answer = []
    
    x_y = int(brown / 2) + 2
    xy = brown + yellow
    
    for x in range(1, x_y):
        for y in range(1, x_y):
            if (x + y == x_y) and (x*y == xy):
                if x >= y:
                    return [x, y]
        
    return answer


# 땅따먹기
# https://school.programmers.co.kr/learn/courses/30/lessons/12913
def solution_12913(land):
    answer = 0

    for i in range(1, len(land)):
        for j in range(4):
            land[i][j] += max([land[i-1][x] for x in list({0, 1, 2, 3} - {j})])
        
    answer= max(land[len(land)-1])
        
    return answer


# 올바른 괄호
# https://school.programmers.co.kr/learn/courses/30/lessons/12909
def solution_12909(s):
    list_stack = []
    
    for ch in s:
        if ch == "(":
            list_stack.append(ch)
        else:
            if list_stack == []:
                return False
            else:
                list_stack.pop()
            
    return list_stack == []