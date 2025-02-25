import sys
import os
import math
import collections
import itertools
import functools
import heapq

def load_common_packages():
    """
    모든 문제 풀이에서 공통으로 사용할 패키지를 자동으로 로드할 수 있도록 설정
    """
    globals().update({
        "sys": sys,
        "os": os,
        "math": math,
        "collections": collections,
        "itertools": itertools,
        "functools": functools,
        "heapq": heapq
    })