# �ִ񰪰� �ּڰ�
# https://school.programmers.co.kr/learn/courses/30/lessons/12939
def solution_12939(s):
    list_s = [int(x) for x in s.split(" ")]
    return f'{min(list_s)} {max(list_s)}'


# �Ҽ� ã��
# https://school.programmers.co.kr/learn/courses/30/lessons/42839
def func_42839(num):
    if num < 2:
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
        # �� �ڸ� ���� ���� �� �ִ� ����� ��
        result = list(itertools.permutations(arr_num, i))

        # �ش� �ڸ� �� �� ��� ����
        if i == i:
            for tmp in result:
                # ���ڿ� ����
                sum_tmp = ""
                for tmp_2 in tmp:
                    sum_tmp += tmp_2

                arr_all.append(int(sum_tmp))

    dup_arr_all = list(set(arr_all))
    # print(dup_arr_all)
    cnt = 0

    for i in range(0, len(dup_arr_all)):
        if func_42839(dup_arr_all[i]):
            cnt += 1
            # print(dup_arr_all[i])

    answer = cnt
    return answer


# ī��
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


# �����Ա�
# https://school.programmers.co.kr/learn/courses/30/lessons/12913
def solution_12913(land):
    answer = 0

    for i in range(1, len(land)):
        for j in range(4):
            land[i][j] += max([land[i-1][x] for x in list({0, 1, 2, 3} - {j})])

    answer = max(land[len(land)-1])

    return answer


# �ùٸ� ��ȣ
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


# JadenCase ���ڿ� �����
# https://school.programmers.co.kr/learn/courses/30/lessons/12951
def solution_12951(s):
    answer = ""
    is_first = True

    for i in range(len(s)):
        if s[i] == " ":
            if is_first == False:
                is_first = True
            answer += s[i]
            continue

        if s[i].isdigit():
            if is_first:
                is_first = False
            answer += s[i]

            continue

        if s[i].isalpha():
            if is_first:
                answer += s[i].upper()
                is_first = False
            else:
                answer += s[i].lower()

    print(answer)

    return answer


# Ÿ�� �ѹ�
# https://school.programmers.co.kr/learn/courses/30/lessons/43165
def solution_43165(numbers, target):
    answer = 0
    aa = pow(2, len(numbers))

    list_tmp = []
    list_arr = []

    for n in range(0, aa):
        tmp = n
        list_tmp = []

        while tmp > 0:
            list_tmp.append(tmp % 2)
            tmp //= 2

        while len(list_tmp) < len(numbers):
            list_tmp.append(0)

        list_arr.append(list(reversed(list_tmp)))

    int_sum = 0
    for tmp in list_arr:
        int_sum = 0

        for i in range(0, len(numbers)):
            if tmp[i]:
                int_sum += -1*numbers[i]
            else:
                int_sum += numbers[i]

        if int_sum == target:
            answer += 1

    return answer
