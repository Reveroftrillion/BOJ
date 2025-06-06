#!/usr/bin/env python3
import os
import sys
import datetime
import shutil

# =========================================
#     템플릿 설정: 필요에 맞춰 수정하세요
# =========================================
TEMPLATE = {
    "py": """\
# {pid} {title} [{tier}]
import sys

def main():
    data = sys.stdin.read().split()
    # 여기에 문제 풀이 코드를 작성하세요
    # 예) print(sum(map(int, data)))

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

    // 여기에 문제 풀이 코드를 작성하세요
    // 예) int a, b; if (cin >> a >> b) cout << (a + b);

    return 0;
}
"""
}
# =========================================
#              END OF TEMPLATE
# =========================================


def prompt_input(prompt_text):
    """
    사용자에게 프롬프트를 띄워서 입력을 받고, strip() 해서 반환합니다.
    """
    try:
        return input(prompt_text).strip()
    except EOFError:
        return ""


def fetch_metadata_manual(pid):
    """
    solved.ac API 호출 대신, 사용자 터미널에서
    문제 제목과 티어(난이도)를 직접 입력받습니다.
    """
    title = ""
    while not title:
        title = prompt_input(f"문제 {pid}의 제목을 입력하세요 (예: 직사각형): ")
        if not title:
            print("⚠️  제목을 비워 둘 수 없습니다. 반드시 입력해주세요.")

    tier = ""
    while not tier:
        tier = prompt_input(f"문제 {pid}의 티어를 입력하세요 (예: Bronze V): ")
        if not tier:
            print("⚠️  티어를 비워 둘 수 없습니다. 반드시 입력해주세요.")

    return title, tier


def create_or_copy_code(pid, title, tier, lang, src_path=None):
    """
    BOJ/<pid>/Main.<ext> 파일을 생성하거나,
    이미 있는 소스 파일(src_path)이 주어지면 그대로 복사하여 덮어씁니다.
    """
    repo_root = os.getcwd()
    problem_dir = os.path.join(repo_root, "BOJ", pid)
    os.makedirs(problem_dir, exist_ok=True)

    ext = "py" if lang == "py" else "cpp"
    dst_fname = f"Main.{ext}"
    dst_path = os.path.join(problem_dir, dst_fname)

    # (1) 이미 파일이 존재하고, src_path가 주어지지 않았다면 스킵
    if os.path.exists(dst_path) and not (src_path and os.path.isfile(src_path)):
        print(f"⚠️  {dst_path} 파일이 이미 존재하여 템플릿 생성은 건너뜁니다.")
        return

    # (2) src_path가 실제 파일이면 복사(덮어쓰기)
    if src_path and os.path.isfile(src_path):
        shutil.copy(src_path, dst_path)
        print(f"📝 {pid} 코드 파일을 '{src_path}'에서 복사하여 → '{dst_path}'로 덮어쓰기했습니다.")
        return

    # (3) 그 외에는 언어별 템플릿 생성
    tpl = TEMPLATE.get(lang)
    if tpl is None:
        print("❌ 지원하지 않는 언어입니다. 'py' 또는 'cpp'만 허용됩니다.")
        sys.exit(1)

    with open(dst_path, "w", encoding="utf-8") as f:
        f.write(tpl.format(pid=pid, title=title, tier=tier))
    print(f"🆕 {pid} 코드 파일 생성 완료: '{dst_path}'")


def update_readme(pid, title, tier, lang):
    """
    루트에 있는 README.md를 열어서,
    Markdown 테이블의 구분자 줄("|:---")을 찾아 그 아래에 새 항목을 삽입합니다.
    기존 항목에 같은 pid가 있으면 삽입하지 않습니다.
    """
    repo_root = os.getcwd()
    readme_path = os.path.join(repo_root, "README.md")
    today = datetime.date.today().isoformat()
    # Markdown 테이블용 한 줄: "문제번호 제목 티어 언어 날짜"
    new_line = f"| {pid} | {title} | {tier} | {lang} | {today} |\n"

    if os.path.exists(readme_path):
        # (1) README.md 전체 읽기
        with open(readme_path, "r", encoding="utf-8") as f:
            lines = f.readlines()

        # (2) Markdown 테이블 구분자("|:---")가 있는 줄 인덱스를 찾는다
        header_sep_idx = None
        for idx, line in enumerate(lines):
            if line.strip().startswith("|:---"):
                header_sep_idx = idx
                break

        if header_sep_idx is None:
            print("❌ README.md에서 '|:---' 테이블 구분자 줄을 찾을 수 없습니다. 형식을 확인해주세요.")
            sys.exit(1)

        # (3) 구분자 바로 아래(인덱스 header_sep_idx+1)부터가 테이블 본문
        #     같은 pid가 이미 존재하는지 검사
        for body_line in lines[header_sep_idx + 1:]:
            # body_line 예시: "| 1855 | 암호 | Bronze I | cpp | 2025-06-06 |\n"
            # split()[1]이 '1855'가 되므로, body_line.split()[1] == pid 로 비교
            parts = body_line.strip().split()
            if len(parts) >= 2 and parts[1] == pid:
                print(f"⚠️  README.md에 이미 {pid}번 항목이 있습니다. 삽입을 건너뜁니다.")
                return

        # (4) 실제로 삽입: header_sep_idx+1 위치에 new_line을 끼워 넣는다
        new_contents = (
            lines[: header_sep_idx + 1]
            + [new_line]
            + lines[header_sep_idx + 1 :]
        )

        # (5) 날짜 순(내림차순)으로 정렬하려면, 삽입 후 아래 과정을 추가해야 하지만,
        #     여기서는 “항상 가장 위에 삽입”하는 방식으로 처리합니다.
        #     → 만약 “날짜 내림차순”으로 유지하고 싶다면, 아래 예시처럼 body만 따로 정렬할 수 있습니다:
        #
        #     body = new_contents[header_sep_idx+1:]
        #     # body 줄들 중에서 날짜(마지막 칸)를 기준으로 내림차순 정렬
        #     def extract_date(line):
        #         cols = [c.strip() for c in line.split("|")]
        #         return cols[-2]  # 마지막에서 두 번째 칸이 날짜
        #     body_sorted = sorted(body, key=extract_date, reverse=True)
        #     new_contents = new_contents[: header_sep_idx + 1] + body_sorted
        #
        #     여기서는 단순히 “맨 위에 새로 추가” 기법만 쓰겠습니다.

        with open(readme_path, "w", encoding="utf-8") as f:
            f.writelines(new_contents)

        print(f"✅ README.md 업데이트 완료: {pid} {title} [{tier}] ({lang}) {today}")

    else:
        # README.md가 없으면 새로 생성
        with open(readme_path, "w", encoding="utf-8") as f:
            f.write("# 백준 풀이 기록\n\n")
            f.write("| 번호 | 제목 | 난이도 | 언어 | 날짜 |\n")
            f.write("|:---:|:---|:---:|:---:|:---|\n")
            f.write(new_line)
        print(f"🆕 README.md를 새로 생성하고, 첫 항목으로 {pid}를 추가했습니다.")


def main():
    # -----------------------------------------------
    # 1) 커맨드 라인 인자 검사
    # -----------------------------------------------
    if len(sys.argv) < 3 or len(sys.argv) > 4:
        print("Usage: new_problem.py <problemId> <lang(py|cpp)> [<srcCodePath>]", file=sys.stderr)
        sys.exit(1)

    pid = sys.argv[1]
    lang = sys.argv[2]
    src_path = sys.argv[3] if len(sys.argv) == 4 else None

    # -----------------------------------------------
    # 2) 사용자에게 제목/티어 입력받기
    # -----------------------------------------------
    title, tier = fetch_metadata_manual(pid)

    # -----------------------------------------------
    # 3) 코드 파일 생성 or 복사
    # -----------------------------------------------
    create_or_copy_code(pid, title, tier, lang, src_path)

    # -----------------------------------------------
    # 4) README.md 업데이트
    # -----------------------------------------------
    update_readme(pid, title, tier, lang)

    # -----------------------------------------------
    # 5) Git에 add & commit
    # -----------------------------------------------
    # Git 사용 중이라면 다음 두 줄을 활성화하여 자동 커밋까지 진행할 수 있습니다.
    # 만약 “자동 커밋 불필요”하면 아래 두 줄을 주석 처리해주세요.
    os.system(f'git add BOJ/{pid} README.md')
    os.system(f'git commit -m "Solve {pid} ({lang}) [{tier}]"')


if __name__ == "__main__":
    main()
