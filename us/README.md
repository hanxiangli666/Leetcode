# 美国站 C++ 刷题

本轮重新练习从 0 开始。旧中国站代码保留在仓库根的 `cpp/` 和 `contest/`，迁移后的美国站解法及新题放在这里的 `cpp/`。

## 当前进度

| 记录 | 状态 |
| --- | --- |
| 历史中文站迁移 | **38 题全部美国站正式 Accepted**，详见 [迁移记录](MIGRATION.md) |
| 本轮重新练习 | 0 题，可从已迁移的题目中重新练习 |

美国站账号的已解题数会包含迁移提交。迁移成果与重新练习进度分开记录；每份迁移代码都注明中文站来源及迁移日期。

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

第 138 题的随机链表在 leetgo 元数据中被误标为普通链表，`leetgo test 138 --local` 无法解析正确输入。它的本地验证改用：

```bash
python3 cpp/0138.copy-list-with-random-pointer/test_local.py
```

该入口检查复制结果及深拷贝的指针关系。远程测试和正式提交仍使用 leetgo。第 49、160、236 题仅调整本地结果比较或输入转换，提交的原始算法保持不变。

## 本机配置

- 站点：`https://leetcode.com`；英文题面，中文讲解。
- 工具：Homebrew 管理 leetgo 1.5.2。
- 编译：`clang++ -O2 -std=c++17`；辅助头文件由当前 leetgo 生成。
- 登录：本机 `us/.env`，权限为 600，已被根 `.gitignore` 忽略。此文件不随仓库同步。
- 教学 skill：`~/.codex/skills/leetcode-coach-cli/SKILL.md`。
- labuladong：已登录的 Chrome 插件，以及 `~/.labuladong/problemlist.json`、`meta.json`。本机缓存不随仓库同步。
- 旧规则和迁移背景：仓库根的 `MAC_LEETCODE_HANDOFF.md`。

2026-11-05（America/New_York）迁移验证：38 题共 113 组本地用例通过，每题均通过美国站远程 Run 和正式提交；38 个独立 Accepted 提交编号已记录，官网逐题状态已复核为 `ac`。
