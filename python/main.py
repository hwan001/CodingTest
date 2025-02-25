import importlib
import sys

from programmers.Lv0 import *
from programmers.Lv1 import *
from programmers.Lv2 import *
from programmers.Lv3 import *
from programmers.Lv4 import *

from leetcode.easy import *

from utils import load_common_packages

load_common_packages()

MODULES = {
    "programmers": "programmers",
    "boj": "boj",
    "leetcode": "leetcode"
}

def run_solution(site, problem_id, *args):
    """
    특정 문제의 풀이 함수를 실행하고 결과 출력
    """
    if site not in MODULES:
        print(f"Unsupported site: {site}")
        return

    module_name = MODULES[site]
    try:
        module = importlib.import_module(f"{module_name}.Lv0")
        if not hasattr(module, f"solution_{problem_id}"):
            module = importlib.import_module(f"{module_name}.Lv1")
        if not hasattr(module, f"solution_{problem_id}"):
            module = importlib.import_module(f"{module_name}.Lv2")
        if not hasattr(module, f"solution_{problem_id}"):
            module = importlib.import_module(f"{module_name}.Lv3")
        if not hasattr(module, f"solution_{problem_id}"):
            module = importlib.import_module(f"{module_name}.Lv4")
        
        solution_func = getattr(module, f"solution_{problem_id}")
        result = solution_func(*args)
        print(f"result: {result}")
    except AttributeError:
        print(f"Not found: {problem_id}에 대한 풀이가 없습니다.")
    except ModuleNotFoundError:
        print(f"Module not found for site: {site}")
    except Exception as e:
        print(f"error: {e}")

if __name__ == "__main__":
    # 실행 예시: python main.py programmers 120913 "abcdefghi" 3
    if len(sys.argv) < 3:
        print("python main.py [site] [ID] [args]")
        sys.exit(1)

    site = sys.argv[1]
    problem_id = sys.argv[2]
    args = sys.argv[3:]
    run_solution(site, problem_id, *args)
