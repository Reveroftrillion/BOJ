#!/usr/bin/env python3
import os
import sys
import datetime
import requests

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
    if len(sys.argv) != 3:
        print("Usage: new_problem.py <problemId> <lang(py|cpp)>", file=sys.stderr)
        sys.exit(1)

    pid, lang = sys.argv[1], sys.argv[2]
    title, tier = fetch_metadata(pid)

    # BOJ/<pid>/Main.ext 경로 준비
    base = os.path.join(os.getcwd(), "BOJ", pid)
    os.makedirs(base, exist_ok=True)
    ext = "py" if lang == "py" else "cpp"
    fname = f"Main.{ext}"
    path = os.path.join(base, fname)

    # 1) 코드 파일 생성 (템플릿)
    if not os.path.exists(path):
        with open(path, "w", encoding="utf-8") as f:
            f.write(TEMPLATE[ext].format(pid=pid, title=title, tier=tier))
    else:
        print(">> File exists, skipping template.")

    # 2) README.md 업데이트
    readme = os.path.join(os.getcwd(), "README.md")
    today = datetime.date.today().isoformat()
    line = f"| {pid} | {title} | {tier} | {lang} | {today} |\n"
    if os.path.exists(readme):
        with open(readme, "r+", encoding="utf-8") as f:
            content = f.read()
            if f"| {pid} |" not in content:
                f.write(line)
    else:
        with open(readme, "w", encoding="utf-8") as f:
            f.write("# BOJ 풀이 기록\n\n")
            f.write("| 번호 | 제목 | 티어 | 언어 | 날짜 |\n")
            f.write("|:---:|:---|:---:|:---:|:---|\n")
            f.write(line)

    # 3) Git에 add & commit
    os.system(f'git add "{base}" "{readme}"')
    os.system(f'git commit -m "Solve {pid} ({lang}) [{tier}]"')

if __name__ == "__main__":
    main()
