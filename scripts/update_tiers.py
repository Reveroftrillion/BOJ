#!/usr/bin/env python3
import datetime
import os
import re

# 숫자 레벨 -> 문자열 티어 매핑
TIER_NAMES = {
    0: "Unrated",
    1: "Bronze V",   2: "Bronze IV", 3: "Bronze III",
    4: "Bronze II",  5: "Bronze I",
    6: "Silver V",   7: "Silver IV", 8: "Silver III",
    9: "Silver II", 10: "Silver I",
    11: "Gold V",   12: "Gold IV",  13: "Gold III",
    14: "Gold II",  15: "Gold I",
    16: "Platinum V",17: "Platinum IV",18: "Platinum III",
    19: "Platinum II",20: "Platinum I",
    21: "Diamond V",22: "Diamond IV",23: "Diamond III",
    24: "Diamond II",25: "Diamond I",
    26: "Ruby"
}

def replace_tier(line):
    # | 번호 | 제목 | 티어 | 언어 | 날짜 |
    # 세 번째 칸(티어)에 숫자만 들어 있는 경우 교체
    parts = [p.strip() for p in line.split("|")]
    if len(parts) >= 6 and parts[3].isdigit():
        num = int(parts[3])
        tier = TIER_NAMES.get(num, parts[3])
        parts[3] = tier
        return "| " + " | ".join(parts[1:6]) + " |"
    return line

def main():
    root = os.getcwd()
    readme = os.path.join(root, "README.md")
    if not os.path.exists(readme):
        print("README.md가 루트에 없습니다.")
        return

    lines = open(readme, encoding="utf-8").read().splitlines()
    header = lines[:2]  # 0: 제목, 1: 구분선
    body = lines[2:]
    new_body = []
    for line in body:
        if line.startswith("|"):
            new_body.append(replace_tier(line))
        else:
            new_body.append(line)

    with open(readme, "w", encoding="utf-8") as f:
        for l in header + new_body:
            f.write(l + "\n")
    print("README.md의 숫자 티어를 문자열 티어로 모두 교체했습니다.")

if __name__ == "__main__":
    main()
