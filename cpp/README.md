### 사용법
- 빌드 환경 구성 (host 에서 실행)
    - docker 설치 후 ./build_container/build.sh -> run.sh
    - vscode > extesions > remote explorer -> container 연결

- 코드 빌드 및 실행 (container 내부에서 실행)
    ```bash
    /root/CodingTest/build.sh
    ./main <baekjoon_number> # https://www.acmicpc.net/problem/1966 여기서 1966만 입력, 기본 함수(./main 시 실행) 지정은 init()에서 가능
    ```