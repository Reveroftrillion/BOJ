#!/usr/bin/env python3
import os
import sys
import datetime
import requests

# 사용방법 : 터미널 창에 Coding에서 python scripts\new_problem.py 문제번호 언어 언어\BOJ_문제번호.언어 를 입력

# solved.ac API
API = "https://solved.ac/api/v3/problem/show"

# level(0~30) → 티어 문자열 매핑 테이블
TIER_NAMES = [
    "Unrated",
    "Bronze V", "Bronze IV", "Bronze III", "Bronze II", "Bronze I",
    "Silver V", "Silver IV", "Silver III", "Silver II", "Silver I",
    "Gold V",   "Gold IV",   "Gold III",   "Gold II",   "Gold I",
    "Platinum V", "Platinum IV", "Platinum III", "Platinum II", "Platinum I",
    "Diamond V",  "Diamond IV",  "Diamond III",  "Diamond II",  "Diamond I",
    "Ruby"
]

# 문제별 코드 템플릿
TEMPLATE = {
    "py": """\
# {pid} {title} [{tier}]
import sys

def main():
    data = sys.stdin.read().split()
    # 여기에 문제 풀이 코드를 작성하세요
    # 예시: print(sum(map(int, data)))

if __name__ == "__main__":
    main()
""",
    "cpp": """\
// {pid} {title} [{tier}]
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b;
    if (!(cin >> a >> b)) return 0;
    cout << (a + b);
    return 0;
}
"""
}

def fetch_metadata(pid):
    """solved.ac에서 제목과 레벨(티어)을 가져와 문자열로 반환"""
    resp = requests.get(API, params={"problemId": pid})
    resp.raise_for_status()
    j = resp.json()
    level = j["level"]
    tier = TIER_NAMES[level]
    return j["titleKo"], tier

def main():
    if len(sys.argv) < 3 or len(sys.argv) > 4:
        print("Usage: new_problem.py <problemId> <lang(py|cpp)> [<srcCodePath>]", file=sys.stderr)
        sys.exit(1)

    pid, lang = sys.argv[1], sys.argv[2]
    title, tier = fetch_metadata(pid)

    # BOJ/<pid>/Main.ext 경로 준비
    base = os.path.join(os.getcwd(), "BOJ", pid)
    os.makedirs(base, exist_ok=True)
    ext = "py" if lang == "py" else "cpp"
    fname = f"Main.{ext}"
    path = os.path.join(base, fname)

    # 1) 코드 파일 생성 또는 복사 (복사 모드면 덮어쓰기)
    overwrite = (len(sys.argv) == 4 and os.path.isfile(sys.argv[3]))
    if os.path.exists(path) and not overwrite:
        # path가 있고, 복사 모드가 아니면 스킵
        print(">> File already exists, skipping template.")
    else:
        # overwrite=True 면 (len==4이고 src 파일이 실제 있으면) 복사
        if overwrite:
            src = sys.argv[3]
            print(f">> Overwriting with your code from {src}")
            import shutil
            shutil.copy(src, path)
        # 그 외에는 템플릿 생성
        else:
            with open(path, "w", encoding="utf-8") as f:
                f.write(TEMPLATE[ext].format(pid=pid, title=title, tier=tier))

    # 2) README.md 업데이트
    readme = os.path.join(os.getcwd(), "README.md")
    today = datetime.date.today().isoformat()
    new_line = f"| {pid} | {title} | {tier} | {lang} | {today} |\n"
    if os.path.exists(readme):
        # 1) 파일 읽기
        with open(readme, "r", encoding="utf-8") as f:
            lines = f.readlines()
       # 2) 헤더(첫 두 줄) 분리
        header = lines[:2]
        # 3) 기존 본문(3번째 줄 이후)을 가져와서, 빈 줄 제거
        body = [l for l in lines[2:] if l.strip().startswith("|")]
        # 4) 새 항목 중복 검사 후 추가
        if not any(l.startswith(f"| {pid} |") for l in body):
            body.append(new_line)
        # 5) 날짜 기준 내림차순 정렬 (각 줄의 마지막 컬럼)
        def extract_date(line):
            return line.strip().split("|")[-2].strip()
        body.sort(key=extract_date, reverse=True)
        # 6) 파일 덮어쓰기
        with open(readme, "w", encoding="utf-8") as f:
            f.writelines(header + body)
    else:
        # 파일이 없을 때(최초 실행)
        with open(readme, "w", encoding="utf-8") as f:
            f.write("# BOJ 풀이 기록\n\n")
            f.write("| 번호 | 제목 | 티어 | 언어 | 날짜 |\n")
            f.write("|:---:|:---|:---:|:---:|:---|\n")
            f.write(new_line)

    # 3) Git에 add & commit
    os.system(f'git add "{base}" "{readme}"')
    os.system(f'git commit -m "Solve {pid} ({lang}) [{tier}]"')

if __name__ == "__main__":
    main()
