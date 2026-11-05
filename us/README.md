# 美国站 C++ 刷题

本轮从 0 开始。旧中国站代码保留在仓库根的 `cpp/` 和 `contest/`，新题放在这里的 `cpp/`。

## 当前进度

| 题目 | 状态 |
| --- | --- |
| 1. Two Sum | 已生成英文题面、C++ 空模板和样例，待学习 |

本轮正式完成：**0 题**。环境验证使用临时目录中的历史解法运行样例，没有正式提交题目，也不计入训练进度。

## 日常使用

在仓库根先查看 Git 状态，然后进入 `us/`：

```bash
git status --short --branch
cd us
leetgo info 1
leetgo pick 1 --skip-editor
```

已有题目文件时先读取，不要重新生成覆盖。写完后测试：

```bash
leetgo test 1 --local
leetgo test 1
```

用户要求正式提交时再运行 `leetgo submit 1`，确认美国站 Accepted 后保存当前题到 GitHub。

## 本机配置

- 站点：`https://leetcode.com`；英文题面，中文讲解。
- 工具：Homebrew 管理 leetgo 1.5.2。
- 编译：`clang++ -O2 -std=c++17`；辅助头文件由当前 leetgo 生成。
- 登录：本机 `us/.env`，权限为 600，已被根 `.gitignore` 忽略。此文件不随仓库同步。
- 教学 skill：`~/.codex/skills/leetcode-coach-cli/SKILL.md`。
- labuladong：已登录的 Chrome 插件，以及 `~/.labuladong/problemlist.json`、`meta.json`。本机缓存不随仓库同步。
- 旧规则和迁移背景：仓库根的 `MAC_LEETCODE_HANDOFF.md`。

2026-11-05（America/New_York）验证：美国站账号只读查询确认登录；取题成功；在临时目录中，本地和美国站远程 Run 均通过 7 组用例。远程 Run 的通过提示不代表正式提交 Accepted。
